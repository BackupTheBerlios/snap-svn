# Microsoft Developer Studio Generated NMAKE File, Based on Core.dsp
!IF "$(CFG)" == ""
CFG=Core - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Core - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Core - Win32 Release" && "$(CFG)" != "Core - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Core.mak" CFG="Core - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Core - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Core - Win32 Debug" (based on "Win32 (x86) Static Library")
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

!IF  "$(CFG)" == "Core - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Core.lib" "$(OUTDIR)\Core.bsc"


CLEAN :
	-@erase "$(INTDIR)\Defs.obj"
	-@erase "$(INTDIR)\Defs.sbr"
	-@erase "$(INTDIR)\dlmalloc.obj"
	-@erase "$(INTDIR)\dlmalloc.sbr"
	-@erase "$(INTDIR)\HashTable.obj"
	-@erase "$(INTDIR)\HashTable.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Core.bsc"
	-@erase "$(OUTDIR)\Core.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GR /GX /Zi /O2 /I "." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Core.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Defs.sbr" \
	"$(INTDIR)\HashTable.sbr" \
	"$(INTDIR)\dlmalloc.sbr"

"$(OUTDIR)\Core.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Core.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Defs.obj" \
	"$(INTDIR)\HashTable.obj" \
	"$(INTDIR)\dlmalloc.obj"

"$(OUTDIR)\Core.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Core - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Core.lib" "$(OUTDIR)\Core.bsc"


CLEAN :
	-@erase "$(INTDIR)\Defs.obj"
	-@erase "$(INTDIR)\Defs.sbr"
	-@erase "$(INTDIR)\dlmalloc.obj"
	-@erase "$(INTDIR)\dlmalloc.sbr"
	-@erase "$(INTDIR)\HashTable.obj"
	-@erase "$(INTDIR)\HashTable.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Core.bsc"
	-@erase "$(OUTDIR)\Core.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Core.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Defs.sbr" \
	"$(INTDIR)\HashTable.sbr" \
	"$(INTDIR)\dlmalloc.sbr"

"$(OUTDIR)\Core.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Core.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Defs.obj" \
	"$(INTDIR)\HashTable.obj" \
	"$(INTDIR)\dlmalloc.obj"

"$(OUTDIR)\Core.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
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
!IF EXISTS("Core.dep")
!INCLUDE "Core.dep"
!ELSE 
!MESSAGE Warning: cannot find "Core.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Core - Win32 Release" || "$(CFG)" == "Core - Win32 Debug"
SOURCE=.\Defs.cpp

"$(INTDIR)\Defs.obj"	"$(INTDIR)\Defs.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dlmalloc.c

"$(INTDIR)\dlmalloc.obj"	"$(INTDIR)\dlmalloc.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HashTable.cpp

"$(INTDIR)\HashTable.obj"	"$(INTDIR)\HashTable.sbr" : $(SOURCE) "$(INTDIR)"



!ENDIF 

