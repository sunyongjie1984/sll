#include <string> // stand library ahead of user define header

#include "sll.h"

int main()
{
    /*
    sll<string> list1(3);
    sll<string> list2(list1);
    cout << list1 << endl;
    globalPrint(cout, list1);
    cout << endl;
    cout << list2 << endl;
    globalPrint(cout, list2);
    cout << endl;

    list1.deleteNode("yong");
    cout << list1 << endl;
    globalPrint(cout, list1);
    cout << endl;

    sll<string> list3(cin);
    cout << list3 << endl;
    */

    sll<int> list4; // sll<int>是一个类型，这个类型的对象是由slln<int>类型的对象组成的链表
                    // list4是一个对象，它就是由一些类型为slln<int>的对象组成的。
    cin >> list4;
    cout << list4 << endl;
    return 0;
}
