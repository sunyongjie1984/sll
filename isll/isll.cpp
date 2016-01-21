#include "isll.h"

isll::isll(const isll& list)
{
    if (nullptr == list.head)
    {
        return;
    }
    islln* n = new islln;
    const islln* q = list.head;
    n->info = q->info;
    SetHead(n);
    q = q->next;
    while (nullptr != q)
    {
        islln* const h = new islln;
        h->info = q->info;
        n = n->next = h;
        q = q->next;
    }
    tail = n;
}

// 我以为不同在于，引用的情况没有传入对象的复制，这样写有，
// 不过对象内置类型来说没有什么，自定义类型不复制是非常大的优化，本处是内置类型，但是为了代码统一，也使用了const引用。
isll::isll(const int& n)
{
    head = new islln;
    islln* p = head;
    cout << "please in put " << n << " int value" << endl;
    cout << "no 1 is: " << endl;
    cin >> head->info;
    for (int i = 0; i < n - 1; i++)
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

isll::~isll()
{
    islln* p = head;
    while(!IsEmpty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

bool isll::IsInList(const int& el) const
{
    const islln* tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return nullptr != tmp;
}

void isll::AddToHead(const int& el)
{
    head = new islln(el, head);
    if (nullptr == tail)
    {
        tail = head;
    }
}

void isll::AddToTail(const int& el)
{
    if (nullptr != tail) // not empty list
    {
        tail = tail->next = new islln(el); // equal to above two lines
    }
    else
    {
        head = tail = new islln(el);
    }
}

bool isll::DeleteFromHead()
{
    bool bFlag; // use one flay to get rid of the multi-return statement
    if (IsEmpty())
    {
        bFlag = false;
    }
    else
    {
        const islln* const tmp = head;
        if (head == tail) // only one node
        {
            head = tail = nullptr;
        }
        else              // more than one node
        {
            head = head->next;
        }
        // 好像是delete tmp,不算是通过指针tmp去修改它所指向的对象，不然应该编译报错
        delete tmp;       // free node head

        bFlag = true;
    }
    return bFlag;
}

bool isll::DeleteFromTail()
{
    bool bFlag;
    if (IsEmpty())
    {
        bFlag = false;
    }
    else
    {
        if (head == tail) // only one node
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            islln* tmp= head;
            for (; tmp->next != tail; tmp = tmp->next);
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
        bFlag = true;
    }
    return bFlag;
}

bool isll::DeleteNode(const int& el)
{
    bool bFlag = false;
    if (!IsEmpty())
    {
        if (head == tail && el == head->info)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (el == head->info)
        {
            const islln* const tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            islln* pred = head;
            const islln* tmp = head->next;
            for (; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
            if (nullptr != tmp)
            {
                pred->next = tmp->next;
                if (tmp == tail)
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

void isll::Reverse()
{
    islln* p = head;
    islln* s = head;
    islln* q = head->next;
    while (q)
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

ostream& operator<<(ostream& os, const isll& object)
{
    for (const islln* p = object.GetHead(); nullptr != p; p = p->next)
    {
        os << p->info << " ";
    }
    return os;
}

//ostream& operator<<(ostream& os, isll& object) // 能用了，不过我把head与tail弄成public了
//{                                                   // 我加一个成员函数用来返回头指针不就好了
//    for (islln* p = object.head; p != NULL; p = p->next) // 试试看，呵呵
//    {
//        os << p->info << " ";
//    }
//    return os;
//}

istream& operator>>(istream& is, isll& object)
{
    islln* h = new islln;
    object.SetHead(h);
    std::cin >> h->info;
    int x;
    while (std::cin >> x)
    {
        islln* const p2 = new islln;
        p2->info = x;
        h->next = p2;
        h = p2;
    }
    object.SetTail(h);
    return is;
}

// 这种情况现在是可以用了，我试着删掉一些东西看看。   // 这是在head,tail是public的情况下的
//istream& operator>>(istream& is, isll& object) // 我的这个程序有很多的地方要改，简直
//{                                                     // 保留的地方少。
//    object.head = new islln;
//    cin >> object.head->info;
//    islln* p1 = object.head;
//    int x;
//    while (std::cin >> x) // 这个位置以前用字母来结束的时候会出问题
//    {                     // 现在没有了，可能是因为节点的构造函数每生成一个的时候都是指针域赋值0的。
//        islln* p2 = new islln;
//        p2->info = x;
//        p1->next = p2;
//        p1 = p2;
//    }
//    // object.tail = p1; // 为什么注释了这个也可以，我要看看我的输出符
//    return is;        // 我的输出符重载函数根本没有用到tail
//}

// 这个输入是head,tail,private的时候。
//istream& operator>>(istream& is, isll& object)
//{
//    islln* h = object.getHead();
//    //	islln* t = object.getTail(); 有用么，要设置它么？
//    islln* p1 = h;
//    p1 = new islln; // 这里错的非常严重，仔细考虑一下。
//    std::cin >> h->info;
//    int x;
//    while (std::cin >> x)
//    {
//        islln* p2 = new islln;
//        p2->info = x;
//        p1->next = p2;
//        p1 = p2;
//    }
//    p1->next = 0;
//    return is;
//}