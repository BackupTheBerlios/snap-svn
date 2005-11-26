#include "Sequence.h"

#include "Persistance/OArchive.h"
#include "Persistance/IArchive.h"
#include "Persistance/STLPersist.h"

ChunkAllocator <Position> Position::__allocator (4);
ChunkAllocator <Sequence> Sequence::__allocator;

void Sequence::serialize (Persistance::OArchive& out)
{
   out << _id;
   out << _data;
   out << _name;
   out << _hasWeight;
   out << _weight;
}

void Sequence::serialize (Persistance::IArchive& in)
{
   in >> _id;
   in >> _data;
   in >> _name;
   in >> _hasWeight;
   in >> _weight;
}

void Position::serialize (Persistance::OArchive& out)
{
   out.registerObject (_sequence, false);
   out << _position;
}

void Position::serialize (Persistance::IArchive& in)
{
   in.registerObject (const_cast <Sequence*&> (_sequence));
   in >> _position;
}


