#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG 

BOOST = /cs/leff/aviadr/boost_1_34_1/
LIBBOOST = /cs/leff/aviadr/boost_1_34_1/stage/lib/
PERL = /usr/bin/perl
PUSHD = /usr/bin/pushd

CC = g++
IFLAGS = -I. -I$(BOOST)
LDLIBS = -lm
LDFLAGS = -L$(LIBBOOST)
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
	$(CC)  $(LDFLAGS) $(CCFLAGS) -o seed $(OBJS) entry_point.o status_reporter/DummyStatusReporter.o -lboost_filesystem-gcc41 -lboost_regex-gcc41
	
unitester$(EXE): core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o $(OBJS)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o seed.test $(OBJS) core/UnitTests.o tests/UnitTestMain.o tests/ParserTests.o tests/AssignmentTests.o tests/SanityTests.o tests/ScoreTests.o tests/SeedSearcherMainTests.o tests/SequenceDBTests.o tests/SeqWeightTests.o status_reporter/DummyStatusReporter.o -lboost_filesystem-gcc41 -lboost_regex-gcc41

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

tags:
	etags --language=c++ *.h *.cpp
# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/Str.h core/Defs.h
Assignment.o: Assignment.cpp Assignment.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset Alphabet.h core/Str.h core/Defs.h \
  persistance/TextWriter.h persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h persistance/Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc persistance/TextWriter.h \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  AssignmentFormat.h Assignment.h core/Defs.h core/STLHelper.h \
  core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc /usr/include/c++/4.2/bitset \
  core/Str.h core/Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h persistance/OutputStream.h \
  persistance/StdOutputStream.h persistance/UnbufferedChannel.h \
  /usr/include/c++/4.2/fstream \
  /usr/include/c++/4.2/i486-linux-gnu/bits/basic_file.h \
  /usr/include/c++/4.2/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/ImplList.h core/Defs.h core/STLHelper.h \
  persistance/TextWriter.h legacy/MathFunctions.h legacy/mathplus.h \
  ExtraMath.h
FeatureSet.o: FeatureSet.cpp FeatureSet.h Feature.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/ImplList.h core/Defs.h core/STLHelper.h \
  persistance/TextWriter.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset LeafPreprocessor.h Preprocessor.h Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SequenceDB.h \
  Alphabet.h core/Str.h core/Defs.h Sequence.h Cluster.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  SeedHash.h DebugLog.h persistance/TextWriter.h \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  AssignmentFormat.h
Parser.o: Parser.cpp Parser.h Defs.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp core/Str.h \
  core/Defs.h core/Argv.h core/Str.h core/GetOptParser.h core/Defs.h \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Argv.h \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h \
  /usr/include/c++/4.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h /usr/include/c++/4.2/bits/cmath.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/regex.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/config/cwchar.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/auto_link.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_workaround.hpp \
  /usr/include/c++/4.2/cassert /usr/include/c++/4.2/stdexcept \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stream_iterator.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h \
  /cs/leff/aviadr/boost_1_34_1/boost/limits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/cstdint.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/scoped_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/scoped_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/regex_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/syntax_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/error_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_traits_defaults.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/cpp_regex_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/pattern_except.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/pending/static_mutex.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/primary_transform.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/pending/object_cache.hpp \
  /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h \
  /usr/include/c++/4.2/bits/list.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/c_regex_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/type_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/yes_no.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/arrays.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc_typename.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/static_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/match_flags.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_raw_buffer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/char_regex_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/states.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regbase.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/iterator_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/basic_regex.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/basic_regex_creator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/basic_regex_parser.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/sub_match.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_format.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/match_results.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/protected_call.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/perl_matcher.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/iterator_category.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_convertible.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/integral_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/ice.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_eq.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_arithmetic.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_float.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_abstract.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_class.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_union.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_cv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/broken_compiler_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/cv_traits_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/intrinsics.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_function_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/perl_matcher_non_recursive.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/perl_matcher_common.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/instances.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_match.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_search.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_token_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_grep.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_replace.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_merge.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/regex/v4/regex_split.hpp DebugLog.h \
  persistance/Defs.h core/Defs.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h Assignment.h \
  core/STLHelper.h /usr/include/c++/4.2/bitset
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc Alphabet.h core/Str.h core/Defs.h \
  Sequence.h Cluster.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h \
  /usr/include/c++/4.2/bits/list.tcc persistance/IArchive.h \
  persistance/Defs.h persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h persistance/TFactory.h \
  persistance/Object.h persistance/Error.h core/AutoPtr.h \
  persistance/OArchive.h persistance/ORegistry.h persistance/TextWriter.h \
  DebugLog.h persistance/TextWriter.h persistance/AbstractFormat.h \
  persistance/Defs.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc Alphabet.h core/Str.h core/Defs.h \
  Sequence.h Cluster.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h Assignment.h \
  persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h \
  /usr/include/c++/4.2/bits/list.tcc
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset AssignmentFormat.h \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  core/Str.h core/Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp ExtraMath.h \
  legacy/MathFunctions.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  legacy/mathplus.h legacy/mathplus.h legacy/RandomGenerator.h \
  legacy/Multinomial.h DebugLog.h persistance/TextWriter.h
