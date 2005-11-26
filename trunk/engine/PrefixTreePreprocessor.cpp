//
// File        : $RCSfile: $ 
//               $Workfile: PrefixTreePreprocessor.cpp $
// Version     : $Revision: 38 $ 
//               $Author: Aviad $
//               $Date: 4/11/04 17:53 $ 
// Description :
//    Concrete preprocessor class - based on a prefix tree
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "PrefixTreePreprocessor.h"

#include "Assignment.h"
#include "Sequence.h"

#include "core/AutoPtr.h"
#include "persistance/IArchive.h"
#include "persistance/OArchive.h"
#include "DebugLog.h"

#include "core/AllocPolicy.h"

#include <algorithm>
#include <time.h>


USING_TYPE (PrefixTreePreprocessor, TreeRep);
USING_TYPE (PrefixTreePreprocessor, TreeNode);
USING_TYPE (PrefixTreePreprocessor, TreeNodeRep);
USING_TYPE (PrefixTreePreprocessor, SeqPositions);

typedef PrivatePoolPolicy CurrentAllocPolicy;


/*****************************
 * TreeNodeRep
 *****************************/



class PrefixTreePreprocessor::TreeNodeRep :
  public Preprocessor::NodeRep,
  public CurrentAllocPolicy::Traits<TreeNodeRep>::TBase
{
   //
   // tree-building interface
private:
   inline TreeNodeRep (TreeNodeRep* parent);
   inline TreeNodeRep (TreeRep* host);
  friend class PrefixTreePreprocessor::TreeRep;

public:
  virtual ~TreeNodeRep ();

   //
   //
   void setup (TreeNodeRep* parent);
   inline void dispose (bool isRoot);

   //
   //
   inline void addSequencePositions (PositionVector* pos);
   inline int addSequencePositionsFinish () const;

   //
   //
   void removeChild (int index);
   TreeNodeRep* getCreateChild (int index, bool& wasCreated);
   SeqPositions getSeqPositions (SequenceDB::ID id) const;

   //
   // user-friendly tree-node interface
public:
   //
   // return the maximum number of children a node can have (in this tree)
   inline int getCardinality () const;

   //
   // get a child of this node of the half-open range [0..cardinality)
   inline TreeNodeRep* getChild (int) const;

   //
   // return the depth of this node
   inline int depth () const;

   //
   // iterate over positions for this node
   // ordered by their sequence
   inline CSeqPositionIterator positionsBySequence () const;
   inline SeqPositionIterator positionsBySequence ();

   //
   // ownership belongs to the caller
   inline AutoPtr <PositionVector> getPositions (SequenceDB::ID) const;

   //
   // iterate over all positions of a particular sequence in this node
   inline PositionIterator positionIterator (SequenceDB::ID);

   //
   //
   const AlphabetCode& getCode () const;

   //
   // general node interface
public:
   //
   // check if node has any positions for a particular sequence
   virtual bool hasPositions (SequenceDB::ID) const; 
   virtual bool hasPositions (const SeqWeightFunction&) const;

   //
   // returns all the sequences in this node
   virtual void add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const;
   virtual void add2SeqClusterPositions (SequenceDB::Cluster&) const;
   virtual void add2PosCluster (PosCluster&, Sequence::ID) const;

   virtual void add2Assignment (Assignment&) const;

   //
   //
   virtual NodePositionIt::Rep* positionIterator () const {
      //
      // 
      return new TreeNodePositionIt (const_cast <TreeNodeRep*> (this));
   }

protected:
  int _depth;
  SeqPositionVector _positions;
  TreeNodeRep ** _children;
  TreeRep* _host;
};








/*****************************
 * TreeRep
 *****************************/

class PrefixTreePreprocessor::TreeRep {
public:
   TreeRep (const SequenceDB* inDb, 
	    const AlphabetCode& code,
	    int inDepth)
     : _depth (inDepth), 
       _db (inDb),
       _code (code)
   {
     _root = new (_allocator) TreeNodeRep (this);
     _root->setupMemory (_allocator);
   }

   ~TreeRep () {
     bool shouldCleanup = _allocator.cleanupMemory ();
     if (shouldCleanup)
       delete _root;
   }

  TreeNodeRep* createNode (TreeNodeRep* parent) {
    TreeNodeRep* result = new (_allocator) TreeNodeRep (parent);
    result->setupMemory (_allocator);
    return result;
  }
  void destroyNode (TreeNodeRep* node) {
    _allocator.cleanupMemory (node);
  }
  TreeNodeRep* getRoot () {
    return _root;
  }
  const AlphabetCode& getCode () const {
    return _code;
  }

