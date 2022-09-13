#include <iostream>

class algebra
{
private:
    const int x;

public:
    static int y;
    void getData();
    algebra(int, int);
};

int algebra::y = 0; // default

algebra::algebra(int x = 0, int y =0) : x(x)
{
    this->y = y;
}
void algebra::getData()
{
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
}

int main()
{
    algebra::y = 30;
    std::cout << algebra::y << "\n"; // 30

    algebra obj1;
    obj1.getData(); // x=0 , y=0
    // only non-static members become object property
    //on the time of creation of object it defaulty initliaze the all values with 0 so static meber became aslo zero

    algebra obj2(2, 7);
    obj2.getData(); // x=2 , y=7
    obj1.getData(); // x=0 , y=7
    std::cout << algebra::y << "\n"; // 7

    algebra obj3;
    obj3.y=9;
    obj1.getData();

    algebra::y=19;
    obj2.getData();

}