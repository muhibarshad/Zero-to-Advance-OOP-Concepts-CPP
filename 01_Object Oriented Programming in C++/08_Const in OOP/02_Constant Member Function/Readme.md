# Const Member functions

### Defination

> Tese are `member functions` of class which allow only _memory reading_.It simply means we can not change any `data member` of class either const or non-const `data member` in Const member functions.The can be accessed by both `const object` and `non-const object`.

### Note

> `constructors` are also _special member functions_ of class but it is not allowed to make constructors const functions.

<p align="center">
    <img src="/04_Material/CodeSnaps/const_functionn.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example code

```cpp

#include<iostream>
using namespace std;

class Student
{
	String name;
	const int Id = 1;

public:

	//-----Getters/Accessors----
	string getName() const
	{
		//Here if you try to modify data member name,it will cause error although it is non-const
		// like:
		// name="Waleed";
      return name;

	}
	int getId() const
	{
		//Here if you try to modify data member Id,it will cause error
		// like:
		// Id=9;
      return Id;

	}

};
int main()
{
	Student student_1;
	Student const  student_2;

	//Accessing constant function by Non const-object
	student_1.getId();

	//Accessing constant function by const-object
	student_2.getId();

}

```