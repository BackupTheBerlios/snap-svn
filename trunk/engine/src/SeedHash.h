#ifndef _SeedSearcher_SeedHash_h
#define _SeedSearcher_SeedHash_h

//
// File        : $RCSfile: $
//               $Workfile: SeedHash.h $
// Version     : $Revision: 15 $
//               $Author: Aviad $
//               $Date: 7/09/04 9:39 $
// Description :
//    Concrete and interface classes for a hash-table of positions
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
#include "Cluster.h"
#include "DebugLog.h"

#include "core/HashTable.h"

namespace seed {

//
//
class SeedHash {
public:
   //
   //
   class AssgKey {
      //
      //
   public:
      AssgKey (const Str&, const Langauge&);
      AssgKey (const Assignment&, const Langauge&);
      AssgKey (const AssgKey& o) : _assg (o._assg), _hash (o._hash) {
      }

      HashValue hash () const {
         return _hash;
      }
      const Assignment& assignment () const {
         return _assg;
      }

   private:
      Assignment _assg;
      HashValue _hash;
   };

   //
   //
   template <class UserCluster>
   class Cluster : public HashLinkEntry <UserCluster> {
   public:
      typedef AssgKey Key;

      inline Cluster (const AssgKey& key) : _key (key) {
         debug_mustbe (_key.assignment ().length () > 0);
         _cluster = new SeqCluster;
      }
      inline bool fitsKey (const AssgKey& key) {
         return _key.assignment () == key.assignment ();
      }
	   inline const AssgKey& getKey() const {
		   return _key;
	   }
      const Assignment& assignment () const {
         return _key.assignment ();
      }

      inline static HashValue hash (const AssgKey& inKey) {
         return inKey.hash ();
      }
      bool hasSequence (const SeqWeightFunction& wf) const{
         return _cluster->hasSequence (wf);
      }

      const SeqCluster& getCluster () const {
         return *_cluster;
      }
      SeqCluster* releaseCluster () {
         return _cluster.release ();
      }

   protected:
      AssgKey _key;
      AutoPtr <SeqCluster> _cluster;
   };

   //
   //
   template <class C, class D = BOOST_DEDUCED_TYPENAME HashTable <C>::Deallocator>
   class Table : public HashTable <C, D> {
   public:
      typedef C UserCluster;
      typedef D Deallocator;

      typedef HashTable <UserCluster, Deallocator> HashTableBase;

      Table (int tableSize, const Langauge& langauge)
      : HashTableBase (tableSize), _langauge (langauge)
      {
      }
      virtual ~Table () {
      }

      //
      // increase table size if necessary
      void adjustTableSize (int overloadFactor = 8, int expFactor = 3) {
         // TODO: is this working properly?
         int tableSize = this->getTableSize ();
         int numberOfEntries = this->getSize ();
         if (numberOfEntries > overloadFactor * tableSize)   {
            int newTableSize = (expFactor * numberOfEntries) - 1;
            DLOG << "Increasing table size from "
                 << tableSize << " to "<< newTableSize << DLOG.EOL ();

            this->resize (newTableSize);
         }
      }

   protected:
      const Langauge& _langauge;
   };
};

}


#endif



