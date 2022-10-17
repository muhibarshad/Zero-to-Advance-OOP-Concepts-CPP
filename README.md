<p align="center">
    <img src="/Some%20extra%20concepts/logo.jpg" style="height: 60vh; padding-left: 50vh;">
</p>

<!-- Place this tag where you want the button to render. -->

<a class="github-button" href="https://github.com/muhib7353" data-color-scheme="no-preference: light; light: light; dark: dark;" aria-label="Follow @muhib7353 on GitHub">Follow @muhib7353</a>

# Zero to Advance OOP Course in C++

> This course helps you to cover all `OBJECT-ORIENTED-PROGRAMMING` concepts .By providing proper documentation of example codes with testing portions, attached slides with every topic, external links thats help to get benefit from them without straggling on internet a lot of hours 🤔.The one plus point for you is that every thing is in the complete `road-map` means you go through step by step without jumping to mixed topics.✨

# Contents

1. [Dynamic Arrays](#dynamic-arrays)
2. [One Dimensional Dynamic Arrays](#one-dimensional-dynamic-arrays)
3. [Two Dimensional Dynamic Arrays](#two-dimensional-dynamic-arrays)
4. [Object Oriented Programming Core Concepts](#core-concepts)
5. [Classes and Static Objects](#classes-and-static-objects)
6. [Dynamic Objects and Access operator(->)](#dynamic-objects-and-access-operator)
7. [Static and Dynamic Object Function Types](#static-and-dynamic-object-function-types)
8. [Object Operators](#object-operators)
   - [Object Assigment operator (=)](#object-assignment-operater)
   - [Object relational operators ( ==, !=, <=, >=, <, > )](#object-relational-operaters)
   - [Object Arithematic operators (+, -, /, \*, %)](#object-arithematic-operators)
9. [Setters and Getters](#setters-and-getters)
10. [This keyword](#this-pointer-or-this-keyword-in-cpp)
11. [Scope Resolution operator (::)](#scope-resolution-operator)
12. [Member Functions](#member-functions)
13. [Constructors and Destructors](#constructors-and-destructors)
    - [Default Constructor]()
    - [Parameterized Constructors](#paramterized-constructor)
    - [Overloaded Constructor](#overloaded-constructor)
    - [Copy Constructor](#copy-constructor)
    - [Destructor](#destructors)
14. [Const in oop](#const-in-oop)
    - [const data member](#const-data-members)
    - [const member Function](#const-member-functions)
    - [const obj](#const-object)

# Dynamic Arrays

> Dynamic memory allocation is the process of changing the size of the memory space during the run-time.

## Why we need it ?

Suppose you have building a facebook like accounts creating application.Users can create or delete accounts.In your database all the accounts can be stored in an array of **Users**.Suppose
at morning the users of your application are **5** `{'Hamza','Abbas','Ali','Ayesha','Fatima','Mujeeb'}`.At evening a boy named **_Ali_** want to delete its account due to some reasons.When he deletes its account then at position of ali `index` becomes empty . like this `{'Hamza','Abbas','','Ayesha','Fatima','Mujeeb'}`.Till the size of array is **5**.Now **Ali** again wants to creates its account, so we wants to add it on `run-time` **How can we increase the size of arrays?🤔**.

Main problem here is that ,when we deletes the account the in our memory, the size of array is till **5** means our memory is wasting . And when we adding an account then how we increase the size of array ?. To resolve such problems we need such a way to increase or decrease `dynamiclly` change the size of our arrays during `run-time`.It is not possible with the `static` arrays which size are always constant.Thats way,`DYNAMIC MEMORY ALLOCATION (DMA)` is introduced.

## Before Starting Something better to know (Heap or Stack):

There are two types of memory in our computers **_Heap and Stack_**.During Dynamic Memory Allocation, When we make a pointer of our variable its can be formed at the stack.(storing the address of our varible only) and its value can be stored at the heap.

In `static memory`, all the varibles and arrays are formed in the memory (stack) at the `compile-time` so after exection all the variables and arrays are destroyed from the memory (stack) by the compiler itself.
But in `Dynamic memory`, all the variables and arrays `values` are formed in the memory (heap) at the run-time, so compiler doesn't made them we `developers` made it during the execuation time. So its our responsibilty to destroyed them from the memory after the completition of their tasks.Otherwise a problem named `memory-leakage` can be created and our program `crashes`.

One more important concept about the dynamic memory allocation.
In local functions we make a varaible and it goes out from the execuation stack after the calling .So we cannot use its value further more to to store its value we make a varaible on heap and ist pointer on the stack and return the pointer from the function and store its in to the main stack pointer varaible.Now your memory cannot be leakage.The main point is your pointer would never be became the dangling pointer. And your heap value can never be became without its pointer.

> Making a dynamic memory is called allocating the memory.
> Deleting a dynamic memory is called dellocating the memory.

## Dangling Pointer

A pointer whose is pointing to such memory in the haep which is not exist .

## One Dimensional Dynamic Arrays

**Firstly**, `allocating`, we make a pointer of our array at the stack that containes the address of the first element of our array.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/ptr.png" style="height: 40vh; padding-left: 50vh;">

 </p>

**Secondly**,we make a array at the heap by the `new` keyword.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/heap.png" style="height: 40vh; padding-left: 50vh;">

 </p>

**Thirdly**,perform your tasks.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/tasks.png" style="height: 50vh; padding-left: 50vh;">

 </p>

**At last**, `dellocating`, delete the array values at the heap by the `delete` keyword.And
make the pointer of our array `nullptr` so its pointing to nothing.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int size = 5;
    int sum=0;

    //Allocating the memory
    int *arr = new int[size]{1,2,3,4,5};

    //sum of array
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    cout<<"The sum of all the elements in the array is = "<<sum<<endl;

    //Delloacting the memory
    delete[] arr;
    arr = nullptr;

    return 0;
}
```

### How to change the size of our arrays at run-time ? or at execution time? How to increase or decrease the size of our arrays dynamically ? or at execution time?

**Firstly**, we made our array whose size we want to change dynamically.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/temp1.png" style="height: 40vh; padding-left: 50vh;">

 </p>

**Secondly**, we create an temp dyanmic 1D-Array.Whose size is the size thats we want after changing meanns `size+increaseNum` or `size+decreaseNum` .

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/temp2.png" style="height: 40vh; padding-left: 50vh;">

 </p>

**Thirdly**, copy the array to tempArray.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/temp3.png" style="height: 50vh; padding-left: 50vh;">

 </p>

**At Last**, delete the array values from heap and mutate the array-pointer to the tempArray-pointer.And now you can mutate the size as `size+=num` (for-increaing) or `size-=num`(for-decreaing)

> Both our array and tempArray pointers in the stack pointing to the same changed tempArray values in the heap.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/temp4.png" style="height: 50vh; padding-left: 50vh;">

 </p>

**Now**,You can perform tasks, to the changed sized array ,after performing methods deallocate the aray and program happily finishes😊.(Problem-Solved,Hurray🥳)

```cpp
#include <iostream>
using namespace std;
int main()
{

    int size = 5;
    int *arr = new int[size]{1, 2, 3, 4, 5};

    int num;
    cout << "Enter the number how much size of array you wnat to cahnge :" << endl;
    cin >> num;

    int *temp = new int[size + num];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }

    //deleting the previous array
    delete[] arr;
    arr=temp;

    //giving values to increased indexs
    for(int i=size;i<size+num;i++){
        cin>>arr[i];
    }
    size+=num;

    delete[] arr;
    arr=nullptr;

    return 0;
}
```

# Boosted Material 1

- To Practice Questions Like ,insert,delete,shrink,add elements to the arrays dynamically
  see [1D-Arrays-Examples](</Object%20Oriented%20Programming/Step0_Dynamic%20Arrays/One%20Dimensional%20(1D)%20%20Dynamic%20Arrays/>)
- To Read more complexities about the dyanmic arrays read book pages from
  [LearnCpp](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- To get slides of dynamic memory [Dynamic Memory Allocation](/Some%20extra%20concepts/Slides/dynamicMemory.pdf)

## Two Dimensional Dynamic arrays

**Firtsly**, In Two Dimensional Dynamic arrays ,make an array of pointers (every element of array contaning the address of first element of each row of matrix) which is stored to the pointer in stack ,beacuse this pointer storing the address first pointer of array, so this pointer is the double pointer.

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/2d-1.png" style="height: 40vh; padding-left: 50vh;">
 </p>
  **Secondly**, Make a new array on the heap (column) from the every element(single-pointer) of the pointers array,that conatain the address of the first element of it column on the stack.

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/2d-2.png" style="height: 50vh; padding-left: 50vh;">
 </p>

**Thirdly**, Now our 2D-array is allocated.Now perform the all tasks on it.

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/2d-3.png" style="height: 70vh; padding-left: 50vh;">
 </p>

**At Last**,Deallocate the firstly all the columns on the heap. Then delete the pointers array.
Then make the matrix pointer to null pointing to the nothing.

```cpp
#include <iostream>
using namespace std;
int main()
{
    int row = 3;
    int col = 3;

    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
        }
    }

    for(int i=0;i<row;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix=nullptr;

    return 0;
}
```

## How to change the size of rows or columns of 2D-arrays at run-time ? How to increase or decrease the size of 2D-arrays dynamically ?

You can understand the one example of how to increase the size of columns and then do others operations by following it.

### Steps:(To increase the rows dynamically)

**Firstly**: Make the new 2D-Dynamic array .

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/temp2-1.png" style="height: 50vh; padding-left: 50vh;">
 </p>

**Secondly**: Make the `temp`2D-Dyanmic array.

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/temp2-2.png" style="height: 60vh; padding-left: 50vh;">
 </p>

**Thirdly**: Copy the pervious 2d-array to temp array.Delete the previous 2D-Array.Give pointer of temp array to previous array.

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/temp2-3.png" style="height: 70vh; padding-left: 50vh;">
 </p>

**At Last**: Add the new elements in the array .And finally dellocate the array.

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int row=3;
    int col=3;

    //Allocating the memory
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

   cout << "The random elements in the array :" << endl;
    for (int i = 0; i < row; i++)
    {
        // cout<<"Enter the row "<<i+1<<" :"<<endl;
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
            // cin>>matrix[i][j];
        }
    }

   int num;
    cout << "Enter the number of rows that you want to increase:" << endl;
    cin >> num;

    //increase the size of the rows
    int **temp = new int *[row + num];
    for (int i = 0; i < row + num; i++)
    {
        temp[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = temp;


    //Entering elemenst in the increased rows
    for (int i = row; i < row + num; i++)
    {
        // cout<<"Enter the row "<<row+1<<" :"<<endl;
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % (100 - 90)) + 1 + 90;
            // cin>>matrix[i][j];
        }
    }
    row += num;

   cout << "The elements in the array :" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << left;
        for (int j = 0; j < col; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    //dellocating the memory
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}

```

## Boosted Material:

- To Practice Questions Like inrease and decrease rows or columns of the 2D-arrays dynamically
  see [1D-Arrays-Examples](</Object%20Oriented%20Programming/Step0_Dynamic%20Arrays/Two%20Dimensional%20(2D)%20%20Dynamic%20Arrays/>)
- To Read more complexities about the dyanmic arrays read book pages from
  [LearnCpp](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- To get slides of dynamic memory [Dynamic Memory Allocation](/Some%20extra%20concepts/Slides/dynamicMemory.pdf)

# Core Concepts

A langugae which containes these four segments is referrred as **_Object-Oriented-Programming_** language.

- ## Classes and object :
  Classes have no exixtence in the memeory,its only a blueprint.When we make an object of that class ,then it should having the some memeory.Class is an user defined-data-Type, called as **_ABSTRACT_DATA_TYPE_**.
- ## Data hiding and Encapsulation:
  Data is hided from every another object is data hiding .All the memebers of a class including data members and member functions are closed in a class like a capsule is referred to as Encapsulation.This feature opens the new term named as `Abstraction` means all the inner details are completetly ifnored and we focus on the working of the software.
- ## Inheritance:
  **_Do not reinvent the wheel_**.In programming the term used as : **Do not repeat the code⛔**.Inheritance has the code reuse-ability.Some features are inherited from the base class and given to the derived class.If any language does not support the inheritance then its not calle the Object oriented programming language its called the **\*Object-Based-Language**.
- ## Polymorphism
  Define as : Single interface having multiple functionalities.(same name different behaviour).
  It has two types :
  - Static
    Function overloading is done in static polymorphism.It has be achieved on the compile time also called the **_compile_time_binding_**.
  - Dynamic
    Function overriding is done in the dynamic polymorphism.It has be achieved on the run time also called the **_Run_Time_binding_**.

# Classes and Static Objects

[What are classes 👀 ❓](#classes-and-object)

## Basic Syntx of class:

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/class1.png" style="height: 40vh; padding-left: 50vh;">
 </p>

## Basic Syntx of object:

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/obj.png" style="height: 40vh; padding-left: 50vh;">
 </p>

we cannot access the dataMemebers of the class outside the class .Their members are by `default-private`.So when we want to access them .The error should come as

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/error1.png" style="height: 40vh; padding-left: 50vh;">

> so when we want to access them outside the class,we use the `access-identifiers`.

## Access-Identifiers

There are there Access specifiers.

- ### Public
  Members declerad as private are only accessible within the class.
- ### Private
  Memebers of public are accessible from anywhere(accissble through the object).
- ### Protected
  Members are only accessible in child class.

Result:

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/result_class.png" style="height: 60vh; padding-left: 50vh;">

### Note:

> The address of a class is same as the address of the first dataMemeber of the class

# Boosted Material 2

- To practice real-world examples [class and object examples](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/)
- To go through slides [Class and object slides](/Some%20extra%20concepts/Slides/classes.pdf)
- For reading more concepts explore this page [Deep learn class and objects](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/)

# Dynamic Objects and Access Operator

Dynamic Objects means the pointer of that objects is on the stack and the whole object is on the heap. The name of the object is actually a pointer so means whenever we use the name of the class actually we refer the address of the object on the heap. So how we can access the data members and member functions of the object ,To refer the data members and the member functions of that class , we use the **access-operator** `->` instead of `(.)` **dot operator** .The access operator make a link between the heap and and stack .

### Understand by excample:

[How we make the dynamic objects of class and how to access their data members of taht dynamic object🙄❓](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/6_DyanmicObjects_and_acessOperaters.cpp)

```cpp
#include <iostream>

using namespace std;

class algebra
{
public:
    int y;
    int x;
    int add;
};

int main()
{
    //Alloacting the memory
    algebra *sum = new algebra;

    //Arrow operaters pointing the members on the heap(->)
    sum->x = 3;
    sum->y = 4;
    sum->add = sum->x + sum->y;

    //Derefernce and userd the dot opearter(.)
    cout << "The sum of " << (*sum).x << " and " << (*sum).y << " = " << (*sum).add << endl;

    //delloacting the memory
    delete sum;
    sum=nullptr;

    return 0;
}
```

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

# Object Operators

These are object opertors:

- [Object Assigment operator (=)](#object-assignment-operater)
- [Object relational operators ( ==, !=, <=, >=, <, > )](#object-relational-operaters)
- [Object Arithematic operators (+, -, /, \*, %)](#object-arithematic-operator)

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

# Object Relational Operaters

Relational operators can be applied only on the varaibles that are made in functions. In objects you cannot apply directly these operaters on the object data members. It cannot be possible by `Member-Wise` or `Agreement-Wise`.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/relational.png" style="height: 50vh; padding-left: 50vh;">
</p>

### Example :

[Can we compare the reational operaters (==,!=,<=,>=) to compare two object data members ?](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/4_RelationalOpearter.cpp)

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
    obj2->setData(6,5);

    //  //Test:01
    // cout<<obj1.getX()!=obj2->getX();
    // /*error: no match for 'operator!=' (operand types are 'std::basic_ostream<char>' and 'int')
    // cout<<obj1.getX()!=obj2->getX();*/

    //  //Test:02
    // cout<<*(obj2)==obj1;
    // //Compile time error Operation not defined

    // Results:So its mean we will never compare the data member wise or agrement wise
    delete obj2;
    obj2=nullptr;



    return 0;
}

```

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

# Setters and Getters

**_Why we need setters and getters_** ? What is the importance of getters and setters in real world?
Understand by exapmle ,in mobile phones when we want to increase the brightness of our mobile then can we go to the whole setting of the mobile and change it here **\*NO\*\*** .We only set the value of brightness same when we want to get the phone number of any person , we just search and get it.
Getters and setters are the same as , to retrieve the single dataMember or whole data member or to update them.

## Setters

> Used to set or update values of individual data members or a complete object.

### Basic Syntax:

- **_Void setVariableName (varaibleDataType parameterName){ variableName = ParameterName;}_**
   <p align="center">
   <img src="/Some%20extra%20concepts/codeSnaps/setters.png" style="height: 60vh; padding-left: 50vh;">
</p>

## Getters

> Used to get values of indiviual or complete object .

### Basic Syntax:

- **_returnType getVariableName (){ return variableName;}_**
     <p align="center">
     <img src="/Some%20extra%20concepts/codeSnaps/getters.png" style="height: 60vh; padding-left: 50vh;">
  </p>

  ## SetData and getData

  These are also the member functions of the class.They set the whole class data members and also get the data memebers of the whole class.

```cpp
/*Write a C++ program how to putData into dataMembers of a class that is private and getData from them
 */
#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
    float z;

public:
    void putData(int xA, int yA, int zA)
    {
        x = xA;
        y = yA;
        z = zA;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
        cout<<"The value of z = "<<z<<endl;
    }
};

int main()
{
    algebra equation1;

    //Test 01:
    equation1.putData(1,2,3);
    equation1.getData();
    return 0;
}
```

### Practice exapmles:

- [Getters and Setters in C++ ](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/2_gettersAndSetters.cpp)
- [getData and setData in C++ ](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/1_getData_and_putData.cpp)

# This Pointer or This KeyWord in Cpp

IN C++ ,**This** is a pointer refer to the insatnce of the class. **This** is a pointer Single copy of this pointer is maintained at class level accessible in member functions only.
**This** pointer has two main functionalities:

1.When in memeber functions of the class ,the local variables name same as the `data-members` name.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/this1.png" style="height: 50vh; padding-left: 50vh;">

 </p>
 
2.Used to return the whole object from the member function. When you want to use the function chaining in objects.
In short,it can be used for the function calls chaining in which the local object returns the refernce of the single object and in function chaining it updates the every previous function value also.
<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/this2.png" style="height: 70vh; padding-left: 50vh;">
 </p>
 
  ### Lets now understand by example 😍:
  [What is a this key Word in C++? Write a C++ program in which the setter function parameter name is same as the class data member name.What is the *this Pointer* in the C++ 😧?](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/9_thisPointer.cpp)

```cpp
#include<iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
public:
    //setters
    void setX(int x)
    {
       this->x=x;
    }
    void setY(int y)
    {
        this->y=y;
    }
    void setData(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    //getters
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
    }

    //member functions
    algebra &value(int x)
    {
        this->x=x;
        return *this;
    }
    algebra &incrementValue(int y)
    {
        this->x++;
        this->y=y;
        return *this;
    }

};

int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.setData(1,2);
    obj2->setData(3,4);

    obj1.getData();
    obj2->getData();

    obj1.value(100).incrementValue(200);
    obj1.getData();//101,200--->chaining is sequential and the changes made to the object’s data members retains for further chaining calls.

    // obj1.setX(90).setY(900);// error: invalid use of 'void'


    return 0;
}
```

# Scope Resolution operator

## Defination:

> Scope Resolution operater (::) define the scope of anything at any place .Used to access the gloabal varables with the same name ,access the class memeber functions outside the the class ,usedin namespaces and in the inheritance

Suppose we have a class having 1000+ member functions our class size will become too springable 🥴 . And other problem is that suppose in your company your team fellow want to see your code he does't want to see your logics and how you write the code he/she just wnat to see what functionalities your class can do and think that your class has 2000+ member functions of different functionalities.In ecah member function you write the 1000+ lines of code.So showing every functionality name takes too much time🤧 and may be its a chance your team member beacome frustated 😡. As a result, **How to resolve these problems ?** The first answer involed in your brain is to make prototypes inside the class and make functions outside the class. Okay ! Thats good, lets try it

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/s-1.png" style="height: 70vh; padding-left: 50vh;">
 </p>

But the error should become :

```diff
- error: invalid use of 'this' in non-member function void setX(int x) { this->x = x; }
```

Beacuse, we know that all the data members and function members are developed public,private and protected only inside the class only accessible to them is protected or publc. And how can we refer that this function is a member function of that specific class.

How to resolve this error :

```diff
+ Use the Scope resolutioon opertor `::`  with the name of the class
```

_Means that this function has scope to that class_

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/s-2.png" style="height: 50vh; padding-left: 50vh;">
</p>

### Understand by complete [Scope-Resolution(::) Example](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/10_scopeResolutionOperter.cpp) 😎:

```cpp
#include <iostream>

using namespace std;

class algebra
{
private:
   int x;
   int y;

public:
   // setters
   void setX(int);
   void setY(int);
   void setData(int, int);
   void setAlgebra(algebra);

   // getters
   int getX() const;
   int getY() const;
   void getData() const;
   algebra getAlgebra() const;

   // memberFunctions are here
   //.........
};

// SETTERS_scope_resolutions
void algebra::setX(int x) { this->x = x; }
void algebra::setY(int y) { this->y = y; }
void algebra::setData(int x, int y)
{
   this->x = x;
   this->y = y;
}
void algebra::setAlgebra(algebra obj)
{
   x = obj.x;
   y = obj.y;
}

// GETTERS_scope_resolutions
int algebra::getX() const { return x; }
int algebra::getY() const { return y; }
void algebra::getData() const
{
   cout << "The value of x = " << x << endl;
   cout << "The value of y = " << y << endl;
}
algebra algebra::getAlgebra() const
{
   return *this;
}

int main()
{
   algebra obj1;
   obj1.setData(1, 2);
   obj1.getData();

   algebra obj2;
   obj2.setAlgebra(obj1);
   obj2.getData();

   obj1.getAlgebra().setX(8);
   obj1.getData();

   return 0;
}
```

# Member Functions

You already know that we had already discussed the member functions, then what they are 🤔 ? Every class has such type of member functions :

- [Getters](#getters)
- [Setters](#setters)
- [Mutators](#setters)
- [Accessers](#getters)
- [Functionaliters](#functionaliters)
- Constructors
- Destructors
- Iterators
- Operators
  In all of above we have done `getters` and `setters`. `Mutators` and `Accessors` are same as `getters` and `setters` beacuse by using the `setters` we can have full access to the data memebers of the class to mutate them directly and sam for the `getters` we can have directly access to retrieve them.
  **NOW**,we will discuss about the **_Functionaliters_**( I think thats not make sense 😅, but according to me its very straightForward to understand).Others will be discuss in the coming points.

## Functionaliters :

> Main functions that perform some operations on the data are called fucntionaliters.
> Functions that perform some mathematical and other operations on the data memebers and show some output or help in other functions to perform functionalities.

### Let understand by example 🙂 :

[Write a c++ program in to find distance between two points and take third point and find from where the distance from third point is closest](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/11_MemberFunctions.cpp)

```cpp
/*Write a c++ program in to find distance between two points and take third point and find from where the distance from third point is closest*/
#include <iostream>
#include <cmath>

using namespace std;

class algebra
{
public:
    // setters
    void setX(int);
    void setY(int);
    void setData(int, int);
    void setAlgebra(algebra);

    // getters
    int getX() const;
    int getY() const;
    void getData() const;
    algebra getAlgebra() const;

    // memberFunctions
    float calculateDistance(algebra);
    algebra closestPoint(algebra , algebra );

private:
    int x;
    int y;
};

// SETTERS_scope_resolutions
void algebra::setX(int x) { this->x = x; }
void algebra::setY(int y) { this->y = y; }
void algebra::setData(int x, int y)
{
    this->x = x;
    this->y = y;
}
void algebra::setAlgebra(algebra obj)
{
    x = obj.x;
    y = obj.y;
}

// GETTERS_scope_resolutions
int algebra::getX() const { return x; }
int algebra::getY() const { return y; }
void algebra::getData() const
{
    cout << "The value of x = " << x << endl;
    cout << "The value of y = " << y << endl;
}
algebra algebra::getAlgebra() const
{
    return *this;
}

// Member_Functions
float algebra::calculateDistance(algebra point)
{
    int d1 = point.x - x;
    int d2 = point.y - y;

    int temp = ((d1 * d1) + (d2 * d2));

    return sqrt(temp);
}

algebra algebra ::closestPoint(algebra p1, algebra p2)
{
    float d1 = calculateDistance(p1);
    float d2 = calculateDistance(p2);

    return d1 <= d2 ? p1 : p2;
}

int main()
{
    algebra point1, point2, point3;

    point1.setData(6, 9);
    point2.setData(12, 3);
    point3.setData(1, 15);

    cout << point1.calculateDistance(point2)<<endl;
    point1.closestPoint(point2,point3).getData();

    return 0;
}
```

# Now its Time for Boosted Material 3

## Go deep 🧐, learn deep 😎

- See basic concept based questions on `setters`, `getters`, `this->pointer`, `object operators` and `object functions` click [here](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/)
- To get slides on these topics click [here](/Some%20extra%20concepts/Slides/memberFunctions.pdf)
- To read about them more briefy visit [here](https://learncpp.com)

# Constructors and Destructors

### Defination:

> It is a function.It does not have any `return type`(like int,void). It has same name as of its class.They can never be called instead(they can be more than two ) are called and executed automaticallu on the time of creation oof object.Their main purpose to initialze the data members of an object being created.

Every object will be called only once in its life by the constructor till it is destroyed.Compiler give us default constructor but ity initliaze the data members with teh garbage values. If any one of the constructor should be written then the compiler does not gives its default constructor Constructor are of three types:

- Deafult Constructor
- Parameterized Constructor
- Copy Constructor

## Default Constructor

Its parameters are empty and it can be called on the time of the object creation.

### Syntax:

 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/cons-1.png" style="height: 50vh; padding-left: 50vh;">
</p>
 
 ### Example:
 ```cpp
 /*Write a C++ program how to write the default constructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;
public:
	algebra();
	void setData(int, int);
	void getData();
};
//Default Constructor
algebra::algebra()
{
	x = 0;
	y = 0;
	cout << "Deafult Constructor should be called:" << endl;
}
void algebra ::setData(int x, int y)
{
	this->x = x;
	this->y = y;
}
void algebra ::getData()
{
	cout << "The value of x = " << x << endl;
	cout << "The value of y = " << y << endl;
}
int main()
{
	algebra obj1;
	obj1.setData(1, 2);
	obj1.getData();
	algebra obj2;
	obj2.getData();

    return 0;

}

````
## Paramterized Constructor:
  Constructors are `overloaded` like `function-overloading`. When there are more than one constructors in a class having different number of parameters are called overloaded or parameterized constructors.
 ### VIP Note:
  >When we call any constructor on an object.Then only that `one` constructor should be called the of constructors should be remain and not be called.

  ### Syntax:

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/cons-2.png" style="height: 50vh; padding-left: 50vh;">
</p>

  ### Example:

```cpp
/*Write a C++ program how to write the parameterized or overloaded constructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;
public:
	algebra();
    algebra(int,int);
	void setData(int, int);
	void getData();
};
//Default Constructor
algebra::algebra()
{
	x = 0;
	y = 0;
	cout << "Deafult Constructor should be called:" << endl;
}
//paremterized constructor
algebra::algebra(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "Parameterized Constructor should be called:" << endl;
}
void algebra ::setData(int x, int y)
{
	this->x = x;
	this->y = y;
}
void algebra ::getData()
{
	cout << "The value of x = " << x << endl;
	cout << "The value of y = " << y << endl;
}
int main()
{
	algebra obj1(1,2);
	obj1.getData();
	algebra obj2;
	obj2.getData();

    return 0;

}
````

# Copy constructor

Copy constructor can be used to copy the one object constructor to another object .In copy constructor the paremterized object should be called as a refernce. Otherwise it creates a problem of `recursion`. To undertsnad this ,suppose we equal the object_2 to object_1 then the copy constructor of object_2 should be called and it takes the object_1 as a parameter and this parameter object makes a copy of the object_1 so to make copy of object_1 again the `copy-constructor` should be called again and agin and this process comes into the `recusrion` (infinity) and our program crushes when the stack overflow. But there is another problem here if we pass the arguemtative object as a refence than there is a dangerous chance to mutate the data of this object beacuse we are passing it as reference to avoid these bugs we pass it as a `const` now its beacame impossible to mutate the original object.

### Note:

> Pass the copying object as a refernce `&`.
> Pass the copying object as a constant `const`.
> It uses copy data of an object `bit-by-bit`.

### Syntax:

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/cons-3.png" style="height: 50vh; padding-left: 50vh;">
</p>
### Example:

```cpp
/*Write a C++ program how to write the copy constructor constructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;
public:
	algebra();
    algebra(int,int);
    algebra(const algebra&);
	void setData(int, int);
	void getData();
};
//Default Constructor
algebra::algebra()
{
	x = 0;
	y = 0;
	cout << "Deafult Constructor should be called:" << endl;
}
//paremterized constructor
algebra::algebra(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "Parameterized Constructor should be called:" << endl;
}
//copy constructor
algebra::algebra(const algebra& temp)
{
    x=temp.x;
    y=temp.y;
    cout<<"Copy constructor should be called:"<<endl;
}
void algebra ::setData(int x, int y)
{
	this->x = x;
	this->y = y;
}
void algebra ::getData()
{
	cout << "The value of x = " << x << endl;
	cout << "The value of y = " << y << endl;
}
int main()
{

    //default
	algebra obj2;
	obj2.getData();
    //parametrized
	algebra obj1(1,2);
	obj1.getData();
    //copy
    algebra obj3=obj1;
    obj3.getData();
    algebra obj4(obj2);
    obj4.getData();

    return 0;

}
```

## Overloaded Constructor :

Overloaded Constrcutor is the sum of the deafult constructor and the parameterized constructor.

### Basic Syntax:

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/over.png" style="height: 50vh; padding-left: 50vh;">
</p>

Example:

```cpp
#include <iostream>
using namespace std;
class phoneDetails
{
private:
    string name;
    int  RAM;
    float processor;
    char battery;
public:
//==============================================
//Overloaded constructor
/*The sum of the
1-deafult constructor
2-Paramterized Constructor
*/
//==============================================
//overloaded Constructor
phoneDetails(string Name="NULL",int ram=0,float process=0.0,char batt=' ')
{
   name=Name;
   RAM=ram;
   processor=process;
   battery=batt;
}

//==============================================
//Copy constructor
//==============================================

phoneDetails(phoneDetails &mob)
{
   name=mob.name;
   RAM=mob.RAM;
   processor=mob.processor;
   battery=mob.battery;
}

void getData();

//==============================================
//Calling destructor
//==============================================

~phoneDetails()
{
    cout<<"Destructor has been called:"<<endl;
}

};

//==============================================
//Accessing the functions of the class outside the class
//==============================================

void phoneDetails::getData()
{
   cout<<"The name of the Phone = "<<name<<endl;
   cout<<"The Ram of the Phone = "<<RAM<<endl;
   cout<<"The Processor of the Phone = "<<processor<<endl;
   cout<<"The Battery of the Phone = "<<battery<<endl;
}

//Main
int main()
{
    phoneDetails d1;//deafult constructor
    phoneDetails d2("Iphone",8,2.8,'1');//parameterized constructor
    phoneDetails d3(d2);//copy constructor

    d1.getData();
    d2.getData();
    d3.getData();

    return 0;
}
```

## Destructors:

### Defination:

> To destroy the object and free the memory.Same syntax as a constructors.Destructors cannot be overloaded since it is destroying the object and no parameter is required.It destroys the every object when the main function is executed. Executes when teh object goes out of scope.Just use the `telda(~)` sign with the destructo to distinguish it between the deafult constructor and the destructor.

### Synatx:

   <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/des.png" style="height: 50vh; padding-left: 50vh;">
</p>

### Example:

```cpp
/*Write a C++ program how to write the destructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;
public:
	algebra();
    algebra(int,int);
    algebra(const algebra&);
	void setData(int, int);
	void getData();
    ~algebra();
};
//Default Constructor
algebra::algebra()
{
	x = 0;
	y = 0;
	cout << "Deafult Constructor should be called:" << endl;
}
//paremterized constructor
algebra::algebra(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "Parameterized Constructor should be called:" << endl;
}
//copy constructor
algebra::algebra(const algebra& temp)
{
    x=temp.x;
    y=temp.y;
    cout<<"Copy constructor should be called:"<<endl;
}
void algebra ::setData(int x, int y)
{
	this->x = x;
	this->y = y;
}
void algebra ::getData()
{
	cout << "The value of x = " << x << endl;
	cout << "The value of y = " << y << endl;
}
//destructor
algebra::~algebra()
{
    cout<<"Destructor should be called"<<endl;
}
int main()
{

    //default
	algebra obj2;
	obj2.getData();
    //parametrized
	algebra obj1(1,2);
	obj1.getData();
    //copy
    algebra obj3=obj1;
    obj3.getData();
    algebra obj4(obj2);
    obj4.getData();

    return 0;

}
```

# Boosted Material 4

## Go deep 🧐 ,learn Deep 🤓

- To get the briefly explained and good UI slides on the constructors and destructors get [here](/Some%20extra%20concepts/Slides/constructorsAndDestructors.pdf)
- To get the practice programs step by step for constructors and destructors get [here](/Object%20Oriented%20Programming/Step2_Constructors%20and%20destructors/)
- To study more abou t the constructors and destructors go [here](https://www.learncpp.com/cpp-tutorial/constructors/)

# Objects Arrays

Every object are same as the simple arrays on each index contain object class. On the time of creation of the objects array the `default_constructors` should be called.

## Syntax:

Basic syntax for the decalaration and initailzation of objects with the default values by calling different constructors :

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/arrays.png" style="height: 50vh; padding-left: 50vh;">
 </p>

- On `0` index initilize the object with the default construtor.
- On `1` index initilize the object with the parameterized construtor.
- On `2` index initilize the object with the copy construtor.

Accessing of these objects is same as the simple arrays `dot(.) operator` for the static arrays and `spread(->) operator` for the dynamic arrays.

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/dot.png" style="height: 70vh; padding-left: 50vh;">
 </p>

# Const in oop

## Const Data Members

### Defination

> The `data members`,state or properties whose value can not be changed during execution time and require value at time upon intialization .

### Note

> You can not left const memmber uninitialized,otherwise it will cause error!

### Ways to declare and initialize


1.  Initializing at time of declarartion.But keep in reminder that some compilers does not allow
    initialazation of const like this way.



 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/constdatamember.png" style="height: 70vh; padding-left: 50vh;">
 </p>

2)Initializing in `Initializer list` of `constructors`

 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/connst_In_initializerlist.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example Code

```cpp
#include<iostream>
using namespace std;

class Student
{
	String name;

	// 1) initializing const member at time of creation
	const int Id=1;
	const double CNIC;

public:
	// 2)initializing const member in member initialization list
	Student():CNIC(123-456789-123) {}

};
```

## Const Member functions

### Defination

> Tese are `member functions` of class which allow only _memory reading_.It simply means we can not change any `data member` of class either const or non-const `data member` in Const member functions.The can be accessed by both `const object` and `non-const object`.

### Note

> `constructors` are also _special member functions_ of class but it is not allowed to make constructors const functions.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/const_functionn.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example code

```cpp

#include<iostream>
using namespace std;

class Student
{
	String name;
	const int Id = 1;

public:

	//-----Getters/Accessors----
	string getName() const
	{
		//Here if you try to modify data member name,it will cause error although it is non-const
		// like:
		// name="Waleed";
      return name;

	}
	int getId() const
	{
		//Here if you try to modify data member Id,it will cause error
		// like:
		// Id=9;
      return Id;

	}

};
int main()
{
	Student student_1;
	Student const  student_2;

	//Accessing constant function by Non const-object
	student_1.getId();

	//Accessing constant function by const-object
	student_2.getId();

}

```

## Const Object

### Defination

> Tese are `objects` of class which allow only **memory reading**.It simply means we can not change any `data member` of class either const or non-const `data member`.

### Note

> const objects give their `refrence` to only const member functions/behaviours.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/const_obj.png" style="height: 70vh; padding-left: 50vh;">
</p>

```cpp


#include<iostream>
using namespace std;

class Student
{
	String name;
	const int Id = 1;

public:

	//-----Getters/Accessors----

	string getName()
	{

      return name;

	}
	int getId() const
	{

      return Id;

	}


};
int main()
{

Student const Student_1;
	//getId is constant member function,Therfore const
    //obj studen_1 give its refrence
	Student_1.getId();



	//getName is not_ constant member function,Therfore const
    //obj studen_1 does not give  its refrence
   //  Error---> Student_1.getName();


}
```

# Static Kewword With Classes

### Defination

> Using the static keyword on a local variable changes its duration from **automatic duration** to **static duration**. This means the variable is now created at the start of the program, and destroyed at the end of the program (just like a global variable). As a result, the static variable will retain its value even after it goes out of scope!

Static kewword has two uses with class which are following below:
- `static data member`
- `static function`

## Static Data member

### Defination

> Static Data members in `Classes` are actually belong to respective Class not to the object,it means it works like `Global Variable` for the `class` and `class objects`.

#### Declaration and defination of static Data member

- static members are declared *inside* the `Class`
- static members are defined *outside* the `Class`

##### Reason of Defining outside the class 😉

> It makes a sense because static data member belong to class and its memory allocated once but imagin if it is defined inside class so whenever the object of class is being made,everytime memory allocated wich is not allowed

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/staticdatamember.png" style="height: 70vh; padding-left: 50vh;">
</p>

##### Best Practice 👀

> It is best practice to access `static data member` by **class name** with `scope resolution (::) operartor` rather than by accessing **object** with `memory access/dot operattor (.)`.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/staticdatamember_define.png" style="height: 70vh; padding-left: 50vh;">
</p>

##### Tips 😎

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/staticdatamember_const.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example code

```cpp
#include<iostream>
using namespace std;

class Circle
{
	int radius;
	static const float Pi;

public:
	//------Mutator/setter-------------
	void setRadius(int radius)
	{
		this->radius = radius;
	}

	//-----Getter/Accessor--------------
	int getRadius() const
	{
		return radius;
	}


	//-----member function-----------
	double calculateArea()
	{
		return Pi * (radius * radius);
	}



};

int main()
{
	Circle circle_1;
	circle_1.setRadius(5);

	cout << circle_1.calculateArea();
}
```

# Static Member Function

## Defination

>`Static member functions` can be used to work with `static member` variables in the **class**. An **object** of the class is not required to call them.

### Interesting Facts about Static functions ✔

- `this pointer` does not exist in `static member function`,because `this pointer` belong to the object where static member function belong to **class** not to object
- In static behaviour ,we can also call other `static data members` and `static functions`
- `static member functions` can not be **constant**.

### Tip 👀

> You can call `static function` by **object name** with `memory access operator (.)` but it doest not good programming practice.So,it is good practice to access `stattic memmber function` of class by **class** name with `scope resolution operator (::)`.


<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/staticFunctions.png" style="height: 70vh; padding-left: 50vh;">
</p>

## Example code

```cpp
#include <iostream>
using namespace std;

class Circle
{
    int radius;
    static const float Pi;

public:
    //--------Setter/Mutator------------
    void setRadius(int radius)
    {
        this->radius = radius;
    }

    int getRadius() const
    {
        return radius;
    }

    //-----Getter/Accessor--------------
    static int getPi()
    {
        // Here,you cant not access any data member and member function directly except static data member and other static function
        //  like
        // radius=6;  -->error
        //  setRadius(5);   -->error

        return Pi;
    }
};

int main()
{ // Accessing static data member of class through static function with class name and scope resolution operartor
    cout << Circle::getPi();
}


```