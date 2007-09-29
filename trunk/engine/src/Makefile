#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

BOOST = /usr/include
PERL = /usr/bin/perl
PUSHD = /usr/bin/pushd

CC = g++
IFLAGS = -I. -I$(BOOST)
LDLIBS = -lm 
OBJS = $(subst .cpp,.o,${SOURCES})
SOURCES = main.cpp Alphabet.cpp Assignment.cpp Cluster.cpp \
		DebugLog.cpp Feature.cpp \
		Parser.cpp \
		PrefixTreePreprocessor.cpp \
		PrefixTreeWalker.cpp  \
		RandomProjections.cpp \
		SeedSearcher.cpp Sequence.cpp \
		SequenceDB.cpp StdOptions.cpp pssm.cpp \
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
		status_reporter/BaseStatusReporter.cpp
		
MYSQL_LIB_DIR = /sw/lib/mysql

all:	unitester seed 

seed$(EXE): entry_point.o $(OBJS) status_reporter/DummyStatusReporter.o	
	$(CC)  $(CCFLAGS) -o seed $(OBJS) entry_point.o status_reporter/DummyStatusReporter.o -lboost_filesystem -lboost_regex
	
unitester$(EXE): core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o $(OBJS)
	$(CC) $(CCFLAGS) -o seed.test $(OBJS) core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o -lboost_filesystem -lboost_regex

seed_server$(EXE): main.o $(OBJS) status_reporter/StatusReporter.o
	$(CC) $(CCFLAGS) -L$(MYSQL_LIB_DIR) -lmysqlclient -o seed_server $(OBJS) main.o status_reporter/StatusReporter.o
	


test: 	seed$(EXE) unitester$(EXE)
	./seed.test
	$(PERL) -Itests/ -Itests/details tests/compare_prep.pl seed$(EXE)

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
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/Str.h core/Defs.h
Assignment.o: Assignment.cpp Assignment.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  Alphabet.h core/Str.h core/Defs.h persistance/TextWriter.h \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h persistance/Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h Assignment.h \
  core/Defs.h core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  core/Str.h core/Defs.h /usr/include/boost/shared_ptr.hpp \
  /usr/include/boost/assert.hpp /usr/include/assert.h \
  /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  persistance/OutputStream.h persistance/StdOutputStream.h \
  persistance/UnbufferedChannel.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/fstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/ImplList.h core/Defs.h persistance/TextWriter.h \
  legacy/MathFunctions.h legacy/mathplus.h ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/ImplList.h core/Defs.h persistance/TextWriter.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  LeafPreprocessor.h Preprocessor.h Defs.h \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SequenceDB.h Alphabet.h \
  core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  SeedHash.h DebugLog.h persistance/TextWriter.h \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  AssignmentFormat.h
Parser.o: Parser.cpp Parser.h Defs.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/Str.h core/Defs.h \
  core/Argv.h core/Str.h core/GetOptParser.h core/Defs.h core/STLHelper.h \
  core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Argv.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h /usr/include/boost/regex.hpp \
  /usr/include/boost/regex/config.hpp /usr/include/boost/regex/user.hpp \
  /usr/include/boost/regex/config/cwchar.hpp \
  /usr/include/boost/config/auto_link.hpp \
  /usr/include/boost/regex/v4/regex.hpp \
  /usr/include/boost/regex/v4/regex_workaround.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cassert \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/stdexcept \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  /usr/include/boost/limits.hpp /usr/include/boost/cstdint.hpp \
  /usr/include/boost/scoped_ptr.hpp /usr/include/boost/scoped_array.hpp \
  /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/regex_fwd.hpp \
  /usr/include/boost/regex/v4/regex_fwd.hpp \
  /usr/include/boost/regex/regex_traits.hpp \
  /usr/include/boost/regex/v4/regex_traits.hpp \
  /usr/include/boost/regex/v4/syntax_type.hpp \
  /usr/include/boost/regex/v4/error_type.hpp \
  /usr/include/boost/regex/v4/regex_traits_defaults.hpp \
  /usr/include/boost/regex/v4/cpp_regex_traits.hpp \
  /usr/include/boost/regex/pattern_except.hpp \
  /usr/include/boost/regex/pending/static_mutex.hpp \
  /usr/include/boost/regex/v4/primary_transform.hpp \
  /usr/include/boost/regex/pending/object_cache.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  /usr/include/boost/regex/v4/c_regex_traits.hpp \
  /usr/include/boost/mpl/has_xxx.hpp /usr/include/boost/mpl/bool.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/type_wrapper.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/yes_no.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/config/arrays.hpp \
  /usr/include/boost/mpl/aux_/config/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/mpl/aux_/config/msvc_typename.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/regex/v4/match_flags.hpp \
  /usr/include/boost/regex/v4/regex_raw_buffer.hpp \
  /usr/include/boost/regex/v4/char_regex_traits.hpp \
  /usr/include/boost/regex/v4/states.hpp \
  /usr/include/boost/regex/v4/regbase.hpp \
  /usr/include/boost/regex/v4/iterator_traits.hpp \
  /usr/include/boost/regex/v4/basic_regex.hpp \
  /usr/include/boost/regex/v4/basic_regex_creator.hpp \
  /usr/include/boost/regex/v4/basic_regex_parser.hpp \
  /usr/include/boost/regex/v4/sub_match.hpp \
  /usr/include/boost/regex/v4/regex_format.hpp \
  /usr/include/boost/regex/v4/match_results.hpp \
  /usr/include/boost/regex/v4/protected_call.hpp \
  /usr/include/boost/regex/v4/perl_matcher.hpp \
  /usr/include/boost/regex/v4/iterator_category.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/type_traits/is_pointer.hpp \
  /usr/include/boost/type_traits/is_member_pointer.hpp \
  /usr/include/boost/type_traits/is_member_function_pointer.hpp \
  /usr/include/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /usr/include/boost/regex/v4/perl_matcher_non_recursive.hpp \
  /usr/include/boost/regex/v4/perl_matcher_common.hpp \
  /usr/include/boost/regex/v4/instances.hpp \
  /usr/include/boost/regex/v4/regex_match.hpp \
  /usr/include/boost/regex/v4/regex_search.hpp \
  /usr/include/boost/regex/v4/regex_iterator.hpp \
  /usr/include/boost/regex/v4/regex_token_iterator.hpp \
  /usr/include/boost/regex/v4/regex_grep.hpp \
  /usr/include/boost/regex/v4/regex_replace.hpp \
  /usr/include/boost/regex/v4/regex_merge.hpp \
  /usr/include/boost/regex/v4/regex_split.hpp DebugLog.h \
  persistance/Defs.h core/Defs.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h Assignment.h \
  core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  persistance/IArchive.h persistance/Defs.h persistance/IRegistry.h \
  persistance/TextReader.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/TFactory.h persistance/Object.h \
  persistance/Error.h core/AutoPtr.h persistance/OArchive.h \
  persistance/ORegistry.h persistance/TextWriter.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  persistance/Defs.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h core/Defs.h core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  AssignmentFormat.h persistance/AbstractFormat.h persistance/Defs.h \
  core/AutoPtr.h core/Str.h core/Defs.h /usr/include/boost/shared_ptr.hpp \
  /usr/include/boost/assert.hpp /usr/include/assert.h \
  /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp ExtraMath.h \
  legacy/MathFunctions.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  legacy/mathplus.h legacy/mathplus.h legacy/RandomGenerator.h \
  legacy/Multinomial.h DebugLog.h persistance/TextWriter.h
