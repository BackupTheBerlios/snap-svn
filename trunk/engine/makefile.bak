#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

CC = g++
IFLAGS = -I.  
LDLIBS = -lm 	
OBJS = $(subst .cpp,.o,${SOURCES})
SOURCES = Alphabet.cpp Assignment.cpp Cluster.cpp \
		DebugLog.cpp HyperGeoCache.cpp \
		HyperGeoScore.cpp \
		PrefixTreePreprocessor.cpp \
		PrefixTreeWalker.cpp  \
		RandomProjections.cpp \
		SeedSearcher.cpp Sequence.cpp \
		SequenceDB.cpp StdOptions.cpp PSSM.cpp \
		Core/Defs.cpp Core/dlmalloc.c Core/HashTable.cpp \
		Core/Str.cpp \
		Persistance/Error.cpp Persistance/IArchive.cpp \
		Persistance/InputStream.cpp Persistance/IRegistry.cpp \
		Persistance/OArchive.cpp Persistance/Object.cpp \
		Persistance/ORegistry.cpp Persistance/OutputStream.cpp \
		Persistance/StreamBuffer.cpp Persistance/TextReader.cpp \
		Persistance/TextWriter.cpp Persistance/TFactory.cpp \
		Legacy/RandomGenerator.cpp Legacy/Multinomial.cpp 

all:	depend seed

seed$(EXE): main.o $(OBJS)
	$(CC) $(CCFLAGS) -o seed $(OBJS) main.o

%.o: %.cpp 
	$(CC) -c $(CCFLAGS) $(IFLAGS) $(LDFLAGS) -o $@ $<


depend: $(SOURCES)
	gccmakedep -- $(IFLAGS) $(LDFLAGS) -- *.cpp 

