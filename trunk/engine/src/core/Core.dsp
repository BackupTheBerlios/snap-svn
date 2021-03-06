# Microsoft Developer Studio Project File - Name="Core" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Core - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Core.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/SeedSearcher/Core", ZCAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Core - Win32 Release"

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
# ADD CPP /nologo /W3 /GR /GX /Zi /O2 /I "." /I ".." /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40d /d "NDEBUG"
# ADD RSC /l 0x40d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Core - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "." /I ".." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /FD /GZ /c
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

# Name "Core - Win32 Release"
# Name "Core - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Argv.cpp
# End Source File
# Begin Source File

SOURCE=.\ConfReader.cpp
# End Source File
# Begin Source File

SOURCE=.\Defs.cpp
# End Source File
# Begin Source File

SOURCE=.\dlmalloc.c
# End Source File
# Begin Source File

SOURCE=.\FixedStr.cpp
# End Source File
# Begin Source File

SOURCE=.\HashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\Parser.cpp
# End Source File
# Begin Source File

SOURCE=.\Str.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllocPolicy.h
# End Source File
# Begin Source File

SOURCE=.\Argv.h
# End Source File
# Begin Source File

SOURCE=.\AutoPtr.h
# End Source File
# Begin Source File

SOURCE=.\Bitset.h
# End Source File
# Begin Source File

SOURCE=.\ChunkAllocator.h
# End Source File
# Begin Source File

SOURCE=.\Compiler.h
# End Source File
# Begin Source File

SOURCE=.\ConfReader.h
# End Source File
# Begin Source File

SOURCE=.\Defs.h
# End Source File
# Begin Source File

SOURCE=.\dlmalloc.h
# End Source File
# Begin Source File

SOURCE=.\FixedStr.h
# End Source File
# Begin Source File

SOURCE=.\HashTable.h
# End Source File
# Begin Source File

SOURCE=.\ImplList.h
# End Source File
# Begin Source File

SOURCE=.\Parser.h
# End Source File
# Begin Source File

SOURCE=.\PoolAllocated.h
# End Source File
# Begin Source File

SOURCE=.\STLHelper.h
# End Source File
# Begin Source File

SOURCE=.\Str.h
# End Source File
# End Group
# Begin Group "boost"

# PROP Default_Filter ""
# Begin Group "pool"

# PROP Default_Filter ""
# Begin Group "details"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\boost\pool\detail\ct_gcd_lcm.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\gcd_lcm.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\guard.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\mutex.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\pool_construct.inc
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\pool_construct_simple.inc
# End Source File
# Begin Source File

SOURCE=..\boost\pool\detail\singleton.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\boost\pool\object_pool.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\pool.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\pool_alloc.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\poolfwd.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\simple_segregated_storage.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\pool\singleton_pool.hpp
# End Source File
# End Group
# Begin Group "config"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\boost\config\abi_prefix.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\abi_suffix.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\auto_link.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\posix_features.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\requires_threads.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\select_compiler_config.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\select_platform_config.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\select_stdlib_config.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\suffix.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\config\user.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\boost\config.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\limits.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\non_type.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\static_assert.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\timer.hpp
# End Source File
# Begin Source File

SOURCE=..\boost\type.hpp
# End Source File
# End Group
# End Target
# End Project
