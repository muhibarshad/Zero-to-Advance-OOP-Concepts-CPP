#include <iostream>

using namespace std;

class A
{
    int a;

protected:
    int hide;

public:
    A(int a = 0) : a(a)
    {
        cout << "Cons. of A\n";
    }
    virtual void print()
    {
        cout << "A = " << a << "\n";
    }
    virtual ~A()
    {
        cout << "Des. of A\n";
    }
};
class B : public A
{
    int b;

public:
    using A::hide;
    B(int a = 0, int b = 0) : A(a), b(b)
    {
        cout << "Cons. of B\n";
    }
    // int print() override
    //// Error:return type is not identical to nor covariant with return type "void" of overridden virtual function "A::print"
    void print() override
    {
        A::print();
        cout << "B = " << b << "\n";
    }
    void testB()
    {
        cout << "Dynamic B test completed\n";
    }
    ~B()
    {
        cout << "Des. of B\n";
    }
};
class C final : public B
{
    int c;

public:
    C(int a = 0, int b = 0, int c = 0) : B(a, b), c(c)
    {
        cout << "Cons. of C\n";
    }
    void print() override final
    {
        B::print();
        cout << "C = " << c << "\n";
    }
    void testC()
    {
        cout << "Dynamic C test completed\n";
    }
    ~C()
    {
        cout << "Des. of C\n";
    }
};
int main()
{

    return 0;
}