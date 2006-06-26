#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

BOOST = D:/Aviad/Dev/boost_1_33_1
PERL = /usr/bin/perl
PUSHD = /usr/bin/pushd

CC = g++
IFLAGS = -I.  -I$(BOOST)
LDLIBS = -lm 	
OBJS = $(subst .cpp,.o,${SOURCES})
SOURCES = main.cpp Alphabet.cpp Assignment.cpp Cluster.cpp \
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
		$(BOOST)/libs/filesystem/src/operations_posix_windows.cpp		\
		$(BOOST)/libs/filesystem/src/path_posix_windows.cpp			\
		$(BOOST)/libs/filesystem/src/convenience.cpp				\
		$(BOOST)/libs/filesystem/src/exception.cpp				\
		$(BOOST)/libs/regex/src/c_regex_traits.cpp				\
		$(BOOST)/libs/regex/src/cpp_regex_traits.cpp				\
		$(BOOST)/libs/regex/src/cregex.cpp					\
		$(BOOST)/libs/regex/src/fileiter.cpp					\
		$(BOOST)/libs/regex/src/instances.cpp					\
		$(BOOST)/libs/regex/src/posix_api.cpp					\
		$(BOOST)/libs/regex/src/regex.cpp					\
		$(BOOST)/libs/regex/src/w32_regex_traits.cpp				\
		$(BOOST)/libs/regex/src/wide_posix_api.cpp				\
		$(BOOST)/libs/regex/src/winstances.cpp					\
		$(BOOST)/libs/regex/src/static_mutex.cpp				\
		$(BOOST)/libs/regex/src/regex_traits_defaults.cpp			\
		$(BOOST)/libs/regex/src/regex_raw_buffer.cpp				\
		$(BOOST)/libs/regex/src/instances.cpp

		
MYSQL_LIB_DIR = /sw/lib/mysql

all:	unitester seed 

seed$(EXE): entry_point.o $(OBJS) status_reporter/DummyStatusReporter.o	
	$(CC) $(CCFLAGS) -o seed $(OBJS) entry_point.o status_reporter/DummyStatusReporter.o
	
unitester$(EXE): core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o $(OBJS)
	$(CC) $(CCFLAGS) -o seed.test $(OBJS) core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o

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
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  ./core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  core/Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h persistance/OutputStream.h \
  persistance/StdOutputStream.h persistance/UnbufferedChannel.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  legacy/MathFunctions.h legacy/MathPlus.h ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  Preprocessor.h Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp SequenceDB.h \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/Str.h \
  core/Defs.h core/Argv.h core/Str.h core/GetOptParser.h ./core/Defs.h \
  ./core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ./core/Argv.h ./persistance/TextTableReport.h ./core/Str.h \
  ./core/FixedStr.h ./core/Str.h ./core/AutoPtr.h ./core/ImplList.h \
  ./core/STLHelper.h ./persistance/TextWriter.h persistance/TextWriter.h \
  /usr/include/math.h D:/Aviad/Dev/boost_1_33_1/boost/regex.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/auto_link.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_workaround.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stdexcept \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  D:/Aviad/Dev/boost_1_33_1/boost/limits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/cstdint.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/scoped_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/scoped_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/regex_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/syntax_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/error_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_traits_defaults.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/cpp_regex_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/pattern_except.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/pending/static_mutex.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/primary_transform.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/pending/object_cache.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/c_regex_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/type_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/yes_no.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/arrays.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc_typename.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/match_flags.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_raw_buffer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/char_regex_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/states.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regbase.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/iterator_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/basic_regex.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/basic_regex_creator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/basic_regex_parser.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/sub_match.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_format.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/match_results.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/protected_call.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/perl_matcher.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/iterator_category.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_function_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/perl_matcher_non_recursive.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/perl_matcher_common.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/instances.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_match.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_search.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_token_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_grep.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_replace.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_merge.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/regex/v4/regex_split.hpp DebugLog.h \
  persistance/Defs.h ./core/Defs.h persistance/AbstractFormat.h \
  ./persistance/Defs.h ./core/AutoPtr.h AssignmentFormat.h Assignment.h \
  core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
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
  persistance/IArchive.h persistance/Defs.h persistance/IRegistry.h \
  persistance/TextReader.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/TFactory.h persistance/Object.h \
  persistance/Error.h ./core/AutoPtr.h persistance/OArchive.h \
  persistance/ORegistry.h persistance/TextWriter.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  ./persistance/Defs.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
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
  Assignment.h core/Defs.h core/Compiler.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  core/Str.h core/Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp ExtraMath.h \
  legacy/MathFunctions.h /usr/include/math.h legacy/MathPlus.h \
  legacy/MathPlus.h legacy/RandomGenerator.h legacy/Multinomial.h \
  DebugLog.h persistance/TextWriter.h
