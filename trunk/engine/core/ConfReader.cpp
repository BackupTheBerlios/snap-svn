#include "ConfReader.h"
//#include "ConfReaderTree.h"

//#include "IO/FileSpec.h"
#include "core/AutoPtr.h"
#include "core/Str.h"


//#include "Base/int64_t.h"
#include "core/ImplList.h"
//#include "Data/Str.h"


//
// not very efficient but should work cross platform
static bool fileExists (const char* name)
{
   FILE* fp = fopen (name, "r");
   if (!fp) {
      //
      // probably doesnt exists
      return false;
   }

   fclose (fp);
   return true;
}

class ServerInfo {
public:
   static Str getComputerName () {
      return "Local";
   }
};



/*                      *
 *
 *  ConfReaderTree.h
 * 
 *
 *                      */




class ConfReaderTree	{
public:
    ConfReaderTree ();
    
    const Str* get(const Str& in);
    void set (const Str& inKey, const Str& inValue);
    
    class Node;
    typedef ImplCyclicList<Node> Nodes;
    
    Node* getRoot() {
        return &root; 
    }
    
    class Node : public Impl1WayNode<Node> {
    public:
        Node () : ancestor(0) {
        }
        Node (const Str& inKey, Node* inAncestor=0) 
	  : ancestor(inAncestor), key(inKey) {
        }
        ~Node();
        
        const Str& getKey() const {
            return key;
        }
        void setKey(Str inKey) {
            key= inKey;
        }
        const Str& getValue() const {
            return value;
        }
        void setValue(Str inValue) {
            value = inValue;
        }
        Nodes& getChildren() {
            return children;
        }
        
        const Nodes& getChildren() const {
            return children;
        }
        
        Node* getAncestor () {
            return ancestor;
        }
        
        const Node* getAncestor () const {
            return ancestor;
        }
        
        void getFullKey (StrBuffer&) const;
        
        Node* find(const Str& in);
        const Node* find(const Str& in) const;
        Node* findCreate(const Str& in);
        
        Node* findChild(const Str& in);
        const Node* findChild(const Str& in) const;
        
    protected:
        Node* ancestor;
        
        StrBuffer key, value;
        Nodes children;
    };
    
    class Iterator {
    public:
        Iterator(ConfReaderTree& inTree, const Str& inNode);
        Iterator(Node* inNode, const Str& inKeyPrefix= 0);
        
        bool atEnd() {
            return rep.atEnd();
        }
        void next() {
            rep.next();
            setupKey();
        }
        const Str& getKey();
        const Str& getValue();
        // 
        // return key without prefix
        Str getRelativeKey ();
        
    private:
        Nodes::ReadIterator rep;
        StrBuffer keyPrefix, curKey;
        
        void setupKey();
    };
    friend class Iterator;
    
    class	KeyIterator {
    public:
        KeyIterator(const Str& in);
        
        bool atEnd() {
            return key.empty();
        }
        const Str& get() {
            return current;
        }
        void next();
        
    private:
        Str key, current;
        Str::Index to;
        
        void setup();
    };
    
    private:
        Node root;
        Nodes& findChildList(const Str& inKey);
};





/*                                      * 
 *
 *  ConfReaderWrapper
 *
 *  A copy of:
 *  util/StringTreeConfig.h
 *
 *                                      */ 


class	ConfReaderWrapper    {
public:
    typedef Str Key;
    
    ConfReaderWrapper (ConfReaderTree::Node* inRep);
    ConfReaderWrapper () : rep (NULL)   {
    }
    ~ConfReaderWrapper ()   {
    }
    
    bool get(Key inKey);
    bool get(Key inKey, StrBuffer& outString);
    void set(Key inKey, int inNumber);
    bool get(Key inKey, int64_t& outNumber, const char* inModifier = 0);
    bool get(Key inKey, int& outNumber);
    void set(Key inKey, Str inString);
    
    bool get(Key inKey, bool& outBool);
    void set(Key inKey, bool inBool);
    
    bool get(Key inKey, float& outFloat);
    void set(Key inKey, float inFloat);
    
//    bool get(Key inKey, FileSpec& out);
//    void set(Key inKey, const FileSpec &in);
    
    static void readFromFile(const Str& inConfigFile, ConfReaderTree& outTree);
    static void saveToFile(const Str& inConfigFile, ConfReaderTree& inTree);
    
    ConfReaderTree::Node* getRep ()    {
        return rep;
    }
    void setRep (ConfReaderTree::Node* inRep)    {
        rep = inRep;
    }
    
protected:
    ConfReaderTree::Node* rep;
    const Str* findKey(const Str& inKey) const;
};





/**********************************************
//
//
// ConfReaderRep.h
//
//
 **********************************************/






class ConfReader::Rep   {
    //
    //
public:
    Rep (const Str& /* inSourceSpec */);
    Rep (const Str& /* inBootstrapSpec */, const Str& /* inSourceSpec */);
    ~Rep ();

    bool isValid ();

    ConfReaderTree::Node* tryGetNode (const Str&);
    ConfReader::PackageRep* tryGetPackage (const Str&, 
					   const Str&, 
					   bool searchGlobal);
    const Str& source ()   {
        return systemSpec;
    }
    const Str& boot ()   {
        return bootSpec;
    }

private:
    void bootstrap ();
    void loadConfig ();
    ConfReader::PackageRep* loadNewPackage (const Str&);


    StrBuffer bootSpec;
    StrBuffer systemSpec;
    ConfReaderTree::Node* packagesNode;
    AutoPtr <ConfReaderTree> configTree;
};





