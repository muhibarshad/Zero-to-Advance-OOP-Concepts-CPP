<p align="center">
    <img src="/Some%20extra%20concepts/logo.jpg" style="height: 60vh; padding-left: 50vh;">
</p>

<!-- Place this tag where you want the button to render. -->

<a class="github-button" href="https://github.com/muhib7353" data-color-scheme="no-preference: light; light: light; dark: dark;" aria-label="Follow @muhib7353 on GitHub">Follow @muhib7353</a>

# Zero to Advance OOP Course in C++

> This course helps you to cover all `OBJECT-ORIENTED-PROGRAMMING` concepts .By providing proper documentation of example codes with testing portions, attached slides with every topic, external links thats help to get benefit from them without straggling on internet a lot of hours 🤔.The one plus point for you is that every thing is in the complete `road-map` means you go through step by step without jumping to mixed topics.✨

# Contents

1. [Dynamic Arrays](#dynamic-arrays)
1. [One Dimensional Dynamic Arrays](#one-dimensional-dynamic-arrays)
1. [Two Dimensional Dynamic Arrays](#two-dimensional-dynamic-arrays)
1. [Object Oriented Programming Core Concepts](#core-concepts)
1. [Classes and Objects](#classes-and-objects)
1. [Setters and Getters](#setters-and-getters)
1. [This keyword](#this-pointer-or-this-keyword-in-c)

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

> Making a dynamic memory is called allocating the memory.
> Deleting a dynamic memory is called dellocating the memory.

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

## Boosted Material:

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

# Classes and Objects

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

## Helping Material 🤫:

- To practice real-world examples [class and object examples](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/)
- To go through slides [Class and object slides](/Some%20extra%20concepts/Slides/classes.pdf)
- For reading more concepts explore this page [Deep learn class and objects](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/)

# Dynamic Objects and Access Operator(->)

Dynamic Objects means the pointer of that objects is on the stack and the whole object is on the heap. The name of the object is actually a pointer so means whenever we use the name of the class actually we refer the address of the object on the heap. So how we can access the data memebers and member functions of the object ,To refer the data memebers and the member functions of that class , we use the **access-operator** `->` instead of `(.)` **dot operator** .The access operator make a link between the heap and and stack .

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

# Object Assignment operater (=):

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

# Object Relational Operaters( ==, !=, <=, >=, <, > )
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

# Object Arithematic Operator (+, -, /, \*, %)

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
   <img src="/Some%20extra%20concepts/codeSnaps/setters.png" style="height: 40vh; padding-left: 50vh;">
</p>

## Getters

> Used to get values of indiviual or complete object .

### Basic Syntax:

- **_returnType getVariableName (){ return variableName;}_**
     <p align="center">
     <img src="/Some%20extra%20concepts/codeSnaps/getters.png" style="height: 40vh; padding-left: 50vh;">
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

# This Pointer or This KeyWord in C++) :

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

# Object Function Types:
  Three type of functions can be implemented on the objects.
  1.By passing object as a value
  2.By passing object as a reference
  3.By return object as a object
