#ifndef _SeedSearcher_SeedHash_h
#define _SeedSearcher_SeedHash_h

#include "Assignment.h"
#include "Cluster.h"

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
      AssgKey (const Str&, const AlphabetCode&, AssignmentWriter&);
      AssgKey (const Assignment&, AssignmentWriter&);
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
   class Cluster : public HashLinkEntry <Cluster> {
   public:
      typedef AssgKey Key;

      inline Cluster (const AssgKey& key) : _key (key) {
         debug_mustbe (_key.assignment ().length () > 0);
      }
      virtual ~Cluster () {
         //
         // TODO: we are owners of the positions, remove them all
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
      
      void addPosition (AutoPtr <Position> pos) {
         PosCluster& posCluster = 
            _cluster.getCreatePositions (pos->sequence ());

         bool result = posCluster.addPosition (pos.release ());
         debug_mustbe (result);
      }

      const SeqCluster& getCluster () const {
         return _cluster;
      }

   protected:
      AssgKey _key;
      SeqCluster _cluster;
   };

   //
   //
   typedef HashTable <Cluster> TableBase;
   class Table : public TableBase {
   public:
      Table (int tableSize, const AlphabetCode&, AssignmentWriter&);
      ~Table ();

      void addPosition (const Str& seedData, AutoPtr <Position> position);
      virtual Cluster* createCluster (const AssgKey& key) {
         return new Cluster (key);
      }

   protected:
      const AlphabetCode& _code;
      AssignmentWriter& _assgWriter;
   };
};



#endif 