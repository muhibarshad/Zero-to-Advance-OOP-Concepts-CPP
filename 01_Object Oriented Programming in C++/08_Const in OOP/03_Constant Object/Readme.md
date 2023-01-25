# Const Object

### Defination

> These are `objects` of a class that only allow **memory reading**. It simply means we cannot change any data member of the class, whether it's a const or non-const `data member`.

### Note

> const objects give their `refrence` to only const member functions/behaviours.

<p align="center">
    <img src="/04_Material/CodeSnaps/const_obj.png" style="height: 70vh; padding-left: 50vh;">
</p>

```cpp


#include<iostream>
using namespace std;

class Student
{
	String name;
	const int Id = 1;

public:

	//-----Getters/Accessors----

	string getName()
	{

      return name;

	}
	int getId() const
	{

      return Id;

	}


};
int main()
{

Student const Student_1;
	//getId is constant member function,Therfore const
    //obj studen_1 give its refrence
	Student_1.getId();



	//getName is not_ constant member function,Therfore const
    //obj studen_1 does not give  its refrence
   //  Error---> Student_1.getName();


}
```
