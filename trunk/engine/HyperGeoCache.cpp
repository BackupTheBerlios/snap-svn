#include "HyperGeoCache.h"

#include "Core/HashTable.h"

struct HyperGeoCache::XK {
   inline XK (int x, int k) : _x (x), _k (k) {
   }
   inline XK (const XK& o) : _x (o._x), _k (o._k) {
   }
   inline bool operator == (const XK& o) {
      return (_x == o._x) && (_k == o._k);
   }

   int _x;
   int _k;
};

class HyperGeoCache::Score : public HashLinkEntry <Score> {
public:
   typedef HyperGeoCache::XK Key;
   
   inline Score (const XK& xk, double score) : _xk (xk), _score (score) {
   }
   inline bool fitsKey (const Key& key) {
      return (_xk == key);
   }
	inline const Key& getKey() const {
		return _xk;
	}
	inline static HashValue hash (const Key& inKey) {
      //
      // TODO: is this good???
		return defaultHashFunction(inKey._x) * defaultHashFunction(inKey._k);
	}
   inline double score () const {
      return _score;
   }

private:
   XK _xk;
   double _score;
};

typedef HashTable <HyperGeoCache::Score> CacheBase;

struct HyperGeoCache::Cache : public  CacheBase{
   Cache (int m, int n) : CacheBase (8 * 256), _m(m), _n(n) {
   }

   int _m;
   int _n;
};

HyperGeoCache::HyperGeoCache (int n, int m) {
   debug_mustbe (m>=0);
   debug_mustbe (n>=0);
   debug_mustbe (n<=m);

   _cache = new Cache (m, n);
}


double HyperGeoCache::logTail (int x, int k)
{
   XK xk (x, k);
   Score* cachedScore = _cache->find (XK (x, k));
   if (cachedScore == NULL) {
      //
      // TODO: compute actual value
      double score = 
         HyperGeometric::logTailhyge (x, _cache->_m, k, _cache->_n);

      cachedScore = new Score (xk, score); 
      _cache->add (cachedScore);
   }
   
   return cachedScore->score ();
}