clean:
	rm -r -f *~
	rm -r -f *.o
	rm -r -f *#
	rm -r -f Core/*~
	rm -r -f Core/*.o
	rm -r -f Core/*#
	rm -r -f Persistance/*~
	rm -r -f Persistance/*.o
	rm -r -f Persistance/*#
	rm -r -f Legacy/*~
	rm -r -f Legacy/*.o
	rm -r -f Legacy/*#
	rm -f seed

tags:
	etags --language=c++ *.h *.cpp


# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo
Assignment.o: Assignment.cpp Assignment.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Persistance/Defs.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc Persistance/TextWriter.h \
  Alphabet.h Persistance/StdOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/UnbufferedChannel.h Persistance/InputStream.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Core/dlmalloc.h Core/Str.h \
  Core/STLHelper.h /usr/include/c++/3.2/map \
  /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h SequenceDB.h Alphabet.h \
  Legacy/mathplus.h
DebugLog.o: DebugLog.cpp DebugLog.h Persistance/Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Persistance/TextWriter.h \
  Persistance/AbstractFormat.h Core/AutoPtr.h AssignmentFormat.h \
  Assignment.h Core/STLHelper.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h /usr/include/c++/3.2/bitset \
  /usr/include/c++/3.2/istream /usr/include/c++/3.2/bits/istream.tcc
HyperGeoCache.o: HyperGeoCache.cpp HyperGeoCache.h /usr/include/assert.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h ExtraMath.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo SeedSearcher.h PrefixTreePreprocessor.h \
  Preprocessor.h Defs.h Core/STLHelper.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h SequenceDB.h Alphabet.h \
  Sequence.h Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h Core/dlmalloc.h Core/Str.h Cluster.h \
  /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Core/AutoPtr.h Assignment.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc Core/HashTable.h \
  Persistance/TextWriter.h
HyperGeoScore.o: HyperGeoScore.cpp HyperGeoScore.h Cluster.h Sequence.h \
  Defs.h Core/Defs.h Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Core/dlmalloc.h Core/Str.h \
  Core/STLHelper.h /usr/include/c++/3.2/map \
  /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h SeedSearcher.h \
  PrefixTreePreprocessor.h Preprocessor.h SequenceDB.h Alphabet.h \
  Core/AutoPtr.h Assignment.h /usr/include/c++/3.2/bitset \
  /usr/include/c++/3.2/istream /usr/include/c++/3.2/bits/istream.tcc \
  HyperGeoCache.h ExtraMath.h Legacy/mathplus.h
main.o: main.cpp SequenceDB.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Alphabet.h Sequence.h Defs.h \
  Persistance/Object.h Persistance/Defs.h Core/ChunkAllocator.h \
  Core/dlmalloc.h Core/Str.h Cluster.h /usr/include/c++/3.2/map \
  /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h PrefixTreePreprocessor.h \
  Preprocessor.h Core/AutoPtr.h Assignment.h /usr/include/c++/3.2/bitset \
  /usr/include/c++/3.2/istream /usr/include/c++/3.2/bits/istream.tcc \
  RandomProjections.h SeedSearcher.h HyperGeoScore.h HyperGeoCache.h \
  ExtraMath.h PrefixTreeWalker.h PSSM.h /usr/include/c++/3.2/iostream \
  StdOptions.h AssignmentFormat.h Persistance/AbstractFormat.h \
  Persistance/TextWriter.h DebugLog.h /usr/include/getopt.h \
  Persistance/StdOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/UnbufferedChannel.h Persistance/InputStream.h \
  Persistance/StdInputStream.h Persistance/TFactory.h \
  Persistance/OArchive.h Persistance/ORegistry.h Persistance/Error.h \
  Persistance/IArchive.h Persistance/IRegistry.h Persistance/TextReader.h \
  /usr/include/c++/3.2/fstream \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/basic_file.h \
  /usr/include/c++/3.2/bits/fstream.tcc
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h SequenceDB.h Alphabet.h \
  Sequence.h Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h Core/dlmalloc.h Core/Str.h Cluster.h \
  /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Core/AutoPtr.h \
  PrefixTreeWalker.h Assignment.h /usr/include/c++/3.2/bitset \
  /usr/include/c++/3.2/istream /usr/include/c++/3.2/bits/istream.tcc \
  Persistance/IArchive.h Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h Persistance/TFactory.h \
  Persistance/Error.h Persistance/OArchive.h Persistance/ORegistry.h \
  Persistance/TextWriter.h DebugLog.h Persistance/AbstractFormat.h \
  AssignmentFormat.h Persistance/STLPersist.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp PrefixTreeWalker.h Assignment.h \
  Core/Defs.h Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Persistance/Defs.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc PrefixTreePreprocessor.h \
  Preprocessor.h Defs.h SequenceDB.h Alphabet.h Sequence.h \
  Persistance/Object.h Core/ChunkAllocator.h Core/dlmalloc.h Core/Str.h \
  Cluster.h /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Core/AutoPtr.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Persistance/Defs.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc PrefixTreePreprocessor.h \
  Preprocessor.h Defs.h SequenceDB.h Alphabet.h Sequence.h \
  Persistance/Object.h Core/ChunkAllocator.h Core/dlmalloc.h Core/Str.h \
  Cluster.h /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Core/AutoPtr.h \
  /usr/include/c++/3.2/iostream
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h Core/Defs.h Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Persistance/Defs.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc ExtraMath.h \
  Legacy/RandomGenerator.h Legacy/Multinomial.h \
  /usr/include/c++/3.2/iostream DebugLog.h Persistance/TextWriter.h \
  Persistance/AbstractFormat.h Core/AutoPtr.h AssignmentFormat.h
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h PrefixTreePreprocessor.h \
  Preprocessor.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h SequenceDB.h Alphabet.h \
  Sequence.h Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h Core/dlmalloc.h Core/Str.h Cluster.h \
  /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Core/AutoPtr.h Assignment.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc PrefixTreeWalker.h DebugLog.h \
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  AssignmentFormat.h Core/HashTable.h Persistance/StrOutputStream.h \
  Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h /usr/include/c++/3.2/iostream
Sequence.o: Sequence.cpp Sequence.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Persistance/Object.h Persistance/Defs.h \
  Core/ChunkAllocator.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Core/dlmalloc.h Core/Str.h \
  Persistance/OArchive.h Persistance/ORegistry.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Persistance/TFactory.h \
  Persistance/Error.h Persistance/TextWriter.h Core/AutoPtr.h \
  Persistance/IArchive.h Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/STLPersist.h /usr/include/c++/3.2/map \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo Sequence.h Defs.h Persistance/Object.h \
  Persistance/Defs.h Core/ChunkAllocator.h /usr/include/c++/3.2/vector \
  /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Core/dlmalloc.h Core/Str.h \
  SequenceDB.h Core/STLHelper.h Alphabet.h Cluster.h \
  /usr/include/c++/3.2/map /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h Persistance/OArchive.h \
  Persistance/ORegistry.h Persistance/TFactory.h Persistance/Error.h \
  Persistance/TextWriter.h Core/AutoPtr.h Persistance/IArchive.h \
  Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/StdInputStream.h Persistance/UnbufferedChannel.h \
  Persistance/InputStream.h Persistance/OutputStream.h \
  /usr/include/c++/3.2/istream /usr/include/c++/3.2/bits/istream.tcc \
  /usr/include/c++/3.2/fstream \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/basic_file.h \
  /usr/include/c++/3.2/bits/fstream.tcc /usr/include/c++/3.2/iostream \
  Persistance/STLPersist.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.2/string \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++config.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/c++/3.2/bits/stringfwd.h \
  /usr/include/c++/3.2/bits/char_traits.h /usr/include/c++/3.2/cstring \
  /usr/include/c++/3.2/cstddef \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/include/c++/3.2/bits/fpos.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++io.h \
  /usr/include/c++/3.2/cstdio \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdio.h \
  /usr/include/bits/types.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h /usr/include/libio.h /usr/include/_G_config.h \
  /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/time.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/initspin.h \
  /usr/include/bits/sigthread.h /usr/include/c++/3.2/cwchar \
  /usr/include/c++/3.2/ctime /usr/include/c++/3.2/memory \
  /usr/include/c++/3.2/bits/stl_algobase.h /usr/include/c++/3.2/climits \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/limits.h \
  /usr/lib/gcc-lib/i586-mandrake-linux-gnu/3.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/wordsize.h /usr/include/c++/3.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/include/c++/3.2/new /usr/include/c++/3.2/exception \
  /usr/include/c++/3.2/iosfwd /usr/include/c++/3.2/bits/functexcept.h \
  /usr/include/c++/3.2/exception_defines.h \
  /usr/include/c++/3.2/bits/stl_pair.h \
  /usr/include/c++/3.2/bits/type_traits.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_types.h \
  /usr/include/c++/3.2/bits/stl_iterator_base_funcs.h \
  /usr/include/c++/3.2/bits/concept_check.h \
  /usr/include/c++/3.2/bits/stl_iterator.h \
  /usr/include/c++/3.2/bits/stl_alloc.h /usr/include/c++/3.2/cassert \
  /usr/include/assert.h /usr/include/c++/3.2/bits/stl_threads.h \
  /usr/include/c++/3.2/bits/stl_construct.h \
  /usr/include/c++/3.2/bits/stl_uninitialized.h \
  /usr/include/c++/3.2/bits/stl_raw_storage_iter.h \
  /usr/include/c++/3.2/bits/stl_function.h \
  /usr/include/c++/3.2/bits/basic_string.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/atomicity.h \
  /usr/include/c++/3.2/algorithm /usr/include/c++/3.2/bits/stl_algo.h \
  /usr/include/c++/3.2/bits/stl_heap.h \
  /usr/include/c++/3.2/bits/stl_tempbuf.h \
  /usr/include/c++/3.2/bits/basic_string.tcc /usr/include/c++/3.2/ostream \
  /usr/include/c++/3.2/ios /usr/include/c++/3.2/bits/localefwd.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/c++locale.h \
  /usr/include/c++/3.2/clocale /usr/include/locale.h \
  /usr/include/bits/locale.h /usr/include/c++/3.2/cctype \
  /usr/include/ctype.h /usr/include/c++/3.2/bits/ios_base.h \
  /usr/include/c++/3.2/streambuf /usr/include/c++/3.2/bits/streambuf.tcc \
  /usr/include/c++/3.2/bits/basic_ios.h \
  /usr/include/c++/3.2/bits/streambuf_iterator.h \
  /usr/include/c++/3.2/bits/locale_facets.h /usr/include/c++/3.2/cwctype \
  /usr/include/wctype.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_base.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/ctype_inline.h \
  /usr/include/c++/3.2/bits/codecvt.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/codecvt_specializations.h \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/messages_members.h \
  /usr/include/c++/3.2/bits/basic_ios.tcc \
  /usr/include/c++/3.2/bits/ostream.tcc /usr/include/c++/3.2/locale \
  /usr/include/c++/3.2/bits/locale_facets.tcc /usr/include/c++/3.2/cerrno \
  /usr/include/errno.h /usr/include/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/c++/3.2/cmath /usr/include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/nan.h \
  /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
  /usr/include/c++/3.2/bits/cmath.tcc /usr/include/c++/3.2/limits \
  /usr/include/c++/3.2/i586-mandrake-linux-gnu/bits/cpu_limits.h \
  /usr/include/c++/3.2/typeinfo SequenceDB.h Core/STLHelper.h \
  /usr/include/c++/3.2/vector /usr/include/c++/3.2/bits/stl_vector.h \
  /usr/include/c++/3.2/bits/stl_bvector.h Alphabet.h Sequence.h \
  Persistance/Object.h Persistance/Defs.h Core/ChunkAllocator.h \
  Core/dlmalloc.h Core/Str.h Cluster.h /usr/include/c++/3.2/map \
  /usr/include/c++/3.2/bits/stl_tree.h \
  /usr/include/c++/3.2/bits/stl_map.h \
  /usr/include/c++/3.2/bits/stl_multimap.h /usr/include/c++/3.2/set \
  /usr/include/c++/3.2/bits/stl_set.h \
  /usr/include/c++/3.2/bits/stl_multiset.h SeedSearcher.h \
  PrefixTreePreprocessor.h Preprocessor.h Core/AutoPtr.h Assignment.h \
  /usr/include/c++/3.2/bitset /usr/include/c++/3.2/istream \
  /usr/include/c++/3.2/bits/istream.tcc AssignmentFormat.h \
  Persistance/AbstractFormat.h HyperGeoCache.h ExtraMath.h \
  Persistance/TextWriter.h DebugLog.h
