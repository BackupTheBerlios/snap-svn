#include "PrefixTreePreprocessor.h"
#include "Sequence.h"
#include "PrefixTreeWalker.h"

#include "Core/AutoPtr.h"
#include "Core/ChunkAllocator.h"
#include "Persistance/IArchive.h"
#include "Persistance/OArchive.h"
#include "DebugLog.h"

#include <algorithm>
#include <time.h>


USING_TYPE (PrefixTreePreprocessor, NodeRep);
USING_TYPE (PrefixTreePreprocessor, TreeRep);
USING_TYPE (PrefixTreePreprocessor, SeqPositions);

USING_TYPE (Preprocessor, PositionVector);
USING_TYPE (Preprocessor, PositionIterator);


ChunkAllocator <PositionVector> PositionVector::__allocator (4);


/*****************************
 * NodeRep
 *****************************/



class PrefixTreePreprocessor::NodeRep : public Persistance::Object {
public:
   NodeRep (NodeRep* parent, int cardinality) : _cardinality (cardinality),
                                                _parent (parent) {
      _children = new NodeRep* [cardinality];
      for (int i=0 ; i<_cardinality ; i++) {
         _children [i] = NULL;
      }

#     if SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION
         //
         // optimization (?) we use the size of the parent's _position vector
         // to hint at our _position vector's approximated size
         if (parent)
            _positions.reserve (parent->_positions.size () / _cardinality);
#     endif
   }
   //
   // used for serialization
   inline NodeRep () 
   : _cardinality (0), _children (NULL), _parent (NULL)   {
   }

   ~NodeRep () {
      dispose (false);
   }

   void dispose (bool isRoot) {
      if (_children) {
         for (int i=0 ; i<_cardinality ; i++) {
            if (_children [i]) {
               _children [i]->dispose (false);
               delete _children [i];
            }
         }
      }

      delete [] _children;
      _children = NULL;

      //
      // free memory of all SeqPositions
      int n = _positions.size ();
      for (int i=0 ; i<n ; i++) {
         _positions [i].dispose (isRoot);
      }
      _positions.clear ();
   }

   void addSequencePositions (PositionVector* pos) {
      debug_mustbe (pos != NULL);
      debug_mustbe (!pos->empty ());
      _positions.push_back (SeqPositions (pos));
   }
   int addSequencePositionsFinish () const
   {
      return _positions.capacity () - _positions.size ();
   }

   SeqPositionIterator positionsBySequence () {
      return SeqPositionIterator (_positions.begin (), _positions.end ());
   }
   NodeRep* getCreateChild (int index, bool&wasCreated) {
      debug_mustbe (index >=0);
      debug_mustbe (index < _cardinality);

      wasCreated = false;
      if (_children [index] == NULL) {
         _children [index] = new NodeRep (this, _cardinality);
         wasCreated = true;
      }

      return _children [index];
   }
   NodeRep* getChild (int index) {
      debug_mustbe (index >=0);
      debug_mustbe (index < _cardinality);
      return _children [index];
   }
   
   SeqPositions getSeqPositions (SequenceDB::ID id);

   void serialize (Persistance::IArchive& in);
   void serialize (Persistance::OArchive& out);

#if SEED_CHUNK_ALLOCATION_OPTIMIZATION
   void* operator new (size_t size) {
      debug_mustbe (size == sizeof (NodeRep));
      return __allocator.newT ();
   }
   void operator delete(void *p)    {
      __allocator.deleteT (reinterpret_cast <NodeRep*> (p));
   }
#endif

   // TODO:
   // maybe save space in the tree by storing the cardinality only in one place
   int _cardinality; 
   SeqPositionVector _positions;
   NodeRep ** _children;
   NodeRep* _parent;
   
   static ChunkAllocator <NodeRep> __allocator;
};

//
// static instantiation
ChunkAllocator <NodeRep> PrefixTreePreprocessor::NodeRep::__allocator (4);