Score.o: Score.cpp Score.h Defs.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SeqWeight.h \
  Sequence.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h persistance/TextWriter.h \
  legacy/mathplus.h /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  ScoreFunction.h Cluster.h /usr/include/c++/4.2/set \
  /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h SequenceDB.h Alphabet.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  ScoreConcepts.h /cs/leff/aviadr/boost_1_34_1/boost/concept_check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator.hpp \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stream_iterator.h \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_convertible.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/integral_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/ice.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_eq.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_arithmetic.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_float.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_abstract.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/static_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_class.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_union.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_cv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/broken_compiler_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/cv_traits_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/intrinsics.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_arity_param.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/dtp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/limits/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bitand.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/add.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/dec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/expr_iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/adt.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/is_binary.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/compl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/reverse.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/detail/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/elem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/sub.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/eti.hpp ExtraMath.h \
  legacy/MathFunctions.h legacy/mathplus.h
SeedConf.o: SeedConf.cpp SeedConf.h core/ConfReader.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/Str.h core/Defs.h \
  persistance/TextWriter.h Parser.h Defs.h core/Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp core/Str.h \
  core/Argv.h core/Str.h core/GetOptParser.h core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Argv.h \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h core/STLHelper.h \
  /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h \
  /usr/include/c++/4.2/bits/list.tcc DebugLog.h persistance/Defs.h \
  core/Defs.h persistance/AbstractFormat.h persistance/Defs.h \
  core/AutoPtr.h AssignmentFormat.h Assignment.h \
  /usr/include/c++/4.2/bitset persistance/StrOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset Cluster.h Sequence.h Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp core/Str.h \
  core/Defs.h SeqWeight.h core/HashTable.h core/Str.h core/AutoPtr.h \
  /usr/include/c++/4.2/map /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h DebugLog.h \
  persistance/TextWriter.h persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h AssignmentFormat.h \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h
