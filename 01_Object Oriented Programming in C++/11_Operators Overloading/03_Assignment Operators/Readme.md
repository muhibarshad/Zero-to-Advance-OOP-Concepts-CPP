# Assignment Operator =

When we don't overload the `assignment operator` then,by `default` our compiler gives the overloaded assignment operator.

- Member Functions are compulsory for assignment
- Both operands should be the same class objects
- Member function takes right operation of operation as argumnet
- Check state of both L.H.S and R.H.S objects data members carefully.
  - If they are pointers address issues, due to different constructors, nullptr or valid memory address.
  - Dynamic arrays size mismatch issues.
  - Self assignment issue with pointer data members

For `STATIC-MEMORY`, we can do assigment of values.
Our all `data-members` are on the stack. So we just copy one varible to other.
our data-members are as follows:

```cpp
private:
    int x, y;
```

<p align="center">
    <img src="/04_Material/CodeSnaps/=.png" style="height: 50vh; padding-left: 0vh;">
 </p>

For `Pointers`,Check L.H.S AND R.H.S objects as;
|Left Operand | Right operand |
|:-----------:|:--------------:|
|nullptr|nullptr|
|nullptr|address|
|address|nullptr|
|address(single variable)|address(single variable)|
|address (Array Size Check)|address (Array Size Check)|

### Syntax:

<p align="center">
    <img src="/04_Material/CodeSnaps/pointer=.png" style="height: 80vh; padding-left: 0vh;">
 </p>

### Subscript Operator []

- Member function is compulsory for subscript operator.
- Left operand should be class object and right should be `int`.
- Member function takes right operand of operation as argument and calls on left operand.
- It provides access to elements of arrays defined inside objects as private data members.
- For example: a class myArray is defined here

**understand Setp by step in the code,See the code Example**

```cpp
#include <iostream>

using namespace std;

class myArray
{
    int size; // Array size
    int *ptr; // Pointer for dynamic 1-D Array
public:
    myArray()
    {
        size = 0;
        ptr = nullptr;
    }
    myArray(int size)
    {
        this->size = size;
        if (size > 0)
        {
            ptr = new int[size];
            for (int i = 0; i < size; i++)
                ptr[i] = i + 1;
        }
        else
            ptr = nullptr;
    }
    int &operator[](const int i);
    const int &operator[](const int i) const;
};
// implementation for Normal object
int &myArray::operator[](const int i)
{
    // check if index i is in range
    if (i >= 0 && i < size)
        return ptr[i];
    // return element by reference as lvalue
}
// implementation accessor for Constant object
const int &myArray::operator[](const int i) const
{
    // check if index i is in range
    if (i >= 0 && i < size)
        return ptr[i];
    // return element by reference as constant rvalue
}
int main()
{
    myArray a1(5); // creates array inside object
    a1[0] = 100;   // return reference to int element 1 of array
    // store 100 in element 1
    a1[1] = a1[0];       // copy element 1 to element 2
    cout << a1[1];       // print value of element 2
    const myArray a2(3); // creates array of size 3 inside constant object
    cout << a2[1];
    // return constant reference (read only) to int
    // a2[1] = 10;                     // wrong as constant reference is returned for constant object
    // • Not work on pointers to objects directly
    myArray *aptr = new myArray(5); // creates array inside object
    aptr[3] = 100;                  // wrong as aptr is pointer
    (*aptr)[3] = 100;               // first dereference the pointer then access data
    aptr[0][3] = 100;
}

```
