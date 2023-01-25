# Member Functions

You are already aware that we previously discussed member functions. But what exactly are they? Member functions are functions that are associated with a specific class and operate on the data members of that class. :

- [Getters](/01_Object%20Oriented%20Programming%20in%20C%2B%2B/04_Settters%20and%20Getters/Readme.md)
- [Setters]()
- [Mutators](#setters)
- [Accessers](#getters)
- [Functionaliters](#functionaliters)
- [Constructors](#constructors-and-destructors)
- [Destructors](#constructors-and-destructors)
- [Iterators](#setters)
- [Operators](#operator-overloading)\
  In all of the above, we have discussed the use of `getters` and `setters`. `Mutators` and `Accessors` are similar to `getters` and `setters` because using the `setters` we can have full access to the data members of the class to change them directly, and the same applies to `getters` for directly accessing and retrieving them.
Now, we will discuss about "Functionalities" (It may not make sense, but it is a straightforward concept to understand). Other topics will be discussed in the coming points..

## Functionaliters :

>Functions that perform specific operations on the data and provide some outcome are known asfunctionalities. >These functions can perform mathematical and other operations on the data members and return results or assist other functions in performing their intended tasks.

### Let understand by example 🙂 :

[Write a C++ program in to find distance between two points and take third point and find from where the distance from third point is closest](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/11_MemberFunctions.cpp)

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