Score.o: Score.cpp Score.h Defs.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SeqWeight.h Sequence.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  persistance/TextWriter.h legacy/mathplus.h /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp ScoreFunction.h Cluster.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  SequenceDB.h Alphabet.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  ExtraMath.h legacy/MathFunctions.h legacy/mathplus.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/Str.h core/Defs.h persistance/TextWriter.h Parser.h Defs.h \
  core/Defs.h /usr/include/boost/shared_ptr.hpp \
  /usr/include/boost/assert.hpp /usr/include/assert.h \
  /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/Str.h core/Argv.h \
  core/Str.h core/GetOptParser.h core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Argv.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  DebugLog.h persistance/Defs.h core/Defs.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h Assignment.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  Cluster.h Sequence.h Defs.h /usr/include/boost/shared_ptr.hpp \
  /usr/include/boost/assert.hpp /usr/include/assert.h \
  /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/Str.h core/Defs.h \
  SeqWeight.h core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  DebugLog.h persistance/TextWriter.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedPerformance.o: SeedPerformance.cpp
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  core/Defs.h core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/ImplList.h core/Defs.h persistance/TextWriter.h \
  PrefixTreePreprocessor.h SeedHash.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h /usr/include/boost/timer.hpp \
  /usr/include/boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp Parser.h core/Str.h \
  core/Defs.h core/Argv.h core/Str.h core/GetOptParser.h core/Defs.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Argv.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h Sequence.h \
  core/STLHelper.h Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h Preprocessor.h SequenceDB.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h PrefixTreePreprocessor.h \
  RandomProjections.h SeedConf.h core/ConfReader.h core/Str.h \
  persistance/TextWriter.h core/ImplList.h StdOptions.h FeatureSet.h \
  LeafPreprocessor.h SeedHash.h ExtraMath.h legacy/MathFunctions.h \
  legacy/mathplus.h ScoreFunction.h \
  status_reporter/BaseStatusReporter.hpp core/Defs.h core/Str.h \
  core/Argv.h /usr/include/boost/cast.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cassert \
  /usr/include/boost/type.hpp /usr/include/boost/limits.hpp \
  /usr/include/boost/detail/select_type.hpp \
  /usr/include/boost/numeric/conversion/cast.hpp \
  /usr/include/boost/numeric/conversion/converter.hpp \
  /usr/include/boost/numeric/conversion/conversion_traits.hpp \
  /usr/include/boost/numeric/conversion/detail/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_same.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/numeric/conversion/detail/meta.hpp \
  /usr/include/boost/mpl/if.hpp \
  /usr/include/boost/mpl/aux_/value_wknd.hpp \
  /usr/include/boost/mpl/aux_/config/integral.hpp \
  /usr/include/boost/mpl/eval_if.hpp /usr/include/boost/mpl/if.hpp \
  /usr/include/boost/mpl/equal_to.hpp \
  /usr/include/boost/mpl/aux_/comparison_op.hpp \
  /usr/include/boost/mpl/aux_/numeric_op.hpp \
  /usr/include/boost/mpl/numeric_cast.hpp \
  /usr/include/boost/mpl/apply_wrap.hpp \
  /usr/include/boost/mpl/aux_/has_apply.hpp \
  /usr/include/boost/mpl/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/type_wrapper.hpp \
  /usr/include/boost/mpl/aux_/yes_no.hpp \
  /usr/include/boost/mpl/aux_/config/arrays.hpp \
  /usr/include/boost/mpl/aux_/config/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/config/msvc_typename.hpp \
  /usr/include/boost/mpl/aux_/config/has_apply.hpp \
  /usr/include/boost/mpl/aux_/msvc_never_true.hpp \
  /usr/include/boost/mpl/aux_/config/use_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/include_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/config/compiler.hpp \
  /usr/include/boost/preprocessor/stringize.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /usr/include/boost/mpl/tag.hpp /usr/include/boost/mpl/eval_if.hpp \
  /usr/include/boost/mpl/void.hpp /usr/include/boost/mpl/aux_/has_tag.hpp \
  /usr/include/boost/mpl/aux_/numeric_cast_utils.hpp \
  /usr/include/boost/mpl/aux_/config/forwarding.hpp \
  /usr/include/boost/mpl/aux_/msvc_eti_base.hpp \
  /usr/include/boost/mpl/aux_/is_msvc_eti_arg.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/equal_to.hpp \
  /usr/include/boost/mpl/not.hpp \
  /usr/include/boost/mpl/aux_/nested_type_wknd.hpp \
  /usr/include/boost/mpl/and.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /usr/include/boost/numeric/conversion/detail/int_float_mixture.hpp \
  /usr/include/boost/numeric/conversion/int_float_mixture_enum.hpp \
  /usr/include/boost/numeric/conversion/detail/sign_mixture.hpp \
  /usr/include/boost/numeric/conversion/sign_mixture_enum.hpp \
  /usr/include/boost/numeric/conversion/detail/udt_builtin_mixture.hpp \
  /usr/include/boost/numeric/conversion/udt_builtin_mixture_enum.hpp \
  /usr/include/boost/numeric/conversion/detail/is_subranged.hpp \
  /usr/include/boost/mpl/multiplies.hpp /usr/include/boost/mpl/times.hpp \
  /usr/include/boost/mpl/aux_/arithmetic_op.hpp \
  /usr/include/boost/mpl/aux_/largest_int.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/times.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/default_params.hpp \
  /usr/include/boost/mpl/less.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/less.hpp \
  /usr/include/boost/numeric/conversion/converter_policies.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cmath \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cmath.tcc \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/numeric/conversion/detail/converter.hpp \
  /usr/include/boost/numeric/conversion/detail/conversion_traits.hpp \
  /usr/include/boost/numeric/conversion/bounds.hpp \
  /usr/include/boost/numeric/conversion/detail/bounds.hpp
