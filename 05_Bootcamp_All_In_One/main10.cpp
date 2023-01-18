#include <iostream>

using namespace std;
class A
{
    int x;

public:
    A(int x = 0) : x(x)
    {
        cout << "Cons of A\n";
    }
    void doSomethingA()
    {
        // ...
    }
    ~A()
    {
        cout << "Des of A\n";
    }
};

class B : public virtual A
{
    int y;

public:
    B(int x = 0, int y = 0) : A(x), y(y)
    {
        cout << "Cons of B\n";
    }
    void doSomethingB()
    {
        // ...
    }
    ~B()
    {
        cout << "Des of B\n";
    }
};

class C : virtual public A
{
    int z;

public:
    C(int x = 0, int z = 0) : A(x), z(z)
    {
        cout << "Cons of C\n";
    }
    void doSomethingC()
    {
        // ...
    }
    ~C()
    {
        cout << "Des of C\n";
    }
};

class D : public B, public C
{
    int q;

public:
    D(int x = 0, int y = 0, int z = 0, int q = 0) : B(x, y), C(x, z), q(q)
    {
        cout << "Cons of D\n";
    }
    void doSomethingD()
    {
        // ...
    }
    ~D()
    {
        cout << "Des of D\n";
    }
};

int main()
{
   {
     D obj(1, 2, 3, 4);
   }

    return 0;
}