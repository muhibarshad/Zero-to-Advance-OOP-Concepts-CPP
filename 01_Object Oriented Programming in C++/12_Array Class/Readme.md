# Objects Arrays

Every object is the same as a simple array, in that each index contains an object class. At the time of creation of the object array, the `default constructors` should be called.

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

# # Array Class

If you come from a background in other high-level programming languages, like `JavaScript`, you may notice that there are functions like `Array.prototype.sort()` that are class prototypal inherited functions. In C++ terms, you may say that they are **member functions attached to the class called on array objects**. In C++, you can create a similar type of class and attach methods to this class. This `Array` class will be more helpful when you are dealing with projects that have an `Array data structure`.

## Fixed points in Array class

1. Every Constructor has its own allocted heap memory of size `X`
2. Destrutor always delete the heap allocated memory
3. Always overload Assignment Operator and deallocate the previous memory and reallocate with new memory
4. Overload subscript operator `[]` for the `l-value_r-value` and `const-r-value` to get more abstraction

> Every Array class has these prequisite, then attach the other member functions that are necessary for your project.

### Making Array Class constructors

1.  Every Constructor has ist own allocted heap memory of size `X`

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/array_3.png" style="height: 70vh; padding-left: 0vh;">
 </p>
2. Destrutor always delete the heap allocated memory

 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/array_2.png" style="height: 30vh; padding-left: 0vh;">
 </p>

3. When overloading the assignment operator, it is essential to always write it in such a way that it deallocates the previous memory and reallocates with new memory. The most important point to understand is that, in the assignment `operator`, firstly we check if there is no self-assignment `&obj!=this`, then there is a chance that the left-hand object has a size different from the size of the right-hand object. If we copy them, then `array index out of bounds` issues will be created. To resolve these problems, we can `delete` the left-hand memory equal to its size to the right-hand object size, then copy them.

 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/array_4.png" style="height: 50vh; padding-left: 0vh;">
 </p>

4.  Overload subscript operator `[]` for the `l-value_r-value` and `const-r-value` to get more abstraction
    suppose we hava an array of `size=5` in main we are accesing the array element be like `arr[8]` then what do we get? We are actually accessing the memory position of 4\*3 bytes index out of bound. We may get some garbage collection here. To restrict the user and resolve this problem we will apply the check `if(index>=0 && index<size)` else get the some alert result.
    There is another interesting fact here that when we are re-assigning the array element with new element in short terms over-writing the variable, then we will return the reference alias `int &` of the original array element to overrite the image of that index value.

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/array_5.png" style="height: 80vh; padding-left: 0vh;">
 </p>

## `Default` Array class blueprint

```cpp
#include <iostream>

using namespace std;

class Array
{
private:
    int *arr;
    int size;

public:
    Array()
    {
        size = 1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const int &size) : size{size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    // PARAMETERIZED_CONSTRUCTOR
    Array(const int &size, const int _arr[]) : size{size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = _arr[i];
        }
    }
    // COPY_CONSTRUCTOR
    Array(const Array &obj) : size{obj.size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    // OVERLOADED_ASSIGNMENT OPERATOR
    Array operator=(const Array &obj)
    {
        if (&obj != this)
        {
            size = obj.size;
            delete[] arr;
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    // OVERLOADED _SUBSCRIPT OPERATOR(For the R-value)
    int operator[](const int &index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        cout << "Array Index is Out-of-Bound" << endl;

        exit(0);
    }
    // OVERLOADED _SUBSCRIPT OPERATOR(For the L-value and R-value)
    int &operator[](const int &index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        cout << "Array Index is Out-of-Bound" << endl;

        exit(0);
    }

    void putData()
    {
        cout << "Put the data in the all array elements of size " << size << ": \n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void getData()
    {
        cout << "The data in the all array elements of size " << size << ": \n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\n";
        }
    }
    ~Array()
    {
        delete[] arr;
    }
};
int main()
{
    int a[5] = {5, 4, 3, 2, 1};

    Array obj1, obj2(7), obj3(5, a), obj4(obj3);
    const Array objc(5, a);

    obj4[3] = 9;

    cout << obj4[3] << endl;

    cout << objc[4] << endl;
    return 0;
}
```
