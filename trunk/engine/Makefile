#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

BOOST = C:/Aviad/Dev/boost_1_33_1

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
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/Str.h core/Defs.h
Assignment.o: Assignment.cpp Assignment.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset Alphabet.h \
  core/Str.h core/Defs.h persistance/TextWriter.h \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h persistance/Defs.h ./core/Defs.h \
  ./core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  ./persistance/Defs.h ./core/AutoPtr.h AssignmentFormat.h Assignment.h \
  core/Defs.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset core/Str.h \
  core/Defs.h boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  persistance/OutputStream.h persistance/StdOutputStream.h \
  persistance/UnbufferedChannel.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp Cluster.h Sequence.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  legacy/MathFunctions.h legacy/MathPlus.h ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp Cluster.h Sequence.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  ./boost/functional.hpp ./boost/call_traits.hpp \
  ./boost/detail/call_traits.hpp ./boost/type_traits/is_arithmetic.hpp \
  ./boost/type_traits/is_integral.hpp ./boost/type_traits/is_float.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset HyperGeoCache.h \
  ExtraMath.h legacy/MathFunctions.h /usr/include/math.h \
  legacy/MathPlus.h legacy/MathPlus.h boost/shared_ptr.hpp \
  ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SeedSearcher.h Feature.h Defs.h \
  ./boost/shared_ptr.hpp Cluster.h Sequence.h core/Str.h core/Defs.h \
  SeqWeight.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h persistance/AbstractFormat.h ./persistance/Defs.h \
  ./core/AutoPtr.h PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h \
  Preprocessor.h SequenceDB.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h boost/checked_delete.hpp ./boost/cast.hpp \
  ./boost/type.hpp ./boost/limits.hpp ./boost/detail/select_type.hpp
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset HyperGeoScore.h \
  Cluster.h Sequence.h Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h boost/checked_delete.hpp HyperGeoCache.h \
  ExtraMath.h legacy/MathFunctions.h legacy/MathPlus.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset LeafPreprocessor.h \
  Preprocessor.h Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SequenceDB.h Alphabet.h core/Str.h \
  core/Defs.h Sequence.h Cluster.h SeqWeight.h core/HashTable.h \
  core/Str.h core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc SeedHash.h \
  DebugLog.h persistance/TextWriter.h persistance/AbstractFormat.h \
  ./persistance/Defs.h ./core/AutoPtr.h AssignmentFormat.h
