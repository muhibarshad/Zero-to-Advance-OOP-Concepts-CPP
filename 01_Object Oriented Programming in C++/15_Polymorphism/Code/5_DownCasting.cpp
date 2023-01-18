#include <iostream>

using namespace std;

class A
{
    int a;

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
    B(int a = 0, int b = 0) : A(a), b(b)
    {
        cout << "Cons. of B\n";
    }
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
class C : public B
{
    int c;

public:
    C(int a = 0, int b = 0, int c = 0) : B(a, b), c(c)
    {
        cout << "Cons. of C\n";
    }
    void print() override
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
    A *ptr = new B(1, 2);
    ptr->print();

    B *ptrD = dynamic_cast<B *>(ptr);
    if (ptrD != nullptr)
        ptrD->testB();
    ptrD->print();

    delete ptr;

    return 0;
}