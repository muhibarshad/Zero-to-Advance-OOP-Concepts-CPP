# Static Data member

### Defination

> Static data members in `classes` actually belong to the respective class, not to the object. This means they function like `global variables` for the `class` and its `objects`.

#### Declaration and defination of static Data member

- static members are declared _inside_ the `Class`
- static members are defined _outside_ the `Class`

##### Reason of Defining outside the class 😉

> It makes sense because static data members belong to the class and its memory is allocated only once. Imagine if it were defined inside the class, memory would be allocated every time an object of the class is created, which is not allowed.

<p align="center">
    <img src="/04_Material/CodeSnaps/staticdatamember.png" style="height: 70vh; padding-left: 50vh;">
</p>

##### Best Practice 👀

> It is best practice to access `static data members` by the **class name** with the scope `resolution (::) operator` rather than by accessing the object with the `memory access/dot operator (.)` .

<p align="center">
    <img src="/04_Material/CodeSnaps/staticdatamember_define.png" style="height: 70vh; padding-left: 50vh;">
</p>

##### Tips 😎

<p align="center">
    <img src="/04_Material/CodeSnaps/staticdatamember_const.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example code

```cpp
#include<iostream>
using namespace std;

class Circle
{
	int radius;
	static const float Pi;

public:
	//------Mutator/setter-------------
	void setRadius(int radius)
	{
		this->radius = radius;
	}

	//-----Getter/Accessor--------------
	int getRadius() const
	{
		return radius;
	}


	//-----member function-----------
	double calculateArea()
	{
		return Pi * (radius * radius);
	}



};

int main()
{
	Circle circle_1;
	circle_1.setRadius(5);

	cout << circle_1.calculateArea();
}
```
