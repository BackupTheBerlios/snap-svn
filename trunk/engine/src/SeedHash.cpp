//
// File        : $RCSfile: $ 
//               $Workfile: SeedHash.cpp $
// Version     : $Revision: 10 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
// Description :
//    Concrete and interface classes for a hash-table of positions
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "SeedHash.h"
#include "AssignmentFormat.h"

#include "persistance/TextWriter.h"
#include "persistance/StrOutputStream.h"

using namespace Persistance;
using namespace seed;


//
// AssgKey
SeedHash::AssgKey::AssgKey (const Str& data,  
                            const Langauge& langauge)
: _assg (data, langauge.code ())
{
   char buffer [8096];
   Persistance::FixedBufferOutputStream output (buffer, sizeof (buffer));
   {  Persistance::TextWriter textWriter (&output, false);
      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction ( buffer, output.getSize ());
}

SeedHash::AssgKey::AssgKey (const Assignment& assg, 
                            const Langauge& langauge)
: _assg (assg)
{
   char buffer [8096];
   Persistance::FixedBufferOutputStream output (buffer, sizeof (buffer));
   {  Persistance::TextWriter textWriter (&output, false);

      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction ( buffer, output.getSize ());
                               
}