SeedPerformance.o: SeedPerformance.cpp
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/ImplList.h core/Defs.h core/STLHelper.h \
  persistance/TextWriter.h PrefixTreePreprocessor.h SeedHash.h \
  persistance/StrOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/timer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp Parser.h \
  core/Str.h core/Defs.h core/Argv.h core/Str.h core/GetOptParser.h \
  core/Defs.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Argv.h \
  persistance/TextTableReport.h core/Str.h core/FixedStr.h core/Str.h \
  core/AutoPtr.h core/ImplList.h core/STLHelper.h \
  persistance/TextWriter.h persistance/TextWriter.h Sequence.h \
  core/STLHelper.h Cluster.h SeqWeight.h core/HashTable.h core/AutoPtr.h \
  /usr/include/c++/4.2/map /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h pssm.h Alphabet.h DebugLog.h \
  Preprocessor.h SequenceDB.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h PrefixTreePreprocessor.h \
  RandomProjections.h SeedConf.h core/ConfReader.h core/Str.h \
  persistance/TextWriter.h core/ImplList.h StdOptions.h FeatureSet.h \
  LeafPreprocessor.h SeedHash.h ExtraMath.h legacy/MathFunctions.h \
  legacy/mathplus.h ScoreFunction.h ScoreConcepts.h \
  /cs/leff/aviadr/boost_1_34_1/boost/concept_check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator.hpp \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stream_iterator.h \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_convertible.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/integral_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/ice.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_eq.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_arithmetic.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_float.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_abstract.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/static_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_class.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_union.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_cv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/broken_compiler_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/cv_traits_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/intrinsics.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_arity_param.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/dtp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/limits/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bitand.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/add.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/dec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/expr_iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/adt.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/is_binary.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/compl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/reverse.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/detail/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/elem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/sub.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/eti.hpp \
  status_reporter/BaseStatusReporter.hpp core/Defs.h core/Str.h \
  core/Argv.h /cs/leff/aviadr/boost_1_34_1/boost/cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/limits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/select_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/converter.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_same.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/meta.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/value_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/eval_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/equal_to.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/comparison_op.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/numeric_op.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/numeric_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/type_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/yes_no.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/arrays.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc_typename.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/msvc_never_true.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/include_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/compiler.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/stringize.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/eval_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/numeric_cast_utils.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/forwarding.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/msvc_eti_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/is_msvc_eti_arg.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/equal_to.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nested_type_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/int_float_mixture.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/int_float_mixture_enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/sign_mixture.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/sign_mixture_enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/udt_builtin_mixture.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/udt_builtin_mixture_enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/is_subranged.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/multiplies.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/times.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arithmetic_op.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/largest_int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/times.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/default_params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/less.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/less.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/converter_policies.hpp \
  /usr/include/c++/4.2/cmath /usr/include/c++/4.2/bits/cmath.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/converter.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/bounds.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/numeric/conversion/detail/bounds.hpp
