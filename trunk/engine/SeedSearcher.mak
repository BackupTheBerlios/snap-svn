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
	-@erase "$(INTDIR)\LeafPreprocessor.obj"
	-@erase "$(INTDIR)\LeafPreprocessor.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\Multinomial.sbr"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.sbr"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.sbr"
	-@erase "$(INTDIR)\Preprocessor.obj"
	-@erase "$(INTDIR)\Preprocessor.sbr"
	-@erase "$(INTDIR)\PSSM.OBJ"
	-@erase "$(INTDIR)\PSSM.SBR"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomGenerator.sbr"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\RandomProjections.sbr"
	-@erase "$(INTDIR)\SeedHash.obj"
	-@erase "$(INTDIR)\SeedHash.sbr"
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
	"$(INTDIR)\LeafPreprocessor.sbr" \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\PrefixTreePreprocessor.sbr" \
	"$(INTDIR)\PrefixTreeWalker.sbr" \
	"$(INTDIR)\Preprocessor.sbr" \
	"$(INTDIR)\PSSM.SBR" \
	"$(INTDIR)\RandomProjections.sbr" \
	"$(INTDIR)\SeedHash.sbr" \
	"$(INTDIR)\SeedSearcher.sbr" \
	"$(INTDIR)\Sequence.sbr" \
	"$(INTDIR)\SequenceDB.sbr" \
	"$(INTDIR)\StdOptions.sbr" \
	"$(INTDIR)\getopt.sbr" \
	"$(INTDIR)\Multinomial.sbr" \
	"$(INTDIR)\RandomGenerator.sbr" \
	"$(INTDIR)\HyperGeoCache.sbr"

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
	"$(INTDIR)\LeafPreprocessor.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\Preprocessor.obj" \
	"$(INTDIR)\PSSM.OBJ" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedHash.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\Sequence.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
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
	-@erase "$(INTDIR)\LeafPreprocessor.obj"
	-@erase "$(INTDIR)\LeafPreprocessor.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\Multinomial.obj"
	-@erase "$(INTDIR)\Multinomial.sbr"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.obj"
	-@erase "$(INTDIR)\PrefixTreePreprocessor.sbr"
	-@erase "$(INTDIR)\PrefixTreeWalker.obj"
	-@erase "$(INTDIR)\PrefixTreeWalker.sbr"
	-@erase "$(INTDIR)\Preprocessor.obj"
	-@erase "$(INTDIR)\Preprocessor.sbr"
	-@erase "$(INTDIR)\PSSM.OBJ"
	-@erase "$(INTDIR)\PSSM.SBR"
	-@erase "$(INTDIR)\RandomGenerator.obj"
	-@erase "$(INTDIR)\RandomGenerator.sbr"
	-@erase "$(INTDIR)\RandomProjections.obj"
	-@erase "$(INTDIR)\RandomProjections.sbr"
	-@erase "$(INTDIR)\SeedHash.obj"
	-@erase "$(INTDIR)\SeedHash.sbr"
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
	"$(INTDIR)\LeafPreprocessor.sbr" \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\PrefixTreePreprocessor.sbr" \
	"$(INTDIR)\PrefixTreeWalker.sbr" \
	"$(INTDIR)\Preprocessor.sbr" \
	"$(INTDIR)\PSSM.SBR" \
	"$(INTDIR)\RandomProjections.sbr" \
	"$(INTDIR)\SeedHash.sbr" \
	"$(INTDIR)\SeedSearcher.sbr" \
	"$(INTDIR)\Sequence.sbr" \
	"$(INTDIR)\SequenceDB.sbr" \
	"$(INTDIR)\StdOptions.sbr" \
	"$(INTDIR)\getopt.sbr" \
	"$(INTDIR)\Multinomial.sbr" \
	"$(INTDIR)\RandomGenerator.sbr" \
	"$(INTDIR)\HyperGeoCache.sbr"

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
	"$(INTDIR)\LeafPreprocessor.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\PrefixTreePreprocessor.obj" \
	"$(INTDIR)\PrefixTreeWalker.obj" \
	"$(INTDIR)\Preprocessor.obj" \
	"$(INTDIR)\PSSM.OBJ" \
	"$(INTDIR)\RandomProjections.obj" \
	"$(INTDIR)\SeedHash.obj" \
	"$(INTDIR)\SeedSearcher.obj" \
	"$(INTDIR)\Sequence.obj" \
	"$(INTDIR)\SequenceDB.obj" \
	"$(INTDIR)\StdOptions.obj" \
	"$(INTDIR)\getopt.obj" \
	"$(INTDIR)\Multinomial.obj" \
	"$(INTDIR)\RandomGenerator.obj" \
	"$(INTDIR)\HyperGeoCache.obj" \
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

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Alphabet.obj"	"$(INTDIR)\Alphabet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\Alphabet.obj"	"$(INTDIR)\Alphabet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Assignment.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Assignment.obj"	"$(INTDIR)\Assignment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\Assignment.obj"	"$(INTDIR)\Assignment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Cluster.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Cluster.obj"	"$(INTDIR)\Cluster.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\Cluster.obj"	"$(INTDIR)\Cluster.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DebugLog.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\DebugLog.obj"	"$(INTDIR)\DebugLog.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\DebugLog.obj"	"$(INTDIR)\DebugLog.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\HyperGeoScore.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\HyperGeoScore.obj"	"$(INTDIR)\HyperGeoScore.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\HyperGeoScore.obj"	"$(INTDIR)\HyperGeoScore.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\LeafPreprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\LeafPreprocessor.obj"	"$(INTDIR)\LeafPreprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\LeafPreprocessor.obj"	"$(INTDIR)\LeafPreprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\main.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\PrefixTreePreprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\PrefixTreePreprocessor.obj"	"$(INTDIR)\PrefixTreePreprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\PrefixTreePreprocessor.obj"	"$(INTDIR)\PrefixTreePreprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\PrefixTreeWalker.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\PrefixTreeWalker.obj"	"$(INTDIR)\PrefixTreeWalker.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\PrefixTreeWalker.obj"	"$(INTDIR)\PrefixTreeWalker.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Preprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Preprocessor.obj"	"$(INTDIR)\Preprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\Preprocessor.obj"	"$(INTDIR)\Preprocessor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\PSSM.CPP

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\PSSM.OBJ"	"$(INTDIR)\PSSM.SBR" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\PSSM.OBJ"	"$(INTDIR)\PSSM.SBR" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\RandomProjections.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\RandomProjections.obj"	"$(INTDIR)\RandomProjections.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\RandomProjections.obj"	"$(INTDIR)\RandomProjections.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SeedHash.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\SeedHash.obj"	"$(INTDIR)\SeedHash.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\SeedHash.obj"	"$(INTDIR)\SeedHash.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SeedSearcher.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\SeedSearcher.obj"	"$(INTDIR)\SeedSearcher.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\SeedSearcher.obj"	"$(INTDIR)\SeedSearcher.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Sequence.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Sequence.obj"	"$(INTDIR)\Sequence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\Sequence.obj"	"$(INTDIR)\Sequence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SequenceDB.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\SequenceDB.obj"	"$(INTDIR)\SequenceDB.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\SequenceDB.obj"	"$(INTDIR)\SequenceDB.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StdOptions.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GR /GX /Zi /O2 /Op /Oy- /Ob1 /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdOptions.obj"	"$(INTDIR)\StdOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdOptions.obj"	"$(INTDIR)\StdOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

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