Parser.o: Parser.cpp Parser.h Defs.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/Str.h core/Defs.h core/Argv.h \
  core/Str.h core/GetOptParser.h ./core/Defs.h ./core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ./core/Argv.h ./persistance/TextTableReport.h ./core/Str.h \
  ./core/FixedStr.h ./core/Str.h ./core/AutoPtr.h ./core/ImplList.h \
  ./core/STLHelper.h ./persistance/TextWriter.h persistance/TextWriter.h \
  /usr/include/math.h ./boost/regex.hpp ./boost/regex/config.hpp \
  ./boost/regex/user.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stdexcept \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/cstdint.hpp ./boost/regex/config/allocator.hpp \
  ./boost/regex/config/cstring.hpp ./boost/scoped_ptr.hpp \
  ./boost/regex/v4/regex.hpp ./boost/cregex.hpp \
  ./boost/regex/v4/cregex.hpp ./boost/regex/v4/match_flags.hpp \
  ./boost/regex_fwd.hpp ./boost/regex/v4/regex_fwd.hpp \
  ./boost/regex/v4/regex_stack.hpp ./boost/regex/v4/regex_raw_buffer.hpp \
  ./boost/regex/v4/regex_kmp.hpp ./boost/regex/pattern_except.hpp \
  ./boost/regex/regex_traits.hpp ./boost/regex/v4/regex_traits.hpp \
  ./boost/regex/v4/regex_cstring.hpp ./boost/scoped_array.hpp \
  ./boost/regex/v4/char_regex_traits.hpp ./boost/regex/v4/states.hpp \
  ./boost/regex/v4/regbase.hpp ./boost/regex/v4/iterator_traits.hpp \
  ./boost/regex/v4/basic_regex.hpp ./boost/regex/v4/sub_match.hpp \
  ./boost/regex/v4/regex_format.hpp ./boost/regex/v4/match_results.hpp \
  ./boost/regex/v4/regex_compile.hpp ./boost/regex/v4/instances.hpp \
  ./boost/regex/v4/regex_match.hpp ./boost/limits.hpp \
  ./boost/regex/v4/perl_matcher.hpp \
  ./boost/regex/v4/iterator_category.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  ./boost/regex/v4/perl_matcher_non_recursive.hpp \
  ./boost/regex/v4/perl_matcher_common.hpp \
  ./boost/regex/v4/regex_search.hpp ./boost/regex/v4/regex_grep.hpp \
  ./boost/regex/v4/regex_replace.hpp ./boost/regex/v4/regex_merge.hpp \
  ./boost/regex/v4/regex_split.hpp ./boost/regex/v4/regex_iterator.hpp \
  ./boost/regex/v4/regex_token_iterator.hpp DebugLog.h persistance/Defs.h \
  ./core/Defs.h persistance/AbstractFormat.h ./persistance/Defs.h \
  ./core/AutoPtr.h AssignmentFormat.h Assignment.h core/STLHelper.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  boost/shared_ptr.hpp
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc \
  boost/checked_delete.hpp persistance/IArchive.h persistance/Defs.h \
  persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h persistance/TFactory.h \
  persistance/Object.h persistance/Error.h ./core/AutoPtr.h \
  persistance/OArchive.h persistance/ORegistry.h persistance/TextWriter.h \
  DebugLog.h persistance/TextWriter.h persistance/AbstractFormat.h \
  ./persistance/Defs.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h core/Defs.h core/Compiler.h ./boost/config.hpp \
  ./boost/config/user.hpp ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset AssignmentFormat.h \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  core/Str.h core/Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp ExtraMath.h legacy/MathFunctions.h \
  /usr/include/math.h legacy/MathPlus.h legacy/MathPlus.h \
  legacy/RandomGenerator.h legacy/Multinomial.h DebugLog.h \
  persistance/TextWriter.h boost/shared_ptr.hpp
Score.o: Score.cpp Score.h Defs.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SeqWeight.h Sequence.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  persistance/TextWriter.h legacy/MathPlus.h /usr/include/math.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  ScoreFunction.h Cluster.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SequenceDB.h Alphabet.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset ExtraMath.h \
  legacy/MathFunctions.h legacy/MathPlus.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h ./core/Defs.h \
  ./core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./core/Str.h ./core/Defs.h ./persistance/TextWriter.h Parser.h Defs.h \
  core/Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/Str.h core/Argv.h core/Str.h \
  core/GetOptParser.h ./core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ./core/Argv.h ./persistance/TextTableReport.h ./core/Str.h \
  ./core/FixedStr.h ./core/Str.h ./core/AutoPtr.h ./core/ImplList.h \
  ./core/STLHelper.h ./persistance/TextWriter.h persistance/TextWriter.h \
  core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc DebugLog.h \
  persistance/Defs.h ./core/Defs.h persistance/AbstractFormat.h \
  ./persistance/Defs.h ./core/AutoPtr.h AssignmentFormat.h Assignment.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  boost/shared_ptr.hpp persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset Cluster.h \
  Sequence.h Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  DebugLog.h persistance/TextWriter.h persistance/AbstractFormat.h \
  ./persistance/Defs.h ./core/AutoPtr.h AssignmentFormat.h \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedPerformance.o: SeedPerformance.cpp
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  core/Defs.h core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp Cluster.h Sequence.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h boost/checked_delete.hpp SeedHash.h \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h ./boost/timer.hpp \
  ./boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp Parser.h core/Str.h core/Defs.h \
  core/Argv.h core/Str.h core/GetOptParser.h ./core/Defs.h \
  ./core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ./core/Argv.h ./persistance/TextTableReport.h ./core/Str.h \
  ./core/FixedStr.h ./core/Str.h ./core/AutoPtr.h ./core/ImplList.h \
  ./core/STLHelper.h ./persistance/TextWriter.h persistance/TextWriter.h \
  Sequence.h core/STLHelper.h Cluster.h SeqWeight.h core/HashTable.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h Preprocessor.h SequenceDB.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h PrefixTreePreprocessor.h \
  boost/checked_delete.hpp RandomProjections.h SeedConf.h \
  core/ConfReader.h ./core/Str.h ./persistance/TextWriter.h \
  core/ImplList.h StdOptions.h ./boost/cast.hpp ./boost/type.hpp \
  ./boost/limits.hpp ./boost/detail/select_type.hpp FeatureSet.h \
  ./boost/functional.hpp ./boost/call_traits.hpp \
  ./boost/detail/call_traits.hpp ./boost/type_traits/is_arithmetic.hpp \
  ./boost/type_traits/is_integral.hpp ./boost/type_traits/is_float.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  LeafPreprocessor.h SeedHash.h ExtraMath.h legacy/MathFunctions.h \
  legacy/MathPlus.h status_reporter/BaseStatusReporter.hpp ./core/Defs.h \
  ./core/Str.h ./core/Argv.h
