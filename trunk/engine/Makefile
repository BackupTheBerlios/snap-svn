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
		core/Defs.cpp core/HashTable.cpp \
		core/Str.cpp core/Argv.cpp core/FixedStr.cpp \
		persistance/Error.cpp persistance/IArchive.cpp \
		persistance/InputStream.cpp persistance/IRegistry.cpp \
		persistance/OArchive.cpp persistance/Object.cpp \
		persistance/ORegistry.cpp persistance/OutputStream.cpp \
		persistance/StreamBuffer.cpp persistance/TextReader.cpp \
		persistance/TextWriter.cpp persistance/TFactory.cpp \
		persistance/TextTableReport.cpp \
		legacy/RandomGenerator.cpp legacy/Multinomial.cpp \
		core/ConfReader.cpp	core/Parser.cpp \
		SeedConf.cpp \
		status_reporter/BaseStatusReporter.cpp	\
		boost/test/cpp_main.cpp	boost/test/execution_monitor.cpp	
		
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
  /usr/include/c++/3.3/string \
  /usr/include/c++/3.3/i486-linux/bits/c++config.h \
  /usr/include/c++/3.3/i486-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.3/bits/stringfwd.h \
  /usr/include/c++/3.3/bits/char_traits.h /usr/include/c++/3.3/cstring \
  /usr/include/c++/3.3/cstddef \
  /usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.3/bits/fpos.h \
  /usr/include/c++/3.3/i486-linux/bits/c++io.h \
  /usr/include/c++/3.3/cstdio /usr/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/wordsize.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h /usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/c++/3.3/i486-linux/bits/gthr.h \
  /usr/include/c++/3.3/i486-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/unistd.h \
  /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
  /usr/include/bits/confname.h /usr/include/getopt.h \
  /usr/include/c++/3.3/cwchar /usr/include/c++/3.3/ctime \
  /usr/include/c++/3.3/memory /usr/include/c++/3.3/bits/stl_algobase.h \
  /usr/include/c++/3.3/climits \
  /usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h \
  /usr/lib/gcc-lib/i486-linux/3.3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/c++/3.3/cstdlib /usr/include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/include/sys/types.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/c++/3.3/new \
  /usr/include/c++/3.3/exception /usr/include/c++/3.3/iosfwd \
  /usr/include/c++/3.3/i486-linux/bits/c++locale.h \
  /usr/include/c++/3.3/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/langinfo.h \
  /usr/include/nl_types.h /usr/include/iconv.h /usr/include/libintl.h \
  /usr/include/c++/3.3/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3/bits/functexcept.h \
  /usr/include/c++/3.3/exception_defines.h \
  /usr/include/c++/3.3/bits/stl_pair.h \
  /usr/include/c++/3.3/bits/type_traits.h \
  /usr/include/c++/3.3/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.3/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.3/bits/concept_check.h \
  /usr/include/c++/3.3/bits/stl_iterator.h \
  /usr/include/c++/3.3/bits/stl_alloc.h \
  /usr/include/c++/3.3/bits/stl_threads.h \
  /usr/include/c++/3.3/i486-linux/bits/atomicity.h \
  /usr/include/c++/3.3/bits/stl_construct.h \
  /usr/include/c++/3.3/bits/stl_uninitialized.h \
  /usr/include/c++/3.3/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.3/bits/stl_function.h \
  /usr/include/c++/3.3/bits/basic_string.h /usr/include/c++/3.3/algorithm \
  /usr/include/c++/3.3/bits/stl_algo.h \
  /usr/include/c++/3.3/bits/stl_heap.h \
  /usr/include/c++/3.3/bits/stl_tempbuf.h \
  /usr/include/c++/3.3/bits/basic_string.tcc \
  /usr/include/c++/3.3/iostream /usr/include/c++/3.3/ostream \
  /usr/include/c++/3.3/ios /usr/include/c++/3.3/bits/localefwd.h \
  /usr/include/c++/3.3/bits/ios_base.h \
  /usr/include/c++/3.3/bits/locale_classes.h \
  /usr/include/c++/3.3/streambuf /usr/include/c++/3.3/bits/streambuf.tcc \
  /usr/include/c++/3.3/bits/basic_ios.h \
  /usr/include/c++/3.3/bits/streambuf_iterator.h \
  /usr/include/c++/3.3/bits/locale_facets.h /usr/include/c++/3.3/cwctype \
  /usr/include/wctype.h /usr/include/c++/3.3/i486-linux/bits/ctype_base.h \
  /usr/include/c++/3.3/i486-linux/bits/ctype_inline.h \
  /usr/include/c++/3.3/bits/codecvt.h \
  /usr/include/c++/3.3/i486-linux/bits/codecvt_specializations.h \
  /usr/include/c++/3.3/i486-linux/bits/time_members.h \
  /usr/include/c++/3.3/i486-linux/bits/messages_members.h \
  /usr/include/c++/3.3/bits/basic_ios.tcc \
  /usr/include/c++/3.3/bits/ostream.tcc /usr/include/c++/3.3/locale \
  /usr/include/c++/3.3/bits/locale_facets.tcc /usr/include/c++/3.3/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
  /usr/include/c++/3.3/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.3/bits/cmath.tcc /usr/include/c++/3.3/limits \
  /usr/include/c++/3.3/typeinfo /usr/include/c++/3.3/istream \
  /usr/include/c++/3.3/bits/istream.tcc core/Str.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
SeedPerformance.o: SeedPerformance.cpp
