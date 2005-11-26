# Microsoft Developer Studio Project File - Name="SeedSearcher" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=SeedSearcher - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SeedSearcher.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/SeedSearcher", ECAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /Zi /O2 /Op /Oy- /I "." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "NDEBUG"
# ADD RSC /l 0x40d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /profile /nodefaultlib

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "_DEBUG"
# ADD RSC /l 0x40d /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "SeedSearcher - Win32 Release"
# Name "SeedSearcher - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Alphabet.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Assignment.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Cluster.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DebugLog.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\HyperGeoScore.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LeafPreprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\main.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Parser.cpp
# End Source File
# Begin Source File

SOURCE=.\PrefixTreePreprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Preprocessor.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PSSM.CPP

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RandomProjections.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SeedHash.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SeedSearcher.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Sequence.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SequenceDB.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdOptions.cpp

!IF  "$(CFG)" == "SeedSearcher - Win32 Release"

# ADD CPP /O2 /Ob1

!ELSEIF  "$(CFG)" == "SeedSearcher - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Alphabet.h
# End Source File
# Begin Source File

SOURCE=.\Assignment.h
# End Source File
# Begin Source File

SOURCE=.\AssignmentFormat.h
# End Source File
# Begin Source File

SOURCE=.\Cluster.h
# End Source File
# Begin Source File

SOURCE=.\DebugLog.h
# End Source File
# Begin Source File

SOURCE=.\Defs.h
# End Source File
# Begin Source File

SOURCE=.\HyperGeoCache.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperGeoCache.h
# End Source File
# Begin Source File

SOURCE=.\HyperGeoScore.h
# End Source File
# Begin Source File

SOURCE=.\LeafPreprocessor.h
# End Source File
# Begin Source File

SOURCE=.\Parser.h
# End Source File
# Begin Source File

SOURCE=.\PrefixTreePreprocessor.h
# End Source File
# Begin Source File

SOURCE=.\Preprocessor.h
# End Source File
# Begin Source File

SOURCE=.\PSSM.h
# End Source File
# Begin Source File

SOURCE=.\RandomProjections.h
# End Source File
# Begin Source File

SOURCE=.\SeedHash.h
# End Source File
# Begin Source File

SOURCE=.\SeedSearcher.h
# End Source File
# Begin Source File

SOURCE=.\Sequence.h
# End Source File
# Begin Source File

SOURCE=.\SequenceDB.h
# End Source File
# Begin Source File

SOURCE=.\StdOptions.h
# End Source File
# End Group
# Begin Group "Legacy"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Legacy\config.h
# End Source File
# Begin Source File

SOURCE=.\ExtraMath.h
# End Source File
# Begin Source File

SOURCE=.\Legacy\getopt.c
# End Source File
# Begin Source File

SOURCE=.\Legacy\Getopt.h
# End Source File
# Begin Source File

SOURCE=.\Legacy\MathFunctions.h
# End Source File
# Begin Source File

SOURCE=.\Legacy\mathplus.h
# End Source File
# Begin Source File

SOURCE=.\Legacy\Multinomial.cpp
# End Source File
# Begin Source File

SOURCE=.\Legacy\Multinomial.h
# End Source File
# Begin Source File

SOURCE=.\Legacy\RandomGenerator.cpp
# End Source File
# Begin Source File

SOURCE=.\Legacy\RandomGenerator.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\TODO.TXT
# End Source File
# End Target
# End Project
