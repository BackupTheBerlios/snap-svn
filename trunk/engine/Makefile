#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

CC = g++
IFLAGS = -I.  
LDLIBS = -lm 	
OBJS = $(subst .cpp,.o,${SOURCES})
SOURCES = Alphabet.cpp Assignment.cpp Cluster.cpp \
		DebugLog.cpp Feature.cpp HyperGeoCache.cpp \
		HyperGeoScore.cpp \
		Parser.cpp \
		PrefixTreePreprocessor.cpp \
		PrefixTreeWalker.cpp  \
		RandomProjections.cpp \
		SeedSearcher.cpp Sequence.cpp \
		SequenceDB.cpp StdOptions.cpp PSSM.cpp \
		SeedSearcherMain.cpp \
		SeedHash.cpp Preprocessor.cpp LeafPreprocessor.cpp \
		SeedConf.cpp FeatureSet.cpp \
		core/Defs.cpp core/HashTable.cpp \
		core/Str.cpp core/Argv.cpp core/FixedStr.cpp \
		core/ConfReader.cpp	core/GetOptParser.cpp \
		persistance/Error.cpp persistance/IArchive.cpp \
		persistance/InputStream.cpp persistance/IRegistry.cpp \
		persistance/OArchive.cpp persistance/Object.cpp \
		persistance/ORegistry.cpp persistance/OutputStream.cpp \
		persistance/StreamBuffer.cpp persistance/TextReader.cpp \
		persistance/TextWriter.cpp persistance/TFactory.cpp \
		persistance/TextTableReport.cpp \
		legacy/RandomGenerator.cpp legacy/Multinomial.cpp \
		status_reporter/BaseStatusReporter.cpp	\
		boost/test/cpp_main.cpp	boost/test/execution_monitor.cpp	\
		boost/filesystem/operations_posix_windows.cpp				\
		boost/filesystem/path_posix_windows.cpp						\
		boost/filesystem/convenience.cpp							\
		boost/filesystem/exception.cpp
		
MYSQL_LIB_DIR = /sw/lib/mysql

all:	seed 

seed$(EXE): main.o $(OBJS) status_reporter/DummyStatusReporter.o	
	$(CC) $(CCFLAGS) -o seed $(OBJS) main.o status_reporter/DummyStatusReporter.o
	
seed_server$(EXE): main.o $(OBJS) status_reporter/StatusReporter.o
	$(CC) $(CCFLAGS) -L$(MYSQL_LIB_DIR) -lmysqlclient -o seed_server $(OBJS) main.o status_reporter/StatusReporter.o

%.o: %.cpp 
	$(CC) -c $(CCFLAGS) $(IFLAGS) $(LDFLAGS) -o $@ $<


depend: $(SOURCES)
	gccmakedep -- $(IFLAGS) $(LDFLAGS) -- *.cpp 

