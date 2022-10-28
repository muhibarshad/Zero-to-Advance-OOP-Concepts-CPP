//===================================================
/***********virtual Functions***************
virtaul functions are to be such that we make that function is virtaul,
Suppose we have two same name functions but know we want to call the only one function at the run time
but we are not clear about which function should we call ,so by virtual functions we decide which function
should we call at the run time according to the suiation and making the other one virtual
Concept used as late binding:
compiler deferr the decision untill the program is running
And at runtime when it comes to know that which class is derived
by PTR then appropriat efunction would be called .
This called as dynamic bonding/late binding 
Now understand by two tests:
*/
//===================================================
#include <iostream>
using namespace std;
class base
{
public:
    //    //============
    //    //FOR THE TEST: 01
    //    //============
    //     void msg()
    //     {
    //         cout<<"I am the base class"<<endl;
    //     }

    // //============
    // // FOR THE TEST: 02
    // //============
    // virtual void msg()
    // {
    //     cout << "I am the base class" << endl;
    // }
};
class derived1 : public base
{
public:
    void msg()
    {
        cout << "I am the derived 1 class" << endl;
    }
};
class derived2 : public base
{
public:
    void msg()
    {
        cout << "I am the derived 2 class" << endl;
    }
};
int main()
{
    base *ptr1 = new derived1();
    base *ptr2 = new derived2();

    //    //============
    //    //TEST: 01
    //    //============
    //    ptr1->msg();
    //    ptr2->msg();

    // //============
    // // TEST: 02
    // //============
    // ptr1->msg();
    // ptr2->msg();

    return 0;
}