SeqWeight.o: SeqWeight.cpp SeqWeight.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  SequenceDB.h Alphabet.h Cluster.h legacy/mathplus.h /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  core/FixedStr.h core/Str.h persistance/TextReader.h core/Defs.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/StdInputStream.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h persistance/OutputStream.h \
  /usr/include/boost/algorithm/string.hpp \
  /usr/include/boost/algorithm/string/std_containers_traits.hpp \
  /usr/include/boost/algorithm/string/std/string_traits.hpp \
  /usr/include/boost/algorithm/string/yes_no_type.hpp \
  /usr/include/boost/algorithm/string/sequence_traits.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/algorithm/string/std/list_traits.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  /usr/include/boost/algorithm/string/trim.hpp \
  /usr/include/boost/algorithm/string/config.hpp \
  /usr/include/boost/range/begin.hpp \
  /usr/include/boost/type_traits/remove_const.hpp \
  /usr/include/boost/type_traits/is_volatile.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/range/config.hpp \
  /usr/include/boost/range/iterator.hpp \
  /usr/include/boost/iterator/iterator_traits.hpp \
  /usr/include/boost/detail/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/range/const_iterator.hpp \
  /usr/include/boost/range/end.hpp \
  /usr/include/boost/range/detail/implementation_help.hpp \
  /usr/include/boost/range/detail/common.hpp \
  /usr/include/boost/range/detail/sfinae.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_void.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/mpl/if.hpp \
  /usr/include/boost/mpl/aux_/value_wknd.hpp \
  /usr/include/boost/mpl/aux_/config/integral.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/type_traits/is_same.hpp \
  /usr/include/boost/algorithm/string/detail/trim.hpp \
  /usr/include/boost/algorithm/string/classification.hpp \
  /usr/include/boost/range/value_type.hpp \
  /usr/include/boost/algorithm/string/detail/classification.hpp \
  /usr/include/boost/algorithm/string/predicate_facade.hpp \
  /usr/include/boost/algorithm/string/case_conv.hpp \
  /usr/include/boost/iterator/transform_iterator.hpp \
  /usr/include/boost/function.hpp \
  /usr/include/boost/preprocessor/iterate.hpp \
  /usr/include/boost/preprocessor/iteration/iterate.hpp \
  /usr/include/boost/preprocessor/array/elem.hpp \
  /usr/include/boost/preprocessor/array/data.hpp \
  /usr/include/boost/preprocessor/array/size.hpp \
  /usr/include/boost/preprocessor/slot/slot.hpp \
  /usr/include/boost/preprocessor/slot/detail/def.hpp \
  /usr/include/boost/function/detail/prologue.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cassert \
  /usr/include/boost/function/function_base.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/stdexcept \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/composite_traits.hpp \
  /usr/include/boost/type_traits/is_enum.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/type_traits/is_function.hpp \
  /usr/include/boost/type_traits/detail/false_result.hpp \
  /usr/include/boost/type_traits/detail/is_function_ptr_helper.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/is_member_pointer.hpp \
  /usr/include/boost/type_traits/is_member_function_pointer.hpp \
  /usr/include/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /usr/include/boost/type_traits/is_pointer.hpp \
  /usr/include/boost/type_traits/is_stateless.hpp \
  /usr/include/boost/type_traits/has_trivial_constructor.hpp \
  /usr/include/boost/type_traits/is_pod.hpp \
  /usr/include/boost/type_traits/is_scalar.hpp \
  /usr/include/boost/type_traits/has_trivial_copy.hpp \
  /usr/include/boost/type_traits/has_trivial_destructor.hpp \
  /usr/include/boost/type_traits/is_empty.hpp /usr/include/boost/ref.hpp \
  /usr/include/boost/utility/addressof.hpp \
  /usr/include/boost/pending/ct_if.hpp \
  /usr/include/boost/utility/enable_if.hpp \
  /usr/include/boost/function_equal.hpp /usr/include/boost/mem_fn.hpp \
  /usr/include/boost/get_pointer.hpp \
  /usr/include/boost/bind/mem_fn_template.hpp \
  /usr/include/boost/bind/mem_fn_cc.hpp \
  /usr/include/boost/preprocessor/enum.hpp \
  /usr/include/boost/preprocessor/repetition/enum.hpp \
  /usr/include/boost/preprocessor/tuple/rem.hpp \
  /usr/include/boost/preprocessor/enum_params.hpp \
  /usr/include/boost/preprocessor/repetition/enum_params.hpp \
  /usr/include/boost/preprocessor/iteration/detail/iter/forward1.hpp \
  /usr/include/boost/preprocessor/iteration/detail/bounds/lower1.hpp \
  /usr/include/boost/preprocessor/slot/detail/shared.hpp \
  /usr/include/boost/preprocessor/iteration/detail/bounds/upper1.hpp \
  /usr/include/boost/function/detail/function_iterate.hpp \
  /usr/include/boost/function/detail/maybe_include.hpp \
  /usr/include/boost/function/function_template.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/include/boost/iterator/detail/enable_if.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/iterator/detail/config_def.hpp \
  /usr/include/boost/iterator/detail/config_undef.hpp \
  /usr/include/boost/iterator/iterator_adaptor.hpp \
  /usr/include/boost/iterator/iterator_categories.hpp \
  /usr/include/boost/mpl/eval_if.hpp \
  /usr/include/boost/mpl/placeholders.hpp /usr/include/boost/mpl/arg.hpp \
  /usr/include/boost/mpl/arg_fwd.hpp \
  /usr/include/boost/mpl/aux_/na_assert.hpp \
  /usr/include/boost/mpl/assert.hpp /usr/include/boost/mpl/not.hpp \
  /usr/include/boost/mpl/aux_/nested_type_wknd.hpp \
  /usr/include/boost/mpl/aux_/yes_no.hpp \
  /usr/include/boost/mpl/aux_/config/arrays.hpp \
  /usr/include/boost/mpl/aux_/arity_spec.hpp \
  /usr/include/boost/mpl/aux_/arg_typedef.hpp \
  /usr/include/boost/mpl/aux_/config/use_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/include_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/config/compiler.hpp \
  /usr/include/boost/preprocessor/stringize.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/iterator/iterator_facade.hpp \
  /usr/include/boost/iterator/interoperable.hpp \
  /usr/include/boost/mpl/or.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  /usr/include/boost/iterator/detail/facade_iterator_category.hpp \
  /usr/include/boost/mpl/and.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /usr/include/boost/type_traits/is_const.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/detail/indirect_traits.hpp \
  /usr/include/boost/type_traits/is_pointer.hpp \
  /usr/include/boost/type_traits/is_volatile.hpp \
  /usr/include/boost/type_traits/is_member_function_pointer.hpp \
  /usr/include/boost/type_traits/is_member_pointer.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/remove_reference.hpp \
  /usr/include/boost/type_traits/remove_pointer.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/implicit_cast.hpp \
  /usr/include/boost/type_traits/add_const.hpp \
  /usr/include/boost/type_traits/add_pointer.hpp \
  /usr/include/boost/type_traits/is_pod.hpp \
  /usr/include/boost/mpl/always.hpp /usr/include/boost/mpl/apply.hpp \
  /usr/include/boost/mpl/apply_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  /usr/include/boost/mpl/apply_wrap.hpp \
  /usr/include/boost/mpl/aux_/has_apply.hpp \
  /usr/include/boost/mpl/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/type_wrapper.hpp \
  /usr/include/boost/mpl/aux_/config/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/config/msvc_typename.hpp \
  /usr/include/boost/mpl/aux_/config/has_apply.hpp \
  /usr/include/boost/mpl/aux_/msvc_never_true.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /usr/include/boost/mpl/lambda.hpp /usr/include/boost/mpl/bind.hpp \
  /usr/include/boost/mpl/bind_fwd.hpp \
  /usr/include/boost/mpl/aux_/config/bind.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  /usr/include/boost/mpl/next.hpp /usr/include/boost/mpl/next_prior.hpp \
  /usr/include/boost/mpl/aux_/common_name_wknd.hpp \
  /usr/include/boost/mpl/protect.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  /usr/include/boost/mpl/aux_/full_lambda.hpp \
  /usr/include/boost/mpl/quote.hpp /usr/include/boost/mpl/void.hpp \
  /usr/include/boost/mpl/aux_/has_type.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  /usr/include/boost/mpl/aux_/template_arity.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  /usr/include/boost/type_traits/function_traits.hpp \
  /usr/include/boost/algorithm/string/detail/case_conv.hpp \
  /usr/include/boost/algorithm/string/predicate.hpp \
  /usr/include/boost/algorithm/string/compare.hpp \
  /usr/include/boost/algorithm/string/find.hpp \
  /usr/include/boost/range/iterator_range.hpp \
  /usr/include/boost/range/functions.hpp \
  /usr/include/boost/range/size.hpp \
  /usr/include/boost/range/size_type.hpp \
  /usr/include/boost/range/empty.hpp /usr/include/boost/range/rbegin.hpp \
  /usr/include/boost/range/reverse_result_iterator.hpp \
  /usr/include/boost/range/result_iterator.hpp \
  /usr/include/boost/iterator/reverse_iterator.hpp \
  /usr/include/boost/utility.hpp \
  /usr/include/boost/utility/base_from_member.hpp \
  /usr/include/boost/preprocessor/repetition/enum_binary_params.hpp \
  /usr/include/boost/preprocessor/repetition/repeat_from_to.hpp \
  /usr/include/boost/utility/enable_if.hpp \
  /usr/include/boost/next_prior.hpp /usr/include/boost/noncopyable.hpp \
  /usr/include/boost/range/reverse_iterator.hpp \
  /usr/include/boost/range/const_reverse_iterator.hpp \
  /usr/include/boost/range/rend.hpp \
  /usr/include/boost/range/difference_type.hpp \
  /usr/include/boost/algorithm/string/finder.hpp \
  /usr/include/boost/algorithm/string/constants.hpp \
  /usr/include/boost/algorithm/string/detail/finder.hpp \
  /usr/include/boost/algorithm/string/detail/predicate.hpp \
  /usr/include/boost/algorithm/string/split.hpp \
  /usr/include/boost/algorithm/string/iter_find.hpp \
  /usr/include/boost/algorithm/string/concept.hpp \
  /usr/include/boost/concept_check.hpp \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/algorithm/string/find_iterator.hpp \
  /usr/include/boost/algorithm/string/detail/find_iterator.hpp \
  /usr/include/boost/algorithm/string/detail/util.hpp \
  /usr/include/boost/algorithm/string/replace.hpp \
  /usr/include/boost/algorithm/string/find_format.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/deque \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_deque.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/deque.tcc \
  /usr/include/boost/algorithm/string/detail/find_format.hpp \
  /usr/include/boost/algorithm/string/detail/find_format_store.hpp \
  /usr/include/boost/algorithm/string/detail/replace_storage.hpp \
  /usr/include/boost/algorithm/string/detail/sequence.hpp \
  /usr/include/boost/mpl/logical.hpp \
  /usr/include/boost/algorithm/string/detail/find_format_all.hpp \
  /usr/include/boost/algorithm/string/formatter.hpp \
  /usr/include/boost/algorithm/string/detail/formatter.hpp \
  /usr/include/boost/algorithm/string/erase.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/fstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/fstream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/sstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/sstream.tcc
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h persistance/OArchive.h persistance/Defs.h \
  core/Defs.h persistance/ORegistry.h persistance/Object.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  persistance/TFactory.h persistance/Error.h persistance/TextWriter.h \
  core/AutoPtr.h persistance/IArchive.h persistance/IRegistry.h \
  persistance/TextReader.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/STLPersist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  Sequence.h Defs.h /usr/include/boost/shared_ptr.hpp \
  /usr/include/boost/assert.hpp /usr/include/assert.h \
  /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SequenceDB.h Alphabet.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/fstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/fstream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/sstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/sstream.tcc \
  core/FixedStr.h core/Str.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SequenceDB.h core/STLHelper.h \
  core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  DebugLog.h persistance/TextWriter.h Preprocessor.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/ImplList.h core/Defs.h persistance/TextWriter.h \
  PrefixTreePreprocessor.h FeatureSet.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/fstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/fstream.tcc \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h
