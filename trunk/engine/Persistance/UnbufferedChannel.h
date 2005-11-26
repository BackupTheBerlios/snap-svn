#ifndef _SeedSearcher_Persistance_UnbufferedStream
#define _SeedSearcher_Persistance_UnbufferedStream

#include "IODefs.h"
#include "InputStream.h"
#include "OutputStream.h"

BEGIN_NAMESPACE (Persistance);

//
// base class for unbuffered streams, useful for integration
// with other strean libraries like iostream
class UnbufferedStream : public IODefs {
public:
   virtual ~UnbufferedStream () {
   }
   virtual bool hasMoreBuffers() const = 0;
};


//
// base class for unbuffered stream output
class UnbufferedOutput : public virtual UnbufferedStream {
public:
   virtual ~UnbufferedOutput () {
   }
   virtual void writeBytes(const void* inPtr, Size inSize) = 0;
   virtual void flush () = 0;
};



//
// concrete class useful for multiplexing data to several UnbufferedStreams
// like writing to file and console at the same time
class UnbufferedOutputMux : public UnbufferedOutput {
public:
   enum {
      MAX_NUMBER_OF_STREAMS = 32
   };

   UnbufferedOutputMux (UnbufferedOutput** inStreams, int inSize, bool owner)
   : _numOfStreams (inSize), _owner (owner) {
      debug_mustbe (_numOfStreams <= MAX_NUMBER_OF_STREAMS);
      memcpy ( _streams, 
               inStreams, 
               _numOfStreams * sizeof (UnbufferedOutput*));
   }
   virtual ~UnbufferedOutputMux () {
      if (_owner) {
         for (int i=0 ; i<_numOfStreams; i++)
            delete _streams [i];
      }
   }
   virtual void writeBytes(const void* inPtr, Size inSize) {
      for (int i=0 ; i<_numOfStreams ; i++) {
         _streams [i]->writeBytes (inPtr, inSize);
      }
   }
   virtual void flush () {
      for (int i=0 ; i<_numOfStreams ; i++) {
         _streams [i]->flush ();
      }
   }
   virtual bool hasMoreBuffers() const {
      //
      // TODO: ???
      return true;
   }

private:
   UnbufferedOutput* _streams [MAX_NUMBER_OF_STREAMS];
   int _numOfStreams;
   bool _owner;
};


//
// OutputStream wrapper over UnbufferedOutput, with static buffer
template <int N>
class SChannelOutput : public OutputStream {
public:
   SChannelOutput (UnbufferedOutput* output, bool owner)
   : _output (output), _owner (owner)   {
   }
   virtual ~SChannelOutput () {
      if (_owner)
         delete _output;
   }

protected:
   virtual void nextBuffer() {
      Size bytes = bytesInBuffer ();
      if (bytes > 0) {
         _output->writeBytes (_buffer, bytes);
      }

   	setupBuffer (reinterpret_cast<Ptr> (_buffer), sizeof (_buffer));
   }
   virtual bool hasMoreBuffers() const {
      return _output->hasMoreBuffers ();
   }
   virtual void flush () {
      OutputStream::flush ();
      _output->flush ();
   }

protected:
   UnbufferedOutput* _output;
   char _buffer [N];
   bool _owner;
};



//
// OutputStream wrapper over UnbufferedOutput, with dynamic buffer
class DChannelOutput : public OutputStream {
public:
   DChannelOutput (UnbufferedOutput* output, bool owner, int bufSize)
   : _bufSize (bufSize), _output (output), _owner (owner)   
   {
      _buffer = new char [_bufSize];
   }
   virtual ~DChannelOutput () {
      delete [] _buffer;
      if (_owner)
         delete _output;
   }

protected:
   virtual void nextBuffer() {
      Size bytes = bytesInBuffer ();
      if (bytes > 0) {
         _output->writeBytes (_buffer, bytes);
      }

   	setupBuffer (reinterpret_cast<Ptr> (_buffer), sizeof (_buffer));
   }
   virtual bool hasMoreBuffers() const {
      return _output->hasMoreBuffers ();
   }
   virtual void flush () {
      OutputStream::flush ();
      _output->flush ();
   }

protected:
   int _bufSize;
   UnbufferedOutput* _output;
   char* _buffer;
   bool _owner;
};






//
// base class for unbuffered stream input
class UnbufferedInput : public virtual UnbufferedStream {
public:
   virtual ~UnbufferedInput () {
   }
   virtual Size readBytes(void* outPtr, Size outSize) = 0;
};


//
// InputStream wrapper over UnbufferedInput, with static buffer
template <int N>
class SChannelInput : public InputStream {
public:
   SChannelInput (UnbufferedInput* input, bool owner)
   : _input (input), _owner (owner)   {
   }
   virtual ~SChannelInput () {
      if (_owner)
         delete _input;
   }

protected:
   virtual void nextBuffer() {
      Size bytesRead = _input->readBytes (_buffer, sizeof (_buffer));
      setupBuffer (reinterpret_cast<Ptr> (_buffer), bytesRead);
   }
   virtual bool hasMoreBuffers() const {
      return _input->hasMoreBuffers ();
   }
   virtual void flush () {
      //nothing to flush on read
   }

protected:
   UnbufferedInput* _input;
   char _buffer [N];
   bool _owner;
};


//
// InputStream wrapper over UnbufferedInput, with dynamic buffer
class DChannelInput : public InputStream {
public:
   DChannelInput (UnbufferedInput* input, bool owner, int bufSize)
   : _bufSize (bufSize), _input (input), _owner (owner)   
   {
      _buffer = new char [_bufSize];
   }
   virtual ~DChannelInput () {
      delete [] _buffer;
      if (_owner)
         delete _input;
   }

protected:
   virtual void nextBuffer() {
      Size bytesRead = _input->readBytes (_buffer, sizeof (_buffer));
      setupBuffer (reinterpret_cast<Ptr> (_buffer), bytesRead);
   }
   virtual bool hasMoreBuffers() const {
      return _input->hasMoreBuffers ();
   }
   virtual void flush () {
      //nothing to flush on read
   }

protected:
   int _bufSize;
   UnbufferedInput* _input;
   char* _buffer;
   bool _owner;
};



typedef SChannelOutput <8 * 1024> SmallChannelOutput;
typedef SChannelInput <8 * 1024> SmallChannelInput;



END_NAMESPACE (Persistance);

#endif // _SeedSearcher_Persistance_UnbufferedStream







