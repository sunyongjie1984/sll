#ifndef INT_SINGLY_LINKED_LIST
#define INT_SINGLY_LINKED_LIST

#include "islln.h"

using std::cout;
using std::cin;
using std::endl;

class isll {
    friend ostream& operator<<(ostream&, const isll&);
    friend istream& operator>>(istream&, isll&);
public:
    isll() : MHead(NULL), MTail(NULL) { }
    isll(const int& n);
    // use the overloaded operator>>
    isll(istream& InStream) { InStream >> *this; }
    isll(const isll& list)
    {
        if (nullptr == list.MHead)
        {
            return;
        }
        islln* n = new islln;
        const islln* q = list.MHead;
        n->info = q->info;
        SetHead(n);
        q = q->next;
        while (NULL != q)
        {
            islln* const h = new islln;
            h->info = q->info;
            n->next = h;
            n = h;
            q = q->next;
        }
        MTail = n;
    }
    ~isll();
    void SetHead(islln* const p_node) { MHead = p_node; }
    void SetTail(islln* const p_node) { MTail = p_node; }

    bool IsEmpty() const { return MHead == NULL; }
    bool IsInList(const int&) const;

    islln* GetHead() const { return MHead; }
    islln* GetTail() const { return MTail; }

    void AddToHead(int const &);
    void AddToTail(int const &);

    bool DeleteFromHead();
    bool DeleteFromTail();
    bool DeleteNode(int const &);

    void reverse();
    // if a member function is logically does not modify the data member
    // it is strongly recommended that we define that function as
    // a const member function
    // because a non const member function can not be invoked by the
    // const object

private:
    islln* MHead;
    islln* MTail;
};

#endif
