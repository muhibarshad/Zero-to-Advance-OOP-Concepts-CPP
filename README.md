<p align="center">
    <img src="/Some%20extra%20concepts/logo.jpg" style="height: 60vh; padding-left: 50vh;">
</p>

<!-- Place this tag where you want the button to render. -->

<a class="github-button" href="https://github.com/muhib7353" data-color-scheme="no-preference: light; light: light; dark: dark;" aria-label="Follow @muhib7353 on GitHub">Follow @muhib7353</a>

# Zero to Advance OOP Course in C++

> This course helps you to cover all `OBJECT-ORIENTED-PROGRAMMING` concepts .By providing proper documentation of example codes with testing portions, attached slides with every topic, external links thats help to get benefit from them without straggling on internet a lot of hours 🤔.The one plus point for you is that every thing is in the complete `road-map` means you go through step by step without jumping to mixed topics.✨

# Contents

1. [Dynamic Arrays](#dynamic-arrays)
2. [Core Concepts](#core-concepts)
3. [Classes and Objects](#classes-and-objects)

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
<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/deallocate.png" style="height: 60vh; padding-left: 50vh;">

 </p>

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

## How to change the size of rows or columns of 2D-arrays at run-time ?  How to increase or decrease the size of 2D-arrays dynamically ? 

You can understand the one example of how to increase the size of columns and then do others operations by following it.

### Steps:(To increase the rows dynamically)

**Firstly**: Make the new 2D-Dynamic array . 

**Secondly**: Make the `temp`2D-Dyanmic array.

**Thirdly**: Copy the pervious 2d-array to temp array.Delete the previous 2D-Array.Give pointer of temp array to previous array.     

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
  * To Practice Questions Like inrease and decrease rows or columns of the 2D-arrays dynamically
  see [1D-Arrays-Examples](/Object%20Oriented%20Programming/Step0_Dynamic%20Arrays/Two%20Dimensional%20(2D)%20%20Dynamic%20Arrays/)
  * To Read more complexities about the dyanmic arrays read book pages from
  [LearnCpp](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
  * To get slides of dynamic memory [Dynamic Memory Allocation](/Some%20extra%20concepts/Slides/dynamicMemory.pdf)

# Core Concepts
  A langugae which containes these four segments is referrred as ***Object-Oriented-Programming*** language.
 * ## Classes and object :
    Classes have no exixtence in the memeory,its only a blueprint.When we make an object of that class ,then it should having the some memeory.Class is an user defined-data-Type, called as ***ABSTRACT_DATA_TYPE***.
 * ## Data hiding and Encapsulation:
    Data is hided from every another object is data hiding .All the memebers of a class including data members and member functions are closed in a class like a capsule is referred to as Encapsulation.This feature opens the new term named as `Abstraction` means all the inner details are completetly ifnored and we focus on the working of the software.
 * ## Inheritance:
    ***Do not reinvent the wheel***.In programming the term used as : **Do not repeat the code⛔**.Inheritance has the code reuse-ability.Some features are inherited from the base class and given to the derived class.If any language does not support the inheritance then its not calle the Object oriented programming language its called the ***Object-Based-Language**.
 * ## Polymorphism
  Define as : Single interface having multiple functionalities.(same name different behaviour).
  It has two types :
   * Static
      Function overloading is done in static polymorphism.It has be achieved on the compile time also called the ***compile_time_binding***.
   * Dynamic
      Function overriding is done in the dynamic polymorphism.It has be achieved on the run time also called the ***Run_Time_binding***.


# Classes and Objects
  [What are classes  👀 ❓](#classes-and-object)
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

 >so when we want to access them outside the class,we use the `access-identifiers`.

 ## Access-Identifiers
  There are there Access specifiers.
* ###  Public
     Members declerad as private are only accessible within the class.
* ### Private
     Memebers of public are accessible from anywhere(accissble through the object).
* ### Protected
     Members are only accessible in child class.

 Result:
    <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/result_class.png" style="height: 60vh; padding-left: 50vh;">

   ### Note:
   >The address of a class is same as the address of the first dataMemeber of the class

 ## Helping Material 🤫:
  * To practice real-world examples [class and object examples](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/)
  * To go through slides [Class and object slides](/Some%20extra%20concepts/Slides/classes.pdf)
  * For reading more concepts explore this page [Deep learn class and objects](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/)





```
