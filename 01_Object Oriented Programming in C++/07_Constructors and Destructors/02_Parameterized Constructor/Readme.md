# Paramterized Constructor:

Constructors are `overloaded` like `function-overloading`. When there are more than one constructors in a class having different number of parameters, they are called overloaded or parameterized constructors.

### VIP Note:

> When we call a constructor on an object, only that one constructor is called and the rest of the constructors remain unused.

### Syntax:

<p align="center">
    <img src="/04_Material/CodeSnaps/cons-2.png" style="height: 50vh; padding-left: 50vh;">
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
```