/*****************************
 * TreeRep
 *****************************/

class PrefixTreePreprocessor::TreeRep : public Persistance::Object{
public:
   TreeRep (const SequenceDB* inDb, NodeRep* inRoot, int inDepth)
      : _depth (inDepth), _root (inRoot), _db (inDb)
   {
   }

   //
   // used for serialization
   TreeRep () {
   }

   ~TreeRep () {
      _root->dispose (true);
      delete _root;
   }

   void serialize (Persistance::IArchive& in);
   void serialize (Persistance::OArchive& out);

   int _depth;
   NodeRep* _root;
   const SequenceDB* _db;
};





/*****************************
 * PositionsBuilder
 *****************************/


class PositionsBuilder {
public:
   PositionsBuilder (int cardinality) 
   : _cardinality (cardinality), _numOfVectors(0), _numOfNodes (0), _sizeInVectors(0), _spaceLostInVectors (0)
   {
      _positions = new PositionVector* [cardinality];
      for (int i=0 ; i < cardinality ; i++) {
         _positions [i] = new PositionVector;
         _numOfVectors++;
      }
   }
   ~PositionsBuilder () {
      for (int i=0 ; i < _cardinality ; i++)
         delete _positions [i];

      delete [] _positions;
   }
   void addPosition (int index, const Position* pos) {
      debug_mustbe (index >=0 && index < _cardinality);
      _positions [index]->push_back (pos);
   }

   void finish (NodeRep* parent) {
      _spaceLostInVectors += parent->addSequencePositionsFinish ();
   }

   void install (NodeRep* parent) {
      //
      //
      for (int i=0 ; i < _cardinality ; i++) {
         if (_positions [i]->size () > 0) {
            
            bool wasCreated;
            NodeRep* child = parent->getCreateChild (i, wasCreated);
            child->addSequencePositions (_positions [i]);

            int vectorSize = _positions [i]->size ();
            int vectorCapacity = _positions [i]->capacity ();
            debug_mustbe (vectorSize <= vectorCapacity);

            _sizeInVectors += vectorSize;
            _spaceLostInVectors += (vectorCapacity - vectorSize);
            _positions [i] = new PositionVector;
            
#           if SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION
               //
               // optimization (?) reserve size in the vector
               // something in the order of the last vector
               _positions [i]->reserve (vectorSize / _cardinality);
#           endif

            //
            // for statistics
            _numOfVectors++;
            if (wasCreated)
               _numOfNodes++;
         }
      }
   }

   int numOfVectors () const {
      return _numOfVectors;
   }
   int numOfNodes () const {
      return _numOfNodes;
   }
   int sizeInVectors () const {
      return _sizeInVectors;
   }
   int spaceLostInVectors () const {
      return _spaceLostInVectors;
   }

private:
   int _cardinality;
   PositionVector** _positions;
   //
   // for statistics
   int _numOfVectors;
   int _numOfNodes;
   int _sizeInVectors;
   int _spaceLostInVectors;
};




/*****************************
 * Tree - building
 *****************************/