   int _depth;
   TreeNodeRep* _root;
   const SequenceDB* _db;
   const AlphabetCode& _code;
   TreeNodeRep::TAllocator _allocator;
};





/*****************************
 * PositionsBuilder
 *****************************/


class PositionsBuilder {
public:
   PositionsBuilder (int cardinality) 
     : _cardinality (cardinality), 
       _numOfVectors(0), _numOfNodes (0), 
       _sizeInVectors(0), _spaceLostInVectors (0)
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
   void addPosition (int index, const SeqPosition* pos) {
      debug_mustbe (index >=0 && index < _cardinality);
      _positions [index]->push_back (pos);
   }

   void finish (TreeNodeRep* parent) {
      _spaceLostInVectors += parent->addSequencePositionsFinish ();
   }

   void install (TreeNodeRep* parent) {
      for (int i=0 ; i < _cardinality ; i++) {
         if (_positions [i]->size () > 0) {
            bool wasCreated;
            TreeNodeRep* child = parent->getCreateChild (i, wasCreated);
            child->addSequencePositions (_positions [i]);

            //
            // for statistics
            updateStatistics (i, wasCreated);
            
            _positions [i] = new PositionVector;

#           if SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION
               //
               // optimization (?) reserve size in the vector
               // something in the order of the last vector
               int vectorSize = _positions [i]->size ();
               _positions [i]->reserve (vectorSize / _cardinality);
#           endif
         }
      }
   }

