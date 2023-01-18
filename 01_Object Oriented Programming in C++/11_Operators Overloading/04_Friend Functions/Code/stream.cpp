#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    algebra(int, int);
    friend ostream &operator<<(ostream &, const algebra &);
    friend istream &operator>>(istream &, algebra &);
};
algebra::algebra(int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
}
//• One operand left one is stream object and right
// one is class object
ostream &operator<<(ostream &out, const algebra &obj)
{
    out << "The value of X :" << obj.x << "\n";
    out << "The value of Y :" << obj.y << "\n";

    return out;
}
// One operand left one is stream object and
// right one is class object
istream &operator>>(istream &in, algebra &obj)
{
    cout << "Enter the value of X:";
    in >> obj.x;
    cout << "Enter the value of Y:";
    in >> obj.y;

    return in;
}

int main()
{
    algebra a1(9, 7);
    cin >> a1;
    cout << a1;

    return 0;
}