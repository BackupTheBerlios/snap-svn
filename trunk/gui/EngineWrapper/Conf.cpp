#include "Conf.h"
#include "Exports.h"
#include "Util.h"

#include "SeedConf.h"
#include "core/ConfReader.h"

static SNAP::Engine::Conf::Section^ newSection (const ::SeedConfList::Options& options)
{
	return gcnew SNAP::Engine::Conf::Section (
		gcnew System::String (options._name), 
		gcnew System::String (options._parameters), 
		gcnew SNAP::Engine::Settings (options._parser));
}

SNAP::Engine::Conf::Conf ()
{
	_sections = gcnew SectionList ();
}
/*
SNAP::Engine::Conf::Conf (SNAP::Engine::Conf::ISectionList^ list)
{
	
	/// clone the list
	cli::array <System::Type^>^ typeArray = gcnew cli::array <System::Type^> (1);
	typeArray [0] = list->GetType ();
	System::Reflection::ConstructorInfo^ copyCtrInfo = list->GetType ()->GetConstructor (typeArray);
	
	cli::array <System::Object^>^ paramsArray = gcnew cli::array <System::Object^> (1);
	paramsArray [0] = list;
	_sections = (ISectionList^) copyCtrInfo->Invoke(paramsArray);
}
*/
/*
SNAP::Engine::Conf^ SNAP::Engine::Conf::LoadFile(System::String^ inFilename) 
{
	return LoadFile (nullptr, inFilename);
}
*/

SNAP::Engine::Conf^ SNAP::Engine::Conf::LoadFile(
//	SNAP::Engine::Conf::ISectionList^ list,
	System::String^ inFilename) 
{
	//Conf^ conf = (list == nullptr)? gcnew Conf () : gcnew Conf (list);
	Conf^ conf = gcnew Conf ();
	/// read the conf file

	StrBuffer buffer;
	const char* args [] = {
		Util::String2StrBuffer (System::Diagnostics::Process::GetCurrentProcess ()->ProcessName , buffer)
	};
	
	::SeedConfList reader (1, args);
	::SeedConf::read (Util::String2StrBuffer (inFilename, buffer), reader);

	/// read the init section, and add it as the first (non-active) section
	Section^ initSection = newSection (reader.getInitOptions ());
	conf->Sections->Add (initSection->Name, initSection);

	/// read all the sections
	for (::SeedConfList::COptionIterator it = reader.const_iterator () ; it.hasNext () ; it.next ())
	{
		Section^ section = newSection (*it.get ());
		conf->Sections->Add (section->Name, section);
	}

	return conf;
}



///
/// Section implementation

SNAP::Engine::Conf::Section::Section (System::String^ name, System::String^ parameters, SNAP::Engine::Settings^ settings)
: _name (name), _parameters (parameters), _settings (settings) 
{
}


System::String^ SNAP::Engine::Conf::Section::Name::get ()
{
	return _name;
}

SNAP::Engine::Settings^ SNAP::Engine::Conf::Section::Settings::get ()
{
	return _settings;
}