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
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
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
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x40d /d "NDEBUG"
# ADD RSC /l 0x40d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

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
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "_DEBUG"
# ADD RSC /l 0x40d /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SeedSearcher - Win32 Release"
# Name "SeedSearcher - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Alphabet.cpp
# End Source File
# Begin Source File

SOURCE=.\Assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\PrefixTreePreprocessor.cpp
# End Source File
# Begin Source File

SOURCE=.\PrefixTreeWalker.cpp
# End Source File
# Begin Source File

SOURCE=.\RandomProjections.cpp
# End Source File
# Begin Source File

SOURCE=.\SeedSearcher.cpp
# End Source File
# Begin Source File

SOURCE=.\SequenceDB.cpp
# End Source File
# Begin Source File

SOURCE=.\StdOptions.cpp
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

SOURCE=.\PrefixTreePreprocessor.h
# End Source File
# Begin Source File

SOURCE=.\PrefixTreeWalker.h
# End Source File
# Begin Source File

SOURCE=.\Preprocessor.h
# End Source File
# Begin Source File

SOURCE=.\RandomProjections.h
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
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ExtraMath.h
# End Source File
# Begin Source File

SOURCE=.\HyperGeoCache.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperGeoCache.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\TODO.TXT
# End Source File
# End Target
# End Project
