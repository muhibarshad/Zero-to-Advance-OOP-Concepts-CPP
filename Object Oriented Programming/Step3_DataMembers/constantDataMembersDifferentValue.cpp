
// Different values for different objects (initialize in constructors)
//Setters are not used in this case for the constant value beacuse ist value is fixed during the compilation time by the constructors 

#include <iostream>
class algebra
{
private:
    int x;
    const int y;

public:
    // OVERLOADED_CONSTRUCTOR
    algebra(int x = 0, int y = 0):y(y)
    {
        setX(x);
    }
    
    //COPY_CONSTRUCTOR
    algebra(const algebra &cpyObj):y(cpyObj.y)
    {
        x=cpyObj.x;
    }

    // SETTERS_AND_GETTERS
    void setX(int x) { this->x = x; }
    void setData(int x, int y)
    {
        this->x = x;
    }
    int getX() { return x; }
    int getY() { return y; }
    void getData()
    {
        std::cout << "x = " << x << "\n";
        std::cout << "y = " << y << "\n";
    }

    // DESTRUCTOR
    ~algebra()
    {
        std::cout << "Destructor has been Called:\n";
    }
};
int main()
{
    algebra obj1;
    obj1.getData(); // y=0

    algebra obj2(2, 3);
    obj2.getData(); // x=2,y=3

    obj2.setData(4,7);
    obj2.getData(); //x=4 y=3(beacuse we firstly fix the valueof constant of objects)

    algebra obj3(obj2);
    obj3.getData();
}