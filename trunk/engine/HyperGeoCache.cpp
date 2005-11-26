//
// File        : $RCSfile: $ 
//               $Workfile: HyperGeoCache.cpp $
// Version     : $Revision: 17 $ 
//               $Author: Aviad $
//               $Date: 18/10/04 7:48 $ 
// Description :
//    Concrete cache for Hyper-Geometric distribution values
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
#include "HyperGeoCache.h"
#include "core/HashTable.h"
#include "persistance/TextWriter.h"

//
//
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


static const unsigned long L_PI = (unsigned long) 314159265;
static const unsigned long L_E = (unsigned long) 271828183;


//
//
class HyperGeoCache::Score : public ScoreParameters, 
                             public HashLinkEntry <Score> 
{
public:
   virtual ~Score () {
   }
   virtual void dispose () {
      //
      // memory is managed by the enclosing HyperGeoCache instance
   }

   typedef HyperGeoCache::XK Key;
   
   inline Score (const XK& xk, double score) 
      : _xk (xk), _score (score) {
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
		return defaultHashFunction(inKey._k) * L_PI 
           + defaultHashFunction(inKey._x) * L_E;
	}
   inline double score () const {
      return _score;
   }

private:
   XK _xk;
   double _score;
};


//
//
typedef HashTable <HyperGeoCache::Score> CacheBase;


//
//
struct HyperGeoCache::Cache : public  CacheBase {
   Cache (int m, int n) : CacheBase (8 * 1024 - 7), _m(m), _n(n) {
   }

   int _m;
   int _n;
};




//
//
//


HyperGeoCache::HyperGeoCache (int n, int m) {
   debug_mustbe (m>=0);
   debug_mustbe (n>=0);
   debug_mustbe (n<=m);

   _cache = new Cache (m, n);
}

HyperGeoCache::~HyperGeoCache ()
{
   delete _cache;
}


double HyperGeoCache::log2Tail (int x, int k, ScoreParameters** params)
{
   XK xk (x, k);
   Score* cachedScore = _cache->find (xk);
   if (cachedScore == NULL) {
      //
      // 
      double score = 
         HyperGeometric::logTailhyge (x, _cache->_m, k, _cache->_n);

      //
      // change from ln to 2-base log
      static const double LN_2 = ::log (static_cast <double> (2));
      double log2score = score / LN_2;

      cachedScore = new Score (xk, log2score); 
      _cache->add (cachedScore);
   }
   if (params != NULL)
      *params = cachedScore;
   
   return cachedScore->score ();
}

double HyperGeoCache::log2Tail (int x, int k)
{
   return log2Tail (x, k, NULL);
}

void HyperGeoCache::writeAsText (
            Persistance::TextWriter& writer, 
            const ScoreParameters* p) const
{
   debug_mustbe (p);

   const Score* cachedScore;
#  if BASE_DEBUG
      cachedScore = dynamic_cast <const Score*> (p);
#  else
      //
      // dont waste time on dynamic cast
      cachedScore = reinterpret_cast <const Score*> (p);
#  endif
   debug_mustbe (cachedScore);


   writer << "X="  << cachedScore->getKey ()._x
          << ", K="<< cachedScore->getKey ()._k
          << ", N="<< _cache->_n
          << ", M="<< _cache->_m;
}




//
//
//



//
//
struct HyperGeoTotalCache::XKNM {
   inline XKNM (int x, int k, int n, int m) : _x (x), _k (k), _n (n), _m(m) {
   }
   inline XKNM (const XKNM& o) : _x (o._x), _k (o._k), _n (o._n), _m(o._m) {
   }
   inline bool operator == (const XKNM& o) {
      return (_x == o._x) && (_k == o._k) && (_n == o._n) && (_m == o._m);
   }

   int _x;
   int _k;
   int _n;
   int _m;
};


//
//
class HyperGeoTotalCache::Score :   public ScoreParameters,
                                    public HashLinkEntry <Score> 
{
public:
   virtual ~Score () {
   }
   virtual void dispose () {
      //
      // memory is managed by the enclosing HyperGeoTotalCache instance
   }

   typedef HyperGeoTotalCache::XKNM Key;
   
   inline Score (const XKNM& xknm, double score) 
      :  _xknm (xknm), _score (score) {
   }
   inline bool fitsKey (const Key& key) {
      return (_xknm == key);
   }
	inline const Key& getKey() const {
		return _xknm;
	}
	inline static HashValue hash (const Key& inKey) {
      //
      // TODO: is this good???
		return defaultHashFunction( (3*inKey._x) * 
                                  (7*inKey._k) * 
                                  (11*inKey._n) * 
                                  (17*inKey._m));
	}
   inline double score () const {
      return _score;
   }

private:
   XKNM _xknm;
   double _score;
};


//
//
typedef HashTable <HyperGeoTotalCache::Score> TotalCacheBase;


//
//
struct HyperGeoTotalCache::Cache : public  TotalCacheBase {
   Cache () : TotalCacheBase (16 * 256 - 7)
   {
   }
};


//
//
//


HyperGeoTotalCache::HyperGeoTotalCache () 
{
   _cache = new Cache ();
}

HyperGeoTotalCache::~HyperGeoTotalCache ()
{
   delete _cache;
}


double HyperGeoTotalCache::log2Tail (int x, int k, int n, int m, 
                                    ScoreParameters** p)
{
   XKNM xknm (x, k, n, m);
   Score* cachedScore = _cache->find (xknm);
   if (cachedScore == NULL) {
      //
      // 
      double score = 
         HyperGeometric::logTailhyge (x, m, k, n);

      //
      // change from ln to 2-base log
      static const double LN_2 = ::log (static_cast <double> (2));
      double log2score = score / LN_2;

      cachedScore = new Score (xknm, log2score); 
      _cache->add (cachedScore);
   }

   if (p != NULL)
      *p = cachedScore;
   
   return cachedScore->score ();
}

double HyperGeoTotalCache::log2Tail (int x, int k, int n, int m)
{
   return log2Tail (x, k, n, m, NULL);
}

void HyperGeoTotalCache::writeAsText (
               Persistance::TextWriter& writer, 
               const ScoreParameters* p) const
{
   debug_mustbe (p);

   const Score* cachedScore;
#  if BASE_DEBUG
      cachedScore = dynamic_cast <const Score*> (p);
#  else
      //
      // dont waste time on dynamic cast
      cachedScore = reinterpret_cast <const Score*> (p);
#  endif
   debug_mustbe (cachedScore);


   writer << "X = "  << cachedScore->getKey ()._x
          << ", K = "<< cachedScore->getKey ()._k
          << ", N = "<< cachedScore->getKey ()._n
          << ", M = "<< cachedScore->getKey ()._m;
}



boost::shared_ptr <HyperGeoTotalCache> _totalCache;
boost::shared_ptr <HyperGeoTotalCache> singleton ()
{
   if (!_totalCache) {
      _totalCache.reset (new HyperGeoTotalCache);
   }

   return _totalCache;
}








