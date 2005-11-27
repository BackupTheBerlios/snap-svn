# Microsoft Developer Studio Generated NMAKE File, Based on Persistance.dsp
!IF "$(CFG)" == ""
CFG=Persistance - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Persistance - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Persistance - Win32 Release" && "$(CFG)" != "Persistance - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Persistance.mak" CFG="Persistance - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Persistance - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Persistance - Win32 Debug" (based on "Win32 (x86) Static Library")
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

!IF  "$(CFG)" == "Persistance - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Persistance.lib" "$(OUTDIR)\Persistance.bsc"


CLEAN :
	-@erase "$(INTDIR)\Error.obj"
	-@erase "$(INTDIR)\Error.sbr"
	-@erase "$(INTDIR)\IArchive.obj"
	-@erase "$(INTDIR)\IArchive.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\IRegistry.obj"
	-@erase "$(INTDIR)\IRegistry.sbr"
	-@erase "$(INTDIR)\OArchive.obj"
	-@erase "$(INTDIR)\OArchive.sbr"
	-@erase "$(INTDIR)\Object.obj"
	-@erase "$(INTDIR)\Object.sbr"
	-@erase "$(INTDIR)\ORegistry.obj"
	-@erase "$(INTDIR)\ORegistry.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\TextReader.obj"
	-@erase "$(INTDIR)\TextReader.sbr"
	-@erase "$(INTDIR)\TextWriter.obj"
	-@erase "$(INTDIR)\TextWriter.sbr"
	-@erase "$(INTDIR)\TFactory.obj"
	-@erase "$(INTDIR)\TFactory.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Persistance.bsc"
	-@erase "$(OUTDIR)\Persistance.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GR /GX /Zi /O2 /I ".." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Persistance.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\IArchive.sbr" \
	"$(INTDIR)\OArchive.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\TextReader.sbr" \
	"$(INTDIR)\TextWriter.sbr" \
	"$(INTDIR)\Object.sbr" \
	"$(INTDIR)\TFactory.sbr" \
	"$(INTDIR)\IRegistry.sbr" \
	"$(INTDIR)\ORegistry.sbr" \
	"$(INTDIR)\Error.sbr"

"$(OUTDIR)\Persistance.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Persistance.lib" 
LIB32_OBJS= \
	"$(INTDIR)\IArchive.obj" \
	"$(INTDIR)\OArchive.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\TextReader.obj" \
	"$(INTDIR)\TextWriter.obj" \
	"$(INTDIR)\Object.obj" \
	"$(INTDIR)\TFactory.obj" \
	"$(INTDIR)\IRegistry.obj" \
	"$(INTDIR)\ORegistry.obj" \
	"$(INTDIR)\Error.obj"

"$(OUTDIR)\Persistance.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Persistance - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Persistance.lib" "$(OUTDIR)\Persistance.bsc"


CLEAN :
	-@erase "$(INTDIR)\Error.obj"
	-@erase "$(INTDIR)\Error.sbr"
	-@erase "$(INTDIR)\IArchive.obj"
	-@erase "$(INTDIR)\IArchive.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\IRegistry.obj"
	-@erase "$(INTDIR)\IRegistry.sbr"
	-@erase "$(INTDIR)\OArchive.obj"
	-@erase "$(INTDIR)\OArchive.sbr"
	-@erase "$(INTDIR)\Object.obj"
	-@erase "$(INTDIR)\Object.sbr"
	-@erase "$(INTDIR)\ORegistry.obj"
	-@erase "$(INTDIR)\ORegistry.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\TextReader.obj"
	-@erase "$(INTDIR)\TextReader.sbr"
	-@erase "$(INTDIR)\TextWriter.obj"
	-@erase "$(INTDIR)\TextWriter.sbr"
	-@erase "$(INTDIR)\TFactory.obj"
	-@erase "$(INTDIR)\TFactory.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Persistance.bsc"
	-@erase "$(OUTDIR)\Persistance.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GR /GX /ZI /Od /I ".." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Persistance.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\IArchive.sbr" \
	"$(INTDIR)\OArchive.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\TextReader.sbr" \
	"$(INTDIR)\TextWriter.sbr" \
	"$(INTDIR)\Object.sbr" \
	"$(INTDIR)\TFactory.sbr" \
	"$(INTDIR)\IRegistry.sbr" \
	"$(INTDIR)\ORegistry.sbr" \
	"$(INTDIR)\Error.sbr"

"$(OUTDIR)\Persistance.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\Persistance.lib" 
LIB32_OBJS= \
	"$(INTDIR)\IArchive.obj" \
	"$(INTDIR)\OArchive.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\TextReader.obj" \
	"$(INTDIR)\TextWriter.obj" \
	"$(INTDIR)\Object.obj" \
	"$(INTDIR)\TFactory.obj" \
	"$(INTDIR)\IRegistry.obj" \
	"$(INTDIR)\ORegistry.obj" \
	"$(INTDIR)\Error.obj"

"$(OUTDIR)\Persistance.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
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
!IF EXISTS("Persistance.dep")
!INCLUDE "Persistance.dep"
!ELSE 
!MESSAGE Warning: cannot find "Persistance.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Persistance - Win32 Release" || "$(CFG)" == "Persistance - Win32 Debug"
SOURCE=.\IArchive.cpp

"$(INTDIR)\IArchive.obj"	"$(INTDIR)\IArchive.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\OArchive.cpp

"$(INTDIR)\OArchive.obj"	"$(INTDIR)\OArchive.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\InputStream.cpp

"$(INTDIR)\InputStream.obj"	"$(INTDIR)\InputStream.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\OutputStream.cpp

"$(INTDIR)\OutputStream.obj"	"$(INTDIR)\OutputStream.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StreamBuffer.cpp

"$(INTDIR)\StreamBuffer.obj"	"$(INTDIR)\StreamBuffer.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\TextReader.cpp

"$(INTDIR)\TextReader.obj"	"$(INTDIR)\TextReader.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\TextWriter.cpp

"$(INTDIR)\TextWriter.obj"	"$(INTDIR)\TextWriter.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Object.cpp

"$(INTDIR)\Object.obj"	"$(INTDIR)\Object.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\TFactory.cpp

"$(INTDIR)\TFactory.obj"	"$(INTDIR)\TFactory.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\IRegistry.cpp

"$(INTDIR)\IRegistry.obj"	"$(INTDIR)\IRegistry.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ORegistry.cpp

"$(INTDIR)\ORegistry.obj"	"$(INTDIR)\ORegistry.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Error.cpp

"$(INTDIR)\Error.obj"	"$(INTDIR)\Error.sbr" : $(SOURCE) "$(INTDIR)"



!ENDIF 

