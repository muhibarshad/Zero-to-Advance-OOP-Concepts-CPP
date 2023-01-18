
//Interface
#include <iostream>

using namespace std;

class IExample
{
public:
    // Pure virtual functions
    virtual void Function1() = 0;
    virtual void Function2() = 0;
    virtual void Function3() = 0;
    virtual ~IExample();
};
class A : public IExample
{
    int a;

public:
    A(int a = 0) { this->a = a; }
    virtual void print() { cout << a; }
    virtual ~A() {}
    // Must implement all Pure virtual functions.
};
int main()
{

    return 0;
}