/*This code has three parts by three tests so you can uncommenntg the every test and check the outputs to understand
1:Pass by value
2:Pass by refernce
3:Return value
*/

#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:

    // setters
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    void setData(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // getters
    int getX() { return x; }
    int gety() { return y; }
    void getData()
    {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
    }
};

// Functions

// 1:Pass by value
bool passByValue(algebra A, algebra B)
{
    return A.getX() == B.getX() ? true : false;
}

// 2:Pass by refernce
void update(algebra &A, algebra B)
{
    A.setX(A.getX()+B.getX());
    A.setY(A.gety()+B.gety());
}

// 3:Return value
algebra sumOfBoth(algebra A, algebra B)
{
    algebra temp;

    temp.setX(A.getX() + B.getX());
    temp.setY(A.gety() + B.gety());

    return temp;
}
int main()
{

    algebra obj1;
    algebra obj2;

    obj1.setData(1, 2);
    obj2.setData(3, 4);

    // // Test:01
    // cout << passByValue(obj1, obj2) << endl;

    // // Test:02
    // cout << "Before passing obj1 as a reference to update function : " << endl;
    // obj1.getData();
    // update(obj1, obj2);
    // cout << "After passing obj1 as a reference to update function : " << endl;
    // obj1.getData();

    // // Test:03
    // cout << "The sum of both object members :" << endl;
    // algebra sum = sumOfBoth(obj1, obj2);
    // sum.getData();

    return 0;
}