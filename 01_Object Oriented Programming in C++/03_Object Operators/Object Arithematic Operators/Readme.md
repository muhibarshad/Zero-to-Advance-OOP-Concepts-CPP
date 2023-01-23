# Object Arithematic Operators

Arithematic operators (+, -, /, \*, %) will be applicable only in member wise

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/arithematic-1.png" style="height: 50vh; padding-left: 50vh;">
</p>
 
  Cannot be applicable directly on the objects agreement wise.
<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/arithematic-2.png" style="height: 60vh; padding-left: 50vh;">
</p>

> Use `Operator_Overloading` to apply these arithematic_operators on the objects directly.We will discuss this in later section [go_here](#).

### Example :

[Can we compare the use the arithematic operaters (+,-,\*,/,%) to perform arithematic calculations between two object data members ?](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/5_ArithematicOpearter.cpp)

```cpp

#include<iostream>

using namespace std;

class algebra
{
public:
    int x;
    int y;
public:

    void setData(int xA,int yA)
    {
        x=xA;
        y=yA;
    }
    void getData()
    {
        cout<<"The value of  x = "<<x<<endl;
        cout<<"The value of  y = "<<y<<endl;
    }

    //getters
    int getX(){ return x;}
    int getY(){ return y;}
};
int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.setData(5,6);
    obj2->setData(1,2);

    //  //Test:01
    // //Member Wise
    // cout<<obj1.getX()+obj2->getX()<<endl;
    // cout<<obj1.getY()+obj2->getY()<<endl;

    //  //Test:02
    // //Agremeent Wise
    // cout<<*(obj2)+obj1<<endl;
    // //Compile time error Operation not defined


   //Results:We can perform the matematical opaertions on the object adat memebers only member wise not agremnet wise.

    delete obj2;
    obj2=nullptr;

    return 0;
}
```