//
//
// Package::Rep interface
//
//

class ConfReader::PackageRep  {
    //
    //
public:
    PackageRep (const Str& /* inAbsoluteName */, 
                ConfReaderTree::Node* /* inPackageRootNode */, 
                bool /* inSearchGlobal */);

    PackageRep (const Str& /* inAbsoluteName */,
				ConfReaderTree::Node* /* inPackageRootNode */, 
				const Str& /* inRemoteHost */, bool /* inSearchGlobal */);

    PackageRep (PackageRep& /* inParentPackage */, const Str& /* inRelativeName */);
    ~PackageRep () {
    }

    const Str& name ()  {
        return _name;
    }

    bool isValid ();
    bool get (const Str&, StrBuffer& outString);
	bool get (const Str&, int& outNumber   );
	bool get (const Str&, bool& outBool    );
	bool get (const Str&, float& outFloat  );
//	bool get (const Str&, FileSpec& out    );
// bool get (const Str&, int64_t&, const char*);

    ConfReaderTree::Node* getLocalNode ();
    ConfReaderTree::Node* getGlobalNode ();

protected:
    StrBuffer _name;
    ConfReaderWrapper _local;
    ConfReaderWrapper _global;
};



//
//
// ConfReader::IteratorRep interface
//
//


class ConfReader::IteratorRep   {
    //
    // This class iterates over both global and local entries of a package
    // it first iterates over global entries, ommiting those overrided by local ones.
    // it then iterates over all local entries.
public:
    IteratorRep (PackageRep& /* inRootNode */, const Str& /* inRelativePath */);
    IteratorRep ();

    bool atEnd();
    void next();
    const Str& getKey();
    const Str& getValue();

private:
    void skipOverridedEntries ();

    bool _local;
    ConfReaderWrapper _localNode;
    ConfReaderWrapper _globalNode;
    ConfReaderTree::Iterator _globalIterator;
    ConfReaderTree::Iterator _localIterator;
};










//#include "ConfReaderTree.h"


//
// ConfReaderTree implementation
// copy of Data/StringTree.cpp
//


static const char separator= '/';
static const Str sepString("/");
static ConfReaderTree::Nodes emptyList;

static inline bool isEqual (const Str& a, const Str& b)
{
    return a.equalsIgnoreCase (b);
}


ConfReaderTree::ConfReaderTree() {
}

const Str* ConfReaderTree::get(const Str& inKey) {
	Node* found= root.find(inKey);
	if (found)
		return &found->getValue();
	else
		return 0;
}

void ConfReaderTree::set(const Str& inKey, const Str& inValue) {
	Node* node= root.findCreate(inKey);
	debug_mustbe(node);
	node->setValue(inValue);
}

ConfReaderTree::Nodes& ConfReaderTree::findChildList(const Str& inKey) {
	Node* found= root.find(inKey);
	return found ? found->getChildren() : emptyList;
}

ConfReaderTree::Iterator::Iterator(ConfReaderTree& inTree, const Str& inKey) : 
	rep(inTree.findChildList(inKey)), keyPrefix(inKey), curKey() {
	setupKey();
}

ConfReaderTree::Iterator::Iterator(ConfReaderTree::Node* inNode, const Str& inKeyPrefix) : 
	rep(inNode ? inNode->getChildren() : emptyList), keyPrefix(inKeyPrefix), curKey() {
	setupKey();
}

const Str& ConfReaderTree::Iterator::getKey() {
	return curKey;
}

const Str& ConfReaderTree::Iterator::getValue() {
	return rep.get()->getValue();
}

Str ConfReaderTree::Iterator::getRelativeKey() {
	return curKey.substring (keyPrefix.length ());
}



void ConfReaderTree::Iterator::setupKey() {
	if (atEnd())
		curKey= Str(0);
	else {
		curKey= keyPrefix;
		curKey+= sepString;
		curKey+= rep.get()->getKey();
	}
}

ConfReaderTree::Node::~Node() {
	while(!children.empty())
		delete children.removeFirst();
}

const ConfReaderTree::Node* ConfReaderTree::Node::findChild(const Str& inKey) const {
	for(Nodes::ReadIterator_const i(children); !i.atEnd(); i.next()) {
		if (isEqual (i.get()->key, inKey))
			return i.get();
	}
	return 0;
}

ConfReaderTree::Node* ConfReaderTree::Node::findChild(const Str& inKey) {
	for(Nodes::ReadIterator i(children); !i.atEnd(); i.next()) {
		if (isEqual (i.get()->key, inKey))
			return i.get();
	}
	return 0;
}

const ConfReaderTree::Node* ConfReaderTree::Node::find(const Str& inKey) const {
	const Node* node= this;
	for(KeyIterator keyIter(inKey); !keyIter.atEnd(); keyIter.next()) {
		node= node->findChild(keyIter.get());
		if (!node)
			return 0;
	}
	return node;
}

ConfReaderTree::Node* ConfReaderTree::Node::find(const Str& inKey) {
	Node* node= this;
	for(KeyIterator keyIter(inKey); !keyIter.atEnd(); keyIter.next()) {
		node= node->findChild(keyIter.get());
		if (!node)
			return 0;
	}
	return node;
}

ConfReaderTree::Node* ConfReaderTree::Node::findCreate(const Str& inKey) {
	Node* node= this;
	KeyIterator keyIter(inKey);
	for(; !keyIter.atEnd(); keyIter.next()) {
		Node* found= node->findChild(keyIter.get());
		if (!found)
			break;
		node= found;
	}
	for(; !keyIter.atEnd(); keyIter.next()) {
		Node* newNode= new Node(keyIter.get(), this);
		node->children.addLast(newNode);
		node= newNode;
	}
	return node;
}

