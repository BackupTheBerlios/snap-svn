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
	rm -r -f seed
	rm -r -f winseed.exe
	rm -r -f Debug
	rm -r -f Release

tags:
	etags --language=c++ *.h *.cpp

# DO NOT DELETE
Alphabet.o: Alphabet.cpp Alphabet.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/Str.h
Assignment.o: Assignment.cpp Assignment.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Alphabet.h Core/Str.h \
  Persistance/TextWriter.h Persistance/StdOutputStream.h \
  Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h Persistance/UnbufferedChannel.h \
  Persistance/InputStream.h DebugLog.h Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h Core/AutoPtr.h AssignmentFormat.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SequenceDB.h Alphabet.h
DebugLog.o: DebugLog.cpp DebugLog.h Persistance/Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h Core/AutoPtr.h AssignmentFormat.h \
  Assignment.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc /usr/include/c++/3.3.1/bitset \
  Core/Str.h Persistance/OutputStream.h Persistance/StreamBuffer.h \
  Persistance/IODefs.h Persistance/UnbufferedChannel.h \
  Persistance/InputStream.h Persistance/StdOutputStream.h \
  /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc
Feature.o: Feature.cpp Feature.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Cluster.h Sequence.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h PSSM.h \
  Alphabet.h DebugLog.h Persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h Legacy/MathFunctions.h /usr/include/assert.h ExtraMath.h
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h Legacy/MathPlus.h SeedSearcher.h \
  Feature.h Defs.h Cluster.h Sequence.h Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h PSSM.h \
  Alphabet.h DebugLog.h Persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h PrefixTreePreprocessor.h Core/HashTable.h
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset HyperGeoScore.h Cluster.h Sequence.h \
  Defs.h Core/Str.h Core/PoolAllocated.h boost/pool/object_pool.hpp \
  boost/pool/poolfwd.hpp boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h PSSM.h Alphabet.h DebugLog.h \
  Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
  PrefixTreePreprocessor.h HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset LeafPreprocessor.h Preprocessor.h Defs.h \
  SequenceDB.h Alphabet.h Core/Str.h Sequence.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedHash.h DebugLog.h \
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h AssignmentFormat.h Core/HashTable.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Alphabet.h Core/Str.h Sequence.h Defs.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc /usr/include/assert.h
Parser.o: Parser.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Persistance/TextWriter.h Core/Str.h
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
  PrefixTreePreprocessor.h Preprocessor.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  SequenceDB.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3.1/bitset Persistance/IArchive.h \
  Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h Persistance/TFactory.h \
  Persistance/Object.h Persistance/Error.h Persistance/OArchive.h \
  Persistance/ORegistry.h Persistance/TextWriter.h DebugLog.h \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h \
  AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  SequenceDB.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3.1/bitset
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
  Assignment.h Core/Defs.h Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset ExtraMath.h Legacy/MathFunctions.h \
  /usr/include/assert.h Legacy/MathPlus.h Legacy/RandomGenerator.h \
  Legacy/Multinomial.h DebugLog.h Persistance/TextWriter.h \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h \
  Core/AutoPtr.h AssignmentFormat.h Core/Str.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Cluster.h Sequence.h Defs.h Core/Str.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h DebugLog.h \
  Persistance/TextWriter.h Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h AssignmentFormat.h Core/HashTable.h \
  Persistance/StrOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
  Core/Defs.h Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Cluster.h Sequence.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Legacy/MathPlus.h Core/AutoPtr.h \
  /usr/include/c++/3.3.1/map /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h PSSM.h \
  Alphabet.h DebugLog.h Persistance/TextWriter.h Preprocessor.h \
  SequenceDB.h PrefixTreePreprocessor.h SeedHash.h Core/HashTable.h \
  Persistance/StrOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h boost/timer.hpp \
  boost/limits.hpp
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
  Core/Defs.h Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Parser.h Persistance/TextWriter.h Sequence.h Core/STLHelper.h \
  Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h PSSM.h Alphabet.h DebugLog.h \
  Preprocessor.h SequenceDB.h PrefixTreePreprocessor.h \
  RandomProjections.h StdOptions.h HyperGeoCache.h /usr/include/assert.h \
  ExtraMath.h Legacy/MathFunctions.h LeafPreprocessor.h SeedHash.h \
  Core/HashTable.h HyperGeoScore.h
Sequence.o: Sequence.cpp Sequence.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Core/STLHelper.h Core/Core/Defs.h /usr/include/c++/3.3.1/vector \
  /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Persistance/OArchive.h \
  Persistance/Defs.h Persistance/ORegistry.h Persistance/Object.h \
  /usr/include/c++/3.3.1/set /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Persistance/TFactory.h \
  Persistance/Error.h Persistance/TextWriter.h Core/AutoPtr.h \
  Persistance/IArchive.h Persistance/IRegistry.h Persistance/TextReader.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/STLPersist.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h
SequenceDB.o: SequenceDB.cpp Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Sequence.h Defs.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Core/Str.h Core/PoolAllocated.h \
  boost/pool/object_pool.hpp boost/pool/poolfwd.hpp boost/config.hpp \
  boost/config/user.hpp boost/config/select_compiler_config.hpp \
  boost/config/compiler/gcc.hpp boost/config/select_stdlib_config.hpp \
  /usr/include/c++/3.3.1/utility /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc SequenceDB.h Alphabet.h Cluster.h \
  Legacy/MathPlus.h Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h AssignmentFormat.h \
  Assignment.h Persistance/Defs.h /usr/include/c++/3.3.1/bitset \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h \
  /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc /usr/include/assert.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h Core/Defs.h \
  Core/Compiler.h /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  SequenceDB.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h SeedSearcher.h Feature.h \
  AssignmentFormat.h Assignment.h Persistance/Defs.h \
  /usr/include/c++/3.3.1/bitset Persistance/AbstractFormat.h \
  Persistance/Persistance/Defs.h PSSM.h DebugLog.h \
  Persistance/TextWriter.h Preprocessor.h PrefixTreePreprocessor.h \
  HyperGeoCache.h /usr/include/assert.h ExtraMath.h \
  Legacy/MathFunctions.h
