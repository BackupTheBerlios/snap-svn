#flags for release version
#CCFLAGS = -g -Wall -O0
CCFLAGS = -O3 -Wall -DNDEBUG

#CC = g++
CC = g++-3.0
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
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/Str.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/memory \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_raw_storage_iter.h
Assignment.o: Assignment.cpp Assignment.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Alphabet.h Core/Str.h Persistance/TextWriter.h \
 Persistance/StdOutputStream.h Persistance/OutputStream.h \
 Persistance/StreamBuffer.h Persistance/IODefs.h \
 Persistance/UnbufferedChannel.h Persistance/InputStream.h DebugLog.h \
 Persistance/AbstractFormat.h Core/AutoPtr.h AssignmentFormat.h
Cluster.o: Cluster.cpp Cluster.h Sequence.h Defs.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 SequenceDB.h Alphabet.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h
DebugLog.o: DebugLog.cpp DebugLog.h Persistance/Defs.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Persistance/TextWriter.h Persistance/AbstractFormat.h Core/AutoPtr.h \
 AssignmentFormat.h Assignment.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Core/Str.h Persistance/OutputStream.h Persistance/StreamBuffer.h \
 Persistance/IODefs.h Persistance/UnbufferedChannel.h \
 Persistance/InputStream.h Persistance/StdOutputStream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream.h
Feature.o: Feature.cpp Feature.h Defs.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Cluster.h Sequence.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 AssignmentFormat.h Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
 Persistance/TextWriter.h Preprocessor.h SequenceDB.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Legacy/MathFunctions.h ExtraMath.h
HyperGeoCache.o: HyperGeoCache.cpp Assignment.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 HyperGeoCache.h ExtraMath.h Legacy/MathFunctions.h \
 /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Legacy/MathPlus.h SeedSearcher.h Feature.h Defs.h Cluster.h \
 Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 AssignmentFormat.h Persistance/AbstractFormat.h PSSM.h Alphabet.h \
 DebugLog.h Persistance/TextWriter.h PrefixTreePreprocessor.h \
 Preprocessor.h SequenceDB.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Core/HashTable.h
HyperGeoScore.o: HyperGeoScore.cpp Assignment.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 HyperGeoScore.h Cluster.h Sequence.h Defs.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 SeedSearcher.h Feature.h AssignmentFormat.h \
 Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
 Persistance/TextWriter.h PrefixTreePreprocessor.h Preprocessor.h \
 SequenceDB.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 HyperGeoCache.h ExtraMath.h Legacy/MathFunctions.h
LeafPreprocessor.o: LeafPreprocessor.cpp Assignment.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 LeafPreprocessor.h Preprocessor.h Defs.h SequenceDB.h Alphabet.h \
 Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 SeedHash.h DebugLog.h Persistance/TextWriter.h \
 Persistance/AbstractFormat.h AssignmentFormat.h Core/HashTable.h
MyMain.o: MyMain.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Persistance/TextWriter.h SequenceDB.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Alphabet.h Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 RandomProjections.h SeedSearcher.h Feature.h AssignmentFormat.h \
 Persistance/AbstractFormat.h PSSM.h DebugLog.h \
 PrefixTreePreprocessor.h Preprocessor.h HyperGeoScore.h \
 HyperGeoCache.h ExtraMath.h Legacy/MathFunctions.h SeedSearcherMain.h \
 StdOptions.h Persistance/StdOutputStream.h Persistance/OutputStream.h \
 Persistance/StreamBuffer.h Persistance/IODefs.h \
 Persistance/UnbufferedChannel.h Persistance/InputStream.h \
 Persistance/StdInputStream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream.h
PSSM.o: PSSM.cpp PSSM.h Assignment.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Alphabet.h Core/Str.h Sequence.h Defs.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo \
 /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
Parser.o: Parser.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Persistance/TextWriter.h Core/Str.h /usr/include/getopt.h \
 /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
PrefixTreePreprocessor.o: PrefixTreePreprocessor.cpp \
 PrefixTreePreprocessor.h Preprocessor.h Defs.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 SequenceDB.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Alphabet.h Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/IArchive.h Persistance/IRegistry.h \
 Persistance/TextReader.h Persistance/StreamBuffer.h \
 Persistance/IODefs.h Persistance/TFactory.h Persistance/Object.h \
 Persistance/Error.h Persistance/OArchive.h Persistance/ORegistry.h \
 Persistance/TextWriter.h DebugLog.h Persistance/AbstractFormat.h \
 AssignmentFormat.h
PrefixTreeWalker.o: PrefixTreeWalker.cpp
Preprocessor.o: Preprocessor.cpp Preprocessor.h Defs.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 SequenceDB.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Alphabet.h Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept
RandomProjections.o: RandomProjections.cpp RandomProjections.h \
 Assignment.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 ExtraMath.h Legacy/MathFunctions.h /usr/include/math.h \
 /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h \
 /usr/include/bits/mathcalls.h Legacy/MathPlus.h \
 Legacy/RandomGenerator.h Legacy/Multinomial.h DebugLog.h \
 Persistance/TextWriter.h Persistance/AbstractFormat.h Core/AutoPtr.h \
 AssignmentFormat.h Core/Str.h
