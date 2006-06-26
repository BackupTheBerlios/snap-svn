#ifndef _SeedSearcher_ScoreFunction_h
#define _SeedSearcher_ScoreFunction_h

#include "Score.h"
#include "SeqWeight.h"
#include "Cluster.h"
#include "SequenceDB.h"
#include "Assignment.h"

namespace Scores {

	namespace detail {
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




	//
	// an implementatino of the FunctionBase interface

	template <class PositionWeighterT, class PositionCounterT>
	class DiscriminativeFunction : public Function {
	public:
		DiscriminativeFunction (
			boost::shared_ptr <SequenceDB>& db,
         boost::shared_ptr <SeqWeightFunction>& wf,
			boost::shared_ptr <Factory>& factory,
			int seedLength)
		: _posSetWeight(0), _negSetWeight (0), _db (db), _wf (wf), _factory (factory)
		{
			//
			// calculate the total weight of the positive and negative sets
			SeqWeightFunction::CIterator it (wf->iterator ());
			for (; it.hasNext() ; it.next ()) {
				const Sequence& seq = db->getSequence (it->first);
				typename PositionWeighterT::counter seqWeight = _weighter.weigh (seq, *wf);
				int seqCount = _counter.maximumCount (seq, seedLength);
				_posSetWeight += seqCount * seqWeight;
				_negSetWeight += seqCount * (1 - seqWeight);
			}
		}


		virtual Score_ptr score (  
			const Assignment& feature,
			const Assignment& projection,
			const SeqCluster& containingFeature // k
			) const
		{
			SeqCluster::CIterator it = containingFeature.iterator ();
			typename PositionWeighterT::counter TP = 0;
			typename PositionWeighterT::counter FP = 0;
			for (; it.hasNext() ; it.next()) {
				typename PositionWeighterT::counter posCount;
				typename PositionWeighterT::counter negCount;
				_counter.count(feature.length (),
									**it,
									containingFeature.getPositions (it),
									*_wf,
									_weighter,
									posCount,
									negCount);
				TP += posCount;
				FP += negCount;
			}

			int FN = _weighter.round (_posSetWeight - TP);
			int TN = _weighter.round (_negSetWeight - FP);
			Scores::TFPN tfpn (_weighter.round (TP), TN,_weighter.round (FP), FN);
			return _factory->create(tfpn);
		}

		//
		// define the concept requirements needed by the weighter and counter types
		BOOST_CLASS_REQUIRE(PositionWeighterT, Scores::detail, PositionWeighter_concept);
		BOOST_CLASS_REQUIRE2(PositionCounterT, PositionWeighterT, Scores::detail, PositionCounter_concept);

	private:
		PositionCounterT _counter;
		PositionWeighterT _weighter;
		typename PositionWeighterT::counter _posSetWeight;
		typename PositionWeighterT::counter _negSetWeight;
		boost::shared_ptr <SequenceDB> _db;
		boost::shared_ptr <SeqWeightFunction> _wf;
		boost::shared_ptr <Factory> _factory;
	};
};

#endif