static void buildTree (PositionsBuilder& builder,
                       const SequenceDB::Cluster* positivelyLabeled, 
                       const AlphabetCode& code,
                       NodeRep* parent,
                       int currentDepth, 
                       int maxDepth) {
   if (currentDepth >= maxDepth)
      return;

   //
   // the 'optimization' below doesn't work - it messes up seed scoring :
   // for example consider a genome with 2 sequences, each with 1 position:
   //    A  - this is the 'positively labeled' sequence
   //    C  - this is the 'non-positively labeled' sequnce.
   //
   // when we build the tree (WITH the optimization below)
   // we would, of course, discard the prefix node 'C' because it
   // doesnt contain any positive positions.
   //
   // when we later score a seed, such as '?' the score should
   // be: 1 positive position, 1 negative position 
   // (because is should find both 'A' and 'C')
   //
   // BUT: the score will only be 1: positive position
   // because the 'C' node is not in the tree at all and so it's positions
   // cant be found! therefore we CANNOT remove ANY nodes from the tree.
   //
#  if 0
      //
      // optimization:
      if (positivelyLabeled != NULL) {
         //
         // we do not continue to build the tree from nodes
         // that do not have any positively labeled positions
         PrefixTreePreprocessor::Node node (parent);
         if (!node.hasPositions (*positivelyLabeled)) {
            return;
         }
      }
#  endif
   
   //
   // now we go over all positions, ordered by the sequence they are located in
   PrefixTreePreprocessor::SeqPositionIterator seqIt = 
      parent->positionsBySequence ();

   
   for (; seqIt.hasNext () ; seqIt.next ()) {
      //
      //
      Preprocessor::PositionIterator it = seqIt->iterator ();
      for (; it.hasNext () ; it.next ()) {
         //
         // decide which child this position belongs to according
         // to the data in 'currentDepth' place in the position
         // 
         // positions which are too close to the end of the sequence
         // are discarded (not passed on to children nodexs) here
         int maxLookahead = (*it)->maxLookahead ();
         if (maxLookahead > currentDepth) {
            AlphabetCode::CodedChar c = 
               code.code ((*it)->getData (currentDepth));

            if (c == AlphabetCode::notInCode) {
               //
               // the character is not in the known alphabet
               throwx (AlphabetCode::UnknownCodeError ((*it)->getData (currentDepth)));
            }
            else if (c == AlphabetCode::dunnoCode) {
               //
               // the user does not know which character lies in the sequence here.
               //
               // TODO: handle this. I should (1) put it in all the children?
               // (2) count how many like this are in a sequence and get rid
               // of positions with too much unknowns?
               //
               // SOLUTION: the user of the tree can circumvent dunno's by
               // using an assignment that does not allow this character
               debug_mustfail ();
            }
            else {
               builder.addPosition (c, *it);
            }
         }
      }

      //
      // finished going through all positions for this sequence
      // put all the positions in the relevant child node
      builder.install (parent);
   }
   builder.finish (parent);

   //
   // finished going through all the sequences of the parent
   // now continue to build the tree for all the children
   for (int i=0 ; i < code.cardinality () ; i++) {
      NodeRep* child = parent->getChild (i);
      if (child == NULL) continue;

      buildTree (builder, positivelyLabeled, code, child, currentDepth+1, maxDepth);
   }
}


static TreeRep* build(const SequenceDB::Cluster* positivelyLabeled,
                      SequenceDB* db, 
                      int maxDepth)
{
   time_t start, finish;
   time (&start);

   int cardinality = 
      db->alphabetCode ().cardinality ();

   int numberOfPositions = 0;
   NodeRep* root = new NodeRep (NULL, cardinality);
   SequenceDB::SequenceIterator it = db->sequenceIterator ();
   for (;it.hasNext () ; it.next ()) {
      //
      // get the sequence we are current working on
      Sequence* seq = it.get ();
      debug_mustbe (seq);

      //
      // create a vector of positions for this sequence
      PositionVector* positions = new PositionVector;

      //
      // stuff every position in this sequence to the root node
      int length = seq->length ();
      numberOfPositions += length;
      for (int i=0 ; i<length ; i++)   {
         Position* position = 
            new Position (seq, i);

         positions->push_back (position);
      }

      root->addSequencePositions (positions);
   }

   //
   // now the root node has all the positions in all sequences.
   // build up the tree until the desired depth 
   PositionsBuilder builder (db->alphabetCode ().cardinality ());
   buildTree (builder, positivelyLabeled, db->alphabetCode (), root, 0, maxDepth);

   time (&finish);
   int totalBytes =  numberOfPositions * sizeof (Position) +
                     builder.numOfNodes () * sizeof (NodeRep) +
                     cardinality * sizeof (NodeRep*) * builder.numOfNodes () + // child arrays
                     builder.numOfVectors () * sizeof (PositionVector) + 
                     builder.sizeInVectors () * sizeof (Position*) + 
                     builder.spaceLostInVectors () * sizeof (Position*);
                     
   DLOG << "PrefixTreePreprocessor created: (" << (finish - start) << " seconds)" << DLOG.EOL ()
          << numberOfPositions << " Position objects each of " << sizeof (Position) << " Bytes." << DLOG.EOL ()
          << builder.numOfNodes () << " Node objects each of " << sizeof (NodeRep) << " Bytes." << DLOG.EOL ()
          << builder.numOfVectors () << " PositionVector objects each of " << sizeof (PositionVector) << " Bytes." << DLOG.EOL ()
          << builder.sizeInVectors () << " total positions in PositionVectors" << DLOG.EOL ()
          << builder.spaceLostInVectors () << " positions lost in PositionVectors capacity" << DLOG.EOL ()
          << (totalBytes / 1024) << " KBytes approximated tree size." << DLOG.EOL ()
          << DLOG.EOL ();

   return new TreeRep (db, root, maxDepth);
}


