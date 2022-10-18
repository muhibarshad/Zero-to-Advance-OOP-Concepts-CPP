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
