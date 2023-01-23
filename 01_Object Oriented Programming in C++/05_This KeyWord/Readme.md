# This Pointer or This KeyWord in Cpp

n C++, '**this'** is a pointer that refers to the instance of the class. A single copy of this pointer is maintained at the class level and is only accessible in member functions. '**This'** pointer has two main functionalities:

1.When naming local variables within member functions of a class, it's important to ensure that the variable names do not conflict with the names of the class`data members`.

<p align="center">
<img src="/Some%20extra%20concepts/codeSnaps/this1.png" style="height: 50vh; padding-left: 50vh;">

 </p>
 
2.Returning the entire object from a member function is useful for function chaining, where the function call updates the previous function's value and returns a reference to the object. This allows for multiple function calls to be chained together and executed in a single statement.
<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/this2.png" style="height: 70vh; padding-left: 50vh;">
 </p>
 
  ### Lets now understand by example 😍:
  [What is a this key Word in C++? Write a C++ program in which the setter function parameter name is same as the class data member name.What is the *this Pointer* in the C++ 😧?](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/9_thisPointer.cpp)

```cpp
#include<iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
public:
    //setters
    void setX(int x)
    {
       this->x=x;
    }
    void setY(int y)
    {
        this->y=y;
    }
    void setData(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    //getters
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
    }

    //member functions
    algebra &value(int x)
    {
        this->x=x;
        return *this;
    }
    algebra &incrementValue(int y)
    {
        this->x++;
        this->y=y;
        return *this;
    }

};

int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.setData(1,2);
    obj2->setData(3,4);

    obj1.getData();
    obj2->getData();

    obj1.value(100).incrementValue(200);
    obj1.getData();//101,200--->chaining is sequential and the changes made to the object’s data members retains for further chaining calls.

    // obj1.setX(90).setY(900);// error: invalid use of 'void'


    return 0;
}
```

# Scope Resolution operator

## Defination:

> The scope resolution operator (::) is used to specify the scope of an item, such as a variable or function. It can be used to access global variables with the same name, access class member functions from outside the class, and in namespaces and inheritance. It allows to specify the context in which an identifier is defined.

Having a class with more than 1000 member functions can make the class size unwieldy and difficult to understand. Additionally, when sharing the class with a colleague, it may be overwhelming to try and navigate through all of the functionality offered by the class. To address these issues, one solution is to use function prototypes inside the class, and implement the functions outside the class. This allows for clear visibility of the class' functionalities without cluttering the class with implementation details.

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/s-1.png" style="height: 70vh; padding-left: 50vh;">
 </p>

But the error should become :

```diff
- error: invalid use of 'this' in non-member function void setX(int x) { this->x = x; }
```

Data members and function members of a class can be designated as public, private, or protected, determining the accessibility of these members. To indicate that a function is a member function of a specific class, the class name is typically included as a prefix to the function name.

How to resolve this error :

```diff
+ Use the Scope resolutioon opertor `::`  with the name of the class
```

_Means that this function has scope to that class_

<p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/s-2.png" style="height: 50vh; padding-left: 50vh;">
</p>

### Understand by complete [Scope-Resolution(::) Example](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/10_scopeResolutionOperter.cpp) 😎:

```cpp
#include <iostream>

using namespace std;

class algebra
{
private:
   int x;
   int y;

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

   // memberFunctions are here
   //.........
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

int main()
{
   algebra obj1;
   obj1.setData(1, 2);
   obj1.getData();

   algebra obj2;
   obj2.setAlgebra(obj1);
   obj2.getData();

   obj1.getAlgebra().setX(8);
   obj1.getData();

   return 0;
}
```
