#ifdef __linux
#include <stdio.h>
#endif

#include "isll.h"

int main()
{
    isll list1;
    cout << "list1 is " << (list1.m_is_empty() ? "empty" : "not empty") << endl;
    list1.m_add_to_head(30);
    cout << "list1 is " << (list1.m_is_empty() ? "empty" : "not empty") << endl;
    cout << list1 << endl;
    list1.m_delete_from_head();
    cout << list1 << endl;
    list1.m_add_to_tail(40);
    cout << list1 << endl;
    list1.m_delete_from_tail();
    cout << list1 << endl;
    list1.m_add_to_head(30);
    list1.m_add_to_tail(20);
    list1.m_add_to_tail(40);
    list1.m_add_to_head(50);
    cout << list1 << endl;
    list1.m_delete_node(20);
    cout << list1 << endl;
    list1.m_delete_node(30);
    cout << list1 << endl;
    list1.m_delete_node(40);
    cout << list1 << endl;
    list1.m_delete_node(50);
    cout << list1 << endl;

    isll list2(4);
    cout << list2 << endl;

    list2.reverse();
    cout << "the reversed list2 is following: " << endl;
    cout << list2 << endl;
    
    isll list3;
    cin >> list3;

    isll list4(list3);  // copy constructor
    isll list5 = list3; // copy constructor

    cout << list3 << endl;
    cout << list4 << endl;
    cout << list5 << endl;



    char tmp  = static_cast<char>(getchar());
    std::cout << tmp << std::endl; // maybe ctrl + d , 4, eot ´«Êä½áÊø
    char tmp2 = static_cast<char>(getchar());     
    std::cout << tmp2 << std::endl; // maybe enter 10£¬ lf,»»ÐÐ·û

    char tmp3 = static_cast<char>(getchar());
    std::cout << tmp3 << std::endl;

    return 0;
}