SeedHash.o: SeedHash.cpp SeedHash.h Assignment.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Cluster.h Sequence.h Defs.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 DebugLog.h Persistance/TextWriter.h Persistance/AbstractFormat.h \
 AssignmentFormat.h Core/HashTable.h Persistance/StrOutputStream.h \
 Persistance/OutputStream.h Persistance/StreamBuffer.h \
 Persistance/IODefs.h
SeedSearcher.o: SeedSearcher.cpp SeedSearcher.h Feature.h Defs.h \
 Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Cluster.h Sequence.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 AssignmentFormat.h Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
 Persistance/TextWriter.h PrefixTreePreprocessor.h Preprocessor.h \
 SequenceDB.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 SeedHash.h Core/HashTable.h Persistance/StrOutputStream.h \
 Persistance/OutputStream.h Persistance/StreamBuffer.h \
 Persistance/IODefs.h
SeedSearcherMain.o: SeedSearcherMain.cpp SeedSearcherMain.h Defs.h \
 Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Parser.h Persistance/TextWriter.h Sequence.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Cluster.h Legacy/MathPlus.h /usr/include/math.h \
 /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h \
 /usr/include/bits/mathcalls.h Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/AbstractFormat.h PSSM.h Alphabet.h DebugLog.h \
 PrefixTreePreprocessor.h Preprocessor.h SequenceDB.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 RandomProjections.h StdOptions.h HyperGeoCache.h ExtraMath.h \
 Legacy/MathFunctions.h LeafPreprocessor.h SeedHash.h Core/HashTable.h \
 HyperGeoScore.h
Sequence.o: Sequence.cpp Sequence.h Defs.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 Persistance/OArchive.h Persistance/Defs.h Persistance/ORegistry.h \
 Persistance/Object.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 Persistance/TFactory.h Persistance/Error.h Persistance/TextWriter.h \
 Core/AutoPtr.h Persistance/IArchive.h Persistance/IRegistry.h \
 Persistance/TextReader.h Persistance/StreamBuffer.h \
 Persistance/IODefs.h Persistance/STLPersist.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h
SequenceDB.o: SequenceDB.cpp Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Sequence.h Defs.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Core/Str.h \
 SequenceDB.h Alphabet.h Cluster.h Legacy/MathPlus.h \
 /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 AssignmentFormat.h Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/AbstractFormat.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream.h
StdOptions.o: StdOptions.cpp StdOptions.h Defs.h Core/Defs.h \
 Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 SequenceDB.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Alphabet.h Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 SeedSearcher.h Feature.h AssignmentFormat.h Assignment.h \
 Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 Persistance/AbstractFormat.h PSSM.h DebugLog.h \
 Persistance/TextWriter.h PrefixTreePreprocessor.h Preprocessor.h \
 HyperGeoCache.h ExtraMath.h Legacy/MathFunctions.h
main.o: main.cpp Parser.h Defs.h Core/Defs.h Core/Compiler.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/string \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstddef \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stddef.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/straits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cctype \
 /usr/include/ctype.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/gnu/stubs.h /usr/include/bits/types.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/cstring \
 /usr/include/string.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_config.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/include/bits/wchar.h /usr/include/gconv.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_alloc.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/exception \
 /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/assert.h /usr/include/pthread.h /usr/include/sched.h \
 /usr/include/signal.h /usr/include/bits/initspin.h \
 /usr/include/bits/sigthread.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iterator \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_relops.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/streambuf.h \
 /usr/include/libio.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/stdarg.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_iterator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/std/bastring.cc \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/iostream \
 Persistance/TextWriter.h SequenceDB.h Core/STLHelper.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/vector \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algobase.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_pair.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/type_traits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/limits.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/new.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_construct.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_uninitialized.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_vector.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_bvector.h \
 Alphabet.h Core/Str.h Sequence.h Core/ChunkAllocator.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/include/typeinfo Cluster.h \
 Legacy/MathPlus.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 Core/AutoPtr.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/map \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tree.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_function.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_map.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multimap.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/set \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_set.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_multiset.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/algorithm \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_tempbuf.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_algo.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stl_heap.h \
 Assignment.h Persistance/Defs.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/bitset \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/stdexcept \
 RandomProjections.h SeedSearcher.h Feature.h AssignmentFormat.h \
 Persistance/AbstractFormat.h PSSM.h DebugLog.h \
 PrefixTreePreprocessor.h Preprocessor.h HyperGeoScore.h \
 HyperGeoCache.h ExtraMath.h Legacy/MathFunctions.h SeedSearcherMain.h \
 StdOptions.h Persistance/StdOutputStream.h Persistance/OutputStream.h \
 Persistance/StreamBuffer.h Persistance/IODefs.h \
 Persistance/UnbufferedChannel.h Persistance/InputStream.h \
 Persistance/StdInputStream.h \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream \
 /usr/lib/gcc-lib/i386-linux/2.95.4/../../../../include/g++-3/fstream.h \
 /usr/include/stdio.h /usr/include/bits/stdio_lim.h
