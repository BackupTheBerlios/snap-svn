#ifndef _SeedSearcher_SeedHash_h
#define _SeedSearcher_SeedHash_h

#include "Assignment.h"
#include "Cluster.h"
#include "DebugLog.h"

#include "Core/HashTable.h"

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
   template <class UserCluster>
   class Table : public HashTable <UserCluster> {
   public:
      typedef HashTable <UserCluster> HashTableBase;

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
         int tableSize = getTableSize ();
         int numberOfEntries = getSize ();
         if (numberOfEntries > overloadFactor * tableSize)   {
            int newTableSize = (expFactor * numberOfEntries) - 1;
            DLOG << "Increasing table size from " 
                 << tableSize << " to "<< newTableSize << DLOG.EOL ();

            resize (newTableSize);
         }
      }

   protected:
      const Langauge& _langauge;
   };
};


#endif 



