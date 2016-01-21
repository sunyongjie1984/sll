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

// ����Ϊ��ͬ���ڣ����õ����û�д������ĸ��ƣ�����д�У�
// ������������������˵û��ʲô���Զ������Ͳ������Ƿǳ�����Ż����������������ͣ�����Ϊ�˴���ͳһ��Ҳʹ����const���á�
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
        // ������delete tmp,������ͨ��ָ��tmpȥ�޸�����ָ��Ķ��󣬲�ȻӦ�ñ��뱨��
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

//ostream& operator<<(ostream& os, isll& object) // �����ˣ������Ұ�head��tailŪ��public��
//{                                                   // �Ҽ�һ����Ա������������ͷָ�벻�ͺ���
//    for (islln* p = object.head; p != NULL; p = p->next) // ���Կ����Ǻ�
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

// ������������ǿ������ˣ�������ɾ��һЩ����������   // ������head,tail��public������µ�
//istream& operator>>(istream& is, isll& object) // �ҵ���������кܶ�ĵط�Ҫ�ģ���ֱ
//{                                                     // �����ĵط��١�
//    object.head = new islln;
//    cin >> object.head->info;
//    islln* p1 = object.head;
//    int x;
//    while (std::cin >> x) // ���λ����ǰ����ĸ��������ʱ��������
//    {                     // ����û���ˣ���������Ϊ�ڵ�Ĺ��캯��ÿ����һ����ʱ����ָ����ֵ0�ġ�
//        islln* p2 = new islln;
//        p2->info = x;
//        p1->next = p2;
//        p1 = p2;
//    }
//    // object.tail = p1; // Ϊʲôע�������Ҳ���ԣ���Ҫ�����ҵ������
//    return is;        // �ҵ���������غ�������û���õ�tail
//}

// ���������head,tail,private��ʱ��
//istream& operator>>(istream& is, isll& object)
//{
//    islln* h = object.getHead();
//    //	islln* t = object.getTail(); ����ô��Ҫ������ô��
//    islln* p1 = h;
//    p1 = new islln; // �����ķǳ����أ���ϸ����һ�¡�
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