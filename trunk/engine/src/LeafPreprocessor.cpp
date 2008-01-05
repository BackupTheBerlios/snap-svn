//
// File        : $RCSfile: $ 
//               $Workfile: LeafPreprocessor.cpp $
// Version     : $Revision: 26 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:09 $ 
// Description :
//    Concrete preprocessor class - based on a hash table
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

#include "Assignment.h"
#include "LeafPreprocessor.h"
#include "DebugLog.h"
#include <time.h>

using namespace seed;
USING_TYPE (LeafPreprocessor, LeafNode);
USING_TYPE (LeafPreprocessor, Rep);


struct LeafPreprocessor::Rep : public SeedHash::Table <LeafNode>
{
   //
   typedef LeafNode NodeType;
   typedef SeedHash::Table <NodeType> SuperClass;

   //
   //
   Rep ( int seedLength, int tableSize, const Langauge& langauge)   
   : SuperClass (tableSize, langauge), _seedLength (seedLength)
   {
   }
   ~Rep () {
      clear ();
   }

   virtual NodeType* createCluster (const SeedHash::AssgKey& key) {
      NodeType* temp = new NodeType (key);
      return temp;
   }

   NodeType& addPosition ( const Str& seedData, 
	   AutoPtr <SeqPosition> position) {
      //
      //
		Assignment assg (seedData, _langauge.code());
		/*
		for (int i=0 ; i < _seedLength - seedData.length () ; ++i) {
			AssgPosition emptyPosition;
			assg.addPosition(emptyPosition);
		}*/

      SeedHash::AssgKey key (assg, _langauge);
      NodeType* seed = this->find (key);
      if (seed == NULL) {
         //
         // this is a new seed
         seed = safe_cast (NodeType*, createCluster (key));
         this->add (seed);
      }

      //
      // add this new position to the seed
      seed->addPosition (position.release ());
      return *seed;
   }

   int _seedLength;
};




LeafPreprocessor::LeafPreprocessor (Rep* rep) : _rep (rep) {
}

LeafPreprocessor::~LeafPreprocessor () {
   delete _rep;
}



//
// smallest/largest searchable assignments
int LeafPreprocessor::minAssignmentSize () const
{
   return _rep->_seedLength;
}

int LeafPreprocessor::maxAssignmentSize () const
{
   return _rep->_seedLength;
}

void LeafPreprocessor::add2Cluster (NodeCluster& nodes, 
												const AssignmentBase& inAssg)  const
{
	int assgLength = inAssg.length ();
	debug_mustbe (assgLength <= _rep->_seedLength);

	Assignment assgTemplate (inAssg);
	Rep::Iterator nodeIt (*_rep);
	for (; nodeIt.hasNext () ; nodeIt.next ()) {
		LeafNode* seed = nodeIt.get ();
		if (seed->assignment().length () < assgLength)
			continue;

		const SubAssignment seedAssg (seed->assignment (), 0, assgLength);

		//
		//
		debug_mustbe (seed);
		debug_mustbe (assgLength == seedAssg.length ());

		if (inAssg.contains (seedAssg)) {
			//
			// make the template specific to the assignment of the seed
			for (int i=0 ; i<assgLength ; ++i) {
				debug_mustbe (seedAssg.getPosition (i).strategy () == assg_discrete);


				if (assgTemplate [i].strategy () == assg_discrete)
					assgTemplate.setPosition (i, seedAssg.getPosition (i));
			}

			AssgNodePair pair (seed, assgTemplate);
			nodes.addNode (pair);
			assgTemplate = inAssg;
		}
	}
}

/*
                                     const AssignmentBase& assg)  const
{
   int assgLength = assg.length ();
   Assignment assgTemplate (assg);
   Rep::Iterator nodeIt (*_rep);
   for (; nodeIt.hasNext () ; nodeIt.next ()) {
      LeafNode* seed = nodeIt.get ();
      const Assignment& seedAssg = seed->assignment ();

      //
      //
      debug_mustbe (seed);
      //debug_mustbe (assg.length () == seedAssg.length ());

      if (assg.contains (seed->assignment ())) {
         //
         // make the template specific to the assignment of the seed
         for (int i=0 ; i<assgLength ; ++i) {
	   debug_mustbe (seedAssg.getPosition (i).strategy () == 
			 assg_discrete);

            if (assgTemplate [i].strategy () == assg_discrete)
               assgTemplate.setPosition (i, seedAssg.getPosition (i));
         }

         AssgNodePair pair (seed, assgTemplate);
         nodes.addNode (pair);
      }
   }
}
*/

//
// iterate over all sequences
AutoPtr <SequenceVector> LeafPreprocessor::getSequences () const
{
   //
   // TODO
   return NULL;
}


LeafPreprocessor::Rep* LeafPreprocessor::buildNoNegatives (
                   int seedLength                  ,
                   const SequenceDB& db            , 
                   const Langauge& langauge        ,
                   const SeqWeightFunction& wf     ) 
{
   Rep* rep = build (seedLength, db, langauge);
   int size = rep->getSize ();

   //
   // now we remove all the totally-negative nodes
   struct NegativeNodeRemover : public LeafPreprocessor::Rep::Visitor {
      NegativeNodeRemover (const SeqWeightFunction& wf) : _wf (wf) {
      }
      virtual ~NegativeNodeRemover () {}
      virtual bool call (LeafPreprocessor::Rep::NodeType* inParm) {
         if (!inParm->hasSequence (_wf)) {
            //
            // this is a totally negative node
#           if 0 
               DLOG  << "Removing: " 
                     << Format (inParm->assignment ()) 
                     << DLOG.EOL ();
               DLOG.flush ();
#           endif

				delete inParm;
            return false;
         }

         return true;
      }

      const SeqWeightFunction& _wf;
   };

   time_t start;
   time (&start);

   NegativeNodeRemover nodeRemover (wf);
   rep->visitAll (nodeRemover);
   int newSize = rep->getSize ();

   time_t finish;
   time(&finish);

   DLOG  << "LeafPreprocessor removed " << (size - newSize) << " negative nodes (" 
         << static_cast <int>(finish - start) << " seconds)" << DLOG.EOL ()
         << DLOG.EOL ();
   DLOG.flush ();


   return rep;
}