Score.o: Score.cpp Score.h Defs.h core/Defs.h core/Compiler.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp SeqWeight.h \
  Sequence.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_map.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multimap.h \
  persistance/TextWriter.h legacy/MathPlus.h /usr/include/math.h \
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp ScoreFunction.h \
  Cluster.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  SequenceDB.h Alphabet.h Assignment.h persistance/Defs.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bitset ExtraMath.h \
  legacy/MathFunctions.h legacy/MathPlus.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h ./core/Defs.h \
  ./core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  core/Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/Str.h \
  core/Argv.h core/Str.h core/GetOptParser.h ./core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
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
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  Sequence.h Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/Str.h \
  core/Defs.h SeqWeight.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
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
  core/Defs.h core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h SeedHash.h persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h D:/Aviad/Dev/boost_1_33_1/boost/timer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp Parser.h \
  core/Str.h core/Defs.h core/Argv.h core/Str.h core/GetOptParser.h \
  ./core/Defs.h ./core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ./core/Argv.h ./persistance/TextTableReport.h ./core/Str.h \
  ./core/FixedStr.h ./core/Str.h ./core/AutoPtr.h ./core/ImplList.h \
  ./core/STLHelper.h ./persistance/TextWriter.h persistance/TextWriter.h \
  Sequence.h core/STLHelper.h Cluster.h SeqWeight.h core/HashTable.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h PrefixTreePreprocessor.h \
  RandomProjections.h SeedConf.h core/ConfReader.h ./core/Str.h \
  ./persistance/TextWriter.h core/ImplList.h StdOptions.h FeatureSet.h \
  LeafPreprocessor.h SeedHash.h ExtraMath.h legacy/MathFunctions.h \
  legacy/MathPlus.h status_reporter/BaseStatusReporter.hpp ./core/Defs.h \
  ./core/Str.h ./core/Argv.h D:/Aviad/Dev/boost_1_33_1/boost/cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/limits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/select_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/converter.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_same.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/meta.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/value_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/eval_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/equal_to.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/comparison_op.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/numeric_op.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/numeric_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/type_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/yes_no.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/arrays.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc_typename.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/msvc_never_true.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/include_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/compiler.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/stringize.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/eval_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/numeric_cast_utils.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/forwarding.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/msvc_eti_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/is_msvc_eti_arg.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/equal_to.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nested_type_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/int_float_mixture.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/int_float_mixture_enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/sign_mixture.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/sign_mixture_enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/udt_builtin_mixture.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/udt_builtin_mixture_enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/is_subranged.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/multiplies.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/times.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arithmetic_op.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/largest_int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/times.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/default_params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/less.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/less.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/converter_policies.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cmath \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cmath.tcc \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/converter.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/bounds.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/numeric/conversion/detail/bounds.hpp
