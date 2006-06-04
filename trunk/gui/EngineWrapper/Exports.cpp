#include "Exports.h"
#include "Util.h"

#include "Parser.h"
#include "DebugLog.h"

static bool setupHasCompleted = false;

void SNAP::Engine::Setup::ProgramName::set (System::String^ name)			
{
	if (!setupHasCompleted) {
		::SeedSearcherLog::setupConsoleLogging (true);
		DLOG << "miew" << DLOG.EOL ();
		DLOG.flush ();
		setupHasCompleted = true;
	}

	SNAP::Engine::Setup::_programName = name;
}


SNAP::Engine::Parser::Parser ()
{
	this->_parser = new ::Parser ();
}

SNAP::Engine::Parser::Parser (const ::Parser& parser)
{
	this->_parser = new ::Parser (parser);
}

SNAP::Engine::Parser::Parser (array <System::String^>^ argv)
{
	StrBuffer finalBuffer, buffer;
	for (int i=0 ; i<argv->Length ; ++i) {
		Util::String2StrBuffer (argv[i], buffer); 
		finalBuffer.append (' ');
		finalBuffer.append (buffer);
	}
	
	/// get current process name into buffer
	Util::String2StrBuffer (System::Diagnostics::Process::GetCurrentProcess ()->ProcessName , buffer); 

	::Argv cpp_args (buffer, finalBuffer);
	this->_parser = new ::Parser (cpp_args);
}

SNAP::Engine::Parser::~Parser ()
{
	delete _parser;
	_parser = NULL;
}





bool SNAP::Engine::Parser::__proj_e::get ()
{
	return _parser->__proj_e;
}

void SNAP::Engine::Parser::__proj_e::set (bool in)
{
	_parser->__proj_e = in;
}

int SNAP::Engine::Parser::__proj_n::get ()
{
	return _parser->__proj_n;
}

void SNAP::Engine::Parser::__proj_n::set (int in)
{
	_parser->__proj_n = in;
}

int SNAP::Engine::Parser::__proj_d::get ()
{
	return _parser->__proj_d;
}
void SNAP::Engine::Parser::__proj_d::set (int in)
{
	_parser->__proj_d = in;
}


int SNAP::Engine::Parser::__proj_mid::get ()
{
	return _parser->__proj_mid;
}
void SNAP::Engine::Parser::__proj_mid::set (int in)
{
	_parser->__proj_mid = in;
}


bool SNAP::Engine::Parser::__proj_spec::get ()
{
	return _parser->__proj_spec;
}
void SNAP::Engine::Parser::__proj_spec::set (bool in)
{
	_parser->__proj_spec = in;
}

int SNAP::Engine::Parser::__proj_i::get ()
{
	return _parser->__proj_i;
}

void SNAP::Engine::Parser::__proj_i::set (int in)
{
	_parser->__proj_i = in;
}

System::String^ SNAP::Engine::Parser::__proj_base::get ()
{
	return gcnew System::String (_parser->__proj_base);
}

void SNAP::Engine::Parser::__proj_base::set (System::String^ in)
{
	Util::String2StrBuffer (in, _parser->__proj_base);
}


bool SNAP::Engine::Parser::__proj_outer::get ()
{
	return _parser->__proj_outer;
}

void SNAP::Engine::Parser::__proj_outer::set (bool in)
{
	_parser->__proj_outer = in;
}

int SNAP::Engine::Parser::__seed_n::get ()
{
	return _parser->__seed_n;
}

void SNAP::Engine::Parser::__seed_n::set (int in)
{
	_parser->__seed_n = in;
}

int SNAP::Engine::Parser::__seed_l::get ()
{
	return _parser->__seed_l;
}

void SNAP::Engine::Parser::__seed_l::set (int in)
{
	_parser->__seed_l = in;
}

int SNAP::Engine::Parser::__seed_r::get ()
{
	return _parser->__seed_r;
}

void SNAP::Engine::Parser::__seed_r::set (int in)
{
	_parser->__seed_r = in;
}

bool SNAP::Engine::Parser::__seed_rr::get ()
{
	return _parser->__seed_rr;
}

void SNAP::Engine::Parser::__seed_rr::set (bool in)
{
	_parser->__seed_rr = in;
}

int SNAP::Engine::Parser::__seed_o::get ()
{
	return _parser->__seed_o;
}

void SNAP::Engine::Parser::__seed_o::set (int in)
{
	_parser->__seed_o = in;
}


SNAP::Engine::PrepType SNAP::Engine::Parser::__prep::get ()
{
	return SNAP::Engine::PrepType (_parser->__prep);
}

void SNAP::Engine::Parser::__prep::set (SNAP::Engine::PrepType in)
{
	_parser->__prep = static_cast <::PrepType> (safe_cast<int> (in));
}

bool SNAP::Engine::Parser::__prep_noneg::get ()
{
	return _parser->__prep_noneg;
}

void SNAP::Engine::Parser::__prep_noneg::set (bool in)
{
	_parser->__prep_noneg = in;
}

int SNAP::Engine::Parser::__prep_l::get ()
{
	return _parser->__prep_l;
}

