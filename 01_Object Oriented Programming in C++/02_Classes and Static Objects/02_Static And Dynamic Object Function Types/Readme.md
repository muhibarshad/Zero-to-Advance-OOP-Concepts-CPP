# Static and Dynamic Object Function Types:

Three type of functions can be implemented on the objects.

1. By passing object as a value
2. By passing object as a reference
3. By return object as a object

## 1.By passing object as a value

In `static` Pass objects into functions as an argument and use these parameters as a local object which has a complete access to the data members and member functions of the class same as for the argumentative object.

> The object which calls the functions is called the `Left_hand_side_object`.

We don't need to pass the two objects as the arguments beacuse L.H.S object is already exist ,and accessible to the class functions and we only need to pass the other funtions which is right hand side object.

In `Dyanmic` the copy of argumentative objects will not be made only the address of these objects will pass and dereferencing these adress and perform operations.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/f-1.png" style="height: 50vh; padding-left: 50vh;">
 </p>

## 2.By passing object as a reference

In `static` When passing object as an argument to the function which recieveing it as a refernce parameter, then the copy of that object will not be produce.The address of this object will be use and its means any changing in data members or function members of the parameter object will aslo mutate the original argumentative object.
In `Dyanmic` the copy of argumentative objects will not be made only the address of these objects will pass ,so we will not have to use the refernce operator `&` , beacause already we pass the address `refernce` of the objects on the heap to function parameters As a result ,dereferencing these adresses and mutating the data memebers and member functions will mutate the original argumentative objects data members and member functions respectively.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/f-2.png" style="height: 70vh; padding-left: 50vh;">
 </p>

## 3.By return object as a object

In `static` Return type of the function is a class name. When you manipulate some data and return a object made inside the function.
In `Dyanmic`,the returing object returns the only address of the making object not the object on the heap. beacuse when the function executes the making pointer will automatically goes out from the execuation stack. but the object on the heap is exixts . So just return the address of the making pointer.

> When an object is returned at compile-time it can be stored an anonymous varaible of same returning dataType and then assign it the varible on which the functions call this process is called the `RETURN_VALUE_OPTIMIZATION(RVO)`. And you when you run the program its destructor will be showed in the screen .

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/RVO.png" style="height: 50vh; padding-left: 50vh;">
 </p>

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/RVO-result.png" style="height: 50vh; padding-left: 50vh;">
 </p>
### Let understand by 😮 [dynamic-example](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/6_DyanmicObjects_and_acessOperaters.cpp):

For static click [here](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/7_staticObjectAndFunctions.cpp)

```cpp
/*Dynamic Objects when we pass to functions they always should be pass as by refernce
/*This code has three parts by three tests so you can uncommenntg the every test and check the outputs to understand
1:Pass by value  for dynamic objects
2:Pass by refernce for dynamic objects
3:Return value for dynamic objects
*/

#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    // setters
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    void setData(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // getters
    int getX() { return x; }
    int gety() { return y; }
    void getData()
    {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
    }
};

// Functions

// 1:Pass by value
bool passByValue(algebra *A, algebra *B)
{
    return A->getX() != B->getX() ? true : false;
}

// 2:Pass by refernce
void update(algebra *A, algebra *B)
{
    B->setX(B->getX() + 100);
    B->setY(B->gety() + 100);
}

// 3:Return value
algebra *createCopy(algebra *A)
{
    algebra *copy = new algebra;

    copy->setX(A->getX());
    copy->setY(A->gety());

    return copy;
}
int main()
{
    algebra *obj1 = new algebra;
    algebra *obj2 = new algebra;

    obj1->setData(1, 2);
    obj2->setData(3, 4);

    // // Test:01
    // cout << passByValue(obj1, obj2);

    // //Test:02
    // cout << "Before passing obj2 as a pointer to update function : " << endl;
    // obj2->getData();
    // update(obj1, obj2);
    // cout << "After passing obj2 as a pointer to update function : " << endl;
    // obj2->getData();

    // //Test:03
    // cout << "The object members :" << endl;
    // algebra *copy=createCopy(obj1);
    // copy->getData();

    /*Results:Object’s data is always
    pass by reference through
    pointers*/

    return 0;
}
```