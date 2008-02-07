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
			
			// must support a counting_pair type
			// must be able to weigh a sequence (gene-counts)
			typename PositionWeighterT::counter_pair a_pair = 
				_weighter.weigh (_sequence, *_wf);
				
			// the pair must look like an std::pair<counter, counter>
			a = a_pair.first;
			a = a_pair.second;
		}

		PositionWeighterT _weighter;
		SeqWeightFunction* _wf;
		Sequence _sequence;
	};

	//
	// PositionWeighter specialized definitions

	template <> 
	struct PositionWeighter <_position_weight_discrete_>{
		typedef int counter;
		typedef std::pair<counter, counter> counter_pair;
		static inline int round (counter c) { return c; }
		static inline counter_pair weigh (const Sequence& s, const SeqWeightFunction& wf) {
			counter posWeight = wf.isPositive (s.id ())? 1 : 0;
			return counter_pair(posWeight, 1 - posWeight);
		}
	};

	template <> 
	struct PositionWeighter <_position_weight_real_>{
		typedef double counter;
		typedef std::pair<counter, counter> counter_pair;
		static inline int round (counter c) { return ROUND (c); }
		static inline counter_pair weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			counter posWeight = wf.weight (s.id ()); 
			return counter_pair(posWeight, 1 - posWeight);
		}
	};

	template <> 
	struct PositionWeighter <_position_weight_hotspots_> {
		typedef double counter;
		typedef std::pair<counter, counter> counter_pair;
		static inline int round (counter in) {return ROUND (in); }
		static inline counter_pair weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			counter posWeight = wf.weight (s.id ());
			return counter_pair(posWeight, 1 - posWeight);
		}

		//
		// this is an extra function, required only with conjunction
		// with total counts.
		static inline counter_pair weigh (	const SeqPosition& p, 
							int seedLength, 
							const SeqWeightFunction& wf) { 
			counter posWeight = wf.weight (p, seedLength);
			return counter_pair(posWeight, 1 - posWeight);
		}
	};

	struct InverseSigmoidPositionWeighter
	{
		typedef double counter;
		typedef std::pair<counter, counter> counter_pair;
		static inline int round (counter c) { return ROUND (c); }
		static inline counter_pair weigh (const Sequence& s, const SeqWeightFunction& wf) { 
			/// y = Sigmoid(x) = 1 / (1 + e^-x)
			/// Inv-Sigmoid(y) = - ln ( [1-y] / y)
			double y = wf.weight (s.id ()); 
			counter posWeight = inverse_sigmoid (y);
			return counter_pair(posWeight, 1 - posWeight);
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
			int count = _counter.maximumCount (_sequence, _seedLength);
			// must support a count method
			typename PositionWeighterT::counter_pair a_pair =
				_counter.count(	_seedLength,
						_sequence,
						_posCluster, 
						*_wf,
						_weighter);
			count++;

		}

		int _seedLength;
		PositionCounterT _counter;
		Sequence _sequence;
		PosCluster* _posCluster;
		SeqWeightFunction* _wf;
		PositionWeighterT _weighter;
	};


	typedef PositionWeighter <_position_weight_hotspots_> HotspotsPositionWeighter;

	//
	// specialization for gene-counts
	template <>
	struct PositionCounter <_count_gene_> {
		int maximumCount (const Sequence&, int) const { return 1; }

		template <class PositionWeighterT>
		typename PositionWeighterT::counter_pair count(	
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const PositionWeighterT& weight
			) const 
		{
			//
			// we return the average weight of a position in this sequence
			return weight.weigh (seq, wf);
		}

		//
		// specialization for hotspots
		HotspotsPositionWeighter::counter_pair count (
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const HotspotsPositionWeighter& weight
			) const 
		{
			//
			// hotspots means that different positions in the same sequence
			// might have different weights
			debug_mustbe (cluster);
			debug_mustbe (!cluster->empty ());
			PosCluster::CIterator it = cluster->iterator ();
			HotspotsPositionWeighter::counter_pair bestWeight;
			for (; it.hasNext() ; it.next()) {
				//
				// here we use a special function available only on 
				// _position_weight_hotspots_ Weighter
				HotspotsPositionWeighter::counter_pair posWeight = 
					weight.weigh (*it.get (), seedLength, wf);

				// TODO: this doesn't work if you are trying to find a hotspot
				// in a negative sequence
				if (posWeight.first > bestWeight.first) {
					bestWeight = posWeight;
					
				}
			}

			return bestWeight;
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
		typename PositionWeighterT::counter_pair count(	
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const PositionWeighterT& weight) const {
			//
			// all individual positions in the same sequence
			// have the same weight
			debug_mustbe (cluster);
			int sizeNoOverlaps = cluster->sizeNoOverlaps(seedLength);
			typename PositionWeighterT::counter_pair outCounts = weight.weigh (seq, wf);
			outCounts.first *= sizeNoOverlaps;
			outCounts.second *= sizeNoOverlaps;
			return outCounts;
		}

		HotspotsPositionWeighter::counter_pair count (
			int seedLength,
			const Sequence& seq,
			const PosCluster* cluster,
			const SeqWeightFunction& wf,
			const HotspotsPositionWeighter& weight
			) const 
		{
			//
			// hotspots means that different positions in the same sequence
			// might have different weights
			HotspotsPositionWeighter::counter_pair outCounts;
			outCounts.first = 0;
			outCounts.second = 0;
			PosCluster::NoOverlapsIterator it = 
				const_cast <PosCluster&> (*cluster).iteratorNoOverlaps (seedLength);
			for (; it.hasNext() ; it.next()) {
				//
				// here we use a special function available only on 
				// _position_weight_hotspots_ Weighter
				HotspotsPositionWeighter::counter_pair posWeight = 
					weight.weigh (it.get (), seedLength, wf);

				outCounts.first += posWeight.first;
				outCounts.second += posWeight.second;
			}
			
			return outCounts;
		}
	};

} // namespace detail
} // namespace Scores
} // namespace seed

#endif
