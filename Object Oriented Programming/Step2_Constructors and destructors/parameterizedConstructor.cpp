/*Write a C++ program how to write the default constructors*/
#include <iostream>
using namespace std;
class algebra
{
private:
    int x;
    int y;

public:
    algebra();
    algebra(int, int);
    void setX(int);
    void setY(int);
    void setData(int, int);
    int getX();
    int getY();
    void getData();
};
//default constructor
algebra::algebra()
{
    x=0;
    y=0;
    cout<<"Default constructor should be called:"<<endl;
}
//paremterized constructor
algebra::algebra(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "Parameterized Constructor should be called:" << endl;
}
void algebra::setX(int x) { this->x = x; };
void algebra::setY(int y) { this->y = y; };
int algebra::getX() { return x; };
int algebra::getY() { return y; };
void algebra ::setData(int x, int y)
{
    this->x = x;
    this->y = y;
}
void algebra ::getData()
{
    cout << "The value of x = " << x << endl;
    cout << "The value of y = " << y << endl;
}

int main()
{
    algebra obj1(1,3);
    obj1.getData();
    algebra obj2;
    obj2.getData();

    return 0;
}