SeqWeight.o: SeqWeight.cpp SeqWeight.h Sequence.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h SequenceDB.h Alphabet.h \
  Cluster.h legacy/mathplus.h /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h /usr/include/c++/4.2/set \
  /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h core/FixedStr.h core/Str.h \
  persistance/TextReader.h core/Defs.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/StdInputStream.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  persistance/OutputStream.h \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/std_containers_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/std/string_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/sequence_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/std/list_traits.hpp \
  /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h \
  /usr/include/c++/4.2/bits/list.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/std/slist_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/config.hpp \
  /usr/include/c++/4.2/ext/slist \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/trim.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/begin.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_volatile.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/cv_traits_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/integral_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/broken_compiler_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/iterator.hpp \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stream_iterator.h \
  /cs/leff/aviadr/boost_1_34_1/boost/range/const_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/end.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/detail/implementation_help.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/detail/common.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/detail/sfinae.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/value_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/eti.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_arity_param.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/dtp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/limits/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bitand.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/add.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/dec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/expr_iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/adt.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/is_binary.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/compl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/reverse.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/detail/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/elem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/sub.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_same.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/trim.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/classification.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/value_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/classification.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/predicate_facade.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/case_conv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/transform_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/iterate.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/iteration/iterate.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/array/elem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/array/data.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/array/size.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/slot/slot.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/slot/detail/def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function/detail/prologue.hpp \
  /usr/include/c++/4.2/cassert \
  /cs/leff/aviadr/boost_1_34_1/boost/function/function_base.hpp \
  /usr/include/c++/4.2/stdexcept \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/composite_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_arithmetic.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_float.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_convertible.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/ice.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_eq.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_abstract.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/static_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_class.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_union.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_cv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/intrinsics.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_function.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/false_result.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/is_function_ptr_helper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_function_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/ref.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility/addressof.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/alignment_of.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/size_t_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/size_t.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/size_t_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/size_t_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility/enable_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function_equal.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mem_fn.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/get_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/bind/mem_fn_template.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/bind/mem_fn_cc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/rem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/enum_params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/enum_params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/iteration/detail/iter/forward1.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/iteration/detail/bounds/lower1.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/slot/detail/shared.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/iteration/detail/bounds/upper1.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function/detail/function_iterate.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function/detail/maybe_include.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/function/function_template.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/enable_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/config_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/config_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_adaptor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_categories.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/eval_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/placeholders.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/arg.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/arg_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nested_type_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/yes_no.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/arrays.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arg_typedef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/include_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/compiler.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/stringize.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_facade.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/interoperable.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/facade_iterator_category.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/indirect_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/implicit_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_pod.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_scalar.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/always.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/type_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc_typename.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/msvc_never_true.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bind_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/next.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/next_prior.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/common_name_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/protect.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/full_lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/quote.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/function_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/case_conv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/predicate.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/compare.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/find.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/iterator_range.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/functions.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/size.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/size_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/rbegin.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/reverse_result_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/result_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/reverse_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility/base_from_member.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/enum_binary_params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat_from_to.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility/enable_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/next_prior.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/noncopyable.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/reverse_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/const_reverse_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/rend.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/range/difference_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/finder.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/constants.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/finder.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/predicate.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/split.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/iter_find.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/concept.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/concept_check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/conversion_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/find_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/find_iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/util.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/join.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/sequence.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/logical.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/replace.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/find_format.hpp \
  /usr/include/c++/4.2/deque /usr/include/c++/4.2/bits/stl_deque.h \
  /usr/include/c++/4.2/bits/deque.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/find_format.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/find_format_store.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/replace_storage.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/find_format_all.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/formatter.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/detail/formatter.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/algorithm/string/erase.hpp \
  /usr/include/c++/4.2/fstream \
  /usr/include/c++/4.2/i486-linux-gnu/bits/basic_file.h \
  /usr/include/c++/4.2/bits/fstream.tcc /usr/include/c++/4.2/sstream \
  /usr/include/c++/4.2/bits/sstream.tcc
Sequence.o: Sequence.cpp Sequence.h Defs.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h \
  persistance/OArchive.h persistance/Defs.h core/Defs.h \
  persistance/ORegistry.h persistance/Object.h /usr/include/c++/4.2/set \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h persistance/TFactory.h \
  persistance/Error.h persistance/TextWriter.h core/AutoPtr.h \
  persistance/IArchive.h persistance/IRegistry.h persistance/TextReader.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/STLPersist.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc Sequence.h Defs.h \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h \
  SequenceDB.h Alphabet.h Cluster.h SeqWeight.h core/HashTable.h \
  core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h \
  /usr/include/c++/4.2/fstream \
  /usr/include/c++/4.2/i486-linux-gnu/bits/basic_file.h \
  /usr/include/c++/4.2/bits/fstream.tcc /usr/include/c++/4.2/sstream \
  /usr/include/c++/4.2/bits/sstream.tcc core/FixedStr.h core/Str.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h core/Defs.h \
  core/Compiler.h /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SequenceDB.h \
  core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc Alphabet.h core/Str.h core/Defs.h \
  Sequence.h Cluster.h SeqWeight.h core/HashTable.h core/Str.h \
  core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset persistance/AbstractFormat.h \
  persistance/Defs.h core/AutoPtr.h pssm.h DebugLog.h \
  persistance/TextWriter.h Preprocessor.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/ImplList.h core/Defs.h core/STLHelper.h \
  persistance/TextWriter.h PrefixTreePreprocessor.h FeatureSet.h \
  /usr/include/c++/4.2/fstream \
  /usr/include/c++/4.2/i486-linux-gnu/bits/basic_file.h \
  /usr/include/c++/4.2/bits/fstream.tcc persistance/StdOutputStream.h \
  persistance/OutputStream.h persistance/StreamBuffer.h \
  persistance/IODefs.h persistance/UnbufferedChannel.h \
  persistance/InputStream.h
