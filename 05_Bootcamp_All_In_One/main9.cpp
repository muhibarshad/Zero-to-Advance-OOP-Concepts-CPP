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
    A(const A &obj) : x(obj.x)
    {
        cout << "Copy cons of A:\n";
    }
    A &operator=(const A &obj)
    {
        x = obj.x;
        return *this;
    }
    // void print()
    virtual void print()
    {
        cout << "The value of x = " << x << "\n";
    }
    void secret()
    {
        cout << "This function to test the using keyword:\n";
    }
    virtual void func() = 0;
    virtual ~A()
    {
        cout << "Des of A:\n";
    }
};
class B : public A
{
    int y;

protected:
    using A::secret;

public:
    B(int x = 0, int y = 0) : A(x), y(y)
    {
        cout << "Cons of B\n";
    }
    B(const B &obj) : A(obj), y(obj.y)
    {
        cout << "Copy cons of B:\n";
    }
    B &operator=(const B &obj)
    {
        y = obj.y;
        A::operator=(obj);
        return *this;
    }
    void print() override
    {
        A::print();
        cout << "The value of y = " << y << "\n";
    }
    void func()
    {
        cout << "Pure Virtual of B\n";
    }
    ~B()
    {
        cout << "Des of B:\n";
    }
};
class C : public B
{
    int z;

public:
    C(int x = 0, int y = 0, int z = 0) : B(x, y), z(z)
    {
        cout << "Cons of C\n";
    }
    C(const C &obj) : B(obj), z(obj.z)
    {
        cout << "Copy cons of C:\n";
    }
    C &operator=(const C &obj)
    {
        z = obj.z;
        B::operator=(obj);
        return *this;
    }
    void print() override final
    {
        B::print();
        cout << "The value of z = " << z << "\n";
    }
    void func()
    {
        cout << "Pure Virtual of C\n";
    }
    ~C()
    {
        cout << "Des of C:\n";
    }
};
int main()
{
    // A obj(1);
    A *ptr = new C(1, 2, 3);
    ptr->print();
    C obj(1, 2, 3);
    // obj.secret();
    ptr->func();
    delete ptr;
    // ptr = new B(4, 5);
    // ptr->print();
    // delete ptr;
    // cout<<sizeof(ptr)<<"\n";

    return 0;
}