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

ALL : "$(OUTDIR)\SeedSearcher.exe" "$(OUTDIR)\SeedSearcher.bsc"

!ELSE 

ALL : "Persistance - Win32 Release" "Core - Win32 Release" "$(OUTDIR)\SeedSearcher.exe" "$(OUTDIR)\SeedSearcher.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Core - Win32 ReleaseCLEAN" "Persistance - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Alphabet.obj"
	-@erase "$(INTDIR)\Alphabet.sbr"
	-@erase "$(INTDIR)\Assignment.obj"
	-@erase "$(INTDIR)\Assignment.sbr"
	-@erase "$(INTDIR)\Cluster.obj"
	-@erase "$(INTDIR)\Cluster.sbr"
	-@erase "$(INTDIR)\DebugLog.obj"
	-@erase "$(INTDIR)\DebugLog.sbr"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\getopt.sbr"
	-@erase "$(INTDIR)\HyperGeoCache.obj"
	-@erase "$(INTDIR)\HyperGeoCache.sbr"
	-@erase "$(INTDIR)\HyperGeoScore.obj"
	-@erase "$(INTDIR)\HyperGeoScore.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\Multinomial.sbr"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.sbr"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.sbr"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomGenerator.sbr"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\RandomProjections.sbr"
	-@erase "$(INTDIR)\SeedSearcher.obj"
	-@erase "$(INTDIR)\SeedSearcher.sbr"
	-@erase "$(INTDIR)\Sequence.obj"
	-@erase "$(INTDIR)\Sequence.sbr"
	-@erase "$(INTDIR)\SequenceDB.obj"
	-@erase "$(INTDIR)\SequenceDB.sbr"
	-@erase "$(INTDIR)\StdOptions.obj"
	-@erase "$(INTDIR)\StdOptions.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SeedSearcher.bsc"
	-@erase "$(OUTDIR)\SeedSearcher.exe"
	-@erase "$(OUTDIR)\SeedSearcher.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SeedSearcher.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Alphabet.sbr" \
	"$(INTDIR)\Assignment.sbr" \
	"$(INTDIR)\Cluster.sbr" \
	"$(INTDIR)\DebugLog.sbr" \
	"$(INTDIR)\HyperGeoScore.sbr" \
	"$(INTDIR)\PrefixTreePreprocessor.sbr" \
	"$(INTDIR)\PrefixTreeWalker.sbr" \
	"$(INTDIR)\RandomProjections.sbr" \
	"$(INTDIR)\SeedSearcher.sbr" \
	"$(INTDIR)\Sequence.sbr" \
	"$(INTDIR)\SequenceDB.sbr" \
	"$(INTDIR)\StdOptions.sbr" \
	"$(INTDIR)\getopt.sbr" \
	"$(INTDIR)\Multinomial.sbr" \
	"$(INTDIR)\RandomGenerator.sbr" \
	"$(INTDIR)\HyperGeoCache.sbr" \
	"$(INTDIR)\main.sbr"

"$(OUTDIR)\SeedSearcher.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\SeedSearcher.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SeedSearcher.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Alphabet.obj" \
	"$(INTDIR)\Assignment.obj" \
	"$(INTDIR)\Cluster.obj" \
	"$(INTDIR)\DebugLog.obj" \
	"$(INTDIR)\HyperGeoScore.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\Sequence.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
	"$(INTDIR)\main.obj" \
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

ALL : "$(OUTDIR)\SeedSearcher.exe" "$(OUTDIR)\SeedSearcher.bsc"

!ELSE 

