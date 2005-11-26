# Microsoft Developer Studio Project File - Name="Persistance" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Persistance - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Persistance.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/SeedSearcher/Persistance", ADAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Persistance - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /Zi /O2 /I ".." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "NDEBUG"
# ADD RSC /l 0x40d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Persistance - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I ".." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "_DEBUG"
# ADD RSC /l 0x40d /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Persistance - Win32 Release"
# Name "Persistance - Win32 Debug"
# Begin Group "Archive"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\IArchive.cpp
# End Source File
# Begin Source File

SOURCE=.\IArchive.h
# End Source File
# Begin Source File

SOURCE=.\OArchive.cpp
# End Source File
# Begin Source File

SOURCE=.\OArchive.h
# End Source File
# End Group
# Begin Group "IO"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\AbstractFormat.h
# End Source File
# Begin Source File

SOURCE=.\InputStream.cpp
# End Source File
# Begin Source File

SOURCE=.\InputStream.h
# End Source File
# Begin Source File

SOURCE=.\IODefs.h
# End Source File
# Begin Source File

SOURCE=.\OutputStream.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputStream.h
# End Source File
# Begin Source File

SOURCE=.\StdInputStream.h
# End Source File
# Begin Source File

SOURCE=.\StdOutputStream.h
# End Source File
# Begin Source File

SOURCE=.\StreamBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\StreamBuffer.h
# End Source File
# Begin Source File

SOURCE=.\StrOutputStream.h
# End Source File
# Begin Source File

SOURCE=.\TextReader.cpp
# End Source File
# Begin Source File

SOURCE=.\TextReader.h
# End Source File
# Begin Source File

SOURCE=.\TextWriter.cpp
# End Source File
# Begin Source File

SOURCE=.\TextWriter.h
# End Source File
# Begin Source File

SOURCE=.\UnbufferedChannel.h
# End Source File
# End Group
# Begin Group "Object"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Object.cpp
# End Source File
# Begin Source File

SOURCE=.\Object.h
# End Source File
# End Group
# Begin Group "Factory"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\TFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\TFactory.h
# End Source File
# End Group
# Begin Group "Registry"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\IRegistry.cpp
# End Source File
# Begin Source File

SOURCE=.\IRegistry.h
# End Source File
# Begin Source File

SOURCE=.\ORegistry.cpp
# End Source File
# Begin Source File

SOURCE=.\ORegistry.h
# End Source File
# End Group
# Begin Group "Base"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Defs.h
# End Source File
# Begin Source File

SOURCE=.\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\Error.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\STLPersist.h
# End Source File
# End Target
# End Project