entry_point.o: entry_point.cpp \
  /usr/include/boost/test/included/prg_exec_monitor.hpp \
  /usr/include/boost/test/impl/execution_monitor.ipp \
  /usr/include/boost/test/detail/config.hpp /usr/include/boost/config.hpp \
  /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/boost/detail/workaround.hpp \
  /usr/include/boost/test/detail/workaround.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/test/detail/suppress_warnings.hpp \
  /usr/include/boost/test/detail/enable_warnings.hpp \
  /usr/include/boost/test/execution_monitor.hpp \
  /usr/include/boost/test/detail/global_typedef.hpp \
  /usr/include/boost/test/utils/basic_cstring/basic_cstring.hpp \
  /usr/include/boost/test/utils/basic_cstring/basic_cstring_fwd.hpp \
  /usr/include/boost/test/utils/basic_cstring/bcs_char_traits.hpp \
  /usr/include/boost/type_traits/add_const.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/test/detail/fwd_decl.hpp \
  /usr/include/boost/test/utils/callback.hpp \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/scoped_ptr.hpp /usr/include/boost/type.hpp \
  /usr/include/boost/cstdlib.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/stdexcept \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cassert \
  /usr/include/bits/signum.h /usr/include/bits/siginfo.h \
  /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
  /usr/include/asm/sigcontext.h /usr/include/asm-i386/sigcontext.h \
  /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
  /usr/include/bits/sigthread.h /usr/include/setjmp.h \
  /usr/include/boost/test/impl/cpp_main.ipp \
  /usr/include/boost/test/utils/basic_cstring/io.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp Cluster.h Sequence.h \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/set \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_set.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multiset.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/list \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_list.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/list.tcc \
  Score.h /usr/include/boost/concept_check.hpp \
  /usr/include/boost/iterator.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iterator \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stream_iterator.h \
  /usr/include/boost/type_traits/conversion_traits.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_array.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_def.hpp \
  /usr/include/boost/type_traits/detail/template_arity_spec.hpp \
  /usr/include/boost/mpl/int.hpp /usr/include/boost/mpl/int_fwd.hpp \
  /usr/include/boost/mpl/aux_/adl_barrier.hpp \
  /usr/include/boost/mpl/aux_/config/adl.hpp \
  /usr/include/boost/mpl/aux_/config/msvc.hpp \
  /usr/include/boost/mpl/aux_/config/intel.hpp \
  /usr/include/boost/mpl/aux_/config/gcc.hpp \
  /usr/include/boost/mpl/aux_/config/workaround.hpp \
  /usr/include/boost/mpl/aux_/nttp_decl.hpp \
  /usr/include/boost/mpl/aux_/config/nttp.hpp \
  /usr/include/boost/mpl/aux_/integral_wrapper.hpp \
  /usr/include/boost/mpl/integral_c_tag.hpp \
  /usr/include/boost/mpl/aux_/config/static_constant.hpp \
  /usr/include/boost/mpl/aux_/static_cast.hpp \
  /usr/include/boost/preprocessor/cat.hpp \
  /usr/include/boost/preprocessor/config/config.hpp \
  /usr/include/boost/mpl/aux_/template_arity_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/params.hpp \
  /usr/include/boost/mpl/aux_/config/preprocessor.hpp \
  /usr/include/boost/preprocessor/comma_if.hpp \
  /usr/include/boost/preprocessor/punctuation/comma_if.hpp \
  /usr/include/boost/preprocessor/control/if.hpp \
  /usr/include/boost/preprocessor/control/iif.hpp \
  /usr/include/boost/preprocessor/logical/bool.hpp \
  /usr/include/boost/preprocessor/facilities/empty.hpp \
  /usr/include/boost/preprocessor/punctuation/comma.hpp \
  /usr/include/boost/preprocessor/repeat.hpp \
  /usr/include/boost/preprocessor/repetition/repeat.hpp \
  /usr/include/boost/preprocessor/debug/error.hpp \
  /usr/include/boost/preprocessor/detail/auto_rec.hpp \
  /usr/include/boost/preprocessor/tuple/eat.hpp \
  /usr/include/boost/preprocessor/inc.hpp \
  /usr/include/boost/preprocessor/arithmetic/inc.hpp \
  /usr/include/boost/mpl/aux_/config/lambda.hpp \
  /usr/include/boost/mpl/aux_/config/ttp.hpp \
  /usr/include/boost/mpl/aux_/config/ctps.hpp \
  /usr/include/boost/mpl/aux_/config/overload_resolution.hpp \
  /usr/include/boost/type_traits/integral_constant.hpp \
  /usr/include/boost/mpl/bool.hpp /usr/include/boost/mpl/bool_fwd.hpp \
  /usr/include/boost/mpl/integral_c.hpp \
  /usr/include/boost/mpl/integral_c_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_support.hpp \
  /usr/include/boost/type_traits/detail/bool_trait_undef.hpp \
  /usr/include/boost/type_traits/add_reference.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/type_traits/detail/type_trait_def.hpp \
  /usr/include/boost/type_traits/detail/type_trait_undef.hpp \
  /usr/include/boost/type_traits/ice.hpp \
  /usr/include/boost/type_traits/detail/ice_or.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/type_traits/detail/ice_not.hpp \
  /usr/include/boost/type_traits/detail/ice_eq.hpp \
  /usr/include/boost/type_traits/is_arithmetic.hpp \
  /usr/include/boost/type_traits/is_integral.hpp \
  /usr/include/boost/type_traits/is_float.hpp \
  /usr/include/boost/type_traits/is_abstract.hpp \
  /usr/include/boost/static_assert.hpp \
  /usr/include/boost/type_traits/detail/yes_no_type.hpp \
  /usr/include/boost/type_traits/is_class.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/broken_compiler_spec.hpp \
  /usr/include/boost/type_traits/detail/cv_traits_impl.hpp \
  /usr/include/boost/type_traits/intrinsics.hpp \
  /usr/include/boost/mpl/identity.hpp \
  /usr/include/boost/mpl/aux_/na_spec.hpp \
  /usr/include/boost/mpl/lambda_fwd.hpp \
  /usr/include/boost/mpl/void_fwd.hpp /usr/include/boost/mpl/aux_/na.hpp \
  /usr/include/boost/mpl/aux_/na_fwd.hpp \
  /usr/include/boost/mpl/aux_/lambda_arity_param.hpp \
  /usr/include/boost/mpl/aux_/arity.hpp \
  /usr/include/boost/mpl/aux_/config/dtp.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/enum.hpp \
  /usr/include/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /usr/include/boost/mpl/limits/arity.hpp \
  /usr/include/boost/preprocessor/logical/and.hpp \
  /usr/include/boost/preprocessor/logical/bitand.hpp \
  /usr/include/boost/preprocessor/identity.hpp \
  /usr/include/boost/preprocessor/facilities/identity.hpp \
  /usr/include/boost/preprocessor/empty.hpp \
  /usr/include/boost/preprocessor/arithmetic/add.hpp \
  /usr/include/boost/preprocessor/arithmetic/dec.hpp \
  /usr/include/boost/preprocessor/control/while.hpp \
  /usr/include/boost/preprocessor/list/fold_left.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_left.hpp \
  /usr/include/boost/preprocessor/control/expr_iif.hpp \
  /usr/include/boost/preprocessor/list/adt.hpp \
  /usr/include/boost/preprocessor/detail/is_binary.hpp \
  /usr/include/boost/preprocessor/detail/check.hpp \
  /usr/include/boost/preprocessor/logical/compl.hpp \
  /usr/include/boost/preprocessor/list/fold_right.hpp \
  /usr/include/boost/preprocessor/list/detail/fold_right.hpp \
  /usr/include/boost/preprocessor/list/reverse.hpp \
  /usr/include/boost/preprocessor/control/detail/while.hpp \
  /usr/include/boost/preprocessor/tuple/elem.hpp \
  /usr/include/boost/preprocessor/arithmetic/sub.hpp \
  /usr/include/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/ImplList.h core/Defs.h persistance/TextWriter.h Parser.h \
  core/Argv.h core/GetOptParser.h core/Argv.h \
  persistance/TextTableReport.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/fstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/fstream.tcc \
  RandomProjections.h SeedSearcher.h PrefixTreePreprocessor.h \
  SeedSearcherMain.h SeedConf.h core/ConfReader.h core/Str.h \
  persistance/TextWriter.h core/ImplList.h StdOptions.h FeatureSet.h \
  persistance/StdInputStream.h persistance/StrOutputStream.h \
  persistance/xmlwriter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/stack \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/deque \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_deque.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/deque.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_stack.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/sstream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/sstream.tcc \
  status_reporter/BaseStatusReporter.hpp core/Defs.h core/Str.h \
  core/Argv.h /usr/include/boost/filesystem/path.hpp \
  /usr/include/boost/filesystem/config.hpp \
  /usr/include/boost/config/auto_link.hpp \
  /usr/include/boost/iterator/iterator_facade.hpp \
  /usr/include/boost/iterator/interoperable.hpp \
  /usr/include/boost/mpl/or.hpp \
  /usr/include/boost/mpl/aux_/config/use_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/nested_type_wknd.hpp \
  /usr/include/boost/mpl/aux_/include_preprocessed.hpp \
  /usr/include/boost/mpl/aux_/config/compiler.hpp \
  /usr/include/boost/preprocessor/stringize.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  /usr/include/boost/type_traits/is_convertible.hpp \
  /usr/include/boost/iterator/detail/config_def.hpp \
  /usr/include/boost/iterator/detail/config_undef.hpp \
  /usr/include/boost/iterator/iterator_traits.hpp \
  /usr/include/boost/detail/iterator.hpp \
  /usr/include/boost/iterator/detail/facade_iterator_category.hpp \
  /usr/include/boost/iterator/iterator_categories.hpp \
  /usr/include/boost/mpl/eval_if.hpp /usr/include/boost/mpl/if.hpp \
  /usr/include/boost/mpl/aux_/value_wknd.hpp \
  /usr/include/boost/mpl/aux_/config/integral.hpp \
  /usr/include/boost/mpl/placeholders.hpp /usr/include/boost/mpl/arg.hpp \
  /usr/include/boost/mpl/arg_fwd.hpp \
  /usr/include/boost/mpl/aux_/na_assert.hpp \
  /usr/include/boost/mpl/assert.hpp /usr/include/boost/mpl/not.hpp \
  /usr/include/boost/mpl/aux_/yes_no.hpp \
  /usr/include/boost/mpl/aux_/config/arrays.hpp \
  /usr/include/boost/mpl/aux_/arity_spec.hpp \
  /usr/include/boost/mpl/aux_/arg_typedef.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  /usr/include/boost/mpl/and.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /usr/include/boost/type_traits/is_same.hpp \
  /usr/include/boost/type_traits/is_const.hpp \
  /usr/include/boost/type_traits/is_reference.hpp \
  /usr/include/boost/detail/indirect_traits.hpp \
  /usr/include/boost/type_traits/is_function.hpp \
  /usr/include/boost/type_traits/detail/false_result.hpp \
  /usr/include/boost/type_traits/detail/is_function_ptr_helper.hpp \
  /usr/include/boost/type_traits/config.hpp \
  /usr/include/boost/type_traits/is_pointer.hpp \
  /usr/include/boost/type_traits/is_member_pointer.hpp \
  /usr/include/boost/type_traits/is_member_function_pointer.hpp \
  /usr/include/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /usr/include/boost/type_traits/is_volatile.hpp \
  /usr/include/boost/type_traits/is_member_function_pointer.hpp \
  /usr/include/boost/type_traits/is_member_pointer.hpp \
  /usr/include/boost/type_traits/remove_cv.hpp \
  /usr/include/boost/type_traits/remove_reference.hpp \
  /usr/include/boost/type_traits/remove_pointer.hpp \
  /usr/include/boost/type_traits/detail/ice_and.hpp \
  /usr/include/boost/iterator/detail/enable_if.hpp \
  /usr/include/boost/implicit_cast.hpp \
  /usr/include/boost/type_traits/add_const.hpp \
  /usr/include/boost/type_traits/add_pointer.hpp \
  /usr/include/boost/type_traits/remove_const.hpp \
  /usr/include/boost/type_traits/is_pod.hpp \
  /usr/include/boost/type_traits/is_void.hpp \
  /usr/include/boost/type_traits/is_scalar.hpp \
  /usr/include/boost/type_traits/is_enum.hpp \
  /usr/include/boost/type_traits/is_union.hpp \
  /usr/include/boost/mpl/always.hpp /usr/include/boost/mpl/apply.hpp \
  /usr/include/boost/mpl/apply_fwd.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  /usr/include/boost/mpl/apply_wrap.hpp \
  /usr/include/boost/mpl/aux_/has_apply.hpp \
  /usr/include/boost/mpl/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/type_wrapper.hpp \
  /usr/include/boost/mpl/aux_/config/has_xxx.hpp \
  /usr/include/boost/mpl/aux_/config/msvc_typename.hpp \
  /usr/include/boost/mpl/aux_/config/has_apply.hpp \
  /usr/include/boost/mpl/aux_/msvc_never_true.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /usr/include/boost/mpl/lambda.hpp /usr/include/boost/mpl/bind.hpp \
  /usr/include/boost/mpl/bind_fwd.hpp \
  /usr/include/boost/mpl/aux_/config/bind.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  /usr/include/boost/mpl/next.hpp /usr/include/boost/mpl/next_prior.hpp \
  /usr/include/boost/mpl/aux_/common_name_wknd.hpp \
  /usr/include/boost/mpl/protect.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  /usr/include/boost/mpl/aux_/full_lambda.hpp \
  /usr/include/boost/mpl/quote.hpp /usr/include/boost/mpl/void.hpp \
  /usr/include/boost/mpl/aux_/has_type.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  /usr/include/boost/mpl/aux_/template_arity.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  /usr/include/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cassert \
  /usr/include/boost/config/abi_prefix.hpp \
  /usr/include/boost/config/abi_suffix.hpp \
  /usr/include/boost/filesystem/convenience.hpp \
  /usr/include/boost/filesystem/operations.hpp \
  /usr/include/boost/cstdint.hpp
