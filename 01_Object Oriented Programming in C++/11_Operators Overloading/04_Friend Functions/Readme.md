# Non-Member functions

**Why we need the non-member functions to operator overloading**?\
Because We know that the L.H.S object calls the R.H.S object . If L.H.S operand is not the object its dataType is different from the L.H.S operand than what we have to do.
Like this,

```cpp
2 + p1; // left operand is int
cout << p1; // left operand is ostream class object
cin >> p1; //left operand if istream class object
```

Therefore, Non-member functions can be used for such operations

- Non-member function cannot be defined inside the class
- They cannot access the private data members of a class
- Operators that cannot be overloaded through non-member functions are
  `=, [], (), ->, &`(address of operator)
- All other operators can be overloaded through non-member functions
- Unary operators
- Non-member function, needs one argument
- Binary operators
- Non-member function, needs two arguments
- One argument must be class object or reference
  • There is no `this` pointer in non-member functions

## Non-Member `friend` functions

`friend` function can access private and protected members of another class.\
•`friend` functions are non-member functions of class.\
•They are defined outside the class scope
Can only add prototype inside class definition for granting friendship.
•There is no `this` pointer in non-member friend functions.\
**Properties of friendship**\
• Friendship is granted, not taken\
• Not symmetric (if B a friend of A, A cannot necessarily be friend of B)\
• Not transitive (if A is friend of B, B is friend of C, A cannot necessarily be friend of C).

### Uniary Operator -

Non-member function takes one
argument that must be the class object

Can be called in two ways.

```cpp
Point p1(3, 4);
operator-(p1);
// calls friend function
Or
-p1;
Point p2 = -p1;
```

• Only add one function member or non-
member friend to avoid conflict.

<p align="center">
    <img src="/04_Material/CodeSnaps/uniaryFriend.png" style="height: 70vh; padding-left: 0vh;">
 </p>

### Binary operator Addition +

Can be overloaded as a friend in 3 ways;

- Both operands are class objects.
- One operand left one is class object.
- One operand right one is class object.

Must define non-member function.\

> Non-member function takes two arguments

<p align="center">
    <img src="/04_Material/CodeSnaps/binaryFriend.png" style="height: 70vh; padding-left: 0vh;">
 </p>
  
Example Code:
```cpp
#include <iostream>

using namespace std;

class Point
{
int x, y;
public:
Point(int x = 0, int y = 0):x(x),y(y){}
//Both are objects
friend Point operator+(const Point &p, const Point &q);
// with int right operand
friend Point operator+(const Point &p, const int &n);
// with int left operand
friend Point operator+(const int &n, const Point &p);
};
Point operator+(const int &n, const Point &p)
{
return p + n;
// Reuse code of right operand function
}
int main()
{
Point p1(3, 4);
operator+(3, p1);
10 + p1;
// both p1 and int 10 are passed argumnets
int a = 10;
Point p3 = a + p1;
// cascaded call
}

````
### Binary Operators Stream insertion (<<) and Stream extraction (>>)

- One operand left one is `stream` object and right one is class object.
- Must define non-member function, which takes two arguments
- First non constant reference of `ostream` object in case of insertion `<<` operator and `istream` object in case of extraction `>>` opeartor.
- Second const reference of class object
- For cascading return `ostream` object by reference from function.

<p align="center">
    <img src="/04_Material/CodeSnaps/stream.png" style="height: 60vh; padding-left: 0vh;">
 </p>

 **Code Example here**:
 ```cpp
 #include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    friend ostream &operator<<(ostream &, const Point &);
    friend istream &operator>>(istream &, Point &);
};

ostream &operator<<(ostream &out, const Point &p)
{
    out << "X:" << p.x << endl;
    out << "Y:" << p.y << endl;
    return out;
}
istream &operator>>(istream &in, Point &p)
{
    in >> p.x;
    in >> p.y;
    return in;
}
int main()
{
    Point p1;
    cin >> p1;  // 1,2
    cout << p1; // X:1,Y:2
}
```

# Summary of Operator Overloading

<p align="center">
    <img src="/04_Material/CodeSnaps/summary.png" style="height: 80vh; padding-left: 0vh;">
 </p>

 # Imporatnt Tip:
 ## When we are overloading normal or friend function

In most cases, the language leaves it up to you to determine whether you want to use the normal or friend member function version of the overload. However, one of the two is usually a better choice than the other.

When dealing with binary operators that don’t modify the left operand (e.g. operator+), the normal or friend function version is typically preferred, because it works for all parameter types, even when the left operand isn’t a class object, or is a class that is not modifiable. The normal or friend function version has the added benefit of `“symmetry”`, as all operands become explicit parameters (instead of the left operand becoming `*this` and the right operand becoming an explicit parameter).

When dealing with binary operators that do modify the left operand (e.g. operator+=), the member function version is typically preferred. In these cases, the leftmost operand will always be a class type, and having the object being modified become the one pointed to by `*this` is natural. Because the rightmost operand becomes an explicit parameter, there’s no confusion over who is getting modified and who is getting evaluated.

Unary operators are usually overloaded as member functions as well, since the member version has no parameters.

The following rules of thumb can help you determine which form is best for a given situation:

- If you’re overloading assignment `(=), subscript ([]), function call (())`, or member selection (->), do so as a member function.
- If you’re overloading a unary operator, do so as a member function.
- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function.
- If you’re overloading a binary operator that modifies its left operand, but you can’t add members to the class definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function.
- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function.
````
