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
        cout << "Copy Cons of A \n";
    }
    A &operator=(const A &obj)
    {
        x = obj.x;
        return *this;
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
class B
{
    int y;

public:
    B()
    {
        cout << "Default Cons of B :\n";
    }
    B(int y) : y(y)
    {
        cout << "Para Cons of B :\n";
    }
    B(const B &obj) : y(obj.y)
    {
        cout << "Copy cons of B:\n";
    }
    B &operator=(const B &obj)
    {
        y = obj.y;
        return *this;
    }
    void print()
    {
        cout << "The value of y  = " << y << endl;
    }
    ~B()
    {
        cout << "Des of B \n";
    }
};
class C : public B, public A
{
    int z;

public:
    C(int x = 0, int y = 0, int z = 0) : A(x), B(y), z(z)
    {
        cout << "Cons of C\n";
    }
    C(const C &obj) : z(obj.z), A(obj), B(obj)
    {
        cout << "Copy cons of C:\n";
    }
    C &operator=(const C &obj)
    {
        z = obj.z;
        A::operator=(obj);
        B::operator=(obj);
        return *this;
    }
    void print()
    {
        A::print();
        B::print();
        cout << "The value of z = " << z << "\n";
    }
    ~C()
    {
        cout << "Des of C:\n";
    }
};
int main()
{
    C c(1, 2, 3);
    C c1(4, 5, 6);
    c = c1;
    c.print();
    c1.print();

    return 0;
}