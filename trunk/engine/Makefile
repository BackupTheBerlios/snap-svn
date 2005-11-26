#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

CC = g++
#CC = g++-3.0
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
		Core/Defs.cpp Core/dlmalloc.c Core/HashTable.cpp \
		Core/Str.cpp \
		Persistance/Error.cpp Persistance/IArchive.cpp \
		Persistance/InputStream.cpp Persistance/IRegistry.cpp \
		Persistance/OArchive.cpp Persistance/Object.cpp \
		Persistance/ORegistry.cpp Persistance/OutputStream.cpp \
		Persistance/StreamBuffer.cpp Persistance/TextReader.cpp \
		Persistance/TextWriter.cpp Persistance/TFactory.cpp \
		Legacy/RandomGenerator.cpp Legacy/Multinomial.cpp \
		Util/ConfReader.cpp

all:	depend seed

seed$(EXE): main.o $(OBJS)
	$(CC) $(CCFLAGS) -o seed $(OBJS) main.o

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

tags:
	etags --language=c++ *.h *.cpp

# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/Str.h
Assignment.o: Assignment.cpp Assignment.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset Alphabet.h Core/Str.h \
  Persistance/TextWriter.h Persistance/StdOutputStream.h \
  Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h Persistance/UnbufferedChannel.h \
  Persistance/InputStream.h DebugLog.h Persistance/AbstractFormat.h \
  Core/AutoPtr.h AssignmentFormat.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h Persistance/Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Persistance/TextWriter.h \
  Persistance/AbstractFormat.h Core/AutoPtr.h AssignmentFormat.h \
  Assignment.h Core/STLHelper.h /usr/include/c++/3.3/vector \
  /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc /usr/include/c++/3.3/bitset \
  Core/Str.h Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h Persistance/UnbufferedChannel.h \
  Persistance/InputStream.h Persistance/StdOutputStream.h \
  /usr/include/c++/3.3/fstream \
  /usr/include/c++/3.3/i486-linux/bits/basic_file.h \
  /usr/include/c++/3.3/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Cluster.h Sequence.h \
  Core/STLHelper.h /usr/include/c++/3.3/vector \
  /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3/bitset \
  Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  Legacy/MathFunctions.h /usr/include/assert.h ExtraMath.h
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h Legacy/MathPlus.h SeedSearcher.h \
  Feature.h Defs.h Cluster.h Sequence.h Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h AssignmentFormat.h \
  Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  PrefixTreePreprocessor.h Core/HashTable.h
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset HyperGeoScore.h Cluster.h Sequence.h Defs.h \
  Core/Str.h Core/PoolAllocated.h boost/pool/object_pool.hpp \
  boost/pool/poolfwd.hpp boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Persistance/AbstractFormat.h PSSM.h Alphabet.h \
  DebugLog.h Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  PrefixTreePreprocessor.h HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset LeafPreprocessor.h Preprocessor.h Defs.h \
  SequenceDB.h Alphabet.h Core/Str.h Sequence.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h SeedHash.h DebugLog.h \
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  AssignmentFormat.h Core/HashTable.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset Alphabet.h Core/Str.h Sequence.h Defs.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc /usr/include/assert.h
Parser.o: Parser.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/Str.h \
  Persistance/TextWriter.h boost/tokenizer.hpp boost/token_iterator.hpp \
  boost/iterator/iterator_adaptor.hpp boost/static_assert.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/detail/workaround.hpp boost/iterator.hpp \
  /usr/include/c++/3.3/iterator \
  /usr/include/c++/3.3/bits/stream_iterator.h boost/detail/iterator.hpp \
  boost/iterator/iterator_categories.hpp \
  boost/iterator/detail/config_def.hpp boost/mpl/apply_if.hpp \
  boost/mpl/if.hpp boost/mpl/void.hpp boost/mpl/void_fwd.hpp \
  boost/mpl/bool.hpp boost/mpl/bool_fwd.hpp \
  boost/mpl/aux_/config/static_constant.hpp \
  boost/mpl/aux_/config/msvc.hpp boost/mpl/aux_/config/workaround.hpp \
  boost/mpl/aux_/value_wknd.hpp boost/mpl/aux_/config/eti.hpp \
  boost/mpl/aux_/static_cast.hpp boost/mpl/aux_/void_spec.hpp \
  boost/mpl/lambda_fwd.hpp boost/mpl/aux_/lambda_arity_param.hpp \
  boost/mpl/aux_/config/ttp.hpp boost/mpl/aux_/config/lambda.hpp \
  boost/mpl/int_fwd.hpp boost/mpl/aux_/preprocessor/params.hpp \
  boost/mpl/aux_/config/preprocessor.hpp boost/preprocessor/cat.hpp \
  boost/preprocessor/config/config.hpp \
  boost/mpl/aux_/preprocessor/enum.hpp \
  boost/mpl/aux_/preprocessor/def_params_tail.hpp \
  boost/mpl/limits/arity.hpp boost/mpl/aux_/config/dtp.hpp \
  boost/preprocessor/comma_if.hpp \
  boost/preprocessor/punctuation/comma_if.hpp \
  boost/preprocessor/control/if.hpp boost/preprocessor/control/iif.hpp \
  boost/preprocessor/logical/bool.hpp \
  boost/preprocessor/facilities/empty.hpp \
  boost/preprocessor/punctuation/comma.hpp \
  boost/preprocessor/logical/and.hpp \
  boost/preprocessor/logical/bitand.hpp boost/preprocessor/identity.hpp \
  boost/preprocessor/facilities/identity.hpp boost/preprocessor/empty.hpp \
  boost/mpl/aux_/preprocessor/filter_params.hpp \
  boost/mpl/aux_/preprocessor/sub.hpp \
  boost/mpl/aux_/preprocessor/tuple.hpp boost/mpl/aux_/arity.hpp \
  boost/mpl/aux_/config/nttp.hpp boost/mpl/aux_/template_arity_fwd.hpp \
  boost/mpl/aux_/algorithm_namespace.hpp \
  boost/mpl/aux_/config/overload_resolution.hpp \
  boost/mpl/aux_/lambda_support.hpp boost/mpl/arg_fwd.hpp \
  boost/mpl/aux_/apply.hpp boost/mpl/identity.hpp \
  boost/mpl/placeholders.hpp boost/mpl/arg.hpp \
  boost/mpl/aux_/arity_spec.hpp boost/mpl/aux_/arg_typedef.hpp \
  boost/mpl/aux_/config/use_preprocessed.hpp \
  boost/mpl/aux_/include_preprocessed.hpp \
  boost/mpl/aux_/config/compiler.hpp boost/preprocessor/stringize.hpp \
  boost/mpl/aux_/preprocessed/gcc/arg.hpp \
  boost/mpl/aux_/preprocessed/gcc/placeholders.hpp \
  boost/type_traits/is_convertible.hpp \
  boost/type_traits/detail/yes_no_type.hpp boost/type_traits/config.hpp \
  boost/type_traits/is_array.hpp \
  boost/type_traits/detail/bool_trait_def.hpp \
  boost/type_traits/detail/template_arity_spec.hpp \
  boost/type_traits/detail/bool_trait_undef.hpp \
  boost/type_traits/add_reference.hpp boost/type_traits/is_reference.hpp \
  boost/type_traits/detail/type_trait_def.hpp \
  boost/type_traits/detail/type_trait_undef.hpp boost/type_traits/ice.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp \
  boost/iterator/detail/config_undef.hpp \
  boost/iterator/iterator_facade.hpp boost/iterator/interoperable.hpp \
  boost/mpl/or.hpp boost/mpl/aux_/nested_type_wknd.hpp \
  boost/mpl/aux_/preprocessed/gcc/or.hpp \
  boost/iterator/iterator_traits.hpp \
  boost/iterator/detail/facade_iterator_category.hpp boost/mpl/and.hpp \
  boost/mpl/aux_/preprocessed/gcc/and.hpp boost/type_traits/is_same.hpp \
  boost/type_traits/is_const.hpp \
  boost/type_traits/detail/cv_traits_impl.hpp \
  boost/iterator/detail/enable_if.hpp boost/type_traits/add_const.hpp \
  boost/type_traits/add_pointer.hpp \
  boost/type_traits/remove_reference.hpp \
  boost/type_traits/broken_compiler_spec.hpp \
  boost/type_traits/remove_const.hpp boost/type_traits/is_volatile.hpp \
  boost/type_traits/is_pod.hpp boost/type_traits/is_void.hpp \
  boost/type_traits/is_scalar.hpp boost/type_traits/is_arithmetic.hpp \
  boost/type_traits/is_integral.hpp boost/type_traits/is_float.hpp \
  boost/type_traits/is_enum.hpp boost/type_traits/is_function.hpp \
  boost/type_traits/detail/false_result.hpp \
  boost/type_traits/detail/is_function_ptr_helper.hpp \
  boost/type_traits/is_class.hpp boost/type_traits/is_union.hpp \
  boost/type_traits/remove_cv.hpp boost/type_traits/intrinsics.hpp \
  boost/type_traits/is_pointer.hpp \
  boost/type_traits/is_member_pointer.hpp \
  boost/type_traits/is_member_function_pointer.hpp \
  boost/type_traits/detail/is_mem_fun_pointer_impl.hpp \
  boost/mpl/always.hpp boost/mpl/aux_/lambda_spec.hpp boost/mpl/apply.hpp \
  boost/mpl/aux_/msvc_never_true.hpp boost/type_traits/same_traits.hpp \
  boost/mpl/aux_/preprocessed/gcc/apply.hpp boost/mpl/not.hpp \
  boost/python/detail/is_xxx.hpp boost/preprocessor/enum_params.hpp \
  boost/preprocessor/repetition/enum_params.hpp \
  boost/preprocessor/repetition/repeat.hpp \
  boost/preprocessor/debug/error.hpp \
  boost/preprocessor/detail/auto_rec.hpp boost/preprocessor/tuple/eat.hpp \
  boost/iterator/detail/minimum_category.hpp boost/token_functions.hpp \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc /usr/include/c++/3.3/stdexcept \
  /usr/include/c++/3.3/cassert /usr/include/assert.h
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc SequenceDB.h Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3/bitset Persistance/IArchive.h \
  Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h Persistance/TFactory.h \
  Persistance/Object.h Persistance/Error.h Persistance/OArchive.h \
  Persistance/ORegistry.h Persistance/TextWriter.h DebugLog.h \
  Persistance/AbstractFormat.h AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc SequenceDB.h Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3/bitset
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h Core/Defs.h Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset ExtraMath.h Legacy/MathFunctions.h \
  /usr/include/assert.h Legacy/MathPlus.h Legacy/RandomGenerator.h \
  Legacy/Multinomial.h DebugLog.h Persistance/TextWriter.h \
  Persistance/AbstractFormat.h Core/AutoPtr.h AssignmentFormat.h \
  Core/Str.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3/bitset Cluster.h Sequence.h Defs.h Core/Str.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h DebugLog.h \
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  AssignmentFormat.h Core/HashTable.h Persistance/StrOutputStream.h \
  Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  Core/Defs.h Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Cluster.h Sequence.h \
  Core/STLHelper.h /usr/include/c++/3.3/vector \
  /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3/map /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3/bitset \
  Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
  Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  PrefixTreePreprocessor.h SeedHash.h Core/HashTable.h \
  Persistance/StrOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h boost/timer.hpp \
  boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  Core/Defs.h Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc Parser.h Core/Str.h \
  Persistance/TextWriter.h Sequence.h Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h Persistance/Defs.h \
  /usr/include/c++/3.3/bitset Persistance/AbstractFormat.h PSSM.h \
  Alphabet.h DebugLog.h Preprocessor.h SequenceDB.h \
  PrefixTreePreprocessor.h RandomProjections.h StdOptions.h \
  HyperGeoCache.h /usr/include/assert.h ExtraMath.h \
  Legacy/MathFunctions.h LeafPreprocessor.h SeedHash.h Core/HashTable.h \
  HyperGeoScore.h
