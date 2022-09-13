#include <iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout << "The deafult constructor of the base class :" << endl;
    }
    base(int n)
    {
        cout << "The parameterized Constructor of the base class" << n << endl;
    }
};
class derived : public base
{
public:

    // /*=============
    //   FOR THE TEST:01 AND TEST:02
    //  =============*/
    // derived()
    // {
    //     cout << "The default constructor of the derived class:" << endl;
    // }
    // derived(int x)
    // {
    //     cout << "The parametrized constructor of the derived class:" << x << endl;
    // }


    // /*=============
    //   FOR THE TEST:03 AND TEST:04
    //  =============*/
    // derived():base()
    // {
    //     cout << "The default constructor of the derived class:" << endl;
    // }
    // derived(int x):base(x)
    // {
    //     cout << "The parametrized constructor of the derived class:" << x << endl;
    // }

};

int main()
{
    // /*=============
    //   TEST:01
    //  =============*/
    // derived d1;

    // /*=============
    //   TEST:02
    //  =============*/
    //  derived d2(2);

    //  /*=============
    //   TEST:03
    //  =============*/
    //  derived d3;

    //  /*=============
    //   TEST:03
    //  =============*/
    //  derived d4(2);
    return 0;
}