#include <iostream>

class algebra
{
private:
    const int x;
    static int y;
public:
    algebra(int, int);
    static void incrementY()
    {
        y++;
    }
    static void printY()
    {
        std::cout<<y<<"\n";
    }
    void getData();
    ~algebra();
};

algebra::algebra(int x = 0, int y =0) : x(x)
{
    this->y = y;
}
void algebra::getData()
{
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
}
algebra::~algebra()
{
    std::cout<<"Destructor has been called:\n";
}
int main()
{


}