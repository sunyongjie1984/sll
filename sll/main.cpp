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

    sll<int> list4; // sll<int>��һ�����ͣ�������͵Ķ�������slln<int>���͵Ķ�����ɵ�����
                    // list4��һ��������������һЩ����Ϊslln<int>�Ķ�����ɵġ�
    cin >> list4;
    cout << list4 << endl;
    return 0;
}