TreeRep* PrefixTreePreprocessor::build (SequenceDB* db, 
                                        int depth)
{
   return ::build (NULL, db, depth);
}

TreeRep* PrefixTreePreprocessor::build (const SequenceDB::Cluster& positivelyLabeled, 
                                        SequenceDB* db, 
                                        int depth)
{
   return ::build (&positivelyLabeled, db, depth);
}



/*****************************
 * Positions
 *****************************/



SeqPositions::SeqPositions () 
:  _positions (NULL) 
{
}

SeqPositions::SeqPositions (PositionVector* pos)
:  _positions (pos)
{
}

SeqPositions::~SeqPositions ()
{
   //
   // memory for positions is owned by the hosting node
}

void SeqPositions::dispose (bool disposePositions)
{
   if (disposePositions) {
      PositionIterator it = iterator ();
      for (; it.hasNext () ; it.next ()) {
         const Position* pos = it.get ();
         delete const_cast <Position*> (pos);
      }
   }

   delete _positions;
   _positions = NULL;
}


SeqPositions& SeqPositions::operator = (const SeqPositions& pos)
{
   _positions = pos._positions;
   return *this;
}

Preprocessor::PositionIterator SeqPositions::iterator ()
{
   if (_positions == NULL) {
      //
      // this is necessary, because sometimes an empty SeqPositions is created
      // and an iterator is wanted, such as when a vector of nodes is being
      // searched for all positions in a specific sequence
      // and one of the nodes does not have such a sequence
      return PositionIterator ();
   }

   return PositionIterator (_positions->begin (), _positions->end ());
}

const PositionVector* SeqPositions::positions () const
{
   return _positions;
}

bool SeqPositions::empty () const
{
   return _positions->empty ();
}

int SeqPositions::size () const
{
   return _positions->size ();
}

const Sequence* SeqPositions::sequence () const
{
   if (_positions == NULL)
      return NULL;

   return _positions->empty ()? NULL : (*_positions) [0]->sequence ();
}




/*****************************
 * PrefixTreePreprocessor
 *****************************/




//
// Ctor
PrefixTreePreprocessor::PrefixTreePreprocessor (TreeRep* rep, bool owner)
: _owner (owner),
  _rep (rep)
{
}


//
// Dtor
PrefixTreePreprocessor::~PrefixTreePreprocessor ()
{
   //
   // TODO: delete all positions (go through all positions in the root and --kill--)
   if (_owner)
      delete _rep;
}


