#ifndef INT_SINGLY_LINKED_LIST
#define INT_SINGLY_LINKED_LIST

#include "islln.h"

using std::cout;
using std::cin;
using std::endl;

class isll {
    friend ostream& operator<<(ostream&, isll const &);
    friend istream& operator>>(istream&, isll&);
public:
    isll(): m_head(NULL), m_tail(NULL) { }
    isll(int const & n);
    // use the overloaded operator>>
    isll(istream& in_stream) { in_stream >> *this; }
    isll(isll const & list)
    {
        islln* n = new islln;
        const islln* q = list.m_head;
        n->info = q->info;
        m_set_head(n);
        q = q->next;
        while (NULL != q)
        {
            islln* const h = new islln;
            h->info = q->info;
            n->next = h;
            n = h;
            q = q->next;
        }
        m_tail = n;
    }
    ~isll();
    void m_set_head(islln* const p_node) { m_head = p_node; }
    void m_set_tail(islln* const p_node) { m_tail = p_node; }

    bool m_is_empty() const { return m_head == NULL; }
    bool m_is_in_list(int const &) const;

    islln* getHead() const { return m_head; }
    islln* getTail() const { return m_tail; }

    void m_add_to_head(int const &);
    void m_add_to_tail(int const &);

    bool m_delete_from_head();
    bool m_delete_from_tail();
    bool m_delete_node(int const &);

    void reverse();
    // if a member function is logically does not modify the data member
    // it is strongly recommended that we define that function as
    // a const member function
    // because a non const member function can not be invoked by the
    // const object

private:
    islln* m_head;
    islln* m_tail;
};

#endif