void ConfReaderTree::Node::getFullKey (StrBuffer& outFullKey) const
{
    if (ancestor)   {
        ancestor->getFullKey (outFullKey);
        outFullKey.append (getKey ());
    }
    else
        outFullKey = "";
}

ConfReaderTree::KeyIterator::KeyIterator(const Str& in)
{
    // ignore separator as first character
    key = (in.getCharAt (0) != separator)? in : in.substring (1);
	setup();
}

void ConfReaderTree::KeyIterator::setup() {
    to= key.indexOf(separator);
	if (to==Str::badIndex)
		current= key;
	else
		current= key.substring(0, to);
}

void ConfReaderTree::KeyIterator::next() {
	if (to==Str::badIndex)
		key= 0;
	else {
		key= key.substring(to + 1);
		setup();
	}
}










/**********************************************
//
//
// ConfReaderTree.cpp
//
//
 **********************************************/

//#include "IO/FileSpec.h"
//#include "util/StrUtils.h"
#include <fstream>
#include <stdio.h>



ConfReaderWrapper::ConfReaderWrapper(ConfReaderTree::Node* inRep) : rep(inRep) {
}

bool ConfReaderWrapper::get(Key inKey)
{
    //
    // returns true if the key was found
    ConfReaderTree::Node* node = rep? rep->find(inKey) : NULL;
    return node != NULL;
}

bool ConfReaderWrapper::get(Key inKey, StrBuffer& outString) {
	const Str* found= findKey(inKey);
	if (found) {
		outString= *found;
		return true;
	}
	return false;
}
void ConfReaderWrapper::set(Key inKey, int inNumber) {
	char buffer[32];
	sprintf(buffer, "%ld", inNumber);
	set(inKey, Str(buffer));
}



/*
bool ConfReaderWrapper::get(Key inKey, int64_t& outNumber, const char* inModifier) {
	StrBuffer value;
   if (get(inKey, value)) {
        return StrUtils::stringToNum (value, outNumber, inModifier);
   }
	else
		return false;
}
*/

//
// imported from StrUtils
static bool stringToNum(const char* inStr, int& outInt)
{
    debug_mustbe(inStr);
    int result = sscanf(inStr, "%d", &outInt);
    if (result==1)
        return true;
    else
        return false;
}

bool ConfReaderWrapper::get(Key inKey, int& outNumber) 
{
	StrBuffer value;
   if (get(inKey, value)) {
        return stringToNum (value, outNumber);
   }
   else {
		return false;
   }
}


void ConfReaderWrapper::set(Key inKey, Str inString) {
	if (rep) {
		ConfReaderTree::Node* node= rep->findCreate(inKey);
		if (node) {
			node->setValue(inString);
		} else {
			debug_mustfail();
		}
	}
}

static bool stringToBool (const Str& in, bool& out)
{
   if (  in.equalsIgnoreCase ("true") || in.equalsIgnoreCase ("on")) {
      out = true;
      return true;
   }
   else if (in.equalsIgnoreCase ("false") || in.equalsIgnoreCase ("off")) {
      out = false;
      return true;
   }

   return false;
}

static void boolToString (bool in, char* out)
{
   strcpy (out, in? "true" : "false");
}


bool ConfReaderWrapper::get(Key inKey, bool& outBool) {
	StrBuffer value;
	if (get (inKey, value)) 
        return stringToBool(value, outBool);
    else
    	return false;
}


void ConfReaderWrapper::set(Key inKey, bool inBool) 
{
	char s[16];
	boolToString (inBool, s);
	set(inKey, Str (s));
}

bool ConfReaderWrapper::get(Key inKey, float& outFloat) 
{
	StrBuffer value;
   if (get (inKey, value)) { 
      int result = sscanf (value, "%f", &outFloat);
      return result == 1;
   }
   else
    	return false;
}


void ConfReaderWrapper::set(Key inKey, float inFloat) 
{
	//StrBuffer s;
	//StrUtils::floatToString (inFloat, s);
   char s[128];
   sprintf (s, "%f", inFloat);
	set (inKey, Str (s));
}
/*
bool ConfReaderWrapper::get(Key inKey, FileSpec& out)
{
	StrBuffer path;
	if (get(inKey, path)) {
		try {
			out = path;
			return true;
		} catch (...) {
		}
	}
	return false;
}

void ConfReaderWrapper::set(Key inKey, const FileSpec &in)
{
	StrBuffer path;
	in.getFullPath(path);
	set(inKey, path);
}
*/

const Str* ConfReaderWrapper::findKey(const Str& inKey) const{
	if (rep) {
		ConfReaderTree::Node* found= rep->find(inKey);
		if (found)
			return &found->getValue();
	}
	return 0;
}