clean:
	rm -r -f *~
	rm -r -f */*~
	rm -r -f *.o
	rm -r -f */*.o
	rm -r -f *#
	rm -r -f */*#
	rm -r -f seed
	rm -r -f winseed.exe
	rm -r -f Debug
	rm -r -f */Debug
	rm -r -f Release
	rm -r -f */Release
	rm -r -f boost/test/*.o

tags:
	etags --language=c++ *.h *.cpp

# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/Str.h
Assignment.o: Assignment.cpp Assignment.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Alphabet.h core/Str.h \
  persistance/TextWriter.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h persistance/Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  persistance/TextWriter.h persistance/AbstractFormat.h core/AutoPtr.h \
  AssignmentFormat.h Assignment.h core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc /usr/include/c++/3.3.1/bitset \
  core/Str.h boost/shared_ptr.hpp boost/assert.hpp /usr/include/assert.h \
  boost/checked_delete.hpp boost/throw_exception.hpp \
  boost/detail/shared_count.hpp boost/detail/lightweight_mutex.hpp \
  boost/detail/lwm_nop.hpp /usr/include/c++/3.3.1/functional \
  boost/detail/workaround.hpp persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  persistance/StdOutputStream.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Cluster.h Sequence.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h legacy/MathFunctions.h ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Cluster.h Sequence.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h boost/functional.hpp \
  boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h legacy/MathFunctions.h legacy/MathPlus.h \
  boost/shared_ptr.hpp boost/assert.hpp boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional boost/detail/workaround.hpp \
  SeedSearcher.h Feature.h Defs.h Cluster.h Sequence.h core/Str.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  boost/pool/detail/ct_gcd_lcm.hpp boost/static_assert.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h PrefixTreePreprocessor.h FeatureSet.h \
  boost/functional.hpp boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp core/HashTable.h \
  boost/cast.hpp /usr/include/c++/3.3.1/cassert boost/type.hpp \
  boost/limits.hpp boost/detail/select_type.hpp
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset HyperGeoScore.h Cluster.h Sequence.h \
  Defs.h core/Str.h core/PoolAllocated.h boost/pool/object_pool.hpp \
  boost/pool/poolfwd.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h persistance/AbstractFormat.h PSSM.h Alphabet.h \
  DebugLog.h persistance/TextWriter.h boost/shared_ptr.hpp \
  boost/assert.hpp /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h PrefixTreePreprocessor.h FeatureSet.h \
  boost/functional.hpp boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp HyperGeoCache.h \
  ExtraMath.h legacy/MathFunctions.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset LeafPreprocessor.h Preprocessor.h Defs.h \
  SequenceDB.h Alphabet.h core/Str.h Sequence.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h legacy/MathPlus.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc SeedHash.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  AssignmentFormat.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  core/HashTable.h core/AllocPolicy.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Alphabet.h core/Str.h Sequence.h Defs.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc /usr/include/assert.h
Parser.o: Parser.cpp Parser.h Defs.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/Str.h core/Argv.h core/GetOptParser.h core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h persistance/TextWriter.h \
  DebugLog.h persistance/Defs.h persistance/AbstractFormat.h \
  AssignmentFormat.h Assignment.h /usr/include/c++/3.3.1/bitset \
  boost/shared_ptr.hpp boost/assert.hpp /usr/include/assert.h \
  boost/checked_delete.hpp boost/throw_exception.hpp \
  boost/detail/shared_count.hpp boost/detail/lightweight_mutex.hpp \
  boost/detail/lwm_nop.hpp /usr/include/c++/3.3.1/functional \
  boost/detail/workaround.hpp
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  SequenceDB.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h legacy/MathPlus.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc boost/checked_delete.hpp \
  persistance/IArchive.h persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h persistance/TFactory.h \
  persistance/Object.h persistance/Error.h persistance/OArchive.h \
  persistance/ORegistry.h persistance/TextWriter.h DebugLog.h \
  persistance/AbstractFormat.h AssignmentFormat.h boost/shared_ptr.hpp \
  boost/assert.hpp /usr/include/assert.h boost/throw_exception.hpp \
  boost/detail/shared_count.hpp boost/detail/lightweight_mutex.hpp \
  boost/detail/lwm_nop.hpp core/AllocPolicy.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  SequenceDB.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h legacy/MathPlus.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h core/Defs.h core/Compiler.h boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset AssignmentFormat.h \
  persistance/AbstractFormat.h core/AutoPtr.h core/Str.h \
  boost/shared_ptr.hpp boost/assert.hpp /usr/include/assert.h \
  boost/checked_delete.hpp boost/throw_exception.hpp \
  boost/detail/shared_count.hpp boost/detail/lightweight_mutex.hpp \
  boost/detail/lwm_nop.hpp /usr/include/c++/3.3.1/functional \
  boost/detail/workaround.hpp ExtraMath.h legacy/MathFunctions.h \
  legacy/MathPlus.h legacy/RandomGenerator.h legacy/Multinomial.h \
  DebugLog.h persistance/TextWriter.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/Str.h persistance/TextWriter.h Parser.h Defs.h core/Argv.h \
  core/GetOptParser.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc DebugLog.h persistance/Defs.h \
  persistance/AbstractFormat.h AssignmentFormat.h Assignment.h \
  /usr/include/c++/3.3.1/bitset boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional boost/detail/workaround.hpp \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Cluster.h Sequence.h Defs.h core/Str.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  AssignmentFormat.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  core/HashTable.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h
SeedPerformance.o: SeedPerformance.cpp
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  core/Defs.h core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Cluster.h Sequence.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h PrefixTreePreprocessor.h FeatureSet.h \
  boost/functional.hpp boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp SeedHash.h \
  core/HashTable.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h boost/timer.hpp boost/limits.hpp boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert boost/type.hpp \
  boost/detail/select_type.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Parser.h core/Str.h core/Argv.h core/GetOptParser.h core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h persistance/TextWriter.h \
  Sequence.h core/PoolAllocated.h boost/pool/object_pool.hpp \
  boost/pool/poolfwd.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset persistance/AbstractFormat.h PSSM.h \
  Alphabet.h DebugLog.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc PrefixTreePreprocessor.h \
  FeatureSet.h boost/functional.hpp boost/call_traits.hpp \
  boost/detail/call_traits.hpp boost/type_traits/is_arithmetic.hpp \
  boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  RandomProjections.h SeedConf.h core/ConfReader.h StdOptions.h \
  HyperGeoCache.h ExtraMath.h legacy/MathFunctions.h boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert boost/type.hpp boost/limits.hpp \
  boost/detail/select_type.hpp LeafPreprocessor.h SeedHash.h \
  core/HashTable.h core/AllocPolicy.h HyperGeoScore.h \
  status_reporter/BaseStatusReporter.hpp
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc persistance/OArchive.h \
  persistance/Defs.h persistance/ORegistry.h persistance/Object.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h persistance/TFactory.h \
  persistance/Error.h persistance/TextWriter.h core/AutoPtr.h \
  persistance/IArchive.h persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/STLPersist.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp core/Defs.h core/Compiler.h boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Sequence.h Defs.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc SequenceDB.h Alphabet.h Cluster.h \
  legacy/MathPlus.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc /usr/include/assert.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  SequenceDB.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h legacy/MathPlus.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset persistance/AbstractFormat.h PSSM.h \
  DebugLog.h persistance/TextWriter.h boost/shared_ptr.hpp \
  boost/assert.hpp /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h PrefixTreePreprocessor.h FeatureSet.h \
  boost/functional.hpp boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp HyperGeoCache.h \
  ExtraMath.h legacy/MathFunctions.h boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert boost/type.hpp boost/limits.hpp \
  boost/detail/select_type.hpp
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/sys/_types.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h \
  /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/c++/3.3.1/cwchar \
  /usr/include/c++/3.3.1/ctime /usr/include/wchar.h \
  /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/type_traits.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3.1/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3.1/bits/concept_check.h \
  /usr/include/c++/3.3.1/bits/stl_iterator.h \
  /usr/include/c++/3.3.1/bits/stl_alloc.h \
  /usr/include/c++/3.3.1/bits/stl_threads.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/atomicity.h \
  /usr/include/c++/3.3.1/bits/stl_construct.h \
  /usr/include/c++/3.3.1/bits/stl_uninitialized.h \
  /usr/include/c++/3.3.1/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3.1/bits/stl_function.h \
  /usr/include/c++/3.3.1/bits/basic_string.h \
  /usr/include/c++/3.3.1/algorithm /usr/include/c++/3.3.1/bits/stl_algo.h \
  /usr/include/c++/3.3.1/bits/stl_heap.h \
  /usr/include/c++/3.3.1/bits/stl_tempbuf.h \
  /usr/include/c++/3.3.1/bits/basic_string.tcc \
  /usr/include/c++/3.3.1/iostream /usr/include/c++/3.3.1/ostream \
  /usr/include/c++/3.3.1/ios /usr/include/c++/3.3.1/bits/localefwd.h \
  /usr/include/c++/3.3.1/bits/ios_base.h \
  /usr/include/c++/3.3.1/bits/locale_classes.h \
  /usr/include/c++/3.3.1/streambuf \
  /usr/include/c++/3.3.1/bits/streambuf.tcc \
  /usr/include/c++/3.3.1/bits/basic_ios.h \
  /usr/include/c++/3.3.1/bits/streambuf_iterator.h \
  /usr/include/c++/3.3.1/bits/locale_facets.h \
  /usr/include/c++/3.3.1/cwctype /usr/include/wctype.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_base.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/include/c++/3.3.1/bits/codecvt.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/time_members.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/messages_members.h \
  /usr/include/c++/3.3.1/bits/basic_ios.tcc \
  /usr/include/c++/3.3.1/bits/ostream.tcc /usr/include/c++/3.3.1/locale \
  /usr/include/c++/3.3.1/bits/locale_facets.tcc \
  /usr/include/c++/3.3.1/cerrno /usr/include/errno.h \
  /usr/include/sys/errno.h /usr/include/c++/3.3.1/cmath \
  /usr/include/math.h /usr/include/c++/3.3.1/bits/cmath.tcc \
  /usr/include/c++/3.3.1/limits /usr/include/c++/3.3.1/typeinfo \
  /usr/include/c++/3.3.1/istream /usr/include/c++/3.3.1/bits/istream.tcc \
  Cluster.h Sequence.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc legacy/MathPlus.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h boost/shared_ptr.hpp boost/assert.hpp \
  /usr/include/assert.h boost/checked_delete.hpp \
  boost/throw_exception.hpp boost/detail/shared_count.hpp \
  boost/detail/lightweight_mutex.hpp boost/detail/lwm_nop.hpp \
  Preprocessor.h SequenceDB.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/ImplList.h Parser.h core/Argv.h \
  core/GetOptParser.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc RandomProjections.h \
  SeedSearcher.h PrefixTreePreprocessor.h FeatureSet.h \
  boost/functional.hpp boost/call_traits.hpp boost/detail/call_traits.hpp \
  boost/type_traits/is_arithmetic.hpp boost/type_traits/is_integral.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp boost/mpl/int.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/adl_barrier.hpp \
  boost/mpl/aux_/config/adl.hpp boost/mpl/aux_/config/msvc.hpp \
  boost/mpl/aux_/config/intel.hpp boost/mpl/aux_/config/gcc.hpp \
  boost/mpl/aux_/config/workaround.hpp boost/mpl/aux_/nttp_decl.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/integral_wrapper.hpp \
  boost/mpl/integral_c_tag.hpp boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/static_cast.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp boost/preprocessor/repeat.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/preprocessor/inc.hpp boost/preprocessor/arithmetic/inc.hpp \
  boost/mpl/aux_/config/lambda.hpp boost/mpl/aux_/config/ttp.hpp \
  boost/mpl/aux_/config/ctps.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp boost/mpl/bool.hpp \
  boost/mpl/bool_fwd.hpp boost/mpl/aux_/lambda_support.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/is_float.hpp boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp HyperGeoScore.h \
  HyperGeoCache.h ExtraMath.h legacy/MathFunctions.h SeedSearcherMain.h \
  SeedConf.h core/ConfReader.h StdOptions.h boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert boost/type.hpp boost/limits.hpp \
  boost/detail/select_type.hpp persistance/StdInputStream.h \
  persistance/StrOutputStream.h status_reporter/BaseStatusReporter.hpp \
  /usr/include/c++/3.3.1/sstream /usr/include/c++/3.3.1/bits/sstream.tcc \
  boost/filesystem/path.hpp boost/filesystem/config.hpp \
  boost/iterator/iterator_facade.hpp boost/iterator.hpp \
  /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  boost/iterator/interoperable.hpp boost/mpl/or.hpp \
  boost/mpl/aux_/config/use_preprocessed.hpp \
  boost/mpl/aux_/nested_type_wknd.hpp boost/mpl/aux_/na_spec.hpp \
  boost/mpl/lambda_fwd.hpp boost/mpl/void_fwd.hpp boost/mpl/aux_/na.hpp \
  boost/mpl/aux_/na_fwd.hpp boost/mpl/aux_/lambda_arity_param.hpp \
  boost/mpl/aux_/arity.hpp boost/mpl/aux_/config/dtp.hpp \
  boost/mpl/aux_/preprocessor/enum.hpp \
  boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  boost/mpl/limits/arity.hpp boost/preprocessor/logical/and.hpp \
  boost/preprocessor/logical/bitand.hpp boost/preprocessor/identity.hpp \
  boost/preprocessor/facilities/identity.hpp boost/preprocessor/empty.hpp \
  boost/preprocessor/arithmetic/add.hpp \
  boost/preprocessor/arithmetic/dec.hpp \
  boost/preprocessor/control/while.hpp \
  boost/preprocessor/list/fold_left.hpp \
  boost/preprocessor/list/detail/fold_left.hpp \
  boost/preprocessor/control/expr_iif.hpp boost/preprocessor/list/adt.hpp \
  boost/preprocessor/detail/is_binary.hpp \
  boost/preprocessor/detail/check.hpp \
  boost/preprocessor/logical/compl.hpp \
  boost/preprocessor/list/fold_right.hpp \
  boost/preprocessor/list/detail/fold_right.hpp \
  boost/preprocessor/list/reverse.hpp \
  boost/preprocessor/control/detail/while.hpp \
  boost/preprocessor/tuple/elem.hpp boost/preprocessor/arithmetic/sub.hpp \
  boost/mpl/aux_/config/eti.hpp boost/mpl/aux_/include_preprocessed.hpp \
  boost/mpl/aux_/config/compiler.hpp boost/preprocessor/stringize.hpp \
  boost/mpl/aux_/preprocessed/gcc/or.hpp \
  boost/type_traits/is_convertible.hpp boost/type_traits/is_array.hpp \
  boost/type_traits/add_reference.hpp boost/type_traits/is_reference.hpp \
  boost/type_traits/detail/type_trait_def.hpp \
  boost/type_traits/detail/type_trait_undef.hpp \
  boost/iterator/detail/config_def.hpp \
  boost/iterator/detail/config_undef.hpp \
  boost/iterator/iterator_traits.hpp boost/detail/iterator.hpp \
  boost/iterator/detail/facade_iterator_category.hpp \
  boost/iterator/iterator_categories.hpp boost/mpl/eval_if.hpp \
  boost/mpl/if.hpp boost/mpl/aux_/value_wknd.hpp \
  boost/mpl/aux_/config/integral.hpp boost/mpl/identity.hpp \
  boost/mpl/placeholders.hpp boost/mpl/arg.hpp boost/mpl/arg_fwd.hpp \
  boost/mpl/aux_/na_assert.hpp boost/mpl/assert.hpp boost/mpl/not.hpp \
  boost/mpl/aux_/yes_no.hpp boost/mpl/aux_/config/arrays.hpp \
  boost/mpl/aux_/arity_spec.hpp boost/mpl/aux_/arg_typedef.hpp \
  boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  boost/mpl/aux_/preprocessed/gcc/placeholders.hpp boost/mpl/and.hpp \
  boost/mpl/aux_/preprocessed/gcc/and.hpp boost/type_traits/is_same.hpp \
  boost/type_traits/is_const.hpp \
  boost/type_traits/detail/cv_traits_impl.hpp \
  boost/iterator/detail/enable_if.hpp boost/type_traits/add_const.hpp \
  boost/type_traits/add_pointer.hpp \
  boost/type_traits/remove_reference.hpp \
  boost/type_traits/broken_compiler_spec.hpp \
  boost/type_traits/remove_const.hpp boost/type_traits/is_volatile.hpp \
  boost/type_traits/is_pod.hpp boost/type_traits/is_void.hpp \
  boost/type_traits/is_scalar.hpp boost/type_traits/is_enum.hpp \
  boost/type_traits/is_function.hpp \
  boost/type_traits/detail/false_result.hpp \
  boost/type_traits/detail/is_function_ptr_helper.hpp \
  boost/type_traits/is_class.hpp boost/type_traits/is_union.hpp \
  boost/type_traits/remove_cv.hpp boost/type_traits/intrinsics.hpp \
  boost/mpl/always.hpp boost/mpl/apply.hpp boost/mpl/apply_fwd.hpp \
  boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp boost/mpl/apply_wrap.hpp \
  boost/mpl/aux_/has_apply.hpp boost/mpl/has_xxx.hpp \
  boost/mpl/aux_/type_wrapper.hpp boost/mpl/aux_/config/has_xxx.hpp \
  boost/mpl/aux_/config/msvc_typename.hpp \
  boost/mpl/aux_/config/has_apply.hpp boost/mpl/aux_/msvc_never_true.hpp \
  boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp boost/mpl/lambda.hpp \
  boost/mpl/bind.hpp boost/mpl/bind_fwd.hpp \
  boost/mpl/aux_/config/bind.hpp \
  boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp boost/mpl/next.hpp \
  boost/mpl/next_prior.hpp boost/mpl/aux_/common_name_wknd.hpp \
  boost/mpl/protect.hpp boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  boost/mpl/aux_/full_lambda.hpp boost/mpl/quote.hpp boost/mpl/void.hpp \
  boost/mpl/aux_/has_type.hpp boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  boost/mpl/aux_/template_arity.hpp \
  boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  boost/mpl/aux_/preprocessed/gcc/apply.hpp boost/config/abi_prefix.hpp \
  boost/config/abi_suffix.hpp
