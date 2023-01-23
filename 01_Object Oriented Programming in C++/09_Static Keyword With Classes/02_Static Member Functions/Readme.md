# Static Member Function

## Defination

> `Static member functions` can be used with `static member` variables in the **class**. An **object** of the class is not required to call them.

### Interesting Facts about Static functions ✔

- The `this` pointer does not exist in static member functions because the `this pointer` belongs to the object, whereas static member functions belong to the **class**, not to the object. In static behavior, we can also call other `static data members` and `static functions`. `Static member functions` cannot be **constant**.

### Tip 👀

> You can call a `static function` by the **object name** with the `memory access operator (.)`, but it is not considered good programming practice. It is better to access the `static member function` of a class by the **class** name with the `scope resolution operator (::)`.
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
        // Here,you can't access any data member and member function directly except static data member and other static function
        //  like
        // radius=6;  -->error
        //  setRadius(5);   -->error

        return Pi;
    }
};

int main()
{ // Accessing static data member of class through static function with class name and scope resolution operator
    cout << Circle::getPi();
}


```