pssm.o: pssm.cpp pssm.h Assignment.h core/Defs.h core/Compiler.h \
  /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp \
  /usr/include/boost/config/select_compiler_config.hpp \
  /usr/include/boost/config/compiler/gcc.hpp \
  /usr/include/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/utility \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_relops.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_pair.h \
  /usr/include/boost/config/stdlib/libstdcpp3.hpp \
  /usr/include/boost/config/select_platform_config.hpp \
  /usr/include/boost/config/platform/linux.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdlib \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h /usr/include/boost/config/suffix.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/string \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stringfwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/char_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstring \
  /usr/include/string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algobase.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iosfwd \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cstdio \
  /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/postypes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwchar \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/functexcept.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception_defines.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/concept_check.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/debug/debug.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/memory \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ext/new_allocator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/new \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/exception \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_construct.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/limits \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_function.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/atomicity.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/algorithm \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_algo.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_heap.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_string.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/iostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ostream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/ios \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/localefwd.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ios_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_classes.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/streambuf \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/codecvt.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/i486-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/ostream.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/locale \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/typeinfo \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/istream \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/istream.tcc \
  core/STLHelper.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/vector \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_vector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_bvector.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/vector.tcc \
  persistance/Defs.h core/Defs.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bitset \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Defs.h \
  /usr/include/boost/shared_ptr.hpp /usr/include/boost/assert.hpp \
  /usr/include/assert.h /usr/include/boost/checked_delete.hpp \
  /usr/include/boost/throw_exception.hpp \
  /usr/include/boost/detail/shared_count.hpp \
  /usr/include/boost/detail/bad_weak_ptr.hpp \
  /usr/include/boost/detail/sp_counted_base.hpp \
  /usr/include/boost/detail/sp_counted_base_gcc_x86.hpp \
  /usr/include/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/functional \
  /usr/include/boost/detail/workaround.hpp SeqWeight.h core/HashTable.h \
  core/Str.h core/AutoPtr.h core/STLHelper.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/map \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_tree.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_map.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/../../../../include/c++/4.1.2/bits/stl_multimap.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
