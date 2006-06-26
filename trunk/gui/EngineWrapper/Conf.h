class SeedConfList;

namespace SNAP{
	namespace Engine {
		ref class Settings;

		public ref class Conf 
		{
		public:
			ref class Section;
			typedef System::Collections::Generic::SortedList <System::String^, Section^> SectionList;
//				SNAP::Util::IndexedSortedList <

		public:
			Conf ();
			//Conf (ISectionList^ list);

			static Conf^ LoadFile (System::String^ filename);
			//static Conf^ LoadFile (SectionList^ list, System::String^ filename);

			/// 
			ref class Section {
			public:
				Section (System::String^ name, System::String^ parameters, Settings^ settings);
				///
				property System::String^ Name
				{
					System::String^ get ();
					//void set (System::String^);
				}

				property SNAP::Engine::Settings^ Settings {
					SNAP::Engine::Settings^ get ();
				}

				property System::String^ Parameters {
					System::String^ get () {
						return _parameters;
					}
				}
				property bool Active {
					bool get ()
					{
						return _active;
					}
				}

				//bool IsOverriden (System::String^ optionName);

			private:
				bool _active;
				SNAP::Engine::Settings^ _settings;
				System::String^ _name;
				System::String^ _parameters;
			};
			
			property SectionList^ Sections {
				SectionList^ get () {
					return _sections;
				}
			}

		private:
			SectionList^ _sections;
		};
	}
}