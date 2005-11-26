# Microsoft Developer Studio Generated NMAKE File, Based on SeedSearcher.dsp
!IF "$(CFG)" == ""
CFG=SeedSearcher - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SeedSearcher - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SeedSearcher - Win32 Release" && "$(CFG)" != "SeedSearcher - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SeedSearcher.mak" CFG="SeedSearcher - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SeedSearcher - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "SeedSearcher - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\SeedSearcher.exe"

!ELSE 

ALL : "Persistance - Win32 Release" "Core - Win32 Release" "$(OUTDIR)\SeedSearcher.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Core - Win32 ReleaseCLEAN" "Persistance - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Alphabet.obj"
	-@erase "$(INTDIR)\Assignment.obj"
	-@erase "$(INTDIR)\DebugLog.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\HyperGeoCache.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\SeedSearcher.obj"
	-@erase "$(INTDIR)\SequenceDB.obj"
	-@erase "$(INTDIR)\StdOptions.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\SeedSearcher.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\SeedSearcher.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SeedSearcher.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\SeedSearcher.pdb" /machine:I386 /out:"$(OUTDIR)\SeedSearcher.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Alphabet.obj" \
	"$(INTDIR)\Assignment.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\DebugLog.obj" \
	".\Core\Release\Core.lib" \
	".\Persistance\Release\Persistance.lib"

"$(OUTDIR)\SeedSearcher.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\SeedSearcher.exe"

!ELSE 

ALL : "Persistance - Win32 Debug" "Core - Win32 Debug" "$(OUTDIR)\SeedSearcher.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Core - Win32 DebugCLEAN" "Persistance - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Alphabet.obj"
	-@erase "$(INTDIR)\Assignment.obj"
	-@erase "$(INTDIR)\DebugLog.obj"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\HyperGeoCache.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\SeedSearcher.obj"
	-@erase "$(INTDIR)\SequenceDB.obj"
	-@erase "$(INTDIR)\StdOptions.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SeedSearcher.exe"
	-@erase "$(OUTDIR)\SeedSearcher.ilk"
	-@erase "$(OUTDIR)\SeedSearcher.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SeedSearcher.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\SeedSearcher.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SeedSearcher.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Alphabet.obj" \
	"$(INTDIR)\Assignment.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\DebugLog.obj" \
	".\Core\Debug\Core.lib" \
	".\Persistance\Debug\Persistance.lib"

"$(OUTDIR)\SeedSearcher.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("SeedSearcher.dep")
!INCLUDE "SeedSearcher.dep"
!ELSE 
!MESSAGE Warning: cannot find "SeedSearcher.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SeedSearcher - Win32 Release" || "$(CFG)" == "SeedSearcher - Win32 Debug"
SOURCE=.\Alphabet.cpp

"$(INTDIR)\Alphabet.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Assignment.cpp

"$(INTDIR)\Assignment.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DebugLog.cpp

"$(INTDIR)\DebugLog.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PrefixTreePreprocessor.cpp

"$(INTDIR)\PrefixTreePreprocessor.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PrefixTreeWalker.cpp

"$(INTDIR)\PrefixTreeWalker.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\RandomProjections.cpp

"$(INTDIR)\RandomProjections.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SeedSearcher.cpp

"$(INTDIR)\SeedSearcher.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SequenceDB.cpp

"$(INTDIR)\SequenceDB.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdOptions.cpp

"$(INTDIR)\StdOptions.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Legacy\getopt.c

"$(INTDIR)\getopt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Legacy\Multinomial.cpp

"$(INTDIR)\Multinomial.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Legacy\RandomGenerator.cpp

"$(INTDIR)\RandomGenerator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\HyperGeoCache.cpp

"$(INTDIR)\HyperGeoCache.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

"Core - Win32 Release" : 
   cd ".\Core"
   $(MAKE) /$(MAKEFLAGS) /F .\Core.mak CFG="Core - Win32 Release" 
   cd ".."

"Core - Win32 ReleaseCLEAN" : 
   cd ".\Core"
   $(MAKE) /$(MAKEFLAGS) /F .\Core.mak CFG="Core - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

"Core - Win32 Debug" : 
   cd ".\Core"
   $(MAKE) /$(MAKEFLAGS) /F .\Core.mak CFG="Core - Win32 Debug" 
   cd ".."

"Core - Win32 DebugCLEAN" : 
   cd ".\Core"
   $(MAKE) /$(MAKEFLAGS) /F .\Core.mak CFG="Core - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

"Persistance - Win32 Release" : 
   cd ".\Persistance"
   $(MAKE) /$(MAKEFLAGS) /F .\Persistance.mak CFG="Persistance - Win32 Release" 
   cd ".."

"Persistance - Win32 ReleaseCLEAN" : 
   cd ".\Persistance"
   $(MAKE) /$(MAKEFLAGS) /F .\Persistance.mak CFG="Persistance - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

"Persistance - Win32 Debug" : 
   cd ".\Persistance"
   $(MAKE) /$(MAKEFLAGS) /F .\Persistance.mak CFG="Persistance - Win32 Debug" 
   cd ".."

"Persistance - Win32 DebugCLEAN" : 
   cd ".\Persistance"
   $(MAKE) /$(MAKEFLAGS) /F .\Persistance.mak CFG="Persistance - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

SOURCE=.\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

