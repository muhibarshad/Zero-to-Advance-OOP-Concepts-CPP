#include <iostream>

using namespace std;

class algebra
{
private:
    int x, y;

public:
    algebra(int x = 1, int y = 1) : x(x), y(y) {}
    // Pre increment Operator
    algebra operator--()
    {
        algebra temp(*this);
        --x;
        --y;
        return temp;
    }
    // Post increment Operator
    algebra operator--(int)
    {
        algebra temp(*this);
        x--;
        y--;
        return temp;
    }
    void getData() { cout << x << "  " << y << "\n"; }
};
int main()
{
    algebra obj(2, 2);
    algebra preMinus_Obj = --obj;
    algebra postMinus_Obj = obj--;
    preMinus_Obj.getData(); // 1    1
    postMinus_Obj.getData(); // 1    1
    obj.getData();      // 0    0
}