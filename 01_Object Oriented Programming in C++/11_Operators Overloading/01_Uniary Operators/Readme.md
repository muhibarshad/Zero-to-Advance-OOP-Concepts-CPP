# Non-Static Member Functions

# Uniary Operators

Member function takes no argument work on single operand must be the class object.

#### - (in-uinary)

Converting object to their negative form.

 <p align="center">
    <img src="/04_Material/CodeSnaps/uniaryNon-static.png" style="height: 70vh; padding-left: 50vh;">
 </p>

#### Pre increment --

Pre-increment operator (++), increments the object by 1 first. In cascading, we have two options: we can return the updated object or just return the non-updated object. The best practice here is to return the non-updated object because we may use this object without incrementing it elsewhere..

 <p align="center">
    <img src="/04_Material/CodeSnaps/preIncrement.png" style="height: 50vh; padding-left: 50vh;">
 </p>

#### Post increment --

Post-increment operator (++), same as to increment the object by 1 after. The cascading strategy is the same as above for [pre-increment](#pre-increment). To distinguish between post and pre, in post we use 'int' as a parameter in the parameter list. That's easy.

 <p align="center">
    <img src="/04_Material/CodeSnaps/postIncrement-2.png" style="height: 50vh; padding-left: 50vh;">
 </p>

##### Now Understand by example:

```cpp
#include <iostream>

using namespace std;

class algebra
{
private:
    int x, y;

public:
    algebra(int x = 1, int y = 1) : x(x), y(y) {}
    // Pre increment Operator
    algebra operator--()
    {
        algebra temp(*this);
        --x;
        --y;
        return temp;
    }
    // Post increment Operator
    algebra& operator--(int)
    {
        x--;
        y--;
        return *this;
    }
    void getData() { cout << x << "  " << y << "\n"; }
};
int main()
{
    algebra obj(2, 2);
    algebra preMinus_Obj = --obj;
    algebra postMinus_Obj = obj--;
    preMinus_Obj.getData(); // 1    1
    postMinus_Obj.getData(); // 0    0
}
```

**Why we use the `&` sign with returing objects ? and When to use it ?**\
This is a very interesting question which may confuse beginners very well.Now understand firstly **why we need `&`and use it**? When we update the current object and return the current object completely by using `return *this`\
Like this,

```cpp
algebra operator-()
{
    x=-x;
    y=-y;
    return *this;
}
```

This means that we are returning the value of the current object completely to algebra and the compiler at that time makes a copy of this `*this` and stores it into `algebra` anonymously, and then assigns it to cascading. So at that time, the `copy constructor` is called, and its `destructor` should also be called. This means our memory is wasted for some period of time. It's not a better way. We can use the `*this` reference instead of copying to anonymous. So that's why we use the `&` sign with the return type to avoid the anonymous `constructors` and `destructors` calling and make our memory and program more efficient.
Now, our next question is **When to use `&`**? The answer to this question is very simple, when we are updating the current object and returning the current object for cascading, then use it.

### Note:(Avoid)

Never use `&` sign when you are returing the non-current class object.Because it gets the address of that object made inside the class and when the function destroys this local object varaible, it also destroys it from the execuation stack. And now you have a refernce of a such object varaiable whose doesn't exist, `resulting in an error`.
