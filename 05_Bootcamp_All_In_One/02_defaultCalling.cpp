#include <iostream>

using namespace std;

class A
{

public:
    int x;
    A()
    {
        cout << "Default Cons of A :\n";
    }
    A(int x) : x(x)
    {
        cout << "Para Cons of A :\n";
    }
    A(const A &obj) : x(obj.x)
    {
    }
    ~A()
    {
        cout << "Des of A \n";
    }
    void print()
    {
        cout << "The value of x  = " << x << endl;
    }
};
class B : private A
{
    int y;

public:
    B() : A()
    {
        cout << "Default Cons of B :\n";
    }
    B(int x, int y) : A(x), y(y)
    {
        cout << "Para Cons of B :\n";
    }
    B(const B &obj) : A(obj), y(y)
    {
    }
    void print()
    {
        A::print();
        cout << "The value of y  = " << y << endl;
    }
    ~B()
    {
        cout << "Des of B \n";
    }
};
int main()
{
    B b(2, 3);
    B c(2, 3);
    return 0;
}