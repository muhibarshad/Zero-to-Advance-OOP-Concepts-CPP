# Default Constructor

Its parameters are empty, and it can be called at the time of object creation.

### Syntax:

 <p align="center">
    <img src="/04_Material/CodeSnaps/cons-1.png" style="height: 50vh; padding-left: 50vh;">
</p>
 
 ### Example:
 ```cpp
 /*Write a C++ program how to write the default constructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;
public:
	algebra();
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
	algebra obj1;
	obj1.setData(1, 2);
	obj1.getData();
	algebra obj2;
	obj2.getData();

    return 0;

}

````