void SNAP::Engine::Parser::__prep_l::set (int in)
{
	_parser->__prep_l = in;
}

SNAP::Engine::CountType SNAP::Engine::Parser::__count::get ()
{
	return SNAP::Engine::CountType (_parser->__count);
}

void SNAP::Engine::Parser::__count::set (SNAP::Engine::CountType in)
{
	_parser->__count = static_cast <::CountType> (safe_cast<int> (in));
}


bool SNAP::Engine::Parser::__count_reverse::get ()
{
	return _parser->__count_reverse;
}

void SNAP::Engine::Parser::__count_reverse::set (bool in)
{
	_parser->__count_reverse = in;
}


SNAP::Engine::StatFixType SNAP::Engine::Parser::__statfix_t::get ()
{
	return SNAP::Engine::StatFixType (_parser->__statfix_t);
}

void SNAP::Engine::Parser::__statfix_t::set (SNAP::Engine::StatFixType in)
{
	_parser->__statfix_t = static_cast <::StatFixType> (safe_cast<int> (in));
}

double SNAP::Engine::Parser::__minusLog10score_min::get ()
{
	return _parser->__minusLog10score_min;
}

void SNAP::Engine::Parser::__minusLog10score_min::set (double in)
{
	_parser->__minusLog10score_min = in;
}


int SNAP::Engine::Parser::__score_min_seq::get ()
{
	return _parser->__score_min_seq;
}

void SNAP::Engine::Parser::__score_min_seq::set (int in)
{
	_parser->__score_min_seq = in;
}

int SNAP::Engine::Parser::__score_min_seq_per::get ()
{
	return _parser->__score_min_seq_per;
}

void SNAP::Engine::Parser::__score_min_seq_per::set (int in)
{
	_parser->__score_min_seq_per = in;
}



SNAP::Engine::PositionWeightType SNAP::Engine::Parser::__score_partial::get ()
{
	return SNAP::Engine::PositionWeightType (_parser->__score_partial);
}

void SNAP::Engine::Parser::__score_partial::set (SNAP::Engine::PositionWeightType in)
{
	_parser->__score_partial = static_cast <::PositionWeightType> (safe_cast<int> (in));
}



float SNAP::Engine::Parser::__weight_t::get ()
{
	return _parser->__weight_t;
}

void SNAP::Engine::Parser::__weight_t::set (float in)
{
	_parser->__weight_t = in;
}




SNAP::Engine::SearchType SNAP::Engine::Parser::__searchType::get ()
{
	return SNAP::Engine::SearchType (_parser->__searchType);
}

void SNAP::Engine::Parser::__searchType::set (SNAP::Engine::SearchType in)
{
	_parser->__searchType = static_cast <::SearchType> (safe_cast<int> (in));
}


SNAP::Engine::ScoreType SNAP::Engine::Parser::__scoreType::get ()
{
	return SNAP::Engine::ScoreType (_parser->__scoreType);
}

void SNAP::Engine::Parser::__scoreType::set (SNAP::Engine::ScoreType in)
{
	_parser->__scoreType = static_cast <::ScoreType> (safe_cast<int> (in));
}


float SNAP::Engine::Parser::__expLossPos::get ()
{
	return _parser->__expLossPos;
}

void SNAP::Engine::Parser::__expLossPos::set (float in)
{
	_parser->__expLossPos = in;
}



float SNAP::Engine::Parser::__expLossNeg::get ()
{
	return _parser->__expLossNeg;
}

void SNAP::Engine::Parser::__expLossNeg::set (float in)
{
	_parser->__expLossNeg = in;
}




SNAP::Engine::OutputType SNAP::Engine::Parser::__generatePSSM::get ()
{
	return SNAP::Engine::OutputType (_parser->__generatePSSM);
}

void SNAP::Engine::Parser::__generatePSSM::set (SNAP::Engine::OutputType in)
{
	_parser->__generatePSSM = static_cast <::Parser::OutputType> (safe_cast<int> (in));
}


SNAP::Engine::OutputType SNAP::Engine::Parser::__generateMotif::get ()
{
	return SNAP::Engine::OutputType (_parser->__generateMotif);
}

void SNAP::Engine::Parser::__generateMotif::set (SNAP::Engine::OutputType in)
{
	_parser->__generateMotif = static_cast <::Parser::OutputType> (safe_cast<int> (in));
}


SNAP::Engine::OutputType SNAP::Engine::Parser::__generateBayesian::get ()
{
	return SNAP::Engine::OutputType (_parser->__generateBayesian);
}

void SNAP::Engine::Parser::__generateBayesian::set (SNAP::Engine::OutputType in)
{
	_parser->__generateBayesian = static_cast <::Parser::OutputType> (safe_cast<int> (in));
}


SNAP::Engine::OutputType SNAP::Engine::Parser::__generateSeedlog::get ()
{
	return SNAP::Engine::OutputType (_parser->__generateSeedlog);
}

void SNAP::Engine::Parser::__generateSeedlog::set (SNAP::Engine::OutputType in)
{
	_parser->__generateSeedlog = static_cast <::Parser::OutputType> (safe_cast<int> (in));
}