Sequence.o: Sequence.cpp Sequence.h Defs.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Persistance/OArchive.h \
  Persistance/Defs.h Persistance/ORegistry.h Persistance/Object.h \
  /usr/include/c++/3.3/set /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h Persistance/TFactory.h \
  Persistance/Error.h Persistance/TextWriter.h Core/AutoPtr.h \
  Persistance/IArchive.h Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/STLPersist.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Sequence.h Defs.h \
  Core/STLHelper.h /usr/include/c++/3.3/vector \
  /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3/utility /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc SequenceDB.h Alphabet.h Cluster.h \
  Legacy/MathPlus.h Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3/bitset \
  Persistance/AbstractFormat.h /usr/include/c++/3.3/fstream \
  /usr/include/c++/3.3/i486-linux/bits/basic_file.h \
  /usr/include/c++/3.3/bits/fstream.tcc /usr/include/assert.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3/string \
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
  /usr/include/c++/3.3/bits/istream.tcc SequenceDB.h Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h Persistance/Defs.h \
  /usr/include/c++/3.3/bitset Persistance/AbstractFormat.h PSSM.h \
  DebugLog.h Persistance/TextWriter.h Preprocessor.h \
  PrefixTreePreprocessor.h HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h
main.o: main.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
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
  /usr/include/c++/3.3/bits/istream.tcc Core/Str.h \
  Persistance/TextWriter.h SequenceDB.h Core/STLHelper.h \
  /usr/include/c++/3.3/vector /usr/include/c++/3.3/bits/stl_vector.h \
  /usr/include/c++/3.3/bits/stl_bvector.h \
  /usr/include/c++/3.3/bits/vector.tcc Alphabet.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3/utility \
  /usr/include/c++/3.3/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp boost/config/platform/linux.hpp \
  boost/config/posix_features.hpp boost/config/suffix.hpp \
  boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3/map \
  /usr/include/c++/3.3/bits/stl_tree.h \
  /usr/include/c++/3.3/bits/stl_map.h \
  /usr/include/c++/3.3/bits/stl_multimap.h /usr/include/c++/3.3/set \
  /usr/include/c++/3.3/bits/stl_set.h \
  /usr/include/c++/3.3/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3/bitset RandomProjections.h \
  SeedSearcher.h Feature.h AssignmentFormat.h \
  Persistance/AbstractFormat.h PSSM.h DebugLog.h Preprocessor.h \
  PrefixTreePreprocessor.h HyperGeoScore.h HyperGeoCache.h \
  /usr/include/assert.h ExtraMath.h Legacy/MathFunctions.h \
  SeedSearcherMain.h StdOptions.h Util/ConfReader.h \
  Persistance/StdOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/UnbufferedChannel.h Persistance/InputStream.h \
  Persistance/StdInputStream.h /usr/include/c++/3.3/fstream \
  /usr/include/c++/3.3/i486-linux/bits/basic_file.h \
  /usr/include/c++/3.3/bits/fstream.tcc /usr/include/c++/3.3/queue \
  /usr/include/c++/3.3/bits/stl_deque.h \
  /usr/include/c++/3.3/bits/stl_queue.h \
  /usr/include/c++/3.3/bits/deque.tcc