void ConfReaderWrapper::readFromFile(const Str& inConfigFile, ConfReaderTree& outTree) 
{
	typedef Impl1WayDataNode< StrBuffer > StrBufferNode;
	typedef ImplCyclicList< StrBufferNode > StrBufferList;
	StrBufferList fileNameList;

	char fileName[1024];
	inConfigFile.getCString (fileName, sizeof (fileName));
   //inConfigFile.getFullPath(fileName, sizeof(fileName));
   //ifstream input (fileName, ios::nocreate | ios::in, filebuf::sh_read);
   std::ifstream input (fileName);


	StrBuffer key, value;
	if (input.good()) {
		while(!input.eof()) {
			char lineBuf[256];
			input.getline(lineBuf, sizeof(lineBuf), '\n');
			if(lineBuf[0] == '#')
				continue;
			if(lineBuf[0] == '$') {
				Str line(lineBuf);
				Str::Index keyBegin= line.indexOf('"');
				Str::Index keyEnd= line.lastIndexOf('"');
				if ((keyBegin!=Str::badIndex) && (keyEnd!=Str::badIndex)) {
					StrBuffer fileName= line.substring(keyBegin+1, keyEnd);
					bool bPresent = false;
					for( StrBufferList::ReadIterator_const i(fileNameList); !i.atEnd(); i.next ()) {
						if ( fileName.equalsIgnoreCase( i->data ) ) {
							bPresent = true;
							break;
						}
					}
					if ( !bPresent )
						fileNameList.addLast( new StrBufferNode( fileName ) );
					continue;
				}	
			}
			Str line(lineBuf);
			Str::Index keyEnd= line.indexOf('=');
			if (keyEnd!=Str::badIndex) {
				key= line.substring(0, keyEnd);
				key.trim();
				value= line.substring(keyEnd+1);
				value.trim();
				outTree.set(key, value);
			}
		}
	}

	for( StrBufferList::ReadIterator i(fileNameList); !i.atEnd(); ) {
      //
      // include mechanism, use config as absolute path
      //FileSpec embConfigFile (i->data);
		StrBuffer embConfigFile (i->data);
      //
      // use current directory as relative path
      //if (!embConfigFile.exists ()) {
      if (fileExists (embConfigFile)) {
         embConfigFile.setLength (inConfigFile.lastIndexOf ("/\\"));
         embConfigFile.append (i->data);
      }
		readFromFile( embConfigFile, outTree );
		StrBufferNode* delNode = i.get();
		i.next();
		delete fileNameList.remove( delNode );
	}

	debug_mustbe( fileNameList.empty() );
}


// used for the save operation, to walk through all the tree
static void Iterate(std::ostream& out, const Str& path, const ConfReaderTree::Node* node)
{
    if (node!=NULL)
    {
        const ConfReaderTree::Nodes& nodes = node->getChildren();
        if (nodes.empty()) return;
        for (ConfReaderTree::Nodes::ReadIterator_const i(nodes.getFirst()); !i.atEnd(); i.next())
        {
            const ConfReaderTree::Node* childNode = i.get();
            const char* key = childNode->getKey().getChars();

            const char* value = childNode->getValue().getChars();
            if ((key) && (value))
                out  << path.getChars()  
                     << key 
                     << " = " 
                     << ((value)? value : "<null>") 
                     << std::endl;
            
            StrBuffer childPath = path;
            childPath.append(key); 
            childPath.append("/"); 
            Iterate(out, childPath, childNode);
        }
    }
}


void ConfReaderWrapper::saveToFile(const Str& inConfigFile, 
                                   ConfReaderTree& inTree)
{
	char fileName[1024];
	//inConfigFile.getFullPath(fileName, sizeof(fileName));
   inConfigFile.getCString (fileName, sizeof(fileName));
   std::ofstream output(fileName);
   Iterate(output, "", inTree.getRoot());
}







/**********************************************
//
//
// ConfReaderRep.cpp
//
//
 **********************************************/





//#include "ConfReaderRep.h"
//#include "Server/util/ServerInfo.h"

//
//
// What it is:
//
//  the complete ConfReader package is designed:
//
//  1. to allow applications to read configuration information from
//     persistant storage (.conf file).
//
//  2. to meet the demands of a cluster of one or more applications 
//     running on one or more hosts.
// 
//  3. to give applications maximum flexibility and ease of use.
// 
//  4. to give .conf writer an expressive langauge which is easy to use,
//     easy to understand, and is expressive.
//
//  this is achieve by building on legacy code, and extending it.
//
//  the files ConfReaderTree.* are copied from
//      util/StringTreeConfig.* & Data/StringTree.*
//
//  these were not reused directly because minor changes had to be made
//  (like supporting case-insensitiveness) which would effect other legacy code.
//
//  ConfReader.* is the application-level interface
//  ConfReaderRep.* is the implementation layer.
//
//
// How it works:
//
//  basically, a configuration file entry looks like this:
//      Packages/some_package/ALL/some_key = some_value
//
//  lets start from the right:
//      some_value is any user defined value (example "Aviad Rozenhek" might be a value)
//      some_key names the value for the application (example "Name" might be a key)
//      ALL declares that this key is valid on all hosts, we'll return to this later
//      some_package names a group of keys for the application (example "Author" might be a package)
//      Packages is the root of all packages.
//
//  since this is supposed to work in a cluster, it is useful to have
//  'global' settings, which will be true on all hosts, and also
//  'local' settings, which will be true on a specific host.
//  it is obvious, of course, that a 'local' value ALWAYS supersedes a 'global' one.
//
//  example:
//      Packages/Communication/ALL/IP = 127.0.0.1
//      Packages/Communication/Joe/IP = 172.16.0.1
//      Packages/Communication/Mike/IP = 172.16.0.2
//
//
//  in this example, applications on Joe's machine will receive the first value
//  when asking for "IP" key from "Communication" package,  
//  while applications on Mike's machine will receive the second value
//  when asking for that same key.
//
//  applications on other machines will get the third value when asking
//  for that same key.
//
//  it achieves this design by having each package instance
//  hold two pointers - 
//      one for the package's node in the ALL branch
//      one for the package's node in the 'local' branch
//
//  when a user requests a package for a key's value, it receives the 'local'
//  value, and only if it is not available, it receives the 'global' value.
//
//  this is true also for iteration. when iterating over keys in some package,
//  it will first give all the keys that are from the 'global' node 
//  and have no equivalent in the 'local' node.
//  then it gives all the keys from the 'local' node.
//
//  this makes sure that configuration like this gets the correct behavior:
//      Packages/Communication/ALL/IP/1 = 127.0.0.1
//      Packages/Communication/Joe/IP/1 = 172.16.0.1
//      Packages/Communication/Joe/IP/2 = 172.16.0.2

