#ifndef INT_SINGLY_LINKED_LIST_NODE
#define INT_SINGLY_LINKED_LIST_NODE

#include <iostream>

using std::ostream;
using std::istream;

class islln
{   // using friend, I keep info and next private
    // and the class isll can access them
    // and the global function overloaded operators can access them.
    // ^_^ and I add this line just for test the git tool, sorry ha ha ha
    // ^_^ this is a test again, I am very sorry for testing git functions
    friend class isll;
    friend ostream& operator<<(ostream&, const isll&);
    friend istream& operator>>(istream&, isll&);
public:
    islln(): info(0), next(nullptr) { }
    islln(int const & i, islln* const p_next = NULL) : info(i), next(p_next) { }
private:
    int info;
    islln* next;
};

#endif
