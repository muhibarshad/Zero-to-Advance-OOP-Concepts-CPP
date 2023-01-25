# Binary Operators

> Member function, needs one argument right operand can be class object or other datatype.

- Left operand must be class object
- When we do not update the L.H.S Object then use the `const` function.
- Also When we don't update the R.H.S Object then we pass the R.H.S object as refernce and to save memory use the `alias(refernce)` of it.
  Be like ,

```cpp
algebra operator +(const algebra& obj) const{
    //function_body
}
```

- All operators can be overloaded through member functions in which left operand is class object.\
  for example:\

```cpp
algebra p1, p2(2, 3);
p1 + p2; //both are class objects of Point class
p1++;
p1 = p2;
//left operand is class object member function will work
p1 + 3;
```

#### Binary Operator Addition (+)

- Both operands are class objects.
- Member function takes right operand of
  operation as one argument.
- Called on left operand must be class object.

##### Syntax:

 <p align="center">
    <img src="/04_Material/CodeSnaps/additionOperator-2.png" style="height: 50vh; padding-left: 50vh;">
 </p>

- Can be called in both ways.

```cpp
int main()
{
    algebra obj1(2,2);
    algebra obj2(3,3);
    obj1.operator+(obj2);
    obj1+obj2;
    algebra obj3=obj1+obj2;
}
```

### Note:

Now the other `Arithematic Operators like -,*,/ ,%` can overloaded in the same way sa above.

### Arirthematic Assignment Operator +=

The simple addition (+=) is like :\
obj1 += obj2;\
We will follow the original definition of the += operator. Here, the += operator adds obj1 and obj2 and returns a current object, which is again stored in obj1 or we can say that the value of obj1 will be updated. The operands on the left, i.e obj2, remain unchanged after the execution of the statement, and the results are stored in obj1, not as a new object, but only the current (previous, called) object is updated.

### Syntax:

 <p align="center">
    <img src="/04_Material/CodeSnaps/arithematicAssignment.png" style="height: 50vh; padding-left: 50vh;">
 </p>

#### Relating + and += :😢

Now, we are trying to relate + and += operators to
make our program more simple( or more complex for some reason
).\
If we focus on the above two chunks of code for the + and += operators, we can see that actually we are doing exactly the same thing in both of the programs.\
The only difference is the object which is to be updated or the object in which the result of addition is stored. In the first case i.e +, we created a new object and updated that object. While in the other case, we changed the current object, and stored the results into it.\
Now consider an example of simple numbers instead of the objects of class.\
`R = obj1 + obj2`; // `R` is the object where result is to be stored and `obj1`
and `obj2 `should remain unchanged.\
One method to do this is by simply adding `obj1` and `obj2` and storing it into `R`.\
But, if we have an option of `+=` then we have follow another method to do the same thing.
First simply let:😎\
`R = obj1`;\
We Stored `obj1` into `R` OR in
programming context made `obj1` copy of a into `R`\
Now, all we need to do is :\
`R = R + obj2;` //Adding R (which is a copy of obj1) into obj2 and storing result into R
Or isn’t it simply :\
`R += B;`Hopefully, we gathered the idea that how `+ and +=` can be used
simultaneously.\
Now, coming back to the coding portion. If we implement the same logic with the objects of the class and add them, The code will
be like this :

<p align="center">
    <img src="/04_Material/CodeSnaps/relate+and+=.png" style="height: 70vh; padding-left: 0vh;">
 </p>

#### Note :

All the other `Arithematic Assignment Operators -=,*=,/=` work in the same way.

Exmple of code is given as :

```cpp
#include <iostream>

using namespace std;

class algebra
{
private:
    int x, y;

public:
    algebra(int x = 1, int y = 1) : x(x), y(y) {}

    algebra operator+(const algebra &obj)
    {
        algebra resultant(*this);
        resultant += obj;
        return resultant;
    }
    algebra &operator+=(const algebra &obj)
    {
        x += obj.x;
        y += obj.y;
        return *this;
    }
    void getData() { cout << x << "  " << y << "\n"; }
};
int main()
{
    // Addition +
    algebra obj1(1, 1);
    algebra obj2(6, 9);
    obj1.operator+(obj2);
    obj1 + obj2;
    algebra obj3 = obj1 + obj2;
    obj3.getData(); // 7  9

    // Assignment Addition +=
    algebra obj4 = obj1 += obj2;
    obj4.getData(); // 7  9
    obj1.getData(); // 7  9
}

```

### Logical Operator ==

- Return type is always `bool`
- Both operands should be class objects.
- Member function takes right operand
  of operation as one argument.
- Called on left operand must be class
  object

#### Syntax:

<p align="center">
    <img src="/04_Material/CodeSnaps/==.png" style="height: 40vh; padding-left: 0vh;">
 </p>

### Logical Operator !=

If logical operatot `==` is defined then relate it with the `!=` as
`!(*this==obj)`

<p align="center">
    <img src="/04_Material/CodeSnaps/!=.png" style="height: 40vh; padding-left: 0vh;">
 </p>

Other Logical operators like `<=,>=,<,>` are work in the same way sa above.

**Example code is given as :**

```cpp
#include <iostream>

using namespace std;

class algebra
{
private:
    int x, y;

public:
    algebra(int x = 1, int y = 1) : x(x), y(y) {}

    bool operator==(const algebra &obj)
    {
        return (x == obj.x && y == obj.y);
    }
    bool operator!=(const algebra &obj)
    {
        return !(*this == obj);
    }
    void getData() { cout << x << "  " << y << "\n"; }
};
int main()
{
    // Addition +
    algebra obj1(2, 2);
    algebra obj2(2, 1);
    cout << (obj1 == obj2) << "\n"; // 1
    cout << (obj1 != obj2) << "\n"; // 1
}
```
