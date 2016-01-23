#ifdef __linux
#include <stdio.h>
#endif

#include "isll.h"

int main()
{
    cout << "Enter function main" << endl;
    isll list1;
    cout << "list1 is " << (list1.IsEmpty() ? "empty" : "not empty") << endl;
    list1.AddToHead(30);
    cout << "list1 is " << (list1.IsEmpty() ? "empty" : "not empty") << endl;
    cout << list1 << endl;
    list1.DeleteFromHead();
    cout << list1 << endl;
    list1.AddToTail(40);
    cout << list1 << endl;
    list1.DeleteFromTail();
    cout << list1 << endl;
    list1.AddToHead(30);
    list1.AddToTail(20);
    list1.AddToTail(40);
    list1.AddToHead(50);
    cout << list1 << endl;
    list1.DeleteNode(20);
    cout << list1 << endl;
    list1.DeleteNode(30);
    cout << list1 << endl;
    list1.DeleteNode(40);
    cout << list1 << endl;
    list1.DeleteNode(50);
    cout << list1 << endl;

    isll list2(4);
    cout << list2 << endl;

    list2.Reverse();
    cout << "the reversed list2 is following: " << endl;
    cout << list2 << endl;

    isll list3;
    // in windows we use ctrl + z as end of input
    // under UNIX like, we use ctrl + d, because in UNIX like ctrl + z means,
    // let the progress go to back ground
    cin >> list3;

    isll list4(list3);  // copy constructor
    isll list5 = list3; // copy constructor

    cout << list3 << endl;
    cout << list4 << endl;
    cout << list5 << endl;

    getchar();
    return 0;
}
