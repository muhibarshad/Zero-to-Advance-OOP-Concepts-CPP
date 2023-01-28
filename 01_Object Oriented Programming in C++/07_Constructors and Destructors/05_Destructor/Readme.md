# Destructors:

### Defination:

> To destroy the object and free the memory, destructors use the same syntax as constructors. Destructors cannot be overloaded since it only destroys the object and no parameters are required. It destroys every object when the main function is executed, and executes when the object goes out of scope. Just use the `tilde (~)` sign with the destructor to distinguish it from the default constructor and the destructor.

### Synatx:

   <p align="center">
    <img src="/04_Material/CodeSnaps/des.png" style="height: 50vh; padding-left: 50vh;">
</p>

### Example:

```cpp
/*Write a C++ program how to write the destructors*/
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
    ~algebra();
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
//destructor
algebra::~algebra()
{
    cout<<"Destructor should be called"<<endl;
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