entry_point.o: entry_point.cpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/included/prg_exec_monitor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/impl/execution_monitor.ipp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/workaround.hpp \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstring /usr/include/string.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/c++/4.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/langinfo.h \
  /usr/include/nl_types.h /usr/include/iconv.h /usr/include/libintl.h \
  /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/char_traits.h \
  /usr/include/c++/4.2/bits/stl_algobase.h /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/c++/4.2/debug/debug.h \
  /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/bits/locale_classes.h /usr/include/c++/4.2/string \
  /usr/include/c++/4.2/memory /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h /usr/include/c++/4.2/algorithm \
  /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /usr/include/c++/4.2/bits/stream_iterator.h \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/suppress_warnings.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/enable_warnings.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/execution_monitor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/global_typedef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/utils/basic_cstring/basic_cstring.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/utils/basic_cstring/basic_cstring_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/utils/basic_cstring/bcs_char_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/detail/fwd_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/utils/callback.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/scoped_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/cstdlib.hpp \
  /usr/include/c++/4.2/stdexcept /usr/include/c++/4.2/cassert \
  /usr/include/bits/signum.h /usr/include/bits/siginfo.h \
  /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
  /usr/include/asm/sigcontext.h /usr/include/asm-i386/sigcontext.h \
  /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
  /usr/include/bits/sigthread.h /usr/include/setjmp.h \
  /cs/leff/aviadr/boost_1_34_1/boost/test/impl/cpp_main.ipp \
  /cs/leff/aviadr/boost_1_34_1/boost/test/utils/basic_cstring/io.hpp \
  /usr/include/c++/4.2/iostream \
  /cs/leff/aviadr/boost_1_34_1/boost/test/prg_exec_monitor.hpp
