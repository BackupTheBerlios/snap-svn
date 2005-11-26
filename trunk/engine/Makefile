#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

BOOST = E:/Dev/boost_1_32_0/

CC = g++
IFLAGS = -I.  -I$(BOOST)
LDLIBS = -lm 	
OBJS = $(subst .cpp,.o,${SOURCES})
SOURCES = Alphabet.cpp Assignment.cpp Cluster.cpp \
		DebugLog.cpp Feature.cpp \
		Parser.cpp \
		PrefixTreePreprocessor.cpp \
		PrefixTreeWalker.cpp  \
		RandomProjections.cpp \
		SeedSearcher.cpp Sequence.cpp \
		SequenceDB.cpp StdOptions.cpp PSSM.cpp \
		SeedSearcherMain.cpp \
		SeedHash.cpp Preprocessor.cpp LeafPreprocessor.cpp \
		SeedConf.cpp FeatureSet.cpp SeqWeight.cpp \
		Score.cpp \
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
		boost/filesystem/exception.cpp								\
		boost/regex/c_regex_traits.cpp								\
		boost/regex/c_regex_traits_common.cpp						\
		boost/regex/cregex.cpp										\
		boost/regex/fileiter.cpp									\
		boost/regex/instances.cpp									\
		boost/regex/posix_api.cpp									\
		boost/regex/regex.cpp										\
		boost/regex/regex_synch.cpp									\
		boost/regex/w32_regex_traits.cpp							\
		boost/regex/wide_posix_api.cpp								\
		boost/regex/winstances.cpp										

		
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
	rm -r -f *.exe
	rm -r -f Debug
	rm -r -f */Debug
	rm -r -f Release
	rm -r -f */Release
	rm -r -f boost/test/*.o
	rm -r -f boost/filesystem/*.o
	rm -r -f boost/regex/*.o	

tags:
	etags --language=c++ *.h *.cpp

# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h persistance/Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  persistance/TextWriter.h persistance/AbstractFormat.h core/AutoPtr.h \
  AssignmentFormat.h Assignment.h core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc /usr/include/c++/3.3.1/bitset \
  core/Str.h E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h persistance/StdOutputStream.h \
  /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/FixedStr.h core/ImplList.h \
  legacy/MathFunctions.h ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/FixedStr.h core/ImplList.h \
  E:/Dev/boost_1_32_0/boost/functional.hpp \
  E:/Dev/boost_1_32_0/boost/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  /usr/include/c++/3.3.1/bitset HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h legacy/MathFunctions.h legacy/MathPlus.h \
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/HashTable.h \
  core/Str.h persistance/TextWriter.h E:/Dev/boost_1_32_0/boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert E:/Dev/boost_1_32_0/boost/type.hpp \
  E:/Dev/boost_1_32_0/boost/limits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/select_type.hpp
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  /usr/include/c++/3.3.1/bitset HyperGeoScore.h legacy/MathPlus.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  /usr/include/c++/3.3.1/bitset LeafPreprocessor.h Preprocessor.h Defs.h \
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SequenceDB.h Alphabet.h \
  core/Str.h Sequence.h Cluster.h SeqWeight.h core/HashTable.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h /usr/include/c++/3.3.1/list \
  /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc SeedHash.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  AssignmentFormat.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h
Parser.o: Parser.cpp Parser.h Defs.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/Str.h core/Argv.h \
  core/GetOptParser.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h persistance/TextWriter.h \
  E:/Dev/boost_1_32_0/boost/regex.hpp boost/regex/config.hpp \
  boost/regex/user.hpp /usr/include/c++/3.3.1/cassert \
  /usr/include/c++/3.3.1/stdexcept /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/cstdint.hpp boost/regex/config/allocator.hpp \
  boost/regex/config/cstring.hpp E:/Dev/boost_1_32_0/boost/scoped_ptr.hpp \
  boost/regex/v4/regex.hpp E:/Dev/boost_1_32_0/boost/cregex.hpp \
  boost/regex/v4/cregex.hpp boost/regex/v4/match_flags.hpp \
  E:/Dev/boost_1_32_0/boost/regex_fwd.hpp boost/regex/v4/regex_fwd.hpp \
  boost/regex/v4/regex_stack.hpp boost/regex/v4/regex_raw_buffer.hpp \
  boost/regex/v4/regex_kmp.hpp boost/regex/pattern_except.hpp \
  boost/regex/regex_traits.hpp boost/regex/v4/regex_traits.hpp \
  boost/regex/v4/regex_cstring.hpp \
  E:/Dev/boost_1_32_0/boost/scoped_array.hpp \
  boost/regex/v4/char_regex_traits.hpp boost/regex/v4/states.hpp \
  boost/regex/v4/regbase.hpp boost/regex/v4/iterator_traits.hpp \
  boost/regex/v4/basic_regex.hpp boost/regex/v4/sub_match.hpp \
  boost/regex/v4/regex_format.hpp boost/regex/v4/match_results.hpp \
  boost/regex/v4/regex_compile.hpp boost/regex/v4/instances.hpp \
  boost/regex/v4/regex_match.hpp E:/Dev/boost_1_32_0/boost/limits.hpp \
  boost/regex/v4/perl_matcher.hpp boost/regex/v4/iterator_category.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  boost/regex/v4/perl_matcher_non_recursive.hpp \
  boost/regex/v4/perl_matcher_common.hpp boost/regex/v4/regex_search.hpp \
  boost/regex/v4/regex_grep.hpp boost/regex/v4/regex_replace.hpp \
  boost/regex/v4/regex_merge.hpp boost/regex/v4/regex_split.hpp \
  boost/regex/v4/regex_iterator.hpp \
  boost/regex/v4/regex_token_iterator.hpp DebugLog.h persistance/Defs.h \
  persistance/AbstractFormat.h AssignmentFormat.h Assignment.h \
  /usr/include/c++/3.3.1/bitset
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc persistance/IArchive.h \
  persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h persistance/TFactory.h \
  persistance/Object.h persistance/Error.h persistance/OArchive.h \
  persistance/ORegistry.h persistance/TextWriter.h DebugLog.h \
  persistance/AbstractFormat.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  /usr/include/c++/3.3.1/bitset AssignmentFormat.h \
  persistance/AbstractFormat.h core/AutoPtr.h core/Str.h \
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp ExtraMath.h \
  legacy/MathFunctions.h legacy/MathPlus.h legacy/RandomGenerator.h \
  legacy/Multinomial.h DebugLog.h persistance/TextWriter.h
Score.o: Score.cpp Score.h Defs.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SeqWeight.h Sequence.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/HashTable.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h persistance/TextWriter.h \
  legacy/MathPlus.h E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp ScoreFunction.h \
  Cluster.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SequenceDB.h Alphabet.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  HyperGeoCache.h ExtraMath.h legacy/MathFunctions.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  core/Str.h persistance/TextWriter.h Parser.h Defs.h \
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/Argv.h \
  core/GetOptParser.h core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc DebugLog.h persistance/Defs.h \
  persistance/AbstractFormat.h AssignmentFormat.h Assignment.h \
  /usr/include/c++/3.3.1/bitset persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  /usr/include/c++/3.3.1/bitset Cluster.h Sequence.h Defs.h \
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  AssignmentFormat.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h
SeedPerformance.o: SeedPerformance.cpp
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  core/Defs.h core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/FixedStr.h core/ImplList.h \
  PrefixTreePreprocessor.h SeedHash.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h E:/Dev/boost_1_32_0/boost/timer.hpp \
  E:/Dev/boost_1_32_0/boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp Parser.h core/Str.h \
  core/Argv.h core/GetOptParser.h core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc persistance/TextTableReport.h \
  core/FixedStr.h core/AutoPtr.h core/ImplList.h persistance/TextWriter.h \
  Sequence.h Cluster.h SeqWeight.h core/HashTable.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset persistance/AbstractFormat.h PSSM.h \
  Alphabet.h DebugLog.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  PrefixTreePreprocessor.h RandomProjections.h SeedConf.h \
  core/ConfReader.h StdOptions.h HyperGeoCache.h ExtraMath.h \
  legacy/MathFunctions.h E:/Dev/boost_1_32_0/boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert E:/Dev/boost_1_32_0/boost/type.hpp \
  E:/Dev/boost_1_32_0/boost/limits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/select_type.hpp FeatureSet.h \
  E:/Dev/boost_1_32_0/boost/functional.hpp \
  E:/Dev/boost_1_32_0/boost/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  LeafPreprocessor.h SeedHash.h status_reporter/BaseStatusReporter.hpp
SeqWeight.o: SeqWeight.cpp SeqWeight.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/HashTable.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h SequenceDB.h Alphabet.h \
  Cluster.h legacy/MathPlus.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h core/FixedStr.h \
  persistance/TextReader.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/StdInputStream.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  persistance/OutputStream.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc \
  E:/Dev/boost_1_32_0/boost/tokenizer.hpp \
  E:/Dev/boost_1_32_0/boost/token_iterator.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_adaptor.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/detail/iterator.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_categories.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/config_def.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/eval_if.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/if.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/value_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/integral.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/placeholders.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/arg.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/arg_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/not.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nested_type_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/yes_no.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/arrays.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arg_typedef.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/use_preprocessed.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/include_preprocessed.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/compiler.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/stringize.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/config_undef.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_facade.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/interoperable.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/or.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_traits.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/facade_iterator_category.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/and.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_same.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/cv_traits_impl.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/enable_if.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/broken_compiler_spec.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_volatile.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pod.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_void.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_scalar.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_enum.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_function.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/false_result.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_function_ptr_helper.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_class.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_union.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_cv.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/intrinsics.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/always.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply_wrap.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/has_apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/has_xxx.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/type_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/has_xxx.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc_typename.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/has_apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/msvc_never_true.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bind_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/next.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/next_prior.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/common_name_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/protect.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/full_lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/quote.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/has_type.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/minimum_category.hpp \
  E:/Dev/boost_1_32_0/boost/token_functions.hpp \
  /usr/include/c++/3.3.1/stdexcept /usr/include/c++/3.3.1/cassert
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h \
  persistance/OArchive.h persistance/Defs.h persistance/ORegistry.h \
  persistance/Object.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h persistance/TFactory.h \
  persistance/Error.h persistance/TextWriter.h core/AutoPtr.h \
  persistance/IArchive.h persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/STLPersist.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  Sequence.h Defs.h E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SequenceDB.h \
  Alphabet.h Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h core/Str.h Sequence.h \
  Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset persistance/AbstractFormat.h PSSM.h \
  DebugLog.h persistance/TextWriter.h Preprocessor.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/FixedStr.h core/ImplList.h \
  PrefixTreePreprocessor.h HyperGeoCache.h ExtraMath.h \
  legacy/MathFunctions.h E:/Dev/boost_1_32_0/boost/cast.hpp \
  /usr/include/c++/3.3.1/cassert E:/Dev/boost_1_32_0/boost/type.hpp \
  E:/Dev/boost_1_32_0/boost/limits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/select_type.hpp FeatureSet.h \
  E:/Dev/boost_1_32_0/boost/functional.hpp \
  E:/Dev/boost_1_32_0/boost/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h
UnitTestMain.o: UnitTestMain.cpp SeqWeight.h Sequence.h Defs.h \
  core/Defs.h core/Compiler.h E:/Dev/boost_1_32_0/boost/config.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp core/STLHelper.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h core/HashTable.h \
  core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h \
  E:/Dev/boost_1_32_0/boost/test/unit_test_suite.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/unit_test_monitor.hpp \
  E:/Dev/boost_1_32_0/boost/test/execution_monitor.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/unit_test_config.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/basic_cstring/basic_cstring.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/basic_cstring/basic_cstring_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/basic_cstring/bcs_char_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/basic_cstring/io.hpp \
  /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/scoped_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/type.hpp \
  E:/Dev/boost_1_32_0/boost/cstdlib.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/suppress_warnings.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/enable_warnings.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/class_properties.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/seq/for_each.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/for.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/detail/for.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/seq/seq.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/seq/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/seq/size.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/rem.hpp \
  E:/Dev/boost_1_32_0/boost/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/broken_compiler_spec.hpp \
  E:/Dev/boost_1_32_0/boost/utility/addressof.hpp \
  E:/Dev/boost_1_32_0/boost/test/auto_unit_test.hpp \
  E:/Dev/boost_1_32_0/boost/test/unit_test.hpp \
  E:/Dev/boost_1_32_0/boost/test/test_tools.hpp \
  E:/Dev/boost_1_32_0/boost/test/unit_test_log.hpp \
  E:/Dev/boost_1_32_0/boost/utility.hpp \
  E:/Dev/boost_1_32_0/boost/utility/base_from_member.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/enum_binary_params.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/enum_params.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat_from_to.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/utility/enable_if.hpp \
  E:/Dev/boost_1_32_0/boost/next_prior.hpp \
  E:/Dev/boost_1_32_0/boost/noncopyable.hpp \
  E:/Dev/boost_1_32_0/boost/test/detail/wrap_stringstream.hpp \
  /usr/include/c++/3.3.1/sstream /usr/include/c++/3.3.1/bits/sstream.tcc \
  /usr/include/c++/3.3.1/stdexcept \
  E:/Dev/boost_1_32_0/boost/test/floating_point_comparison.hpp \
  E:/Dev/boost_1_32_0/boost/limits.hpp core/Argv.h
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  E:/Dev/boost_1_32_0/boost/config.hpp boost/config/user.hpp \
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
  E:/Dev/boost_1_32_0/boost/shared_ptr.hpp \
  E:/Dev/boost_1_32_0/boost/assert.hpp /usr/include/assert.h \
  E:/Dev/boost_1_32_0/boost/checked_delete.hpp \
  E:/Dev/boost_1_32_0/boost/throw_exception.hpp \
  E:/Dev/boost_1_32_0/boost/detail/shared_count.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lightweight_mutex.hpp \
  E:/Dev/boost_1_32_0/boost/detail/lwm_nop.hpp \
  /usr/include/c++/3.3.1/functional \
  E:/Dev/boost_1_32_0/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc core/Str.h SeqWeight.h \
  core/HashTable.h core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h legacy/MathPlus.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  /usr/include/c++/3.3.1/list /usr/include/c++/3.3.1/bits/stl_list.h \
  /usr/include/c++/3.3.1/bits/list.tcc Score.h \
  E:/Dev/boost_1_32_0/boost/concept_check.hpp \
  E:/Dev/boost_1_32_0/boost/iterator.hpp /usr/include/c++/3.3.1/iterator \
  /usr/include/c++/3.3.1/bits/stream_iterator.h \
  E:/Dev/boost_1_32_0/boost/type_traits/conversion_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_convertible.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/yes_no_type.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/config.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_array.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/template_arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/int_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/adl_barrier.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/adl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/intel.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/gcc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/workaround.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nttp_decl.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/nttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/integral_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/integral_c_tag.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/static_constant.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/static_cast.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/cat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/config/config.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/params.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/preprocessor.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma_if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/if.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bool.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/punctuation/comma.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/repetition/repeat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/debug/error.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/auto_rec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/eat.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/inc.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/inc.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ttp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/ctps.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/overload_resolution.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bool_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_support.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/bool_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_def.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/type_trait_undef.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/ice.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_or.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_not.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/ice_eq.hpp \
  E:/Dev/boost_1_32_0/boost/static_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/identity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/lambda_arity_param.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/dtp.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/enum.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/limits/arity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/and.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/bitand.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/facilities/identity.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/empty.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/add.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/dec.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_left.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/expr_iif.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/adt.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/is_binary.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/detail/check.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/logical/compl.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/detail/fold_right.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/list/reverse.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/control/detail/while.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/tuple/elem.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/arithmetic/sub.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/FixedStr.h core/ImplList.h Parser.h \
  core/Argv.h core/GetOptParser.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc RandomProjections.h \
  SeedSearcher.h PrefixTreePreprocessor.h HyperGeoScore.h \
  SeedSearcherMain.h SeedConf.h core/ConfReader.h StdOptions.h \
  HyperGeoCache.h ExtraMath.h legacy/MathFunctions.h \
  E:/Dev/boost_1_32_0/boost/cast.hpp /usr/include/c++/3.3.1/cassert \
  E:/Dev/boost_1_32_0/boost/type.hpp E:/Dev/boost_1_32_0/boost/limits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/select_type.hpp FeatureSet.h \
  E:/Dev/boost_1_32_0/boost/functional.hpp \
  E:/Dev/boost_1_32_0/boost/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/call_traits.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_arithmetic.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_integral.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_float.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_member_function_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  persistance/StdInputStream.h persistance/StrOutputStream.h \
  status_reporter/BaseStatusReporter.hpp /usr/include/c++/3.3.1/sstream \
  /usr/include/c++/3.3.1/bits/sstream.tcc boost/filesystem/path.hpp \
  boost/filesystem/config.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_facade.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/interoperable.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/or.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/use_preprocessed.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/nested_type_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/include_preprocessed.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/compiler.hpp \
  E:/Dev/boost_1_32_0/boost/preprocessor/stringize.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/config_def.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/config_undef.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_traits.hpp \
  E:/Dev/boost_1_32_0/boost/detail/iterator.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/facade_iterator_category.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/iterator_categories.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/eval_if.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/if.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/value_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/integral.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/placeholders.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/arg.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/arg_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/na_assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/assert.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/not.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/yes_no.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/arrays.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arity_spec.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/arg_typedef.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/and.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_same.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/cv_traits_impl.hpp \
  E:/Dev/boost_1_32_0/boost/iterator/detail/enable_if.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/add_pointer.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_reference.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/broken_compiler_spec.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_const.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_volatile.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_pod.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_void.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_scalar.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_enum.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_function.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/false_result.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/detail/is_function_ptr_helper.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_class.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/is_union.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/remove_cv.hpp \
  E:/Dev/boost_1_32_0/boost/type_traits/intrinsics.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/always.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/apply_wrap.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/has_apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/has_xxx.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/type_wrapper.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/has_xxx.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/msvc_typename.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/has_apply.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/msvc_never_true.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/bind_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/config/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/next.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/next_prior.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/common_name_wknd.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/protect.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/full_lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/quote.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/void.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/has_type.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/template_arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  E:/Dev/boost_1_32_0/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  boost/config/abi_prefix.hpp boost/config/abi_suffix.hpp
