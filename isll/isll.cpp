#include "isll.h"

// isll::isll(const int n)  // 我以为不同在于，引用的情况没有传入对象的复制，这样写有，
                            // 不过对象内置类型来说没有什么，对于自定义类型就不好说了
isll::isll(const int& n)   // 不过为了与自定义类型统一，我这里写用引用了
{
    m_head = new islln;
    islln* p = m_head;
    cout << "please in put " << n << " int value" << endl;
    cout << "no 1 is: " << endl;
    cin >> m_head->info;
    for (int i = 0; i < n - 1; i++)
    {
        islln* const p_new = new islln;
        cout << "no "<< i + 2 << " is: " << endl;
        cin >> p_new->info;
        p->next = p_new;
        p = p_new;
    }
    m_tail = p;
    m_tail->next = NULL;
}

isll::~isll()
{
    islln* p = m_head;
    while(!m_is_empty())
    {
        p = m_head->next;
        delete m_head;
        m_head = p;
    }
}

void isll::m_add_to_head(const int& el)
{
    m_head = new islln(el, m_head);
    if (m_tail == NULL)
    {
        m_tail = m_head;
    }
}

void isll::m_add_to_tail(const int& el)
{
    if (m_tail != NULL) // not empty list
    {
        //tail->next = new islln(el);
        //tail = tail->next;

        m_tail = m_tail->next = new islln(el); // equal to above two lines
    }
    else // empty list
    {
        m_head = m_tail = new islln(el);
    }
}

bool isll::m_delete_from_head()
{
    bool bFlag; // use one flay to get rid of the multi-return statement
    if (m_is_empty())
    {
        bFlag = false;
    }
    else
    {
        const islln* const tmp = m_head;
        if (m_head == m_tail) // only one node
        {
            m_head = m_tail = NULL;
        }
        else              // more than one node
        {
            m_head = m_head->next;
        }
        // 好像是delete tmp;不算是通过指针tmp去修改它所指向的对象，不然应该编译报错
        delete tmp;       // free node head

        bFlag = true;
    }
    return bFlag;
}

bool isll::m_delete_from_tail()
{
    bool bFlag;
    if (m_is_empty())
    {
        bFlag = false;
    }
    else
    {
        if (m_head == m_tail) // only one node
        {
            delete m_head;
            m_head = m_tail = NULL;
        }
        else
        {
            islln* tmp= m_head;
            for (; tmp->next != m_tail; tmp = tmp->next);
            delete m_tail;
            m_tail = tmp;
            m_tail->next = NULL;
        }
        bFlag = true;
    }
    return bFlag;
}

bool isll::m_delete_node(const int& el)
{
    bool bFlag = false;
    if (!m_is_empty())
    {
        if (m_head == m_tail && el == m_head->info)
        {
            delete m_head;
            m_head = m_tail = NULL;
        }
        else if (el == m_head->info)
        {
            const islln* const tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
        else
        {
            islln* pred = m_head;
            const islln* tmp = m_head->next;
            for (; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
            if (tmp != NULL)
            {
                pred->next = tmp->next;
                if (tmp == m_tail)
                {
                    m_tail = pred;
                }
                delete tmp;
            }
        }
        bFlag = true;
    }
    return bFlag;
}

bool isll::m_is_in_list(const int& el) const
{
    const islln* tmp;
    for (tmp = m_head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != NULL;
}

void isll::reverse()
{
    islln* p = m_head;
    islln* s = m_head;
    islln* q = m_head->next;
    while (q)
    {
        p = q;
        q = q->next;
        p->next = s;
        s = p;
    }
    islln* tmp = m_head;
    m_head->next = nullptr;
    m_head = m_tail;
    m_tail = tmp;
}

//ostream& operator<<(ostream& os, isll& object) // 能用了，不过我把head与tail弄成public了
//{                                                   // 我加一个成员函数用来返回头指针不就好了
//    for (islln* p = object.head; p != NULL; p = p->next) // 试试看，呵呵
//    {
//        os << p->info << " ";
//    }
//    return os;
//}

ostream& operator<<(ostream& os, const isll& object)
{
    for (const islln* p = object.getHead(); p != NULL; p = p->next)
    {
        os << p->info << " ";
    }
    return os;
}

istream& operator>>(istream& is, isll& object)
{
    islln* h = new islln;
    object.m_set_head(h);
    std::cin >> h->info;
    int x;
    while (std::cin >> x)
    {
        islln* const p2 = new islln;
        p2->info = x;
        h->next = p2;
        h = p2;
    }
    object.m_set_tail(h);
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