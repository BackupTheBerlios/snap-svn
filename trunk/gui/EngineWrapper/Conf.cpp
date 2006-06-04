#include "Conf.h"
#include "Exports.h"
#include "Util.h"

#include "SeedConf.h"
#include "core/ConfReader.h"

SNAP::Engine::Conf^ SNAP::Engine::Conf::LoadFile(System::String^ inFilename) 
{
	Conf^ conf = gcnew Conf ();
	/// read the conf file
	
	StrBuffer buffer;
	const char* args [] = {
		Util::String2StrBuffer (System::Diagnostics::Process::GetCurrentProcess ()->ProcessName , buffer)
	};
	
	::SeedConfList reader (1, args);
	::SeedConf::read (Util::String2StrBuffer (inFilename, buffer), reader);
	for (::SeedConfList::COptionIterator it = reader.const_iterator () ; it.hasNext () ; it.next ())
	{
		Section^ section = gcnew Section (
			gcnew System::String (it.get ()->_name),
			gcnew SNAP::Engine::Parser (it.get ()->_parser)
			);

		conf->Sections->Add (section->Name, section);
	}

	return conf;
}



///
/// Section implementation

SNAP::Engine::Conf::Section::Section (System::String^ name, Parser^ settings)
: _name (name), _settings (settings) 
{
}


System::String^ SNAP::Engine::Conf::Section::Name::get ()
{
	return _name;
}

SNAP::Engine::Parser^ SNAP::Engine::Conf::Section::Settings::get ()
{
	return _settings;
}