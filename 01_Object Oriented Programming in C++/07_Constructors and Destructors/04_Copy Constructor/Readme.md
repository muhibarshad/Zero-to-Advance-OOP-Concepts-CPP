# Copy constructor

`Copy constructors` can be used to copy one objects constructor to another object. In a `copy constructor`, the parameterized object should be called as a reference. Otherwise, it creates a problem of 'recursion'. To understand this, suppose we assign object_2 to object_1, then the `copy constructor` of object_2 should be called and it takes the object_1 as a parameter and this parameter object makes a copy of the object_1. So to make a copy of object_1 again, the 'copy-constructor' should be called again and again and this process leads to 'recursion' (infinity) and our program crashes when the stack overflows. But there is another problem here. If we pass the argumentative object as a reference, there is a dangerous chance to `mutate` the data of this object. To avoid these bugs we pass it as 'const' now it has become impossible to mutate the original object.

### Note:

> Pass the copying object as a refernce `&`.
> Pass the copying object as a constant `const`.
> It uses copy data of an object `bit-by-bit`.

### Syntax:

<p align="center">
    <img src="/04_Material/CodeSnaps/cons-3.png" style="height: 50vh; padding-left: 50vh;">
</p>
### Example:

```cpp
/*Write a C++ program how to write the copy constructor constructors*/
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
    algebra(const algebra&);
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
//copy constructor
algebra::algebra(const algebra& temp)
{
    x=temp.x;
    y=temp.y;
    cout<<"Copy constructor should be called:"<<endl;
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

    //default
	algebra obj2;
	obj2.getData();
    //parametrized
	algebra obj1(1,2);
	obj1.getData();
    //copy
    algebra obj3=obj1;
    obj3.getData();
    algebra obj4(obj2);
    obj4.getData();

    return 0;

}
```