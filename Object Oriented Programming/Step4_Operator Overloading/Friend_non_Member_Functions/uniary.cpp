#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    algebra(int, int);
    friend algebra operator-(const algebra &);
    void getData();
};
algebra::algebra(int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
}
algebra operator-(const algebra &obj)
{
    algebra r;
    r.x = -obj.x;
    r.y = -obj.y;
    return r;
}
void algebra ::getData()
{
    cout << "The value of x = " << x << "\n";
    cout << "The value of y = " << y << "\n";
}
int main()
{
    algebra a1(1, 2);
    a1.getData();

    operator-(a1).getData();

    (-a1).getData();
    
    algebra a2 = -a1;
    a2.getData();

    return 0;
}