main.o: main.cpp main.h Feature.h Defs.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc \
  /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp Cluster.h \
  Sequence.h core/STLHelper.h core/Defs.h /usr/include/c++/4.2/vector \
  /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc core/Str.h core/Defs.h SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h legacy/mathplus.h \
  /usr/include/math.h /usr/include/bits/huge_val.h \
  /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
  /usr/include/bits/inf.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/4.2/set /usr/include/c++/4.2/bits/stl_set.h \
  /usr/include/c++/4.2/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h persistance/Defs.h core/Defs.h /usr/include/c++/4.2/bitset \
  persistance/AbstractFormat.h persistance/Defs.h core/AutoPtr.h pssm.h \
  Alphabet.h DebugLog.h persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h /usr/include/c++/4.2/list \
  /usr/include/c++/4.2/bits/stl_list.h /usr/include/c++/4.2/bits/list.tcc \
  Score.h persistance/TextTableReport.h core/Str.h core/FixedStr.h \
  core/Str.h core/ImplList.h core/Defs.h core/STLHelper.h \
  persistance/TextWriter.h Parser.h core/Argv.h core/GetOptParser.h \
  core/STLHelper.h core/Argv.h persistance/TextTableReport.h \
  persistance/StdOutputStream.h persistance/OutputStream.h \
  persistance/StreamBuffer.h persistance/IODefs.h \
  persistance/UnbufferedChannel.h persistance/InputStream.h \
  /usr/include/c++/4.2/fstream \
  /usr/include/c++/4.2/i486-linux-gnu/bits/basic_file.h \
  /usr/include/c++/4.2/bits/fstream.tcc RandomProjections.h \
  SeedSearcher.h PrefixTreePreprocessor.h SeedSearcherMain.h SeedConf.h \
  core/ConfReader.h core/Str.h persistance/TextWriter.h core/ImplList.h \
  StdOptions.h FeatureSet.h persistance/StdInputStream.h \
  persistance/StrOutputStream.h persistance/xmlwriter.h \
  /usr/include/c++/4.2/stack /usr/include/c++/4.2/deque \
  /usr/include/c++/4.2/bits/stl_deque.h \
  /usr/include/c++/4.2/bits/deque.tcc \
  /usr/include/c++/4.2/bits/stl_stack.h /usr/include/c++/4.2/sstream \
  /usr/include/c++/4.2/bits/sstream.tcc \
  status_reporter/BaseStatusReporter.hpp core/Defs.h core/Str.h \
  core/Argv.h /cs/leff/aviadr/boost_1_34_1/boost/filesystem/path.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/filesystem/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/auto_link.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_facade.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator.hpp \
  /usr/include/c++/4.2/iterator \
  /usr/include/c++/4.2/bits/stream_iterator.h \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/interoperable.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bool_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/adl_barrier.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/adl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/intel.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/workaround.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_tag.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/static_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/use_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nested_type_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ctps.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/ttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/int_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/nttp_decl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/nttp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/integral_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/static_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/cat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/config/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_arity_param.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/dtp.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/params.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/preprocessor.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bool.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/punctuation/comma.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/repetition/repeat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/debug/error.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/auto_rec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/eat.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/inc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/limits/arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/bitand.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/facilities/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/empty.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/add.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/dec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_left.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/expr_iif.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/adt.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/is_binary.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/detail/check.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/logical/compl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/detail/fold_right.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/list/reverse.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/control/detail/while.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/tuple/elem.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/arithmetic/sub.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/eti.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/overload_resolution.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/lambda_support.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/include_preprocessed.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/compiler.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/preprocessor/stringize.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_convertible.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/yes_no_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_array.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/template_arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/integral_constant.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/integral_c_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/bool_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/type_trait_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/ice.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_or.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/ice_eq.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_arithmetic.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_float.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_abstract.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/static_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_class.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_union.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_cv.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/broken_compiler_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/cv_traits_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/intrinsics.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/config_def.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/config_undef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/iterator.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/facade_iterator_category.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/iterator_categories.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/eval_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/value_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/integral.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/identity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/placeholders.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/arg.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/arg_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/na_assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/assert.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/not.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/yes_no.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/arrays.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arity_spec.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/arg_typedef.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/and.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_same.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/indirect_traits.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_function.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/false_result.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/is_function_ptr_helper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_member_function_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_volatile.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_reference.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/iterator/detail/enable_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/implicit_cast.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/add_pointer.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/remove_const.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_pod.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_scalar.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/type_traits/is_enum.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/always.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/type_wrapper.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_xxx.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/msvc_typename.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/has_apply.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/msvc_never_true.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply_wrap.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/bind_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/config/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/bind_fwd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/next.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/next_prior.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/common_name_wknd.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/protect.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/bind.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/full_lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/quote.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/void.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/has_type.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/quote.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/template_arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/template_arity.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/full_lambda.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/mpl/aux_/preprocessed/gcc/apply.hpp \
  /usr/include/c++/4.2/stdexcept /usr/include/c++/4.2/cassert \
  /cs/leff/aviadr/boost_1_34_1/boost/config/abi_prefix.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/abi_suffix.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/filesystem/convenience.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/filesystem/operations.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/utility/enable_if.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/cstdint.hpp
