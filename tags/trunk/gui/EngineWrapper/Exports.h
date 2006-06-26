#include "core/GetOptParser.h"

class Parser;

namespace SNAP {
	namespace Engine {


		public ref class Setup {
		public:
			static property System::String^ ProgramName {
				System::String^ get () {
					return _programName;
				}
				void set (System::String^);
			}

		private:
			static System::String^ _programName;
		};


		//
		//
		public enum class PrepType {
			_prep_leaf_,
			_prep_tree_
		};

		public enum class SearchType {
			_search_default_ = - 1,
			_search_table_ = PrepType::_prep_leaf_,
			_search_tree_ = PrepType::_prep_tree_ // works only with _prep_tree_ 
		};

		//
		//
		public enum class CountType {
			_count_total_,
			_count_gene_
		};

		public enum class ScoreType {
			_score_hypegeo_,
			_score_exp_

		};

		public enum class Strand {
			_strand_pos_= true,
			_strand_neg_ = false,
		};

		public enum class PositionWeightType {
			// {0, 1} counts per sequence
			_position_weight_discrete_,   
			// [0, 1] counts per sequence
			_position_weight_real_,       
			// [0, 1] counts, with possible different weights 
			// for different positions in the same sequence
			_position_weight_hotspots_,   
		};

		public enum class StatFixType {
			_statfix_none_,
			_statfix_bonf_,// use Bonferroni statistical fix
			_statfix_fdr_	// use FDR statistical fix
		};

		public enum class OutputType {
			_out_all_,
			_out_pos_,
			_out_none_,
		};

		public ref class SettingType {
		private:
			const GetOptParser::OptionBase* _setting;

		public:
			SettingType (const GetOptParser::OptionBase* setting) : _setting (setting)
			{
			}

			property System::String^ Name{
				System::String^ get () {
					return gcnew System::String (_setting->name ());
				}
			}

			property System::String^ DisplayName{
				System::String^ get () {
					// TODO: add support for display name in GetOptParser::OptionBase
					return gcnew System::String (_setting->name ());
				}
			}

			property System::String^ Help {
				System::String^ get () {
					return gcnew System::String (_setting->desc ());
				}
			}
		};

		template <typename TType>
		public ref class SettingValue : SettingType {
		public:
			property TType DefaultValue {
				TType get () {
					return _defaultValue;
				}
				void set (TType in) {
					_defaultValue = in;
				}
			}

			property TType Value
			{
				TType get () {
					return _value;
				}
				void set (TType in) {
					_value = in;
				}
			}

		private:
			TType _defaultValue;
			TType _value;
		};


		public ref class Settings
		{
		private:
			::Parser* _parser;

		public:
			Settings ();
			Settings (const ::Parser&);
			Settings (array <System::String^>^ argv);
			virtual ~Settings ();

			//
			// exhaustive projections
			/*
			property SettingValue <bool>^ __proj_e {
				SettingValue <bool>^ get ();
				//void set (bool);
			}
			*/
			property bool __proj_e {
				bool get ();
				void set (bool);
			}
			//
			// number of projections
			property int __proj_n {
				int get ();
				void set (int);
			}

			//
			// no. of wildcards in projection
			property int __proj_d{
				int get ();
				void set (int);
			}
			//
			// how long is midsection (which is only wildcards)
			property int __proj_mid{
				int get ();
				void set (int);
			}
			//
			// specialize projection 
			// (expert optimization, may lead to incorrect results)
			property bool __proj_spec{
				bool get ();
				void set (bool);
			}
			//
			// seed for random projections 
			property int __proj_i{
				int get ();
				void set (int);
			}
			//
			// ask for a specific projection (not random)
			property System::String^ __proj_base{
				System::String^ get ();
				void set (System::String^);
			}

			//
			// allow outer wildcards in projection (in the first and last positions)
			property bool __proj_outer
			{
				bool get ();
				void set (bool);
			}
			//
			// no of seeds to output
			property int __seed_n
			{
				int get ();
				void set (int);
			}
			//
			// length of the seed to search for
			property int __seed_l
			{
				int get ();
				void set (int);
			}
			//
			// offset for checking seed redundancy
			property int __seed_r
			{
				int get ();
				void set (int);
			}
			//
			// flag for checking reverse redundancy
			property bool __seed_rr
			{
				bool get();
				void set (bool);
			}
			//
			// length of seed to output (PSSM length)
			property int __seed_o
			{
				int get ();
				void set (int);
			}
			//
			// type of preprocessor
			property PrepType __prep
			{
				PrepType get ();
				void set (PrepType);
			}

			//
			// remove totally negative features
			// (expert feature, may lead to incorrect results)
			property bool __prep_noneg
			{
				bool get ();
				void set (bool);
			}
			//
			// how deep/long should preprocessed k-mers be
			property int __prep_l
			{
				int get ();
				void set (int);
			}
			//
			// type of counting mechanism: gene-count / total count
			property CountType __count
			{
				CountType get ();
				void set (CountType);
			}
			//
			//
			property bool __count_reverse
			{
				bool get ();
				void set (bool);
			}

			property StatFixType __statfix_t
			{
				StatFixType get ();
				void set (StatFixType);
			}

			//
			// worst score to allow
			property double __minusLog10score_min {
				double get ();
				void set (double);
			}

			//
			// minimal number to positive sequences for a seed
			property int __score_min_seq
			{
				int get ();
				void set (int);
			}
			//
			// minimal percent of positive sequences for a seed
			property int __score_min_seq_per
			{
				int get ();
				void set(int);
			}
			//
			// score using partial counts (weights) or assg_discrete counts
			property PositionWeightType __score_partial {
				PositionWeightType get ();
				void set (PositionWeightType);
			}
			//
			// threshold for counting a sequence as positive
			property float __weight_t
			{
				float get ();
				void set (float);
			}

			//
			// which type of search to perform: tree search or table search
			// note: tree search only works with tree preprocessor
			property SearchType __searchType
			{
				SearchType get ();
				void set (SearchType);

			}
			property ScoreType __scoreType
			{
				ScoreType get ();
				void set (ScoreType);
			}

			//
			// values for exponential loss score
			property float __expLossPos
			{
				float get ();
				void set(float);
			}
			property float __expLossNeg
			{
				float get ();
				void set (float);
			}

			//
			// flag that determines if PSSM files should be created
			property OutputType __generatePSSM
			{
				OutputType get ();
				void set (OutputType);
			}
			//
			// flag that determines if .Motif files should be created
			property OutputType __generateMotif			{
				OutputType get ();
				void set (OutputType);
			}
			//
			// flag that determines if .sample file should be created
			property OutputType __generateBayesian			{
				OutputType get ();
				void set (OutputType);
			}
			//
			// flag that determines if seeds should be outputed to the log
			property OutputType __generateSeedlog			{
				OutputType get ();
				void set (OutputType);
			}

			//
			//
			//property __conf;

			//
			//
			//int __firstFileArg;
		
			bool IsOverriden (System::String^ settingName)
			{
				return false;
			}
		};

	}
}