SeqWeight.o: SeqWeight.cpp SeqWeight.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  SequenceDB.h Alphabet.h Cluster.h legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  core/FixedStr.h ./core/Str.h persistance/TextReader.h ./core/Defs.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/StdInputStream.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h persistance/OutputStream.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h persistance/OArchive.h persistance/Defs.h \
  ./core/Defs.h persistance/ORegistry.h persistance/Object.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  persistance/TFactory.h persistance/Error.h persistance/TextWriter.h \
  ./core/AutoPtr.h persistance/IArchive.h persistance/IRegistry.h \
  persistance/TextReader.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/STLPersist.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  Sequence.h Defs.h ./boost/shared_ptr.hpp ./boost/assert.hpp \
  ./boost/checked_delete.hpp ./boost/throw_exception.hpp \
  ./boost/detail/shared_count.hpp ./boost/detail/lightweight_mutex.hpp \
  ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SequenceDB.h Alphabet.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  boost/shared_ptr.hpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h boost/checked_delete.hpp ./boost/cast.hpp \
  ./boost/type.hpp ./boost/limits.hpp ./boost/detail/select_type.hpp \
  FeatureSet.h ./boost/functional.hpp ./boost/call_traits.hpp \
  ./boost/detail/call_traits.hpp ./boost/type_traits/is_arithmetic.hpp \
  ./boost/type_traits/is_integral.hpp ./boost/type_traits/is_float.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h