SeqWeight.o: SeqWeight.cpp SeqWeight.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h core/HashTable.h core/Str.h core/AutoPtr.h \
  ./core/STLHelper.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/map \
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
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/std_containers_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/std/string_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/sequence_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/std/list_traits.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/trim.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/begin.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_volatile.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/range/const_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/end.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/detail/implementation_help.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/detail/common.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/detail/sfinae.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_void.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/value_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_same.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/trim.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/classification.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/value_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/classification.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/predicate_facade.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/case_conv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/transform_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/iterate.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/iteration/iterate.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/array/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/array/data.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/array/size.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/slot/slot.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/slot/detail/def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function/detail/prologue.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function/function_base.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stdexcept \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/composite_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_function.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/false_result.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/is_function_ptr_helper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_function_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_stateless.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/has_trivial_constructor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pod.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_scalar.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/has_trivial_copy.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/has_trivial_destructor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/ref.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/utility/addressof.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/pending/ct_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/utility/enable_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function_equal.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mem_fn.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/get_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/bind/mem_fn_template.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/bind/mem_fn_cc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/rem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/enum_params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/enum_params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/iteration/detail/iter/forward1.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/iteration/detail/bounds/lower1.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/slot/detail/shared.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/iteration/detail/bounds/upper1.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function/detail/function_iterate.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function/detail/maybe_include.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/function/function_template.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/enable_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/config_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/config_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_adaptor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_categories.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/eval_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/placeholders.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/arg.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/arg_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nested_type_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/yes_no.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/arrays.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arg_typedef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/include_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/compiler.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/stringize.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_facade.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/interoperable.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/facade_iterator_category.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/indirect_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_volatile.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_function_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/implicit_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pod.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/always.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/type_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc_typename.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/msvc_never_true.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bind_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/next.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/next_prior.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/common_name_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/protect.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/full_lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/quote.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/function_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/case_conv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/predicate.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/compare.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/find.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/iterator_range.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/functions.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/size.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/size_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/rbegin.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/reverse_result_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/result_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/reverse_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/utility.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/utility/base_from_member.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/enum_binary_params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat_from_to.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/utility/enable_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/next_prior.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/noncopyable.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/reverse_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/const_reverse_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/rend.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/range/difference_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/finder.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/constants.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/finder.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/predicate.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/split.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/iter_find.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/concept.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/find_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/find_iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/util.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/replace.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/find_format.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/deque \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_deque.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/deque.tcc \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/find_format.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/find_format_store.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/replace_storage.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/sequence.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/logical.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/find_format_all.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/formatter.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/detail/formatter.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/algorithm/string/erase.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
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
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  Sequence.h Defs.h D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp core/STLHelper.h \
  ./core/Defs.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SequenceDB.h Alphabet.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
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
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  core/FixedStr.h ./core/Str.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h ./core/STLHelper.h \
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
  PSSM.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/list \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_list.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/list.tcc Score.h \
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
  persistance/TextTableReport.h ./core/Str.h ./core/FixedStr.h \
  ./core/Str.h ./core/ImplList.h ./core/Defs.h ./persistance/TextWriter.h \
  PrefixTreePreprocessor.h FeatureSet.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/user.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_compiler_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/compiler/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_stdlib_config.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/utility \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_relops.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/stdlib/libstdcpp3.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/select_platform_config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/platform/cygwin.hpp \
  /usr/include/unistd.h /usr/include/sys/unistd.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/cygwin/config.h \
  /usr/include/sys/types.h /usr/include/machine/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/machine/types.h /usr/include/sys/features.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/getopt.h \
  D:/Aviad/Dev/boost_1_33_1/boost/config/posix_features.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/suffix.hpp \
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
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
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
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/shared_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/checked_delete.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/throw_exception.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/shared_count.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/bad_weak_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/sp_counted_impl.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h ./core/Defs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  core/Str.h core/Defs.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h ./core/STLHelper.h \
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
  D:/Aviad/Dev/boost_1_33_1/boost/concept_check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iterator \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stream_iterator.h \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/conversion_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_array.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/template_arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/int_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/adl_barrier.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/adl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/intel.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/gcc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nttp_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/nttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/integral_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_tag.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/static_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/static_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/cat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/config/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/params.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/preprocessor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/punctuation/comma.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/repetition/repeat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/debug/error.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/auto_rec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/eat.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/inc.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ttp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/ctps.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/overload_resolution.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/integral_constant.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bool_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/integral_c_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_support.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/bool_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/type_trait_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/ice.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_eq.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_arithmetic.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_float.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_abstract.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/static_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/yes_no_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_class.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/broken_compiler_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/cv_traits_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/intrinsics.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/lambda_arity_param.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/dtp.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/limits/arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/bitand.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/facilities/identity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/empty.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/add.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/dec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_left.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/expr_iif.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/adt.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/is_binary.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/detail/check.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/logical/compl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/detail/fold_right.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/list/reverse.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/control/detail/while.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/tuple/elem.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/arithmetic/sub.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/eti.hpp \
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
  SeedSearcherMain.h SeedConf.h core/ConfReader.h ./core/Str.h \
  ./persistance/TextWriter.h core/ImplList.h StdOptions.h FeatureSet.h \
  persistance/StdInputStream.h persistance/StrOutputStream.h \
  Persistance/xmlwriter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stack \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/deque \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_deque.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/deque.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_stack.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  status_reporter/BaseStatusReporter.hpp ./core/Defs.h ./core/Str.h \
  ./core/Argv.h D:/Aviad/Dev/boost_1_33_1/boost/filesystem/path.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/filesystem/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/auto_link.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_facade.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/interoperable.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/nested_type_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/include_preprocessed.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/compiler.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/preprocessor/stringize.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_convertible.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/config_def.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/config_undef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/iterator.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/facade_iterator_category.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/iterator_categories.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/eval_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/value_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/integral.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/placeholders.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/arg.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/arg_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/na_assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/assert.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/not.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/yes_no.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/arrays.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arity_spec.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/arg_typedef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_same.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/detail/indirect_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_function.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/false_result.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/is_function_ptr_helper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_function_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_volatile.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_function_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_member_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_cv.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_reference.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/detail/ice_and.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/iterator/detail/enable_if.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/implicit_cast.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/add_pointer.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/remove_const.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_pod.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_void.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_scalar.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_enum.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type_traits/is_union.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/always.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/type_wrapper.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_xxx.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/msvc_typename.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/has_apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/msvc_never_true.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/bind_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/config/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/next.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/next_prior.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/common_name_wknd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/protect.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/full_lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/quote.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/void.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/has_type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/template_arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/abi_prefix.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/config/abi_suffix.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/filesystem/convenience.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/filesystem/operations.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/cstdint.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/included/prg_exec_monitor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/impl/execution_monitor.ipp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/config.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/workaround.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/suppress_warnings.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/enable_warnings.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/execution_monitor.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/global_typedef.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/utils/basic_cstring/basic_cstring.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/utils/basic_cstring/basic_cstring_fwd.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/utils/basic_cstring/bcs_char_traits.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/detail/fwd_decl.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/utils/callback.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/scoped_ptr.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/type.hpp \
  D:/Aviad/Dev/boost_1_33_1/boost/cstdlib.hpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/stdexcept \
  /usr/include/setjmp.h /usr/include/machine/setjmp.h \
  D:/Aviad/Dev/boost_1_33_1/boost/test/impl/cpp_main.ipp \
  D:/Aviad/Dev/boost_1_33_1/boost/test/utils/basic_cstring/io.hpp
