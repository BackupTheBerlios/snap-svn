namespace SNAP{
	namespace Engine {
		ref class Parser;


		public ref class Conf 
		{
		public:
			Conf () {
				_sections = gcnew System::Collections::Generic::SortedDictionary <System::String^, Section^> ();
			}

			static Conf^ LoadFile (System::String^ filename);

			/// 
			ref class Section {
			public:
				Section (System::String^ name, Parser^ settings);
				///
				property System::String^ Name
				{
					System::String^ get ();
					//void set (System::String^);
				}

				property Parser^ Settings {
					Parser^ get ();
				}

			private:
				Parser^ _settings;
				System::String^ _name;
			};
			
			typedef System::Collections::Generic::IDictionary<System::String^, Section^> SectionMap;
			
			property SectionMap^ Sections {
				SectionMap^ get () {
					return _sections;
				}
			}

		private:
			SectionMap^ _sections;
		};
	}
}