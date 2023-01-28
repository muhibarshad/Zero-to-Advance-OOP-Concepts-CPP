# Operator Overloading

**So, the first Question is what are operators?**\
In mathematics and computer programming, an operator is a symbol that represents an action. For example, the '+' symbol is an arithmetic operator that represents addition.\
**Why we need operator overloading concept?**\
The arithmetic operators (+, -, \*, /, %) are already defined for built-in data types like int, float, char, etc. But when we create our own data types, such as a class, we need to define our own operators for them.

### Defination

> Perform operations on class objects (variables of user defined ADTs) as performed on system defined datatypes.

### Operators that can be overloaded

| +   | -    | \*   | /   | =    | ==     | >=    | <=       |
| --- | ---- | ---- | --- | ---- | ------ | ----- | -------- |
| >   | <    | +=   | -=  | \*=  | /=     | &     | \|       |
| %   | ^    | !    | %=  | ^=   | &=     | \|=   | >>       |
| <<  | <<== | >>== | &&  | \|\| | ++     | --    | ,        |
| ->  | ->\* | []   | ()  | new  | delete | new[] | delete[] |

### Operators that cannot be overloaded

| .   | .\* | ::  | ?:  | sizeof |
| --- | --- | --- | --- | ------ |

### Operators Classification

> Opertors can be classified into **two** main categeries.

1.Uniary operators\
2.Binary operators

#### Uniary Operators

- (minus)
- !
- ++ (pre and post)
- -- (pre and post)
- ~ ( bitwise not)
- & (address of)

#### Binary Operators

- Arithmetic -, +, _, /, % , +=, -=, _=, /=, %=
- Relational ==, !=, >=,<=, <, >
- Assignment =
- Logical &&, ||
- Subscript []
- Member access ->
- Stream operators can be overload for file stream or command line stream
  << (stream insertion), >> (stream extraction)
- Bitwise: &, |, >> (shift right), <<(shift left), ^ (XOR)
- Memory management: new, delete

#### Note:

> Operator as += must be overloaded explicitly because + does not overload +=

### Operators Function

The overloaded function is of two type.

1. Non-static member function of a class.
2. Non-member function.

## Basic Syntax

Operator function header contains\
1.return type\
2.`operator` reserve word\
3.operator symbol\
4.parameters list

 <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/operatorSyantx.png" style="height: 50vh; padding-left: 50vh;">
 </p>

### Before Starting : Prerequisite (Cascadding Concept)

When we learn [this](#this-pointer-or-this-keyword-in-cpp) keyword, we will discuss about the reference of current object class returning of [this](#this-pointer-or-this-keyword-in-cpp).We can use the same concept for the `operator` overloading.In opertor overloading the `Left-hand-Object` can overload the `Right-hand-object`.

```cpp
int main()
{
    algebra x,y;
    x+y;
}
```

In the above example the object `x` be overloaded and it calls the `y` object in its overloaded function as a parameter.
Now , suppose we want to add the three objects consectively.
like this

```cpp
int main()
{
    algebra x,y,z;
    x+y+z;
}
```

In this case, the `precedence` of operators comes into play. Firstly, the operator `+` can be overloaded for the objects `x` and `y` to return a new object as the result. This new object can then be overloaded with the object `z`. The returning of a new object is referred to as `cascading` of operators.

Now, we discuss another case and understand more about the `cascading`.
Suppose we want to add the `x+y` and store into `z`.Like this

```cpp
int main()
{
    algebra x,y,z;
    z=x+y;
}
```

The object `z` is of class type `algebra` and stores the result only in that class type. So, here the cascading comes, we can return the result of `x+y` in the same data type as `z`.
To summarize, when we overload a function, we can follow these instructions:

Can it just update the current object and not require to store the updated object in another object?
Like this.

```cpp
void operator --()
{
    --x;
    --y;
}
```

2.Can it update the current object and store the updated object anywhere?\
Like this,

```cpp
algebra operator --()
{
    --x;
    --y;
    return *this;
}
```

3.Can it just perform the functionality on the objects? without updating objects and returns a new resultant object and use this resultant object anywhere.
Like this,

```cpp
algebra operator +(const algebra& obj)
{
 return algebra(x+obj.x,y+obj.y);
}
```

### Note:(Better-Practice)

> "A better practice is to always make operator overloading functions that support cascading, because we don't know how the result of these operators will be used in the main program. This makes the program more generic.