static int buildReverse (
                     LeafPreprocessor::Rep* rep  ,
                     int seedLength              ,
                     const SequenceDB& db        , 
                     const Langauge& langauge    )
{
   int numberOfPositions = 0;

   //
   //
   SequenceDB::SequenceIterator it = db.sequenceIterator ();
   for (;it.hasNext () ; it.next ()) {
      //
      // get the sequence we are current working on
      Sequence* seq = it.get ();
      debug_mustbe (seq);

      //
      // 
      //
      // stuff every position in this sequence to table
      // even those that don`t have enough lookahead!
      int seqLength = seq->length ();
      // int lastPosition =  seqLength - seedLength;
		int lastPosition =  seqLength - 1;
      numberOfPositions += (lastPosition + 1);

      //
      //
      for (int i=0 ; i<=lastPosition ; i++)   {
         SeqPosition* posPosition = 
            new SeqPosition (seq, i, _strand_pos_);

         SeqPosition* negPosition = 
            new SeqPosition (seq, i, _strand_neg_);
         
         Str data = posPosition->getSeedString (seedLength);
         Str rev_data = negPosition->getSeedString (seedLength);
			
         debug_mustbe (data.length () <= seedLength);
			debug_mustbe (0 < data.length ());
         debug_mustbe (rev_data.length () <= seedLength);
			debug_mustbe (0 < rev_data.length ());

         rep->addPosition (data, posPosition);
         rep->addPosition (rev_data, negPosition);
      }

      rep->adjustTableSize ();
   }

   return numberOfPositions;
}

static int buildNoReverse (
                     LeafPreprocessor::Rep* rep  ,
                     int seedLength              ,
                     const SequenceDB& db        , 
                     const Langauge& langauge    )
{
   int numberOfPositions = 0;

   //
   //
   SequenceDB::SequenceIterator it = db.sequenceIterator ();
   for (;it.hasNext () ; it.next ()) {
      //
      // get the sequence we are current working on
      Sequence* seq = it.get ();
      debug_mustbe (seq);

      //
      // stuff every position in this sequence to table
      // except those that dont have enough lookahead
      int lastPosition = seq->length () - seedLength;
      numberOfPositions += (lastPosition + 1) ;

      //
      //
      for (int i=0 ; i<=lastPosition ; i++)   {
         SeqPosition* position = 
            new SeqPosition (seq, i);

         Str data = position->getSeedString (seedLength);
         debug_mustbe (data.length () == seedLength);
         rep->addPosition (data, position);
      }

      //
      // increase table size if necessary
      rep->adjustTableSize ();
   }

   return numberOfPositions;
}



//
//
LeafPreprocessor::Rep* LeafPreprocessor::build (
                     int seedLength              ,
                     const SequenceDB& db        , 
                     const Langauge& langauge    ) 
{
   time_t start, finish;
   time (&start);

   DLOG << '#' << DLOG.EOL () 
        << "# LeafPreprocessor" << DLOG.EOL ();
   DLOG.flush ();

   const int TABLE_SIZE = 1024 * 1024 - 1;
   //
   // TODO: guess an estimate to the number of seeds
   Rep* rep = new Rep (seedLength, TABLE_SIZE, langauge);

   int numberOfPositions = langauge.supportComplement ()?
      buildReverse (rep, seedLength, db, langauge) :
      buildNoReverse (rep, seedLength, db, langauge);

   time (&finish);
   const int totalBytes =  numberOfPositions * sizeof (SeqPosition) + 
                           rep->getSize () * sizeof (LeafNode);

	DLOG	<< "LeafPreprocessor (Depth == " 
			<< seedLength
			<< ") created: (" << static_cast <int> (finish - start) 
			<< " seconds)" << DLOG.EOL ()
			<< numberOfPositions << " SeqPosition objects each of " 
			<< sizeof (SeqPosition) << " Bytes." << DLOG.EOL ()
			<< rep->getSize () << " Node objects each of " 
			<< sizeof (LeafNode) << " Bytes." << DLOG.EOL ()
			<< (totalBytes / 1024) 
			<< " KBytes (loose) lower bound to preprocessor size." << DLOG.EOL ()
			<< DLOG.EOL ();
   DLOG.flush ();

   return rep;
}


//
// LeafNode
//


//
// check if node has any positions for a particular sequence
bool LeafPreprocessor::LeafNode::hasPositions (SequenceDB::ID id) const
{
   return _cluster->hasPositions (id);
}


bool 
   LeafPreprocessor::LeafNode::
      hasPositions (const SeqWeightFunction& wf) const
{
   //
   // TODO
   mustfail ();
   return false;
}

//
// returns all the sequences in this node

void LeafPreprocessor::LeafNode::
      add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const
{
   outSeqInNode.unify (*_cluster);
}


void LeafPreprocessor::LeafNode ::
      add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const
{
   outSeqInNode.unifyPositions (*_cluster);
}


void LeafPreprocessor::LeafNode::
      add2PosCluster (PosCluster& out, Sequence::ID id)  const
{
   const PosCluster* pos = _cluster->getPositions (id);
   if (pos) {
      out.unify (*pos);
   }

}


void LeafPreprocessor::LeafNode::
      add2Assignment (Assignment& assg) const
{
   assg.unify (assignment ());
}



