# Dynamic Objects and Access Operator

Dynamic Objects means the pointer of that objects is on the stack and the whole object is on the heap. The name of the object is actually a pointer so means whenever we use the name of the class actually we refer the address of the object on the heap. So how we can access the data members and member functions of the object ,To refer the data members and the member functions of that class , we use the **access-operator** `->` instead of `(.)` **dot operator** .The access operator make a link between the heap and and stack .

### Understand by excample:

How we make the dynamic objects of class and how to access their data members of that dynamic object🙄❓

```cpp
#include <iostream>

using namespace std;

class algebra
{
public:
    int y;
    int x;
    int add;
};

int main()
{
    //Alloacting the memory
    algebra *sum = new algebra;

    //Arrow operaters pointing the members on the heap(->)
    sum->x = 3;
    sum->y = 4;
    sum->add = sum->x + sum->y;

    //Derefernce and userd the dot opearter(.)
    cout << "The sum of " << (*sum).x << " and " << (*sum).y << " = " << (*sum).add << endl;

    //delloacting the memory
    delete sum;
    sum=nullptr;

    return 0;
}
```