#ifndef _SeedSearcher_ScoreFunction_h
#define _SeedSearcher_ScoreFunction_h

#include "Score.h"
#include "SeqWeight.h"
#include "Cluster.h"
#include "SequenceDB.h"
#include "Assignment.h"
#include "ScoreConcepts.h"

namespace seed {
namespace Scores {

	//
	// an implementatino of the FunctionBase interface

	template <class PositionWeighterT, class PositionCounterT>
	class DiscriminativeFunction : public Function 
	{
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

				const Sequence& seq = db->getSequence (it.id ());
				typename PositionWeighterT::counter_pair seqWeight = _weighter.weigh (seq, *wf);
				int seqCount = _counter.maximumCount (seq, seedLength);
				_posSetWeight += seqCount * seqWeight.first;
				_negSetWeight += seqCount * seqWeight.second;
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
				typename PositionWeighterT::counter_pair counts =
					_counter.count(		feature.length (),
								*(*it),
								containingFeature.getPositions (it),
								*_wf,
								_weighter);
				TP += counts.first;
				FP += counts.second;
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

	//
	// utility for creating a score function
	boost::shared_ptr <Scores::Function> makeFunction (
		CountType countType,
		PositionWeightType scorePartial,
		boost::shared_ptr <SequenceDB>& db,
		boost::shared_ptr <SeqWeightFunction>& wf,
		boost::shared_ptr <Factory>& factory,
		int seedLength);

	//
	// utility for creating a score function
	template <class PositionWeighterT>
	boost::shared_ptr <Scores::Function> makeFunction (
		CountType countType,
		boost::shared_ptr <SequenceDB>& db,
		boost::shared_ptr <SeqWeightFunction>& wf,
		boost::shared_ptr <Factory>& factory,
		int seedLength)
	{
		switch (countType) {
			case _count_gene_:
				return boost::shared_ptr <Scores::Function> (
					new DiscriminativeFunction <
						PositionWeighterT, 
						detail::PositionCounter <_count_gene_>
					> (db, wf, factory, seedLength)
				);
			case _count_total_:
				return Function_ptr (
					new DiscriminativeFunction <
						PositionWeighterT, 
						detail::PositionCounter <_count_total_>
					> (db, wf, factory, seedLength)
				);
		};

		mustfail ();
		return boost::shared_ptr <Scores::Function>  ();
	}

};	// namespace Scores
};	// namespace seed


#endif

