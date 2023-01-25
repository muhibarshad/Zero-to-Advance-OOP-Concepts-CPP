# Const in oop

## Const Data Members

### Defination

> The `data members`,state or properties whose value can not be changed during execution time and require value at time upon intialization .

### Note

> You can not leave const memmber uninitialized,otherwise it will cause error!

### Ways to declare and initialize

1.  Initializing at the time of declaration. But keep in mind that some compilers do not allow initialization of 'const' in this way.

 <p align="center">
    <img src="/04_Material/CodeSnaps/constdatamember.png" style="height: 70vh; padding-left: 50vh;">
 </p>

2)Initializing in `Initializer list` of `constructors`

 <p align="center">
    <img src="/04_Material/CodeSnaps/connst_In_initializerlist.png" style="height: 70vh; padding-left: 50vh;">
</p>

### Example Code

```cpp
#include<iostream>
using namespace std;

class Student
{
	String name;

	// 1) initializing const member at time of creation
	const int Id=1;
	const double CNIC;

public:
	// 2)initializing const member in member initialization list
	Student():CNIC(123-456789-123) {}

};
```
