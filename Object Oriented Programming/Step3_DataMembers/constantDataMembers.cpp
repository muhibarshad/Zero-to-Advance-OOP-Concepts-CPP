
//With one fix value for all objects (initialize in class definition)
#include <iostream>
class algebra
{
private:
    int x;
    const int y = 30;

public:

    //OVERLOADED_CONSTRUCTOR
    algebra(int x = 0, int y = 0)
    {
        setX(x);
        // setY(0);
    }

    //SETTERS_AND_GETTERS
    void setX(int x) { this->x = x; }
    // void setY(int y) { this->y = y; }
    void setData(int x, int y)
    {
        this->x = x;
        // this->y=y;
    }
    int getX() { return x; }
    int getY() { return y; }
    void getData()
    {
        std::cout << "x = " << x << "\n";
        std::cout << "y = " << y << "\n";
    }

    //DESTRUCTOR
    ~algebra()
    {
        std::cout << "Destructor has been Called:\n";
    }
};
int main()
{
    algebra obj1,obj2;
    obj1.getData();//y=30

    obj2.setData(2,3);
    obj2.getData();//y=30
}