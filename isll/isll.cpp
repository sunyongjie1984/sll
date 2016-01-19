#include "isll.h"

// isll::isll(const int n)  // ����Ϊ��ͬ���ڣ����õ����û�д������ĸ��ƣ�����д�У�
                            // ������������������˵û��ʲô���Զ������Ͳ������Ƿǳ�����Ż����������������ͣ�����Ϊ�˴���ͳһ��Ҳʹ����const���á�
isll::isll(const int& n)
{
    std::cout << "isll::isll(const int& n)" << std::endl;
    MHead = new islln;
    islln* p = MHead;
    cout << "please in put " << n << " int value" << endl;
    cout << "no 1 is: " << endl;
    cin >> MHead->info;
    for (int i = 0; i < n - 1; i++)
    {
        islln* const p_new = new islln;
        cout << "no " << i + 2 << " is: " << endl;
        cin >> p_new->info;
        p->next = p_new;
        p = p_new;
    }
    MTail = p;
    MTail->next = NULL;
}

isll::~isll()
{
    islln* p = MHead;
    while(!IsEmpty())
    {
        p = MHead->next;
        delete MHead;
        MHead = p;
    }
}

void isll::AddToHead(const int& el)
{
    MHead = new islln(el, MHead);
    if (MTail == NULL)
    {
        MTail = MHead;
    }
}

void isll::AddToTail(const int& el)
{
    if (MTail != NULL) // not empty list
    {
        //tail->next = new islln(el);
        //tail = tail->next;

        MTail = MTail->next = new islln(el); // equal to above two lines
    }
    else // empty list
    {
        MHead = MTail = new islln(el);
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
        const islln* const tmp = MHead;
        if (MHead == MTail) // only one node
        {
            MHead = MTail = NULL;
        }
        else              // more than one node
        {
            MHead = MHead->next;
        }
        // ������delete tmp;������ͨ��ָ��tmpȥ�޸�����ָ��Ķ��󣬲�ȻӦ�ñ��뱨��
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
        if (MHead == MTail) // only one node
        {
            delete MHead;
            MHead = MTail = NULL;
        }
        else
        {
            islln* tmp= MHead;
            for (; tmp->next != MTail; tmp = tmp->next);
            delete MTail;
            MTail = tmp;
            MTail->next = NULL;
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
        if (MHead == MTail && el == MHead->info)
        {
            delete MHead;
            MHead = MTail = NULL;
        }
        else if (el == MHead->info)
        {
            const islln* const tmp = MHead;
            MHead = MHead->next;
            delete tmp;
        }
        else
        {
            islln* pred = MHead;
            const islln* tmp = MHead->next;
            for (; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
            if (tmp != NULL)
            {
                pred->next = tmp->next;
                if (tmp == MTail)
                {
                    MTail = pred;
                }
                delete tmp;
            }
        }
        bFlag = true;
    }
    return bFlag;
}

bool isll::IsInList(const int& el) const
{
    const islln* tmp;
    for (tmp = MHead; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != NULL;
}

void isll::reverse()
{
    islln* p = MHead;
    islln* s = MHead;
    islln* q = MHead->next;
    while (q)
    {
        p = q;
        q = q->next;
        p->next = s;
        s = p;
    }
    islln* tmp = MHead;
    MHead->next = nullptr;
    MHead = MTail;
    MTail = tmp;
}

//ostream& operator<<(ostream& os, isll& object) // �����ˣ������Ұ�head��tailŪ��public��
//{                                                   // �Ҽ�һ����Ա������������ͷָ�벻�ͺ���
//    for (islln* p = object.head; p != NULL; p = p->next) // ���Կ����Ǻ�
//    {
//        os << p->info << " ";
//    }
//    return os;
//}

ostream& operator<<(ostream& os, const isll& object)
{
    for (const islln* p = object.GetHead(); p != NULL; p = p->next)
    {
        os << p->info << " ";
    }
    return os;
}

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