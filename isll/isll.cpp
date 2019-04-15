#include "isll.h"

isll::isll( const isll& list )
{
    if ( nullptr == list.head )
    {
        return;
    }
    islln* n = new islln;
    const islln* q = list.head;
    n->info = q->info;
    SetHead( n );
    q = q->next;
    while ( nullptr != q )
    {
        islln* const h = new islln;
        h->info = q->info;
        n = n->next = h;
        q = q->next;
    }
    tail = n;
}

// not necessary for built-in type, good for user defined classes
// save the copy time, this place for one style of coding rules, I use const reference
isll::isll( const int& n )
{
    head = new islln;
    islln* p = head;
    cout << "please in put " << n << " int value" << endl;
    cout << "no 1 is: " << endl;
    cin >> head->info;
    for ( int i = 0; i < n - 1; i++ )
    {
        islln* const p_new = new islln;
        cout << "no " << i + 2 << " is: " << endl;
        cin >> p_new->info;
        p->next = p_new;
        p = p_new;
    }
    tail = p;
    tail->next = nullptr;
}

isll::~isll( )
{
    islln* p;
    while( nullptr != ( p = head ) )
    {
        head = head->next;
        delete p;
    }
}

bool isll::IsInList( const int& el ) const
{
    const islln* p = head;
    for ( ; nullptr != p && el != p->info; p = p->next );
    return nullptr != p;
}

void isll::AddToHead( const int& el )
{
    cout << "isll is adding " << el << " to head " << endl;
    head = new islln( el, head );
    if ( nullptr == tail )
    {
        tail = head;
    }
}

void isll::AddToTail( const int& el )
{
    cout << "isll is adding " << el << " to tail " << endl;
    if ( nullptr != tail ) // not empty list
    {
        tail = tail->next = new islln( el ); // equal to above two lines
    }
    else
    {
        head = tail = new islln( el );
    }
}

bool isll::DeleteFromHead( )
{
    cout << "isll is deleting from head" << endl;
    bool bFlag; // use one flay to get rid of the multi-return statement
    if ( IsEmpty( ) )
    {
        bFlag = false;
    }
    else
    {
        const islln* const tmp = head;
        if ( head == tail ) // only one node
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete tmp;       // free node head

        bFlag = true;
    }
    return bFlag;
}

bool isll::DeleteFromTail( )
{
    cout << "isll is deleting from tail" << endl;
    bool bFlag;
    if ( IsEmpty( ) )
    {
        bFlag = false;
    }
    else
    {
        if ( head == tail ) // only one node
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            islln* tmp = head;
            for ( ; tmp->next != tail; tmp = tmp->next );
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
        bFlag = true;
    }
    return bFlag;
}

bool isll::DeleteNode( const int& el )
{
    cout << "isll is deleting node " << el << endl;
    bool bFlag = false;
    if ( !IsEmpty( ) )
    {
        if ( head == tail && el == head->info )
        {
            delete head;
            head = tail = nullptr;
        }
        else if ( el == head->info )
        {
            const islln* const tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            islln* pred = head;
            const islln* tmp = head->next;
            for ( ; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next );
            if ( nullptr != tmp )
            {
                pred->next = tmp->next;
                if ( tmp == tail )
                {
                    tail = pred;
                }
                delete tmp;
            }
        }
        bFlag = true;
    }
    return bFlag;
}

void isll::Reverse( )
{
    islln* p = head;
    islln* s = head;
    islln* q = head->next;
    while ( q )
    {
        p = q;
        q = q->next;
        p->next = s;
        s = p;
    }
    islln* tmp = head;
    head->next = nullptr;
    head = tail;
    tail = tmp;
}

ostream& operator<<( ostream& os, const isll& object )
{
    for ( const islln* p = object.GetHead(); nullptr != p; p = p->next )
    {
        os << p->info << " ";
    }
    return os;
}

istream& operator>>( istream& is, isll& object )
{
    islln* h = new islln;
    object.SetHead( h );
    std::cin >> h->info;
    int x;
    // in windows we use ctrl + z as end of input
    // under UNIX like, we use ctrl + d, because in UNIX like ctrl + z means,
    // let the progress go to back ground
    while ( std::cin >> x )
    {
        islln* const p2 = new islln;
        p2->info = x;
        h->next = p2;
        h = p2;
    }
    object.SetTail( h );
    return is;
}
