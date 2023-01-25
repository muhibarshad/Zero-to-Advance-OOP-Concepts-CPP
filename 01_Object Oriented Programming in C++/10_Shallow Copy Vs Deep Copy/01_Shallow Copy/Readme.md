# shallow vs deep copy

As we have studied earlier, the C++ compiler provides a default copy constructor and assignment operator. Until now, we have been dealing with data members which were simple variables, but what happens when we deal with pointer or reference variables? Think about it🤔.

## shallow copy

> Because C++ does not have detailed information about your class, the default copy constructor and `default assignment operators` it provides use a copying method known as a **memberwise copy** (also known as a `shallow copy`).

<p align="center">
    <img src="/04_Material/CodeSnaps/shallowcopy1.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example code

```cpp
#include <iostream>
    using namespace std;
class fraction
{
    int numerator;
    int denominator;

public:
    //---------Default  constructor-----------
    fraction() : numerator(1), denominator(2) {}

    void printData() const
    {
        cout << "Rational number is: " << numerator << "/" << denominator << endl;
    }
};
int main()
{
    fraction f1;

    fraction f2(f1); // memberwise copying of f1 into f2 by default copy constructor that compiler provides.

    fraction f3 = f1; // memberwise copying of f1 into f3 by default copy assignment operator
    return 0;
}

```

### What's the problem with shallow copy ? 😒

shallow copying by default copy constructor or by copying assignment operator works fine until tha class data members have dynamic memory allocation.let understand this by code.

### code example

```cpp
#include <iostream>
using namespace std;
class fraction
{
    int* numerator;
    int denominator;

public:
    //---------Default  constructor-----------
    fraction()
    {
        numerator = new int(1);
        denominator = 2;
    }
    //---------setter------------------------
    void setNumerator(int n)
    {
        *numerator = n;
    }

    void printData() const
    {
        cout << "Rational number is: " << *numerator << "/" << denominator << endl;
    }
};
int main()
{
    fraction f1;

    fraction f2(f1); // memberwise copying of f1 into f2 by default copy constructor that compiler provides.

    fraction f3 = f1; // memberwise copying of f1 into f3t by default copy assignment operator

    f3.setNumerator(6); //  numerator=6 ==> of f3,but it will also change the value of numerator of f1 and f2

    //==> Reason: because shallow copy does memberwise copy and in class we have dynamic memmry allocation for numerator,
    // so when f2,f3 are created by default copy constructor ,their data member numerator copies the address of numerator of
    // f1,so as a result numerator of all objects are pointing by same memory address and changing in one will reflect in all.

    f3.printData(); //nemerator=6
    f1.printData(); //numerator=6
    f2.printData(); //numerartor=6
    return 0;

}

```

### so what's the solution when we have dynamic memory alloaction😉 ?

> Here, the concept of `deep copy` comes into play. Whenever we have to do `dynamic memory allocation` with **class data members**, we have to use deep `copy rather` than `shallow copy`.
