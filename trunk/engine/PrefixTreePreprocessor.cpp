#include "PrefixTreePreprocessor.h"
#include "Sequence.h"
#include "PrefixTreeWalker.h"

#include "Core/AutoPtr.h"

#include <algorithm>


USING_TYPE (PrefixTreePreprocessor, NodeRep);
USING_TYPE (PrefixTreePreprocessor, TreeRep);
USING_TYPE (PrefixTreePreprocessor, SeqPositions);

USING_TYPE (SequenceDB, Sequence);
USING_TYPE (SequenceDB, Position);
USING_TYPE (Preprocessor, PositionVector);
USING_TYPE (Preprocessor, PositionIterator);





/*****************************
 * TreeRep
 *****************************/

class PrefixTreePreprocessor::TreeRep {
public:
   TreeRep (const SequenceDB* inDb, NodeRep* inRoot, int inDepth)
      : _depth (inDepth), _root (inRoot), _db (inDb)
   {
   }

   int _depth;
   NodeRep* _root;
   const SequenceDB* _db;
};





/*****************************
 * NodeRep
 *****************************/



class PrefixTreePreprocessor::NodeRep {
public:
   NodeRep (NodeRep* parent, int cardinality) : _cardinality (cardinality),
                                                _parent (parent) {
      _children = new NodeRep* [cardinality];
      for (int i=0 ; i<_cardinality ; i++) {
         _children [i] = NULL;
      }
   }
   ~NodeRep () {
      delete [] _children;
   }
   void addSequencePositions (PositionVector* pos) {
      debug_mustbe (pos != NULL);
      debug_mustbe (!pos->empty ());
      _positions.push_back (pos);
   }
   SeqPositionIterator positionsBySequence () {
      return SeqPositionIterator (_positions.begin (), _positions.end ());
   }
   NodeRep* getCreateChild (int index) {
      debug_mustbe (index >=0);
      debug_mustbe (index < _cardinality);

      if (_children [index] == NULL)
         _children [index] = new NodeRep (this, _cardinality);

      return _children [index];
   }
   NodeRep* getChild (int index) {
      debug_mustbe (index >=0);
      debug_mustbe (index < _cardinality);
      return _children [index];
   }
   
   SeqPositions getSeqPositions (SequenceDB::ID id);

   // TODO:
   // maybe save space in the tree by storing the cardinality only in one place
   int _cardinality; 
   SeqPositionVector _positions;
   NodeRep ** _children;
   NodeRep* _parent;
};





/*****************************
 * PositionsBuilder
 *****************************/


class PositionsBuilder {
public:
   PositionsBuilder (int cardinality) : _cardinality (cardinality) {
      _positions = new PositionVector* [cardinality];
      for (int i=0 ; i < cardinality ; i++) {
         _positions [i] = new PositionVector;
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
   void install (NodeRep* parent) {
      for (int i=0 ; i < _cardinality ; i++) {
         if (_positions [i]->size () > 0) {
            NodeRep* child = parent->getCreateChild (i);
            child->addSequencePositions (_positions [i]);
               _positions [i] = new PositionVector;
         }
      }
   }

private:
   int _cardinality;
   PositionVector** _positions;
};




/*****************************
 * Tree - building
 *****************************/



static void buildTree (const AlphabetCode& code,
                        NodeRep* parent, 
                        int currentDepth, 
                        int maxDepth) {
   if (currentDepth >= maxDepth)
      return;

   PositionsBuilder builder (code.cardinality ());
   
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
               // TODO: handle this. I should (1) put it in all the children
               // (2) count how many like this are in a sequence and get rid
               // of positions with too much unknowns
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

   //
   // finished going through all the sequences of the parent
   // now continue to build the tree for all the children
   for (int i=0 ; i < code.cardinality () ; i++) {
      NodeRep* child = parent->getChild (i);
      if (child == NULL) continue;

      buildTree (code, child, currentDepth+1, maxDepth);
   }
}


TreeRep* PrefixTreePreprocessor::build(SequenceDB* db, int maxDepth)
{
   NodeRep* root = new NodeRep (NULL, db->alphabetCode ().cardinality ());
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
      for (int i=0 ; i<length ; i++)   {
         SequenceDB::Position* position = 
            new SequenceDB::Position (seq, i);

         positions->push_back (position);
      }

      root->addSequencePositions (positions);
   }

   //
   // now the root node has all the positions in all sequences.
   // build up the tree until the desired depth 
   buildTree (db->alphabetCode (), root, 0, maxDepth);
   return new TreeRep (db, root, maxDepth);
}






/*****************************
 * Positions
 *****************************/



SeqPositions::SeqPositions () 
  : _owner (false),
    _positions (NULL) 
{
}

SeqPositions::SeqPositions (PositionVector* pos, bool owner)
  : _owner (owner),
    _positions (pos)
{
}

SeqPositions::~SeqPositions ()
{
   if (_owner)
      delete _positions;
}

SeqPositions& SeqPositions::operator = (const SeqPositions& pos)
{
   //
   // no implicit ownership tranfer
   _owner = false;
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

const SequenceDB::Sequence* SeqPositions::sequence () const
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
bool PrefixTreePreprocessor::Node::hasPositions (SequenceDB::ID id)
{
   return !_rep->getSeqPositions (id).empty ();
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
      outSeqInNode.add (it->sequence ()->id ());
   }
}
