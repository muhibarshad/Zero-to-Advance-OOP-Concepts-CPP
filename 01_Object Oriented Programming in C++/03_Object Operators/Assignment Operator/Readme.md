# Object Assignment operater

In generally, the assignment operator can be used to copy one thing into another. The data memebers of one object can be copied to another data members in two ways

> Only if member access specifier is public.

1.Member wise data Assignment

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/assignment-1.png" style="height: 50vh; padding-left: 50vh;">

 </p>
 
 2.Aggregate Wise data Assignment
        <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/assignment-2.png" style="height: 50vh; padding-left: 50vh;">
 </p>
 
  ### Lets now understand by example 😍:
  [In C++ how the class data members of one object to be copied to the another object data memebers](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/3_AssignmentOperater.cpp)

```cpp
#include <iostream>

using namespace std;

class algebra
{
public:
int x;
int y;

    void getData()
    {
        cout<<"The value of x ="<<x<<endl;
        cout<<"The value of y ="<<y<<endl;
    }

};

int main()
{
algebra obj1;
algebra \*obj2=new algebra;

    obj1.x=1;
    obj1.y=2;

    //MEMEBER WISE COPYING
    cout<<"\t\tMEMEBER WISE COPYING :"<<endl;
    obj2->x=obj1.x;
    obj2->y=obj1.y;

    cout<<"The values in object 1 : "<<endl;
    obj1.getData();
    cout<<"The values in object 2 : "<<endl;
    obj2->getData();

    // Aggregate WISE COPYING
    cout<<"\t\tAggregate WISE COPYING :"<<endl;
    (*obj2)=obj1;

    cout<<"The values in object 1 : "<<endl;
    obj1.getData();
    cout<<"The values in object 2 : "<<endl;
    obj2->getData();

    delete obj2;
    obj2=nullptr;

    return 0;

}

```