ALL : "Persistance - Win32 Debug" "Core - Win32 Debug" "$(OUTDIR)\SeedSearcher.exe" "$(OUTDIR)\SeedSearcher.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"Core - Win32 DebugCLEAN" "Persistance - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\Alphabet.obj"
	-@erase "$(INTDIR)\Alphabet.sbr"
	-@erase "$(INTDIR)\Assignment.obj"
	-@erase "$(INTDIR)\Assignment.sbr"
	-@erase "$(INTDIR)\Cluster.obj"
	-@erase "$(INTDIR)\Cluster.sbr"
	-@erase "$(INTDIR)\DebugLog.obj"
	-@erase "$(INTDIR)\DebugLog.sbr"
	-@erase "$(INTDIR)\getopt.obj"
	-@erase "$(INTDIR)\getopt.sbr"
	-@erase "$(INTDIR)\HyperGeoCache.obj"
	-@erase "$(INTDIR)\HyperGeoCache.sbr"
	-@erase "$(INTDIR)\HyperGeoScore.obj"
	-@erase "$(INTDIR)\HyperGeoScore.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\Multinomial.sbr"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.sbr"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.sbr"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomGenerator.sbr"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\RandomProjections.sbr"
	-@erase "$(INTDIR)\SeedSearcher.obj"
	-@erase "$(INTDIR)\SeedSearcher.sbr"
	-@erase "$(INTDIR)\Sequence.obj"
	-@erase "$(INTDIR)\Sequence.sbr"
	-@erase "$(INTDIR)\SequenceDB.obj"
	-@erase "$(INTDIR)\SequenceDB.sbr"
	-@erase "$(INTDIR)\StdOptions.obj"
	-@erase "$(INTDIR)\StdOptions.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SeedSearcher.bsc"
	-@erase "$(OUTDIR)\SeedSearcher.exe"
	-@erase "$(OUTDIR)\SeedSearcher.ilk"
	-@erase "$(OUTDIR)\SeedSearcher.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SeedSearcher.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Alphabet.sbr" \
	"$(INTDIR)\Assignment.sbr" \
	"$(INTDIR)\Cluster.sbr" \
	"$(INTDIR)\DebugLog.sbr" \
	"$(INTDIR)\HyperGeoScore.sbr" \
	"$(INTDIR)\PrefixTreePreprocessor.sbr" \
	"$(INTDIR)\PrefixTreeWalker.sbr" \
	"$(INTDIR)\RandomProjections.sbr" \
	"$(INTDIR)\SeedSearcher.sbr" \
	"$(INTDIR)\Sequence.sbr" \
	"$(INTDIR)\SequenceDB.sbr" \
	"$(INTDIR)\StdOptions.sbr" \
	"$(INTDIR)\getopt.sbr" \
	"$(INTDIR)\Multinomial.sbr" \
	"$(INTDIR)\RandomGenerator.sbr" \
	"$(INTDIR)\HyperGeoCache.sbr" \
	"$(INTDIR)\main.sbr"

"$(OUTDIR)\SeedSearcher.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\SeedSearcher.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SeedSearcher.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Alphabet.obj" \
	"$(INTDIR)\Assignment.obj" \
	"$(INTDIR)\Cluster.obj" \
	"$(INTDIR)\DebugLog.obj" \
	"$(INTDIR)\HyperGeoScore.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\Sequence.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
	"$(INTDIR)\main.obj" \
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

"$(INTDIR)\Alphabet.obj"	"$(INTDIR)\Alphabet.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Assignment.cpp

"$(INTDIR)\Assignment.obj"	"$(INTDIR)\Assignment.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Cluster.cpp

"$(INTDIR)\Cluster.obj"	"$(INTDIR)\Cluster.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DebugLog.cpp

"$(INTDIR)\DebugLog.obj"	"$(INTDIR)\DebugLog.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HyperGeoScore.cpp

"$(INTDIR)\HyperGeoScore.obj"	"$(INTDIR)\HyperGeoScore.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\main.cpp

"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PrefixTreePreprocessor.cpp

"$(INTDIR)\PrefixTreePreprocessor.obj"	"$(INTDIR)\PrefixTreePreprocessor.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PrefixTreeWalker.cpp

"$(INTDIR)\PrefixTreeWalker.obj"	"$(INTDIR)\PrefixTreeWalker.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\RandomProjections.cpp

"$(INTDIR)\RandomProjections.obj"	"$(INTDIR)\RandomProjections.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SeedSearcher.cpp

"$(INTDIR)\SeedSearcher.obj"	"$(INTDIR)\SeedSearcher.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Sequence.cpp

"$(INTDIR)\Sequence.obj"	"$(INTDIR)\Sequence.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SequenceDB.cpp

"$(INTDIR)\SequenceDB.obj"	"$(INTDIR)\SequenceDB.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdOptions.cpp

"$(INTDIR)\StdOptions.obj"	"$(INTDIR)\StdOptions.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Legacy\getopt.c

"$(INTDIR)\getopt.obj"	"$(INTDIR)\getopt.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Legacy\Multinomial.cpp

"$(INTDIR)\Multinomial.obj"	"$(INTDIR)\Multinomial.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Legacy\RandomGenerator.cpp

"$(INTDIR)\RandomGenerator.obj"	"$(INTDIR)\RandomGenerator.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\HyperGeoCache.cpp

"$(INTDIR)\HyperGeoCache.obj"	"$(INTDIR)\HyperGeoCache.sbr" : $(SOURCE) "$(INTDIR)"


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


!ENDIF 

