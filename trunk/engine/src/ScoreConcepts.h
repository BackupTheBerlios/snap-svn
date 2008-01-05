#ifndef _SeedSearcher_ScoreConcept_h
#define _SeedSearcher_ScoreConcept_h

#include "Sequence.h"
#include "Cluster.h"
#include <boost/concept_check.hpp>

namespace seed { 
namespace Scores {
namespace detail{
	//
	// forward definitions

	//
	// 
	template <PositionWeightType weightType>
	struct PositionWeighter;

	//
	// 
	template <CountType countType>
	struct PositionCounter;


	template <class PositionWeighterT, class PositionCounterT>
	class Function;

	//
	// we use many specialized versions of the PositionWeighter template
	// this concept defines the requirements from a specialization

	template <class PositionWeighterT>
	struct PositionWeighter_concept {
		void constraints() {
			// must support a counting type
			// which allows adding and multiplying
			typename PositionWeighterT::counter a = typename PositionWeighterT::counter ();
			a += a;
			a = a * a;
			// must support a round method
			int i = _weighter.round (a);
			a = a * i;
			// must be able to weigh a sequence (gene-counts)
			a = _weighter.weigh (*(Sequence*) NULL, *(SeqWeightFunction*) NULL);
		}

		PositionWeighterT _weighter;
	};

	//
	// PositionWeighter specialized definitions

	template <> 
	struct PositionWeighter <_position_weight_discrete_>{
		typedef int counter;
		static inline int round (counter c) { return c; }
		static inline counter weigh (const Sequence& s, const SeqWeightFunction& wf) {
			return wf.isPositive (s.id ())? 1 : 0;
		}
	};

	template <> 
	struct PositionWeighter <_position_weight_real_>{
		typedef double counter;
		static inline int round (counter c) { return ROUND (c); }
		static inline counter weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			return wf.weight (s.id ()); 
		}
	};

	template <> 
	struct PositionWeighter <_position_weight_hotspots_> {
		typedef double counter;
		static inline int round (counter in) {return ROUND (in); }
		static inline counter weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			return wf.weight (s.id ()); 
		}

		//
		// this is an extra function, required only with conjunction
		// with total counts.
		static inline counter weigh (	
								const SeqPosition& p, 
								int seedLength, 
								const SeqWeightFunction& wf) { 
			return wf.weight (p, seedLength);
		}
	};

	struct InverseSigmoidPositionWeighter
	{
		typedef double counter;
		static inline int round (counter c) { return ROUND (c); }
		static inline counter weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			/// y = Sigmoid(x) = 1 / (1 + e^-x)
			/// Inv-Sigmoid(y) = - ln ( [1-y] / y)
			double y = wf.weight (s.id ()); 
			return inverse_sigmoid (y);
		}

		/// sigmoid [-inf, inf] -->> [0, 1]
		/// see http://mathworld.wolfram.com/SigmoidFunction.html
		static inline double sigmoid (double x)
		{
			return 1 / (1 + exp (-x));
		}

		///
		/// the inverse of the sigmoid function
		static inline double inverse_sigmoid (double y)
		{
			mustbe (y>= 0 && y<= 1);
			if (y == double (1))
				return HUGE_VAL;
			else if (y == double (0))
				return -HUGE_VAL;
			else
				return -log ( (1 - y) / y);
		}
	};

	//
	// concept check class for class PositionCounter;

	template <class PositionCounterT, class PositionWeighterT>
	struct PositionCounter_concept {
		void constraints () {
			// must support a maximumCount method
			// that returns the maximum number of positions in a sequence
			int count = _counter.maximumCount (*(Sequence*)NULL, /*seedLength */ 0);
			// must support a count method
			typename PositionWeighterT::counter a;
			_counter.count (	/* _seedLength */ 0,
									*(Sequence*)NULL,
									(PosCluster*)NULL, 
									*(SeqWeightFunction*) NULL,
									*(PositionWeighterT*) NULL,
									a,
									a);
			count++;

		}

		PositionCounterT _counter;
	};


	typedef PositionWeighter <_position_weight_hotspots_> HotspotsPositionWeighter;

	//
	// specialization for gene-counts
	template <>
	struct PositionCounter <_count_gene_> {
		int maximumCount (const Sequence&, int) const { return 1; }

		template <class PositionWeighterT>
		void count(	int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const PositionWeighterT& weight, 
			typename PositionWeighterT::counter& outPositiveCount,
			typename PositionWeighterT::counter& outNegativeCount) const {
			//
			// we return the average weight of a position in this sequence
			outPositiveCount = weight.weigh (seq, wf);
			outNegativeCount = 1 - outPositiveCount;
		}

		//
		// specialization for hotspots
		void count (
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const HotspotsPositionWeighter& weight, 
			HotspotsPositionWeighter::counter& outPositiveCount,
			HotspotsPositionWeighter::counter& outNegativeCount
			) const 
		{
			//
			// hotspots means that different positions in the same sequence
			// might have different weights
			debug_mustbe (cluster);
			debug_mustbe (!cluster->empty ());
			PosCluster::CIterator it = cluster->iterator ();
			HotspotsPositionWeighter::counter bestWeight = 0;
			for (; it.hasNext() ; it.next()) {
				//
				// here we use a special function available only on 
				// _position_weight_hotspots_ Weighter
				HotspotsPositionWeighter::counter posWeight = 
					weight.weigh (*it.get (), seedLength, wf);

				if (posWeight > bestWeight) bestWeight = posWeight;
			}

			outPositiveCount = bestWeight;
			outNegativeCount = 1 - bestWeight;
		}
	};


	//
	// specialization for total-counts
	template <>
	struct PositionCounter <_count_total_> {
		int maximumCount (const Sequence& s, int seedLength) const { 
			return s.length () / seedLength; 
		}

		template <class PositionWeighterT>
		void count(	int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const PositionWeighterT& weight, 
			typename PositionWeighterT::counter& outPositiveCount,
			typename PositionWeighterT::counter& outNegativeCount) const {
			//
			// all individual positions in the same sequence
			// have the same weight
			debug_mustbe (cluster);
			int sizeNoOverlaps = cluster->sizeNoOverlaps(seedLength);
			typename PositionWeighterT::counter seqWeight = weight.weigh (seq, wf);
			outPositiveCount = sizeNoOverlaps * seqWeight;
			outNegativeCount = sizeNoOverlaps * (1 - seqWeight);
		}

		void count (
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const HotspotsPositionWeighter& weight, 
			HotspotsPositionWeighter::counter& outPositiveCount,
			HotspotsPositionWeighter::counter& outNegativeCount
			) const 
		{
			//
			// hotspots means that different positions in the same sequence
			// might have different weights
			outPositiveCount = 0;
			outNegativeCount = 0;
			PosCluster::NoOverlapsIterator it = 
				const_cast <PosCluster&> (*cluster).iteratorNoOverlaps (seedLength);
			for (; it.hasNext() ; it.next()) {
				//
				// here we use a special function available only on 
				// _position_weight_hotspots_ Weighter
				HotspotsPositionWeighter::counter posWeight = 
					weight.weigh (it.get (), seedLength, wf);

				outPositiveCount += posWeight;
				outNegativeCount += 1 - posWeight;
			}
		}
	};

} // namespace detail
} // namespace Scores
} // namespace seed

#endif