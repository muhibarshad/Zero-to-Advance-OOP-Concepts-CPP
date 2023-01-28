# Deep copy

In `Deep copy`, an object is created by copying the data of all variables and it also allocates the same size of `dynamic memory` with the same values to the new object. To perform a `Deep copy`, we need to **explicitly** define the `copy constructor` and assign **dynamic memory** as well, if required. It is also necessary to dynamically allocate memory to the variables in other `constructors` and to deallocate memory in the destructor manually using the `delete keyword`.

It has two sub - Divisions

- Deep copy in copy constructor
- Deep copy in assignmen operator

#### 1) deep copy in copy constructor

<p align = "center">
<img src = "/04_Material/CodeSnaps/deepcopy2.png" style = "height: 70vh; padding-left: 50vh;">
< / p>

#### 2) deep copy in assignment operator

<p align = "center">
<img src = "/04_Material/CodeSnaps/deepcopy3.png" style = "height: 70vh; padding-left: 50vh;">
< / p>

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

    //--------Deep copy in copy constructor-----
    fraction(const fraction& tempObj)
    {
        numerator = new int;
        *numerator = *(tempObj.numerator);
        denominator = tempObj.denominator;
    }

    // -----Deep copy in assignment opeartor--
    fraction& operator==(const fraction& obj)
    {
        delete numerator; // first has to free the address that numerator already contain to prevent memory leak
        if (this != &obj) // self assignment check
        {
            numerator = new int;
            *numerator = *(obj.numerator);
            denominator = obj.denominator;
        }
        return *this; // return current obj for cascading
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
    // ------Destructor-----------------
    ~fraction()
    {//It is neccessary to deallocate memmory manually to prevevnt memmory leak.
        delete numerator;
    }
};
int main()
{
    fraction f1;

    fraction f2(f1); // deep copy of f1 into f2

    fraction f3 = f1; // deep copy by assignment operator

    f3.setNumerator(6); //  numerator=6 ==> of f3,but it will not change the value of numerator of f1 and f2

    //<====Test cases====>
    f3.printData();
    f1.printData();
    f2.printData();
    return 0;
}

```
