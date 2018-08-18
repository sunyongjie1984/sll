#ifndef INT_SINGLY_LINKED_LIST_NODE
#define INT_SINGLY_LINKED_LIST_NODE

#include <iostream>

using std::ostream;
using std::istream;

#if defined __linux || defined __APPLE__
class isll; // I don't know why, in centos g++ 4.7.0 without this line, compile error
#endif

class islln
{
    // using friend, I keep info and next private
    // and the class isll can access them
    // and the global function overloaded operators can access them.

    friend class isll;
    friend ostream& operator<<( ostream&, const isll& );
    friend istream& operator>>( istream&, isll& );

public:
    islln() : info(0), next(nullptr) { }
    islln( const int& info, islln* const PNext = nullptr ) : info( info ), next( PNext ) { }

private:
    int    info;
    islln* next;
};

#endif