UnitTestMain.o: UnitTestMain.cpp SeqWeight.h Sequence.h Defs.h \
  core/Defs.h core/Compiler.h ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  ./boost/test/unit_test_suite.hpp \
  ./boost/test/detail/unit_test_monitor.hpp \
  ./boost/test/execution_monitor.hpp \
  ./boost/test/detail/unit_test_config.hpp \
  ./boost/test/detail/basic_cstring/basic_cstring.hpp \
  ./boost/test/detail/basic_cstring/basic_cstring_fwd.hpp \
  ./boost/test/detail/basic_cstring/bcs_char_traits.hpp \
  ./boost/type_traits/add_const.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp \
  ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/test/detail/basic_cstring/io.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/scoped_ptr.hpp ./boost/type.hpp ./boost/cstdlib.hpp \
  ./boost/test/detail/suppress_warnings.hpp \
  ./boost/test/detail/enable_warnings.hpp \
  ./boost/test/detail/class_properties.hpp \
  ./boost/preprocessor/seq/for_each.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/repetition/for.hpp \
  ./boost/preprocessor/repetition/detail/for.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/seq/seq.hpp ./boost/preprocessor/seq/elem.hpp \
  ./boost/preprocessor/seq/size.hpp ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/tuple/rem.hpp ./boost/call_traits.hpp \
  ./boost/detail/call_traits.hpp ./boost/type_traits/is_arithmetic.hpp \
  ./boost/type_traits/is_integral.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/is_float.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/config.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/add_pointer.hpp \
  ./boost/type_traits/remove_reference.hpp \
  ./boost/type_traits/broken_compiler_spec.hpp \
  ./boost/utility/addressof.hpp ./boost/test/auto_unit_test.hpp \
  ./boost/test/unit_test.hpp ./boost/test/test_tools.hpp \
  ./boost/test/unit_test_log.hpp ./boost/utility.hpp \
  ./boost/utility/base_from_member.hpp \
  ./boost/preprocessor/repetition/enum_binary_params.hpp \
  ./boost/preprocessor/repetition/enum_params.hpp \
  ./boost/preprocessor/repetition/repeat_from_to.hpp \
  ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/utility/enable_if.hpp \
  ./boost/next_prior.hpp ./boost/noncopyable.hpp \
  ./boost/test/detail/wrap_stringstream.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  ./boost/test/floating_point_comparison.hpp ./boost/limits.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stdexcept core/Argv.h \
  StdOptions.h SequenceDB.h Alphabet.h Cluster.h legacy/MathPlus.h \
  /usr/include/math.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
  persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/is_array.hpp ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp ./boost/type_traits/ice.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h boost/checked_delete.hpp ./boost/cast.hpp \
  ./boost/detail/select_type.hpp FeatureSet.h ./boost/functional.hpp \
  SeedSearcherMain.h Parser.h core/GetOptParser.h ./core/Argv.h \
  ./persistance/TextTableReport.h RandomProjections.h SeedConf.h \
  core/ConfReader.h ./core/Str.h ./persistance/TextWriter.h \
  core/ImplList.h
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  ./boost/config.hpp ./boost/config/user.hpp \
  ./boost/config/select_compiler_config.hpp \
  ./boost/config/compiler/gcc.hpp ./boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  ./boost/config/stdlib/libstdcpp3.hpp \
  ./boost/config/select_platform_config.hpp \
  ./boost/config/platform/cygwin.hpp /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/types.h \
  /usr/include/machine/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/getopt.h \
  ./boost/config/posix_features.hpp ./boost/config/suffix.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/sys/reent.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ./boost/shared_ptr.hpp ./boost/assert.hpp ./boost/checked_delete.hpp \
  ./boost/throw_exception.hpp ./boost/detail/shared_count.hpp \
  ./boost/detail/lightweight_mutex.hpp ./boost/detail/lwm_nop.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  ./boost/detail/workaround.hpp Cluster.h Sequence.h core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h boost/shared_ptr.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  legacy/MathPlus.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset \
  persistance/AbstractFormat.h ./persistance/Defs.h ./core/AutoPtr.h \
  PSSM.h Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  C:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp ./boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  ./boost/type_traits/conversion_traits.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/type_traits/detail/yes_no_type.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_array.hpp \
  ./boost/type_traits/detail/bool_trait_def.hpp \
  ./boost/type_traits/detail/template_arity_spec.hpp ./boost/mpl/int.hpp \
  ./boost/mpl/int_fwd.hpp ./boost/mpl/aux_/adl_barrier.hpp \
  ./boost/mpl/aux_/config/adl.hpp ./boost/mpl/aux_/config/msvc.hpp \
  ./boost/mpl/aux_/config/intel.hpp ./boost/mpl/aux_/config/gcc.hpp \
  ./boost/mpl/aux_/config/workaround.hpp ./boost/mpl/aux_/nttp_decl.hpp \
  ./boost/mpl/aux_/config/nttp.hpp ./boost/mpl/aux_/integral_wrapper.hpp \
  ./boost/mpl/integral_c_tag.hpp \
  ./boost/mpl/aux_/config/static_constant.hpp \
  ./boost/mpl/aux_/static_cast.hpp ./boost/preprocessor/cat.hpp \
  ./boost/preprocessor/config/config.hpp \
  ./boost/mpl/aux_/template_arity_fwd.hpp \
  ./boost/mpl/aux_/preprocessor/params.hpp \
  ./boost/mpl/aux_/config/preprocessor.hpp \
  ./boost/preprocessor/comma_if.hpp \
  ./boost/preprocessor/punctuation/comma_if.hpp \
  ./boost/preprocessor/control/if.hpp \
  ./boost/preprocessor/control/iif.hpp \
  ./boost/preprocessor/logical/bool.hpp \
  ./boost/preprocessor/facilities/empty.hpp \
  ./boost/preprocessor/punctuation/comma.hpp \
  ./boost/preprocessor/repeat.hpp \
  ./boost/preprocessor/repetition/repeat.hpp \
  ./boost/preprocessor/debug/error.hpp \
  ./boost/preprocessor/detail/auto_rec.hpp \
  ./boost/preprocessor/tuple/eat.hpp ./boost/preprocessor/inc.hpp \
  ./boost/preprocessor/arithmetic/inc.hpp \
  ./boost/mpl/aux_/config/lambda.hpp ./boost/mpl/aux_/config/ttp.hpp \
  ./boost/mpl/aux_/config/ctps.hpp \
  ./boost/mpl/aux_/config/overload_resolution.hpp ./boost/mpl/bool.hpp \
  ./boost/mpl/bool_fwd.hpp ./boost/mpl/aux_/lambda_support.hpp \
  ./boost/type_traits/detail/bool_trait_undef.hpp \
  ./boost/type_traits/add_reference.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/type_traits/detail/type_trait_def.hpp \
  ./boost/type_traits/detail/type_trait_undef.hpp \
  ./boost/type_traits/ice.hpp ./boost/type_traits/detail/ice_or.hpp \
  ./boost/type_traits/detail/ice_and.hpp \
  ./boost/type_traits/detail/ice_not.hpp \
  ./boost/type_traits/detail/ice_eq.hpp ./boost/static_assert.hpp \
  ./boost/mpl/identity.hpp ./boost/mpl/aux_/na_spec.hpp \
  ./boost/mpl/lambda_fwd.hpp ./boost/mpl/void_fwd.hpp \
  ./boost/mpl/aux_/na.hpp ./boost/mpl/aux_/na_fwd.hpp \
  ./boost/mpl/aux_/lambda_arity_param.hpp ./boost/mpl/aux_/arity.hpp \
  ./boost/mpl/aux_/config/dtp.hpp ./boost/mpl/aux_/preprocessor/enum.hpp \
  ./boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  ./boost/mpl/limits/arity.hpp ./boost/preprocessor/logical/and.hpp \
  ./boost/preprocessor/logical/bitand.hpp \
  ./boost/preprocessor/identity.hpp \
  ./boost/preprocessor/facilities/identity.hpp \
  ./boost/preprocessor/empty.hpp ./boost/preprocessor/arithmetic/add.hpp \
  ./boost/preprocessor/arithmetic/dec.hpp \
  ./boost/preprocessor/control/while.hpp \
  ./boost/preprocessor/list/fold_left.hpp \
  ./boost/preprocessor/list/detail/fold_left.hpp \
  ./boost/preprocessor/control/expr_iif.hpp \
  ./boost/preprocessor/list/adt.hpp \
  ./boost/preprocessor/detail/is_binary.hpp \
  ./boost/preprocessor/detail/check.hpp \
  ./boost/preprocessor/logical/compl.hpp \
  ./boost/preprocessor/list/fold_right.hpp \
  ./boost/preprocessor/list/detail/fold_right.hpp \
  ./boost/preprocessor/list/reverse.hpp \
  ./boost/preprocessor/control/detail/while.hpp \
  ./boost/preprocessor/tuple/elem.hpp \
  ./boost/preprocessor/arithmetic/sub.hpp ./boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  Parser.h core/Argv.h core/GetOptParser.h ./core/Argv.h \
  ./persistance/TextTableReport.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  RandomProjections.h SeedSearcher.h PrefixTreePreprocessor.h \
  boost/checked_delete.hpp SeedSearcherMain.h SeedConf.h \
  core/ConfReader.h ./core/Str.h ./persistance/TextWriter.h \
  core/ImplList.h StdOptions.h ./boost/cast.hpp ./boost/type.hpp \
  ./boost/limits.hpp ./boost/detail/select_type.hpp FeatureSet.h \
  ./boost/functional.hpp ./boost/call_traits.hpp \
  ./boost/detail/call_traits.hpp ./boost/type_traits/is_arithmetic.hpp \
  ./boost/type_traits/is_integral.hpp ./boost/type_traits/is_float.hpp \
  ./boost/type_traits/is_pointer.hpp \
  ./boost/type_traits/is_member_pointer.hpp \
  ./boost/type_traits/is_member_function_pointer.hpp \
  ./boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  persistance/StdInputStream.h persistance/StrOutputStream.h \
  status_reporter/BaseStatusReporter.hpp ./core/Defs.h ./core/Str.h \
  ./core/Argv.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  ./boost/filesystem/path.hpp ./boost/filesystem/config.hpp \
  ./boost/iterator/iterator_facade.hpp ./boost/iterator/interoperable.hpp \
  ./boost/mpl/or.hpp ./boost/mpl/aux_/config/use_preprocessed.hpp \
  ./boost/mpl/aux_/nested_type_wknd.hpp \
  ./boost/mpl/aux_/include_preprocessed.hpp \
  ./boost/mpl/aux_/config/compiler.hpp ./boost/preprocessor/stringize.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/or.hpp \
  ./boost/type_traits/is_convertible.hpp \
  ./boost/iterator/detail/config_def.hpp \
  ./boost/iterator/detail/config_undef.hpp \
  ./boost/iterator/iterator_traits.hpp ./boost/detail/iterator.hpp \
  ./boost/iterator/detail/facade_iterator_category.hpp \
  ./boost/iterator/iterator_categories.hpp ./boost/mpl/eval_if.hpp \
  ./boost/mpl/if.hpp ./boost/mpl/aux_/value_wknd.hpp \
  ./boost/mpl/aux_/config/integral.hpp ./boost/mpl/placeholders.hpp \
  ./boost/mpl/arg.hpp ./boost/mpl/arg_fwd.hpp \
  ./boost/mpl/aux_/na_assert.hpp ./boost/mpl/assert.hpp \
  ./boost/mpl/not.hpp ./boost/mpl/aux_/yes_no.hpp \
  ./boost/mpl/aux_/config/arrays.hpp ./boost/mpl/aux_/arity_spec.hpp \
  ./boost/mpl/aux_/arg_typedef.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/placeholders.hpp ./boost/mpl/and.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/and.hpp \
  ./boost/type_traits/is_same.hpp ./boost/type_traits/is_const.hpp \
  ./boost/type_traits/detail/cv_traits_impl.hpp \
  ./boost/type_traits/is_reference.hpp \
  ./boost/iterator/detail/enable_if.hpp ./boost/type_traits/add_const.hpp \
  ./boost/type_traits/add_pointer.hpp \
  ./boost/type_traits/remove_reference.hpp \
  ./boost/type_traits/broken_compiler_spec.hpp \
  ./boost/type_traits/remove_const.hpp \
  ./boost/type_traits/is_volatile.hpp \
  ./boost/type_traits/remove_reference.hpp ./boost/type_traits/is_pod.hpp \
  ./boost/type_traits/is_void.hpp ./boost/type_traits/is_scalar.hpp \
  ./boost/type_traits/is_enum.hpp ./boost/type_traits/is_function.hpp \
  ./boost/type_traits/detail/false_result.hpp \
  ./boost/type_traits/detail/is_function_ptr_helper.hpp \
  ./boost/type_traits/config.hpp ./boost/type_traits/is_class.hpp \
  ./boost/type_traits/is_union.hpp ./boost/type_traits/remove_cv.hpp \
  ./boost/type_traits/intrinsics.hpp ./boost/type_traits/is_union.hpp \
  ./boost/mpl/always.hpp ./boost/mpl/apply.hpp ./boost/mpl/apply_fwd.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  ./boost/mpl/apply_wrap.hpp ./boost/mpl/aux_/has_apply.hpp \
  ./boost/mpl/has_xxx.hpp ./boost/mpl/aux_/type_wrapper.hpp \
  ./boost/mpl/aux_/config/has_xxx.hpp \
  ./boost/mpl/aux_/config/msvc_typename.hpp \
  ./boost/mpl/aux_/config/has_apply.hpp \
  ./boost/mpl/aux_/msvc_never_true.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp ./boost/mpl/lambda.hpp \
  ./boost/mpl/bind.hpp ./boost/mpl/bind_fwd.hpp \
  ./boost/mpl/aux_/config/bind.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp ./boost/mpl/next.hpp \
  ./boost/mpl/next_prior.hpp ./boost/mpl/aux_/common_name_wknd.hpp \
  ./boost/mpl/protect.hpp ./boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  ./boost/mpl/aux_/full_lambda.hpp ./boost/mpl/quote.hpp \
  ./boost/mpl/void.hpp ./boost/mpl/aux_/has_type.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  ./boost/mpl/aux_/template_arity.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  ./boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  ./boost/config/abi_prefix.hpp ./boost/config/abi_suffix.hpp
test.o: test.cpp