main.o: main.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
  /usr/include/c++/3.3.1/string \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++config.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/os_defines.h \
  /usr/include/c++/3.3.1/bits/stringfwd.h \
  /usr/include/c++/3.3.1/bits/char_traits.h \
  /usr/include/c++/3.3.1/cstring /usr/include/c++/3.3.1/cstddef \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/cygwin/config.h /usr/include/sys/reent.h \
  /usr/include/sys/_types.h /usr/include/c++/3.3.1/bits/fpos.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++io.h \
  /usr/include/c++/3.3.1/cstdio /usr/include/stdio.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/sys/features.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/sys/stdio.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr.h \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/include/c++/3.3.1/cwchar /usr/include/c++/3.3.1/ctime \
  /usr/include/wchar.h /usr/include/c++/3.3.1/memory \
  /usr/include/c++/3.3.1/bits/stl_algobase.h \
  /usr/include/c++/3.3.1/climits \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/limits.h \
  /usr/lib/gcc-lib/i686-pc-cygwin/3.3.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/c++/3.3.1/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/c++/3.3.1/new \
  /usr/include/c++/3.3.1/exception /usr/include/c++/3.3.1/iosfwd \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/c++locale.h \
  /usr/include/c++/3.3.1/clocale /usr/include/locale.h \
  /usr/include/c++/3.3.1/cctype /usr/include/ctype.h \
  /usr/include/c++/3.3.1/bits/functexcept.h \
  /usr/include/c++/3.3.1/exception_defines.h \
  /usr/include/c++/3.3.1/bits/stl_pair.h \
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
  Persistance/TextWriter.h SequenceDB.h Core/STLHelper.h Core/Core/Defs.h \
  /usr/include/c++/3.3.1/vector /usr/include/c++/3.3.1/bits/stl_vector.h \
  /usr/include/c++/3.3.1/bits/stl_bvector.h \
  /usr/include/c++/3.3.1/bits/vector.tcc Alphabet.h Core/Str.h Sequence.h \
  Core/PoolAllocated.h boost/pool/object_pool.hpp boost/pool/poolfwd.hpp \
  boost/config.hpp boost/config/user.hpp \
  boost/config/select_compiler_config.hpp boost/config/compiler/gcc.hpp \
  boost/config/select_stdlib_config.hpp /usr/include/c++/3.3.1/utility \
  /usr/include/c++/3.3.1/bits/stl_relops.h \
  boost/config/stdlib/libstdcpp3.hpp \
  boost/config/select_platform_config.hpp \
  boost/config/platform/cygwin.hpp boost/config/posix_features.hpp \
  boost/config/suffix.hpp boost/pool/detail/mutex.hpp boost/pool/pool.hpp \
  /usr/include/c++/3.3.1/functional boost/pool/detail/ct_gcd_lcm.hpp \
  boost/static_assert.hpp boost/detail/workaround.hpp \
  boost/type_traits/ice.hpp boost/type_traits/detail/yes_no_type.hpp \
  boost/type_traits/detail/ice_or.hpp \
  boost/type_traits/detail/ice_and.hpp \
  boost/type_traits/detail/ice_not.hpp \
  boost/type_traits/detail/ice_eq.hpp boost/pool/detail/gcd_lcm.hpp \
  boost/pool/simple_segregated_storage.hpp \
  boost/pool/detail/pool_construct.inc Cluster.h Legacy/MathPlus.h \
  Core/AutoPtr.h /usr/include/c++/3.3.1/map \
  /usr/include/c++/3.3.1/bits/stl_tree.h \
  /usr/include/c++/3.3.1/bits/stl_map.h \
  /usr/include/c++/3.3.1/bits/stl_multimap.h /usr/include/c++/3.3.1/set \
  /usr/include/c++/3.3.1/bits/stl_set.h \
  /usr/include/c++/3.3.1/bits/stl_multiset.h Assignment.h \
  Persistance/Defs.h /usr/include/c++/3.3.1/bitset RandomProjections.h \
  SeedSearcher.h Feature.h AssignmentFormat.h \
  Persistance/AbstractFormat.h Persistance/Persistance/Defs.h PSSM.h \
  DebugLog.h Preprocessor.h PrefixTreePreprocessor.h HyperGeoScore.h \
  HyperGeoCache.h /usr/include/assert.h ExtraMath.h \
  Legacy/MathFunctions.h SeedSearcherMain.h StdOptions.h \
  Persistance/StdOutputStream.h Persistance/OutputStream.h \
  Persistance/StreamBuffer.h Persistance/IODefs.h \
  Persistance/UnbufferedChannel.h Persistance/InputStream.h \
  Persistance/StdInputStream.h /usr/include/c++/3.3.1/fstream \
  /usr/include/c++/3.3.1/i686-pc-cygwin/bits/basic_file.h \
  /usr/include/c++/3.3.1/bits/fstream.tcc /usr/include/c++/3.3.1/queue \
  /usr/include/c++/3.3.1/bits/stl_deque.h \
  /usr/include/c++/3.3.1/bits/stl_queue.h \
  /usr/include/c++/3.3.1/bits/deque.tcc