//
// returns true iff the sequence has at least one position which corresponds
// to the given assignment
bool PrefixTreePreprocessor::hasAssignment (SequenceDB::ID id, const Assignment& assg)
{
   PrefixTreeWalker::Nodes nodes;
   nodes.addAssignmentNodes (*this, assg);
   PrefixTreeWalker::NodeIterator it (nodes.iterator ());
   for (; it.hasNext (); it.next ()) {
      Node node (it.get ());
      if (node.hasPositions (id))
         return true;
   }

   return false;
}

//
// iterate over all sequences that have at least one position which corresponds 
// to the given assignment
Preprocessor::SequenceVector*  
PrefixTreePreprocessor::getSequences (const Assignment& assg)
{
   PrefixTreeWalker::Nodes nodes;
   nodes.addAssignmentNodes (*this, assg);
   return nodes.sequences ();
}



//
// iterate over all sequences
Preprocessor::SequenceVector*
PrefixTreePreprocessor::getSequences ()
{
   //
   // here we have to copy the vector provided by SequenceDB,
   // into a new vector, which contains exactly the same pointers to Sequnces
   return createNewVector <Preprocessor::SequenceVector> (
	  _rep->_db->size (),
	  _rep->_db->sequences ().begin (),
	  _rep->_db->sequences ().end ()
	  );
}     

//
// iterate over all positions that correspond to an assignment on a given sequence
Preprocessor::PositionVector* 
PrefixTreePreprocessor::getPositions (SequenceDB::ID id, 
                                      const Assignment& assg)
{
   PrefixTreeWalker::Nodes nodes;
   nodes.addAssignmentNodes (*this, assg);
   return nodes.positions (id);
}

int PrefixTreePreprocessor::minAssignmentSize ()
{
   //
   // TODO: check is this exact?
   return 1;
}

int PrefixTreePreprocessor::maxAssignmentSize ()
{
   //
   // TODO: check is this exact?
   return _rep->_depth;
}

const SequenceDB* PrefixTreePreprocessor::getSequenceDB () const {
   return _rep->_db;
}

int PrefixTreePreprocessor::getDepth () const
{
   return _rep->_depth;
}


/*****************************
 * NodeRep
 *****************************/

//
// a predicate class for searching for our sequence
class GetSeqPosition {
public:
   GetSeqPosition (const SeqPositions*& found) : _found (found) {
   }
   bool operator () (const SeqPositions& pos, SequenceDB::ID id) {
      int seqId = pos.sequence ()->id ();
      if (seqId == id) {
         //
         // we have found the SeqPosisition we were looking for!
         _found = &pos;
      }

      return seqId < id;
   }
   bool operator () (SequenceDB::ID id, const SeqPositions& pos) {
      int seqId = pos.sequence ()->id ();
      if (seqId == id) {
         //
         // we have found the SeqPosisition we were looking for!
         _found = &pos;
      }

      return id < seqId;
   }

private:
   const SeqPositions*& _found; 

};

SeqPositions PrefixTreePreprocessor::NodeRep::getSeqPositions (SequenceDB::ID id)
{

   //
   // stupid 'binary-search' does not take the predicate by-reference
   // so we have to hold GetSeqPosition's state here...
   const SeqPositions* _found = NULL;
   GetSeqPosition pos (_found);
   //
   // we search for the SeqPositions object using binary search
   // because only a part of all possible sequences are relevant to each node
   bool result = 
      std::binary_search (_positions.begin (), _positions.end (), id, pos);

   debug_mustbe (result == (_found != NULL));
   return result? *_found : SeqPositions ();
}

/*****************************
 * Node
 *****************************/

int PrefixTreePreprocessor::Node::getCardinality ()
{
   return _rep->_cardinality;
}

NodeRep* PrefixTreePreprocessor::Node::getChild (int index)
{
   return _rep->getChild (index);
}

NodeRep* PrefixTreePreprocessor::Node::getParent ()
{
   return _rep->_parent;
}

int PrefixTreePreprocessor::Node::depth ()
{
   //
   // TODO: not implemented (is it really necessary?)
   debug_mustfail ();
   return -1;
}

