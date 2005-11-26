#ifndef _SeedSearcher__ConfReader_h
#define _SeedSearcher__ConfReader_h

#include "Core/Defs.h"
#include "Core/Str.h"
#include "Persistance/TextWriter.h"



class ConfReader  {
    //
    // This class allows the creation of 'local' configuration repositories
public:
    static const char* defaultHost; // = NULL
    static const char* defaultKey;  // = NULL

    class Package;
    class Iterator;
    class HostIterator;
    class Shared;

    //
    // exceptions
    class GeneralError;
    class ConfigError;
    class PackageNotFound;
    class ValueNotFound;


    //
    // Rep fwd declarations
    class Rep;
    class PackageRep;
    class SubPackageRep;
    class RootPackageRep;
    class EmptyPackageRep;
    class HostIteratorRep;
    class IteratorRep;
public:
    ConfReader ();
    ConfReader (const Str& /* inSourceName */);
    ConfReader (const Str& /* inBootstrapName */, const Str& /* inSourceNameDefault */);
    ~ConfReader ();

    //
    // direct the source to a config file, either directly or through bootstrap
    // the bootstrap/conf files are considered to be in the same directory as the executable
    //
    bool bootstrap (const Str& /* inBootstrapName */);
    bool bootstrap (const Str& /* inBootstrapName */, const Str& /* inSourceNameDefault */);
    bool setup (const Str& /* inSourceName */);

    //
    // returns a nil implementation, if the package does not exist    
    PackageRep* tryGetPackage (const Str& name, 
                               const Str& host = defaultHost,
                               bool searchGlobal = true);


    //
    // throws an exception if the package does not exist
    PackageRep* getPackage (const Str& name, 
                            const Str& host = defaultHost,
                            bool searchGlobal = true);


	//
    // returns true if the configuration source file exists
    bool valid ();

    // 
    // returns the spec for the configuration boot/source file
    //const FileSpec& source ();
    //const FileSpec& boot ();
    const Str& source ();
    const Str& boot ();

   // 
   // this method takes the hassle of appending a relative path to another path.
   static void appendPath (StrBuffer&, const Str&, const Str&);

    //
    // returns the implementation object
    Rep* getRep ();

private:
    Rep* rep;
};
    
    
    
    
    
    
    
class ConfReader::Package   {
    //
    // encapsulates configuration information for a particular, named, 
    // server component. 
    //
public:
    Package ();
    ~Package ();
    explicit Package (PackageRep*);

    //
    // sets / get the rep member of package. 
    PackageRep* getRep ();
    void setRep (PackageRep*);

    //
    // returns true if the package exists.
    bool valid ();

    //
    // if the package is valid, returns its name
    Str name ();

    //
    // returns a nil implementation, if the package does not exist
    PackageRep* tryCreateSubPackage (const Str& name);

    //
    // throws an exception if the package does not exist
    PackageRep* createSubPackage (const Str& name);

    //
    // return 'true' if key exists
	bool get (const Str&, StrBuffer& outString);
	bool get (const Str&, int& outNumber);
	bool get (const Str&, bool& outBool);
	bool get (const Str&, float& outFloat);
	//bool get (const Str&, FileSpec& out);
   //bool get (const Str&, int64_t&, const char* = 0);

    //
    // throw an exception if value does not exist
   void mustGet (const Str&, StrBuffer& outString);
	void mustGet (const Str&, int& outNumber);
	void mustGet (const Str&, bool& outBool);
	void mustGet (const Str&, float& outFloat);
	//void mustGet (const Str&, FileSpec& out);
   //void mustGet (const Str&, int64_t&, const char* = 0);

private:
    PackageRep* rep;
};


class ConfReader::Iterator  {
    //
    // Allows dynamic sub-paths discovery from a package or known path.
    //
public:
    Iterator (Package&, const Str& subkey = defaultKey);
    Iterator (PackageRep&, const Str& subkey = defaultKey);
    ~Iterator ();

    bool atEnd ();
    void next ();
    //
    // returns relative path, with a '/' prefix
    const Str& get ();
    //
    // returns relative path without the '/' prefix
    Str getName () {
       return get().substring (1);
    }

    StrBuffer operator + (const Str&);
    // appends 

private:
    IteratorRep* rep;
};



class ConfReader::HostIterator  {
    //
    // allows user to iterate over all configurations of a package
    // e.g. over all the specializations of that package for specific hosts.
    //
public:
//    HostIterator (const Str& packageName);
    HostIterator (ConfReader&, const Str& packageName);
    ~HostIterator ();

    bool atEnd ();
    void next ();

    //
    // returns a rep of the package for the particular host
    PackageRep* get ();

    //
    // returns the name of the host
    const char* name ();

private:
    HostIteratorRep* rep;
};


//
// Exceptions
//


class ConfReader::GeneralError : public BaseException    {
    //
    //
};



class ConfReader::ConfigError : public ConfReader::GeneralError    {
    //
    //
public:
	ConfigError (const Str& /* inError */);
    ConfigError (const Str& /* inError */, const Str& /* inPackageName */);
    ConfigError (const Str& /* inError */, const Str& /* inPackageName */, const Str& /* inValueName */);

    virtual void explain (std::ostream &);

protected:
	StrBuffer message;
};



class ConfReader::PackageNotFound : public ConfReader::GeneralError    {
    //
    //
public:
	PackageNotFound (const Str& /* inPackageName */);
   virtual void explain (std::ostream&);

private:
    StrBuffer package;
};


class ConfReader::ValueNotFound : public ConfReader::GeneralError  {
    //
    //
public:
	ValueNotFound (const Str& /* inPackageName */, const Str& /* inValueName */);
   virtual void explain (std::ostream&);

private:
    StrBuffer package;
    StrBuffer value;
};



class ConfReader::Shared {
    //
    // This class facilitates sharing & using configuration information
    // by providing a single, global, entry point.
    //
public:
   static ConfReader& get ();
    //
    // returns a nil implementation, if the package does not exist    
    static PackageRep* tryGetPackage (const Str& name, 
                                      const Str& host = defaultHost,
                                      bool searchGlobal = true);


    //
    // throws an exception if the package does not exist
    static PackageRep* getPackage (const Str& name, 
                                   const Str& host = defaultHost,
                                   bool searchGlobal = true);


   //
   // returns true if the configuration source file exists
   static bool valid ();


   // 
   // returns the spec for the configuration source file
   //static const FileSpec& source ();
   static const Str& source ();

	//
	// sets the configuration source file, disables bootsrapping, works only if configuration was not loaded yet
	static void setSource (const Str&);
};

#endif

/* $Header: /home/cvs/Lib/Server/Util/ConfReader.h,v 1.19 2001/12/31 15:00:55 aviad Exp $	

    Utility classes that help to share configuration information 
across different Server componenent.

$Author: Aviad 11/10/2000 

*/