   void updateStatistics (int i, bool wasCreated) {
      int vectorSize = _positions [i]->size ();
      int vectorCapacity = _positions [i]->capacity ();
      debug_mustbe (vectorSize <= vectorCapacity);

      _sizeInVectors += vectorSize;
      _spaceLostInVectors += (vectorCapacity - vectorSize);

      _numOfVectors++;
      if (wasCreated)
         _numOfNodes++;
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

static void negativeNodeOptimization (int cardinality,
                                      const SeqWeightFunction& wf,
                                      TreeNodeRep* parent)
{
   //
   // the optimization below works this way:
   // it removes nodes with only negative positions from the tree.
   //
   // WARNING:
   // in order to score seeds correctly, one has to take note of this:
   // any random projection must be 'specialized' - 
   // e.g. it must refer with it's wildcards only to actual positive seeds
   // it has encountered.
   //
   // Example:
   // suppose we have 3 sequnces Pos1, Pos2, Neg (2 positives & 1 negative)
   //    Pos1: 'A'
   //    Pos2: 'C'
   //    Neg:  'G'
   //
   // and we build the tree with the optimization below.
   // further suppose we are searching with a '?' projection.
   // we of course will find only 'A' & 'C' 
   // (because 'G' was thrown out of the tree)
   // now in order to give accurate information about projection scores
   // the projection must be specialized to reflect the fact it knows 
   // very little about negative positions - 
   // the projection should be changed to: 'A or C'
   for (int i=0 ; i < cardinality ; i++) {
      TreeNodeRep* child = parent->getChild (i);
      if (child == NULL) continue;

      if (!child->hasPositions (wf))
         parent->removeChild (i);
   }
}

static void buildTree (PositionsBuilder& builder,
                       bool optimize,
                       const SeqWeightFunction& wf, 
                       const AlphabetCode& code,
                       TreeNodeRep* parent,
                       int currentDepth, 
                       int maxDepth) {
   if (currentDepth >= maxDepth)
      return;
   
   //
   // now we go over all positions, ordered by the sequence they are located in
   PrefixTreePreprocessor::SeqPositionIterator seqIt = 
      parent->positionsBySequence ();

   
   for (; seqIt.hasNext () ; seqIt.next ()) {
      //
      //
      PositionIterator it = seqIt->iterator ();
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
               throwx (AlphabetCode::
		       UnknownCodeError ((*it)->getData (currentDepth)));
            }
            else if (c == AlphabetCode::dunnoCode) {
               //
               // the user does not know which character lies in 
	      // the sequence here.
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
   // perform optimization
   if (optimize) {
      negativeNodeOptimization (code.cardinality (), wf, parent);
   }

   //
   // finished going through all the sequences of the parent
   // now continue to build the tree for all the children
   for (int i=0 ; i < code.cardinality () ; i++) {
      TreeNodeRep* child = parent->getChild (i);
      if (child == NULL) continue;

      buildTree (builder, optimize, wf, code, child, currentDepth+1, maxDepth);
   }
}


static TreeRep* build(bool optimize,
                      const SeqWeightFunction& wf,
                      const SequenceDB& db,
                      const Langauge& langauge,
                      int maxDepth)
{
   time_t start, finish;
   time (&start);

   DLOG << '#' << DLOG.EOL () 
        << "# PrefixTreePreprocessor" << DLOG.EOL ();
   DLOG.flush ();

   const AlphabetCode& code = langauge.code ();
   int cardinality = code.cardinality ();

   AutoPtr <TreeRep> tree (new TreeRep (&db, code, maxDepth));

   int numberOfPositions = 0;
   TreeNodeRep* root = tree->getRoot ();
   SequenceDB::SequenceIterator it = db.sequenceIterator ();
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
         SeqPosition* position = 
            new SeqPosition (seq, i);

         positions->push_back (position);
      }

      root->addSequencePositions (positions);
   }

   //
   // now the root node has all the positions in all sequences.
   // build up the tree until the desired depth 
   PositionsBuilder builder (cardinality);
   buildTree (builder, optimize, wf, code, root, 0, maxDepth);

   time (&finish);
   int totalBytes =  
     numberOfPositions * sizeof (SeqPosition) +
     builder.numOfNodes () * sizeof (TreeNodeRep) +
     cardinality * sizeof (TreeNodeRep*) * 
     builder.numOfNodes () + // child arrays
     builder.numOfVectors () * sizeof (PositionVector) + 
     builder.sizeInVectors () * sizeof (SeqPosition*) + 
     builder.spaceLostInVectors () * sizeof (SeqPosition*);
                     
   DLOG << "PrefixTreePreprocessor created: (" 
	<< (finish - start) << " seconds)" 
	<< DLOG.EOL ()
	<< numberOfPositions << " SeqPosition objects each of " 
	<< sizeof (SeqPosition) << " Bytes." 
	<< DLOG.EOL ()
	<< builder.numOfNodes () << " Node objects each of " 
	<< sizeof (TreeNodeRep) << " Bytes." 
	<< DLOG.EOL ()
	<< builder.numOfVectors () << " PositionVector objects each of " 
	<< sizeof (PositionVector) << " Bytes." 
	<< DLOG.EOL ()
	<< builder.sizeInVectors () << " total positions in PositionVectors" 
	<< DLOG.EOL ()
	<< builder.spaceLostInVectors () 
	<< " positions lost in PositionVectors capacity" 
	<< DLOG.EOL ()
	<< (totalBytes / 1024) << " KBytes approximated tree size." 
	<< DLOG.EOL ()
	<< DLOG.EOL ();

   return tree.release ();
}


TreeRep* PrefixTreePreprocessor::build (bool optimization,
                                        const SeqWeightFunction& wf, 
                                        const SequenceDB& db,
                                        const Langauge& langauge,
                                        int depth)
{
   return ::build (optimization, wf, db, langauge, depth);
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


SeqPositions& SeqPositions::operator = (const SeqPositions& pos)
{
   _positions = pos._positions;
   return *this;
}

PositionIterator SeqPositions::iterator ()
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

CPositionIterator SeqPositions::iterator () const
{
   if (_positions == NULL) {
      //
      // this is necessary, because sometimes an empty SeqPositions is created
      // and an iterator is wanted, such as when a vector of nodes is being
      // searched for all positions in a specific sequence
      // and one of the nodes does not have such a sequence
      return CPositionIterator ();
   }

   return CPositionIterator (_positions->begin (), _positions->end ());
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

const SeqPosition* SeqPositions::firstPosition () const
{
   if (_positions == NULL)
      return NULL;
   else {
      debug_mustbe (!_positions->empty ());
      return ((*_positions) [0]);
   }
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
   // delete all positions (go through all positions in the root and --kill--)
   //
   // turn this off if cleanup is a problem
#  if 1
      if (_owner)
         delete _rep;
#  endif
}


TreeNodeRep* PrefixTreePreprocessor::getRoot () const
{
   return _rep->_root;
}


//
// iterate over all sequences
AutoPtr <SequenceVector>
PrefixTreePreprocessor::getSequences ()  const
{
   //
   // here we have to copy the vector provided by SequenceDB,
   // into a new vector, which contains exactly the same pointers to Sequnces
   return createNewVector <SequenceVector> (
	  _rep->_db->size (),
	  _rep->_db->sequences ().begin (),
	  _rep->_db->sequences ().end ()
	  );
}     

int PrefixTreePreprocessor::maxAssignmentSize () const
{
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
 * TreeNodeRep
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

SeqPositions TreeNodeRep::getSeqPositions (SequenceDB::ID id) const
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



TreeNodeRep::TreeNodeRep (TreeRep* host)
: _depth (0), _host (host)  
{
   setup (NULL);
}


TreeNodeRep::TreeNodeRep (TreeNodeRep* parent)
: _depth (parent->_depth +1), _host (parent->_host) 
{
   setup (parent);
}

TreeNodeRep::~TreeNodeRep () 
{
   dispose (false);
}

void TreeNodeRep::setup (TreeNodeRep* parent)
{
   int cardinality = getCode ().cardinality ();
   _children = new TreeNodeRep* [cardinality];
   for (int i=0 ; i<cardinality ; i++) {
      _children [i] = NULL;
   }
   
#     if SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION
         //
         // optimization (?) we use the size of the parent's _position vector
         // to hint at our _position vector's approximated size
         if (parent)
            _positions.reserve (parent->_positions.size () / cardinality);
#     endif
}


inline void TreeNodeRep::dispose (bool isRoot) 
{
   //
   // free memory of all SeqPositions
   int n = _positions.size ();
   if (n > 0) {
      for (int i=0 ; i<n ; i++) {
         _positions [i].dispose (isRoot);
      }
      _positions.clear ();
   }

   int cardinality = getCode ().cardinality ();
   if (_children) {
      for (int i=0 ; i<cardinality ; i++) {
         if (_children [i]) {
            _host->destroyNode (_children [i]);
            _children [i] = NULL;
         }
      }

      delete [] _children;
      _children = NULL;
   }

}

void TreeNodeRep::addSequencePositions (PositionVector* pos) 
{
   debug_mustbe (pos != NULL);
   debug_mustbe (!pos->empty ());
   _positions.push_back (SeqPositions (pos));
}

int TreeNodeRep::addSequencePositionsFinish () const
{
   return _positions.capacity () - _positions.size ();
}

PrefixTreePreprocessor::CSeqPositionIterator TreeNodeRep::
   positionsBySequence ()  const
{
   return CSeqPositionIterator (_positions.begin (), _positions.end ());
}

PrefixTreePreprocessor::SeqPositionIterator TreeNodeRep::
   positionsBySequence ()  
{
   return SeqPositionIterator (_positions.begin (), _positions.end ());
}

void TreeNodeRep::removeChild (int index)
{
  debug_only (
   int cardinality = getCode().cardinality ();

   debug_mustbe (index >=0);
   debug_mustbe (index < cardinality);
   );

   delete _children [index];
   _children [index] = NULL;
}


TreeNodeRep* TreeNodeRep::getCreateChild (int index, bool&wasCreated) 
{
  debug_only (
   int cardinality = getCode().cardinality ();

   debug_mustbe (index >=0);
   debug_mustbe (index < cardinality);
   );

   wasCreated = false;
   if (_children [index] == NULL) {
      _children [index] = _host->createNode (this);
      wasCreated = true;
   }

   return _children [index];
}


TreeNodeRep* TreeNodeRep::getChild (int index) const
{
  debug_only (
   int cardinality = getCode().cardinality ();

   debug_mustbe (index >=0);
   debug_mustbe (index < cardinality);
   );

   return _children [index];
}

//
// check if node has any positions for a particular sequence
bool TreeNodeRep::hasPositions (SequenceDB::ID id) const
{
   return !getSeqPositions (id).empty ();
}

bool TreeNodeRep::hasPositions (const SeqWeightFunction& wf) const
{
   CSeqPositionIterator it (positionsBySequence ());
   for (; it.hasNext () ; it.next ()) {
      if (wf.isPositive (*it->sequence ()))
         return true;
   }

   return false;
}

//
// returns all the sequences in this node
void TreeNodeRep::add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const
{
   CSeqPositionIterator it (positionsBySequence ());
   for (; it.hasNext () ; it.next ()) {
      outSeqInNode.addSequence (it->sequence ());
   }
}

void TreeNodeRep::add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const
{
   CSeqPositionIterator it (positionsBySequence ());
   for (; it.hasNext () ; it.next ()) {
      outSeqInNode.addSequence (it->sequence ());
      
      CPositionIterator posIt (it->iterator ());
      PosCluster& posCluster = 
         outSeqInNode.getCreatePositions (it->sequence ());
      for (; posIt.hasNext () ; posIt.next ()) {
         posCluster.addPosition (*posIt);
      }
   }
}

void TreeNodeRep::add2PosCluster (PosCluster& posCluster, Sequence::ID id) const
{
   PositionIterator posIt (getSeqPositions (id).iterator ());
   for (; posIt.hasNext () ; posIt.next ()) {
      posCluster.addPosition (*posIt);
   }
}

void TreeNodeRep::add2Assignment (Assignment& outAssg) const
{
   //
   debug_mustbe (!_positions.empty ());
   const SeqPosition* samplePosition = _positions[0].firstPosition ();

   //
   debug_mustbe (samplePosition != NULL);

   //
   Assignment assg (samplePosition->getSeedString (_depth), getCode ());
   outAssg.unify (assg);
}



int TreeNodeRep::getCardinality () const
{
   return getCode().cardinality ();
}


int TreeNodeRep::depth () const
{
   return _depth;
}

//
// ownership belongs to the caller
AutoPtr <PositionVector> 
   TreeNodeRep::getPositions (SequenceDB::ID id) const
{
   const PositionVector* myVector = getSeqPositions (id).positions ();
   return new PositionVector (*myVector);
}

//
// iterate over all positions of a particular sequence in this node
PositionIterator 
PrefixTreePreprocessor::TreeNodeRep::positionIterator (SequenceDB::ID id)
{
   return getSeqPositions (id).iterator ();
}

const AlphabetCode& TreeNodeRep::getCode () const {
  return _host->getCode ();
} 




/*****************************
 * Node
 *****************************/

TreeNode::TreeNode (TreeNodeRep* in) : Node (in), _rep (in) {
}

int PrefixTreePreprocessor::TreeNode::getCardinality ()
{
   return _rep->getCardinality ();
}

TreeNodeRep* PrefixTreePreprocessor::TreeNode::getChild (int index)
{
   return _rep->getChild (index);
}

int PrefixTreePreprocessor::TreeNode::depth ()
{
   return _rep->depth ();
}

//
// iterate over positions for this node
// ordered by their sequence
PrefixTreePreprocessor::SeqPositionIterator 
PrefixTreePreprocessor::TreeNode::positionsBySequence ()
{
   return _rep->positionsBySequence ();
}

//
// ownership belongs to the caller
AutoPtr <PositionVector> PrefixTreePreprocessor::TreeNode::
   getPositions (SequenceDB::ID id)
{
   return _rep->getPositions (id);
}

//
// iterate over all positions of a particular sequence in this node
PositionIterator PrefixTreePreprocessor::TreeNode::
   positionIterator (SequenceDB::ID id)
{
   return _rep->positionIterator (id);
}








/********************
 * NodeCluster
 ********************/

//
//
//

static void rec_addAssignmentNodes (int depth,
                                int desiredDepth,
                                int childIndex,
                                Preprocessor::NodeCluster& nodes,
                                PrefixTreePreprocessor::TreeNodeRep* inNode,
                                const Assignment& assg,
                                Assignment& path)

{
   if (inNode == NULL)
      return;

   const Assignment::Position& thisPosition = assg [depth -1];
   if (thisPosition.strategy () == assg_together) {
      //
      // this means that we got here with 'assg_together' strategy
      // so we keep the exact same positions in the feature
      path.setPosition (depth - 1, thisPosition);
   }
   else {
      debug_mustbe (thisPosition.strategy () == assg_discrete);
      //
      // this means that the exact code of this depth is important
      path.setPosition (depth -1, 
         Assignment::Position (childIndex, assg_discrete)); 
   }

   if (depth == desiredDepth) {
      Preprocessor::AssgNodePair pair(inNode, path);
      nodes.addNode (pair);
      //
      // there is no need to go further down the tree
      // because no new positions can be found further down (this is a prefix tree)
      return;
   }

   PrefixTreePreprocessor::TreeNode node (inNode);
   Assignment::PositionIterator it (assg [depth]);
   for (; it.hasNext () ; it.next ()) {
      int nodeIndex = it.get ();
      rec_addAssignmentNodes (depth+1, 
                              desiredDepth,
                              nodeIndex,
                              nodes, 
                              node.getChild (nodeIndex), 
                              assg,
                              path);
   }
}

void PrefixTreePreprocessor::add2Cluster (NodeCluster& cluster, 
                                          const AssignmentBase& assg)  const
{
   if (assg.length () <= 0)
      return;

   Assignment path;
   TreeNode node (this->getRoot ());
   Assignment::PositionIterator it (assg [0]);
   for (; it.hasNext () ; it.next ()) {
      int nodeIndex = it.get ();
      rec_addAssignmentNodes (1,                         // starting depth
                              assg.length (),            // desired depth
                              nodeIndex,
                              cluster,                     // NodeVector
                              node.getChild (nodeIndex), // starting node
                              assg,                      // the assignment
                              path);
   }
}