//
//  meaning that the application iterating over "IP" in "Communication"
//  will see only Joe's IP and not the 'global' one.
//
//  another example might help here:
//      Packages/Cache/ALL/Folder/1 = D:\Cache
//      Packages/Cache/ALL/Folder/2 = E:\Cache
//      Packages/Cache/Joe/Folder/2 = \\NetStore1\Cache
//      Packages/Cache/Joe/Folder/3 = \\NetStore1\Cache
//
//  in this example most hosts have a D Drive and an E Drive for caching,
//  except for Joe's computer, which does not have an E Drive,
//  but instead stores his cache remotely.
//
//
// 31/12/2001 AR.
//

/*
static ConfReaderTree::Node* findNodeChild (ConfReaderTree::Node* in, 
                                            const Str& key)	
{
    if (in != NULL && !key.empty ())
        return in->find (key);

    return in;
}
*/


//
//
// ConfReader::Rep 
//
//


ConfReader::Rep::Rep (const Str& inSourceSpec)
:   systemSpec (inSourceSpec), packagesNode (NULL)
{
    
    loadConfig ();
}

ConfReader::Rep::Rep (const Str& inBootstrapSpec, 
                      const Str& inSourceSpec)
:   bootSpec (inBootstrapSpec),
    systemSpec (inSourceSpec), 
    packagesNode (NULL)
{
    bootstrap ();
    loadConfig ();
}


ConfReader::Rep::~Rep ()
{
}


void ConfReader::Rep::bootstrap ()
{
    //
    // check if the bootstrap conf file exists
    //if (!bootSpec.exists ())
   if (!fileExists (bootSpec))
        return;

    // load the bootstrap file
    ConfReaderTree bootstrapTree;
    ConfReaderWrapper::readFromFile (bootSpec, bootstrapTree);
    ConfReader::PackageRep bootstrapConfig ("Configuration", bootstrapTree.getRoot ()->find ("Bootstrap/Configuration"), true);
    
    // read the path to the system file 
    bootstrapConfig.get ("Local", systemSpec);
}

void ConfReader::Rep::loadConfig ()
{
    //if (systemSpec.exists ())  {
   if (fileExists (systemSpec)) {
        configTree = new ConfReaderTree;
        ConfReaderWrapper::readFromFile (systemSpec, *configTree);
        packagesNode = configTree->getRoot ()->find ("Packages");
    }
}

bool ConfReader::Rep::isValid ()
{
    return packagesNode != NULL;
}




ConfReader::PackageRep* 
ConfReader::Rep::tryGetPackage (const Str& inKey, const Str& host, bool searchGlobal)
{
    ConfReaderTree::Node* node = packagesNode? packagesNode->find (inKey) : NULL;
    ConfReader::PackageRep* package =
        host.empty ()? new PackageRep (inKey, node, searchGlobal) : 
                       new PackageRep (inKey, node, host, searchGlobal);

    return package;
}

ConfReaderTree::Node* ConfReader::Rep::tryGetNode (const Str& inKey)
{
    return  packagesNode? packagesNode->find (inKey) : NULL;
}







//
// PackageRep implementation
//

ConfReader::PackageRep::PackageRep (const Str& inName, 
                                    ConfReaderTree::Node* node,
									bool searchGlobal)
:   _name (inName),
    _local  (node? node->find (ServerInfo::getComputerName ()) : NULL),
    _global ((searchGlobal && node)? node->find ("ALL") : NULL)
{
}


ConfReader::PackageRep::PackageRep (const Str& inName, 
											ConfReaderTree::Node* node, 
                                            const Str& remoteHost,
											bool searchGlobal)
:   _name (inName),
    _local  (node? node->find (remoteHost): NULL),
    _global ((searchGlobal && node)? node->find ("ALL") : NULL)
{
}

ConfReader::PackageRep::PackageRep (PackageRep& inParentPackage, 
                                    const Str& inRelativeName)
{
    if (inRelativeName.empty ())    {
        _name = inParentPackage.name ();
        _local.setRep (inParentPackage.getLocalNode ());
        _global.setRep (inParentPackage.getGlobalNode ());
    }
    else    {
        ConfReader::appendPath (_name, inParentPackage.name (), inRelativeName);
        ConfReaderTree::Node* localNode = inParentPackage.getLocalNode ();
        ConfReaderTree::Node* globalNode = inParentPackage.getGlobalNode ();
        _local.setRep (localNode? localNode->find (inRelativeName) : NULL);
        _global.setRep (globalNode? globalNode->find (inRelativeName) : NULL);
    }
}

ConfReaderTree::Node* ConfReader::PackageRep::getLocalNode ()
{
    return _local.getRep ();
}

ConfReaderTree::Node* ConfReader::PackageRep::getGlobalNode ()
{
    return _global.getRep ();
}

bool ConfReader::PackageRep::isValid () 
{
    return ((_local.getRep () != NULL) || (_global.getRep () != NULL));
}

