#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    algebra(int, int);

    friend algebra operator+(const algebra &, const algebra &);
    friend algebra operator+(const algebra &, const int &);
    friend algebra operator+(const int &, const algebra &);
    void getData();
};
algebra::algebra(int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
}

void algebra ::getData()
{
    cout << "The value of x = " << x << "\n";
    cout << "The value of y = " << y << "\n";
}

// Both operands are class objects.
algebra operator+(const algebra &obj1, const algebra &obj2)
{
    return algebra(obj1.x + obj2.x, obj1.y + obj2.y);
}

// One operand left one is class object
algebra operator+(const algebra &obj, const int &n)
{
    return algebra(obj.x + n, obj.y + n);
}

// One operand Right one is class object
algebra operator+(const int &n, const algebra &obj)
{
    return obj + n;
}

int main()
{
    algebra a1(1, 2);
    algebra a2(3, 4);
    operator+(a1, a2).getData();
    cout << "----------------"
         << "\n";
    (a1 + a2).getData();
    cout << "----------------"
         << "\n";
    algebra a3 = a1 + a2;
    a3.getData();

    
    cout << "----------------"
         << "\n";
    (a1 + 10).getData();
    cout << "----------------"
         << "\n";
    (10 + a2).getData();

    return 0;
}