pssm.o: pssm.cpp pssm.h Assignment.h core/Defs.h core/Compiler.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/user.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_compiler_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/compiler/gcc.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_stdlib_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/no_tr1/utility.hpp \
  /usr/include/c++/4.2/utility \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++config.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/cpu_defines.h \
  /usr/include/c++/4.2/bits/stl_relops.h \
  /usr/include/c++/4.2/bits/stl_pair.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/stdlib/libstdcpp3.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/select_platform_config.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/config/platform/linux.hpp \
  /usr/include/c++/4.2/cstdlib /usr/include/c++/4.2/cstddef \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stddef.h \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/xlocale.h \
  /usr/include/sys/types.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/time.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/sigset.h /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/posix_features.hpp \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /cs/leff/aviadr/boost_1_34_1/boost/config/suffix.hpp \
  /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/stringfwd.h \
  /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring \
  /usr/include/string.h /usr/include/c++/4.2/bits/stl_algobase.h \
  /usr/include/c++/4.2/climits \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/limits.h \
  /usr/lib/gcc/i486-linux-gnu/4.2.3/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/c++/4.2/iosfwd \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++locale.h \
  /usr/include/c++/4.2/cstdio /usr/include/stdio.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc/i486-linux-gnu/4.2.3/include/stdarg.h \
  /usr/include/bits/sys_errlist.h /usr/include/c++/4.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h /usr/include/c++/4.2/cstdarg \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++io.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
  /usr/include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/c++/4.2/cctype /usr/include/ctype.h \
  /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar \
  /usr/include/c++/4.2/ctime /usr/include/stdint.h \
  /usr/include/c++/4.2/bits/functexcept.h \
  /usr/include/c++/4.2/exception_defines.h \
  /usr/include/c++/4.2/bits/cpp_type_traits.h \
  /usr/include/c++/4.2/ext/type_traits.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/4.2/bits/concept_check.h \
  /usr/include/c++/4.2/bits/stl_iterator.h \
  /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory \
  /usr/include/c++/4.2/bits/allocator.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/c++allocator.h \
  /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new \
  /usr/include/c++/4.2/exception \
  /usr/include/c++/4.2/bits/stl_construct.h \
  /usr/include/c++/4.2/bits/stl_uninitialized.h \
  /usr/include/c++/4.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/4.2/limits /usr/include/c++/4.2/bits/ostream_insert.h \
  /usr/include/c++/4.2/bits/stl_function.h \
  /usr/include/c++/4.2/bits/basic_string.h \
  /usr/include/c++/4.2/ext/atomicity.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/atomic_word.h \
  /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h \
  /usr/include/c++/4.2/bits/stl_heap.h \
  /usr/include/c++/4.2/bits/stl_tempbuf.h \
  /usr/include/c++/4.2/bits/basic_string.tcc \
  /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream \
  /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h \
  /usr/include/c++/4.2/bits/ios_base.h \
  /usr/include/c++/4.2/bits/locale_classes.h \
  /usr/include/c++/4.2/streambuf /usr/include/c++/4.2/bits/streambuf.tcc \
  /usr/include/c++/4.2/bits/basic_ios.h \
  /usr/include/c++/4.2/bits/streambuf_iterator.h \
  /usr/include/c++/4.2/bits/locale_facets.h /usr/include/c++/4.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/4.2/bits/codecvt.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/time_members.h \
  /usr/include/c++/4.2/i486-linux-gnu/bits/messages_members.h \
  /usr/include/c++/4.2/bits/basic_ios.tcc \
  /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale \
  /usr/include/c++/4.2/bits/locale_facets.tcc \
  /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream \
  /usr/include/c++/4.2/bits/istream.tcc core/STLHelper.h core/Defs.h \
  /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/stl_vector.h \
  /usr/include/c++/4.2/bits/stl_bvector.h \
  /usr/include/c++/4.2/bits/vector.tcc persistance/Defs.h core/Defs.h \
  /usr/include/c++/4.2/bitset Alphabet.h core/Str.h core/Defs.h \
  Sequence.h Defs.h /cs/leff/aviadr/boost_1_34_1/boost/shared_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/assert.hpp /usr/include/assert.h \
  /cs/leff/aviadr/boost_1_34_1/boost/checked_delete.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/throw_exception.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/shared_count.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/bad_weak_ptr.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_base_gcc_x86.hpp \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/sp_counted_impl.hpp \
  /usr/include/c++/4.2/functional \
  /cs/leff/aviadr/boost_1_34_1/boost/detail/workaround.hpp SeqWeight.h \
  core/HashTable.h core/Str.h core/AutoPtr.h /usr/include/c++/4.2/map \
  /usr/include/c++/4.2/bits/stl_tree.h \
  /usr/include/c++/4.2/bits/stl_map.h \
  /usr/include/c++/4.2/bits/stl_multimap.h /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h