bool ConfReader::PackageRep::get (const Str& in, StrBuffer& out)   
{
    return _local.get (in, out) ? true : _global.get (in, out);
}

/*
bool ConfReader::PackageRep::get (const Str& in, FileSpec& out )   
{
    return _local.get (in, out) ? true : _global.get (in, out);
}
*/

bool ConfReader::PackageRep::get (const Str& in, int& out  )   
{
    return _local.get (in, out) ? true : _global.get (in, out);
}

bool ConfReader::PackageRep::get (const Str& in, bool& out )   
{
    return _local.get (in, out) ? true : _global.get (in, out);
}

bool ConfReader::PackageRep::get (const Str& in, float& out)   
{
    return _local.get (in, out) ? true : _global.get (in, out);
}
/*
bool ConfReader::PackageRep::get(const Str& in, int64_t& out, const char* modifier)    
{
    return _local.get (in, out, modifier) ? true : _global.get (in, out, modifier);
}
*/






//
// ConfReader::IteratorRep implementation
//

ConfReader::IteratorRep::IteratorRep (PackageRep& inRootNode, 
				      const Str& inRelativePath) 
:   _local (false),
    _localNode (inRootNode.getLocalNode ()),
    _globalNode (inRootNode.getGlobalNode ()),
    _globalIterator (inRootNode.getGlobalNode (), inRelativePath),
    _localIterator (inRootNode.getLocalNode (), inRelativePath)
{
    //
    // first start iterating over global nodes.
    skipOverridedEntries ();
}


bool ConfReader::IteratorRep::atEnd()    
{
    if (!_local && _globalIterator.atEnd ())
        _local = true;

    return _local && _localIterator.atEnd ();
}

void ConfReader::IteratorRep::next () 
{
    if (!_local)    {
        //
        // skip global entries that are overrided by local entries
        skipOverridedEntries ();
    }

    _local? _localIterator.next () : _globalIterator.next ();
}

const Str& ConfReader::IteratorRep::getKey() 
{
    return _local? _localIterator.getKey () : _globalIterator.getKey ();
}

const Str& ConfReader::IteratorRep::getValue()   
{
    return _local? _localIterator.getValue () : _globalIterator.getValue ();
}


void ConfReader::IteratorRep::skipOverridedEntries ()    
{
    debug_mustbe (!_local);
    while (!_globalIterator.atEnd ())  {
        if (_localNode.get (_globalIterator.getRelativeKey ())) {
            //
            // this entry is overrided by a local one, skip it
            _globalIterator.next ();
        }
        else    {
            //
            // this entry is NOT overrided by a local one, so keep it.
            break;
        }
    }

    if (_globalIterator.atEnd ())
        _local = true;
}





/**********************************************
//
//
// ConfReader.cpp
//
//
 **********************************************/





//#include "ConfReader.h"
//#include "ConfReaderRep.h"

//#include "util/StatusLogWriter.h"
//#include "Data/Singleton.h"

//#include "Server/ConfReaderig.h"
//#include "Server/util/ServerInfo.h"
//#include "Server/util/ServerMessage.h"


const char* ConfReader::defaultHost = NULL;
const char* ConfReader::defaultKey = NULL;




//
// ConfReader
//

static void replaceSource (ConfReader::Rep*& inoutOld, ConfReader::Rep* inNew)
{
    ConfReader::Rep* temp;
    temp = inoutOld; inoutOld = NULL;
    delete temp; inoutOld = inNew;
}

ConfReader::ConfReader () : rep (NULL)
{
}

ConfReader::ConfReader (const Str& inSourceName) : rep (NULL)
{
    setup (inSourceName);
}

ConfReader::ConfReader (const Str& inBootstrapName, const Str& inSourceNameDefault) : rep (NULL)
{
    bootstrap (inBootstrapName, inSourceNameDefault);
}

ConfReader::~ConfReader ()
{
    replaceSource (rep, NULL);
}

//
// direct the source to a config file, either directly or through bootstrap
bool ConfReader::bootstrap (const Str& inBootstrapName)
{
    //FileSpec boot (ConfReaderig::getExecutionDirectory (), StrBuffer (inBootstrapName));
    //replaceSource (rep, new Rep (boot));
   replaceSource (rep, new Rep (inBootstrapName));
   return rep->isValid ();
}

bool ConfReader::bootstrap (const Str& inBootstrapName, 
                                    const Str& inSourceNameDefault)
{
//    FileSpec boot (ConfReaderig::getExecutionDirectory (), StrBuffer (inBootstrapName));
//    FileSpec source (ConfReaderig::getExecutionDirectory (), StrBuffer (inSourceNameDefault));

//    replaceSource (rep, new Rep (boot, source));
   replaceSource (rep, new Rep (inBootstrapName, inSourceNameDefault));
   return rep->isValid ();
}

bool ConfReader::setup (const Str& inSourceName)
{
    //FileSpec source (ConfReaderig::getExecutionDirectory (), StrBuffer (inSourceName));
    //replaceSource (rep, new Rep (source));
   replaceSource (rep, new Rep (inSourceName));
   return rep->isValid ();
}

//
// returns a nil implementation, if the package does not exist    
ConfReader::PackageRep* ConfReader::tryGetPackage (const Str& name, 
                                                           const Str& host,
                                                           bool searchGlobal)
{
    debug_mustbe (rep);
    return rep->tryGetPackage (name, host, searchGlobal);
}


