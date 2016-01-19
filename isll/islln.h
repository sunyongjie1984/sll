#ifndef INT_SINGLY_LINKED_LIST_NODE
#define INT_SINGLY_LINKED_LIST_NODE

#include <iostream>

using std::ostream;
using std::istream;

#ifdef __linux
class isll; // I don't know why, in centos g++ 4.7.0 without this line, compile error
#endif

class islln
{
    // using friend, I keep info and next private
    // and the class isll can access them
    // and the global function overloaded operators can access them.

    friend class isll;
    friend ostream& operator<<(ostream&, const isll&);
    friend istream& operator>>(istream&, isll&);

public:
    islln() : info(0), next(nullptr) { }
    islln(const int& i, islln* const p_next = NULL) : info(i), next(p_next) { }

private:
    int    info;
    islln* next;
};

#endif
