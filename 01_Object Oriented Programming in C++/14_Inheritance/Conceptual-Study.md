# Inheritance

## what is Inheritance?

In C++, `inheritance` allows a new class `(derived class)` to inherit properties and methods of an existing class `(base class)`. This enables code reuse and `abstraction`, making it useful for creating complex systems. The `derived class` can access and use the properties and methods of the base class as if they were its own.

// inheritance 1(photo)

## why wee need it👀?

- `Inheritance` in C++ allows for code reuse, `abstraction`, `polymorphism`, `better organization`, and **improved readability** and **maintainability**.
- It allows derived classes to use existing code from the base class, group related `classes` together, and define a clear hierarchy.
- This leads to a more understandable and manageable overall program structure.

## Inheritance with different Access-Specifier

### 1- Public

In `public inheritance`e, the `public members` of the `base` `class` are `inherited` as `public` in the derived class. Private members are `inherited` as `private` and can only be accessed through `getter` and `setter` methods. Protected members are `inherited` as `protected` and can be accessed directly by the `derived class`.

### 2- Protected

In `protected inheritance`, `public members` of the base class become protected in the derived class, private members remain private and can only be accessed via getters/setters, and `protected` members are inherited as `protected` and can be accessed directly by the derived class.

### 3- private

In `private inheritance`, public and protected members of the `base class` become `private` in the derived class, and can only be accessed via `getters/setters`.

## Important Note

Members that are not `inherited` from a base class include `constructors`, `destructor`, `assignment operator` and `non-member functions`. Derived class constructors, destructor and assignment operators can call the base class's respective functions.

## Example code

```cpp
#include<iostream>
using namespace std;
class A{
int a;
public:
A(int a=0){ this->a=a;}
void print(){ cout<<a;}
};
//This is the base class A with a private member variable 'a' and a public function 'print' which outputs the value of 'a'. The constructor takes an optional parameter with a default value of 0, which initializes the value of 'a'.

class B: A{
int b;
public:
B(int b=0){ this->b = b;}
};
//This is the derived class B which inherits from class A using private inheritance. It has its own private member variable 'b' and a constructor that takes an optional parameter with a default value of 0, which initializes the value of 'b'. Since class B inherits from class A with private inheritance, the 'print' function from class A is private in class B and cannot be accessed from an object of class B outside the class.

class C: protected B{
int c;
public:
C(int c=0){ this->c = c;}
};
//This is the derived class C which inherits from class B using protected inheritance. It has its own private member variable 'c' and a constructor that takes an optional parameter with a default value of 0, which initializes the value of 'c'. Since class C inherits from class B with protected inheritance, the 'print' function from class A is inherited as private in class C and cannot be accessed from an object of class C outside the class.

void main(){
A a1;
a1.print();
//print is public in a
B b1;
b1.print();
//print is now private in b cannot be
//accessed from object of class B outside
C c1;
c1.print();
//print is inherited as private and
//cannot be accessed from object of class
//C outside
}


```

## Constructors/Destructors In Inheritance

- Chain of constructor calls: When a derived class object is created, the derived class constructor calls the base class constructor.
- The base class constructor can be invoked implicitly by the system's default constructor or explicitly by the programmer using a parametrized or copy constructor.
- The base class constructor at the top of the inheritance hierarchy is the last constructor called in the chain and the first constructor body to finish executing.
- Each base class constructor initializes its own data members which are inherited by the derived class

### Default constructor

//Inheritance-2(photo)

### parametrize constructor constructor

//Inheritance-3(photo)

### Copy constructor

//Inheritance-4(photo)

### calling Sequence

//Inheritance-5(photo)
