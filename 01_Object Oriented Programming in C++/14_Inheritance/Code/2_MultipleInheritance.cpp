// MULTIPLE INHERITANCE
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

class B
{
    int b;

public:
    B()
    {
        b = 0;
        cout << "Default constructor of B:\n";
    }
    B(int b) : b(b)
    {
        cout << "Parameterized construor of B\n";
    }
    B(const B &obj) : b(obj.b)
    {
        cout << "Copy constructor of B:\n";
    }
    void setB(int b)
    {
        this->b = b;
    }
    int getB()
    {
        return b;
    }
    void print()
    {
        cout << "B = " << b << "\n";
    }

    ~B() { cout << "Destructor of B\n"; }
};

class C : public A, public B
{
    int c;

public:
    C() : B(), A()
    {
        c=0;
        cout << "Default constructor of C:\n";
    }
    C(int a, int b, int c) : B(b), A(a),c(c)
    {
        cout << "Parameterized construor of C\n";
    }
    C(const C &obj) : A(obj), B(obj),c(obj.c)
    {
        cout << "Copy construtor of C\n";
    }
    void setC(int a, int b, int c)
    {
        A::setA(a);
        B::setB(b);
        this->c = c;
    }
    int getC()
    {
        return c;
    }
    void print()
    {
        A::print();
        B::print();
        cout << "C = " << c << "\n";
    }
    ~C() { cout << "Destructor of C\n"; }
};

int main()
{
   C objC(1,2,3);
   C objCopy(objC);
   objC.print();
   objCopy.print();

    return 0;
}