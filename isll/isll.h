#ifndef INT_SINGLY_LINKED_LIST
#define INT_SINGLY_LINKED_LIST

#include "islln.h"

using std::cout;
using std::cin;
using std::endl;

class isll {
    friend ostream& operator<<( ostream&, const isll& );
    friend istream& operator>>( istream&, isll& );
public:
    isll() : head( nullptr ), tail( nullptr ) { } // default constructor
    isll( const isll& list );                   // copy constructor
    isll( const int& n );
    isll( istream& InStream ) { InStream >> *this; } // use the overloaded operator>>
    ~isll( );

    bool IsEmpty( ) const { return nullptr == head; }
    bool IsInList( const int& ) const;

    islln* GetHead( ) const { return head; }
    islln* GetTail( ) const { return tail; }

    void SetHead( islln* const PNode ) { head = PNode; }
    void SetTail( islln* const PNode ) { tail = PNode; }

    void AddToHead( int const& );
    void AddToTail( int const& );

    bool DeleteFromHead( );
    bool DeleteFromTail( );
    bool DeleteNode( const int& );

    void Reverse( );
    // if a member function is logically does not modify the data member
    // it is strongly recommended that we define that function as a const member fuction
    // because a non const member function can not be invoked by the const object

private:
    islln* head;
    islln* tail;
};

#endif
