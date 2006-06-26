#include "core/Str.h"

#include <vcclr.h>

namespace SNAP {
	namespace Engine {
		private ref class Util {
		public:
			static StrBuffer& String2StrBuffer (const System::String^ in, StrBuffer& out)
			{
				pin_ptr<const wchar_t> wch = PtrToStringChars(in);

				// Convert to a char*
				size_t origsize = wcslen(wch) + 1;

				size_t convertedChars = 0;

				const size_t newsize = 4096;
				char nstring[newsize];

				wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);

				out = Str (nstring);

				return out;
			}
		};
	}
}