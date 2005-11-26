#include "Error.h"
#include "Core/Defs.h"

using namespace Persistance;

void Error::raise (const char* filename, int line, const char* error)
{
   ProgramException::raise (line, filename, error);
}

void Error::raise (int line, const char* error)
{
   ProgramException::raise (line, NULL, error);
}