//
// iterate over positions for this node
// ordered by their sequence
PrefixTreePreprocessor::SeqPositionIterator 
PrefixTreePreprocessor::Node::positionsBySequence ()
{
   return _rep->positionsBySequence ();
}

//
// ownership belongs to the caller
PositionVector* PrefixTreePreprocessor::Node::getPositions (SequenceDB::ID id)
{
   return new PositionVector (*_rep->getSeqPositions (id).positions ());
}

//
// iterate over all positions of a particular sequence in this node
PositionIterator 
PrefixTreePreprocessor::Node::positionIterator (SequenceDB::ID id)
{
   return _rep->getSeqPositions (id).iterator ();
}

//
// check if node has any positions for a particular sequence
bool PrefixTreePreprocessor::Node::hasPositions (SequenceDB::ID id) const
{
   return !_rep->getSeqPositions (id).empty ();
}

bool PrefixTreePreprocessor::Node::hasPositions (const SeqCluster& cluster) const
{
   SeqPositionIterator it (_rep->positionsBySequence ());
   for (; it.hasNext () ; it.next ()) {
      if (cluster.hasSequence (it->sequence ()))
         return true;
   }

   return false;
}

NodeRep* PrefixTreePreprocessor::getRoot () const
{
   return _rep->_root;
}

//
// returns all the sequences in this node
void PrefixTreePreprocessor::Node::
   getCluster (SequenceDB::Cluster& outSeqInNode) const
{
   outSeqInNode.clear ();
   SeqPositionIterator it (_rep->positionsBySequence ());
   for (; it.hasNext () ; it.next ()) {
      outSeqInNode.addSequence (it->sequence ());
   }
}




//
// Serialization
//
#include "Persistance/STLPersist.h"
using namespace Persistance;


void PrefixTreePreprocessor::TreeRep::serialize (Persistance::OArchive& out)
{
   out.registerObject (_db, false);
   out << _depth;
   out.registerObject (_root, true);
}


void PrefixTreePreprocessor::TreeRep::serialize (Persistance::IArchive& in)
{
   in.registerObject (const_cast <SequenceDB*&> (_db));
   in >> _depth;
   in.registerObject (_root);
}





void PrefixTreePreprocessor::NodeRep::serialize (Persistance::OArchive& out)
{
   out << _cardinality; 
 
   out.setContext (_parent);
   out << OSTL <SeqPositionVector> (_positions);

   for (int i=0 ; i<_cardinality ; i++)
      out.registerObject (_children [i], true);

   out.registerObject (_parent, false);
}

void PrefixTreePreprocessor::NodeRep::serialize (Persistance::IArchive& in)
{
   in >> _cardinality; 
   in >> ISTL <SeqPositionVector> (_positions);

   _children = new NodeRep* [_cardinality];
   for (int i=0 ; i<_cardinality ; i++)
      in.registerObject (_children [i]);

   in.registerObject (_parent);
}



void PrefixTreePreprocessor::SeqPositions::serialize (Persistance::OArchive& out)
{
   bool isRoot = out.getContext () == NULL;

   if (isRoot) 
      out << OSTL <PositionVector, OInstance> (*_positions);
   else 
      out << OSTL <PositionVector, OLink> (*_positions);
}

void PrefixTreePreprocessor::SeqPositions::serialize (Persistance::IArchive& in)
{
   _positions = new PositionVector;
   in >> ISTLReg <PositionVector> (*_positions);
}

void PrefixTreePreprocessor::serialize (Persistance::IArchive& in)
{
   in.readObject (_rep);
}
void PrefixTreePreprocessor::serialize (Persistance::OArchive& out)
{
   out.writeObject (_rep);
}

void PrefixTreePreprocessor::createFactories (TFactoryList& factories)
{
   new TFactory <TreeRep> (&factories);
   new TFactory <NodeRep> (&factories);
}





