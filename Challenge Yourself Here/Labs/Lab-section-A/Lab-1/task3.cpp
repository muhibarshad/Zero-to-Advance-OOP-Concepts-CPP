// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:28:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda
/*Run this code and check if there is any issue, also detect dangling pointer and memory leak.
int*ptr = new int;
    cout << "Enter Int Value: ";
    cin >> *ptr;
    cout <<"Value is: " <<*ptr << endl;
    cout << "Pointer Value is: " << ptr << endl;
    delete ptr;
    cout << "After Del,,Value is: " << *ptr << endl;
    cout << "After Del,,Pointer Value is: " << ptr << endl;
    cout << "Dangling Pointer ? If Yes, then Resolve issue" << endl;
    cout << "Dynamically occupied Float Variable: "<<new float << endl;
    int*ptr1 = new int;
    *ptr1=9;
    cout << *ptr1 << endl;
    ptr1++;
    cout << *ptr1 << endl;
cout << "Find Memory Leak" << endl;
*/
#include <iostream>
using namespace std;
int main()
{
    int *ptr = new int;
    cout << "Enter Int Value: ";
    cin >> *ptr;
    cout << "Value is: " << *ptr << endl;
    cout << "Pointer Value is: " << ptr << endl;
    delete ptr;
    ptr = nullptr;
    cout << "After Del,,Value is: " << ptr << endl;
    cout << "After Del,,Pointer Value is: " << ptr << endl;
    cout << "Dangling Pointer ? If Yes, then Resolve issue" << endl;
    cout << "Dynamically occupied Float Variable: " << new float << endl;
    int *ptr1 = new int;
    *ptr1 = 9;
    cout << *ptr1 << endl;
    (*ptr1)++;
    cout << *ptr1 << endl;
    cout << "Find Memory Leak" << endl;
    delete ptr1;
    ptr1 = nullptr;
    delete new float;

    return 0;
}