//
// throws an exception if the package does not exist
ConfReader::PackageRep* ConfReader::getPackage (const Str& name, 
                                                        const Str& host,
                                                        bool searchGlobal)
{
    AutoPtr <ConfReader::PackageRep> package = tryGetPackage (name, host, searchGlobal);
    if (!package || !package->isValid ())
        throwx (ConfReader::PackageNotFound (name));

    return package.release ();
}


//
// returns true if the configuration source file exists
bool ConfReader::valid ()
{
    return (rep && rep->isValid ());
}

// 
// returns the spec for the configuration source file
const Str& ConfReader::source ()
{
    debug_mustbe (rep);
    return rep->source ();
}

// 
// returns the spec for the configuration boot file
const Str& ConfReader::boot ()
{
    debug_mustbe (rep);
    return rep->boot ();
}

ConfReader::Rep* ConfReader::getRep ()
{
    return rep;
}










//
//
// ConfReader::Rep singleton instance
//
//

static bool enableBootstrap = true;
static StrBuffer bootstrapConf  = "Bootstrap.conf";
static StrBuffer systemConf = "RTimage.conf";

void ConfReader::Shared::setSource (const Str& inSource)
{
	//
	// disable bootstrapping
	enableBootstrap = false;

	//
	// change the source name
	systemConf = inSource;
}

/*

static void setup (ConfReader::Source& source)
{
    try {
        if (enableBootstrap)    {
            source.bootstrap (bootstrapConf, systemConf);
            
            //
            // assert existance of boot file
            FileSpec bootSpec = source.boot ();
            //if (!bootSpec.exists ())  {
                //
                // boot file does not exists, reverting to default system conf
                StrBuffer buffer;
                bootSpec.getFullPath (buffer);
                StatusLogWriter::output ("The %s bootstrap file does not exist, unable to update configuration.", buffer.getCString ());
            }
        }
        else    {
            //
            // reverting to user-defined system conf
            source.setup (systemConf);
        }

        //
        // assert existance of conf file
        FileSpec sourceSpec = source.source ();
        if (!sourceSpec.exists ())  {
            //
            // severe error, no conf file
            StrBuffer buffer;
            sourceSpec.getFullPath (buffer);
            StatusLogWriter::output ("The %s conf file does not exist, configuration is not available.", buffer.getCString ());
        }
    }
    catch (BaseException& excp) {
        ServerMessage::dump_ctx (excp, "ConfReader::setup ()",
                                        ServerMessage::Fatal ()     );
    }
}


static Singleton <ConfReader::Source> s_config (setup);
*/

//
//
// ConfReader::Package
//
//


ConfReader::Package::Package ()
:   rep (0)
{
}

ConfReader::Package::Package (PackageRep* inRep)
:   rep (inRep)
{
}

ConfReader::Package::~Package ()
{
    delete rep;
    rep = NULL;
}

void ConfReader::Package::setRep (PackageRep* inRep)
{
	delete rep;
    rep = inRep;
}

ConfReader::PackageRep* ConfReader::Package::getRep ()
{
    return rep;
}

bool ConfReader::Package::valid ()
{
    return (rep && rep->isValid ());
}






//
//
// ConfReader wrapper
//
//
/*
ConfReader::PackageRep* ConfReader::tryGetPackage (const Str& inKey, 
                                                   const Str& host,
												   bool searchGlobal)
{
    return s_config->tryGetPackage (inKey, host, searchGlobal);
}


const FileSpec& ConfReader::source ()
{
    return s_config->source ();
}

bool ConfReader::valid ()
{
	FileSpec systemSpec;

    if (s_config.valid ())  {
        systemSpec= s_config->source ();
    }
    else    {
        Source source (bootstrapConf, systemConf);
        systemSpec = source.source ();
    }

	return systemSpec.exists ();
}
*/



void ConfReader::appendPath (StrBuffer& out, const Str& a, const Str& b)
{
    mustbe ((a != NULL) && (b != NULL));

    out = a;
    out.append ('/');
    out.append (b);
}

/*
ConfReader::PackageRep* ConfReader::getPackage (const Str& inKey, 
                                                const Str& host,
												bool searchGlobal)
{
    return s_config->getPackage (inKey, host, searchGlobal);
}
*/

Str ConfReader::Package::name ()
{
    return rep? rep->name () : NULL;
}


bool ConfReader::Package::get (const Str& in, StrBuffer& out)
{
    return rep? rep->get (in, out) : false;
}

bool ConfReader::Package::get (const Str& in, int& out)
{
    return rep? rep->get (in, out) : false;
}

bool ConfReader::Package::get (const Str& in, bool& out)
{
    return rep? rep->get (in, out) : false;
}

bool ConfReader::Package::get (const Str& in, float& out)
{
    return rep? rep->get (in, out) : false;
}
/*
bool ConfReader::Package::get (const Str& in, FileSpec& out)
{
    return rep? rep->get (in, out) : false;
}

bool ConfReader::Package::get (const Str& in, int64_t& out, const char* modifier)
{
    return rep? rep->get (in, out, modifier) : false;
}
*/





void ConfReader::Package::mustGet (const Str& in, StrBuffer& out)
{
    debug_mustbe (rep);
    if (!get (in, out))
        throwx (ValueNotFound (rep->name (), in));
}

void ConfReader::Package::mustGet (const Str& in, int& out)
{
    debug_mustbe (rep);
    if (!get (in, out))
        throwx (ValueNotFound (rep->name (), in));
}

void ConfReader::Package::mustGet (const Str& in, bool& out)
{
    debug_mustbe (rep);
    if (!get (in, out))
        throwx (ValueNotFound (rep->name (), in));
}

