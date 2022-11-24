// Compile time binding
/*Base class pointer has access a memory of Derived , but calll its type only.
*/
#include <iostream>

using namespace std;

class A
{
    int x;

public:
    A()
    {
        x = 0;
        cout << "Default constructor of A:\n";
    }
    A(int x) : x(x)
    {
        cout << "Parameterized construor of A\n";
    }
    A(const A &obj) : x(obj.x)
    {
        cout << "Copy constructor of A:\n";
    }
    void setA(int x)
    {
        this->x = x;
    }
    int getA()
    {
        return x;
    }
    void print()
    {
        cout << "A = " << x << "\n";
    }
    ~A() { cout << "Destructor of A\n"; }
};

class B : public A
{
    int b;

public:
    B() : A()
    {
        b = 0;
        cout << "Default constructor of B:\n";
    }
    B(int x, int b) : A(x), b(b)
    {
        cout << "Parameterized construor of B\n";
    }
    B(const B &obj) : A(obj), b(obj.b)
    {
        cout << "Copy constructor of B:\n";
    }
    void setB(int a, int b)
    {
        this->b = b;
        A::setA(a);
    }
    int getB() const
    {
        return b;
    }
    void print()
    {
        A::print();
        cout << "B = " << b << "\n";
    }
    void funB() const
    {
        cout << "Func B "
             << "\n";
    }

    ~B() { cout << "Destructor of B\n"; }
};

class C : public B
{
    int c;

public:
    C() : B()
    {
        c = 0;
        cout << "Default constructor of C:\n";
    }
    C(int a, int b, int c) : B(a, b), c(c)
    {
        cout << "Parameterized construor of C\n";
    }
    C(const C &obj) : B(obj), c(obj.c)
    {
        cout << "Copy construtor of C\n";
    }
    void setC(int a, int b, int c)
    {
        this->c = c;
        B::setB(a, b);
    }
    int getC() const
    {
        return c;
    }
    void print()
    {
        B::print();
        cout << "C = " << c << "\n";
    }
    void print(int num)
    {
        cout << "Overloaded function in derived = " << c + num << "\n";
    }
    void funC() const
    {
        cout << "Func C "
             << "\n";
    }
    ~C() { cout << "Destructor of C\n"; }
};

int main()
{
    A *obj = new B(1, 2);
    cout << obj->getA() << "\n";
    //Base class reference can only see base class members, derived part still exist.
    // cout<<obj.funcB();//compile time error
    delete obj;
    return 0;
}