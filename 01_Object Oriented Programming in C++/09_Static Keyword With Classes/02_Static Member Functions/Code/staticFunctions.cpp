#include <iostream>

class algebra
{
private:
    const int x;
    static int y;

public:
    algebra(int, int);
    static void incrementY();
    static void printY();
    static void setY(int );
    void getData();
    ~algebra();
};

int algebra::y = 0;

algebra::algebra(int x = 0, int y = 0) : x(x)
{
    this->y = y;
}
void algebra::getData()
{
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
}

//Do not use static while definig
void algebra::setY(int y)
{
    algebra::y=y;
}
void algebra::incrementY()
{
    algebra::y++;
}
void algebra::printY()
{
    std::cout << algebra::y << "\n";
}

algebra::~algebra()
{
    std::cout << "Destructor has been called:\n";
}
int main()
{
    algebra::incrementY();//0++
    algebra::printY();//1

    algebra obj1;//x=0,y=0
    obj1.printY();//y=0
    obj1.incrementY();//y=0++ => y=1

    obj1.getData();//x=0, y=1

    algebra obj2(2,7);//x=2 , static y=7 (ovwrWrited)
    obj2.getData();

    algebra::printY();//y=7
    obj1.getData();
    obj1.incrementY();
    obj2.getData();//x=2, y=8

    algebra::setY(6);

    obj1.getData();
}