void ConfReader::Package::mustGet (const Str& in, float& out)
{
    debug_mustbe (rep);
    if (!get (in, out))
        throwx (ValueNotFound (rep->name (), in));
}
/*
void ConfReader::Package::mustGet (const Str& in, FileSpec& out)
{
    debug_mustbe (rep);
    if (!get (in, out))
        throwx (ValueNotFound (rep->name (), in));
}


void ConfReader::Package::mustGet (const Str& in, int64_t& out, const char* modifier)
{
    debug_mustbe (rep);
    if (!get (in, out, modifier))
        throwx (ValueNotFound (rep->name (), in));
}
*/



ConfReader::PackageRep* ConfReader::Package::createSubPackage (const Str& name)
{
    AutoPtr <PackageRep> package = tryCreateSubPackage (name);
    if (!package.valid ())
        throwx (PackageNotFound (name));

    return package.release ();
}

ConfReader::PackageRep* ConfReader::Package::tryCreateSubPackage (const Str& name)
{
    return new PackageRep (*rep, name);
}














//
//
// Iterator
// 
//





ConfReader::Iterator::Iterator (Package& inRootPackage, const Str& inRelativePath)
{
    PackageRep subpackage (*inRootPackage.getRep (), inRelativePath);
    rep = new IteratorRep (subpackage, inRelativePath);
}


ConfReader::Iterator::Iterator (PackageRep& inRootPackage, const Str& inRelativePath)
{
    PackageRep subpackage (inRootPackage, inRelativePath);
    rep = new IteratorRep (subpackage, inRelativePath);
}

ConfReader::Iterator::~Iterator ()
{
    delete rep;
}

bool ConfReader::Iterator::atEnd ()
{
    return rep->atEnd ();
}

void ConfReader::Iterator::next ()
{
    rep->next ();
}

const Str& ConfReader::Iterator::get ()
{
	return rep->getKey ();
}

StrBuffer ConfReader::Iterator::operator + (const Str& in)
{
    StrBuffer buffer;
    ConfReader::appendPath (buffer, get (), in);
    return buffer;
}





//
//
// HostIterator
//
//


class ConfReader::HostIteratorRep : public ConfReaderTree::Iterator  {
public:
    HostIteratorRep (ConfReader& conf,   
                     ConfReaderTree::Node* node, 
                     const Str& name) 
    :   ConfReaderTree::Iterator (node), mName (name), mConf (conf)  {
    }

    StrBuffer mName;
    ConfReader mConf;
};

/*
ConfReader::HostIterator::HostIterator (const Str& packageName) 
:   rep (0)
{
    Rep* source_rep = s_config->getRep ();
    ConfReaderTree::Node* node = source_rep->tryGetNode (packageName);
    if (node)   {
        rep = new HostIteratorRep (node, packageName);
    }
}
*/

ConfReader::HostIterator::HostIterator (ConfReader& inSource, const Str& packageName) 
:   rep (0)
{
    Rep* source_rep = inSource.getRep ();
    ConfReaderTree::Node* node = source_rep->tryGetNode (packageName);
    if (node)   {
        rep = new HostIteratorRep (inSource, node, packageName);
    }
}


ConfReader::HostIterator::~HostIterator ()
{
    delete rep;
}

bool ConfReader::HostIterator::atEnd ()
{
    return (!rep || rep->atEnd ());
}

void ConfReader::HostIterator::next ()
{
    rep->next ();
}

ConfReader::PackageRep* ConfReader::HostIterator::get ()
{
    // returns a rep of the package for the particular host
    return rep->mConf.getPackage (rep->mName, rep->getKey ().getChars (), false);
}

const char* ConfReader::HostIterator::name ()
{
    const char* myName = rep->getKey ().getChars ();

    //
    // remove the leading '/'
    return myName? myName + 1 : NULL;
}




ConfReader::ConfigError::ConfigError (const Str& inMessage) : message (inMessage)
{
}

ConfReader::ConfigError::ConfigError (const Str& inError, const Str& inPackageName)
{
    message.append (inError);
    message.append (" in configuration package ");
    message.append (inPackageName);
}

ConfReader::ConfigError::ConfigError (const Str& inError, 
                                      const Str& inPackageName, 
                                      const Str& inValueName)
{
    message.append (inError);
    message.append (" in configuration value ");
    message.append (inPackageName);
    message.append ('/');
    message.append (inValueName);
}

void ConfReader::ConfigError::explain (std::ostream & writer)
{
    BaseException::explain (writer);
    writer << " - " << message;
}




ConfReader::PackageNotFound::PackageNotFound (const Str& inPackageName) : package (inPackageName) 
{
}

void ConfReader::PackageNotFound::explain (std::ostream& out) 
{ 
	out << "Configuration package ";
   out.write (package.getChars (), package.length ());
   out << " is missing."; 
}

ConfReader::ValueNotFound::ValueNotFound (const Str& inPackageName, 
                                          const Str& inValueName) 
:   package (inPackageName),
    value (inValueName) 
{
}

void ConfReader::ValueNotFound::explain (std::ostream& out) 
{ 
	 out << "Configuration value ";
    out.write (package.getChars (), package.length ());
    out << '/';
    out.write (value.getChars (), value.length ()); 
    out << " is missing."; 
}

//
// File        : $RCSfile: $ 
//               $Workfile: ConfReader.cpp $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 28/08/04 5:40 $ 
// Description :
//	The Persistence library contains both high & low level IO classes
//	and is high-performance, highly reusable framework 
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
//

