#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int *y;

public:
    algebra()
    {
        x = 0;
        y = nullptr;
    }
    algebra(int x, int y)
    {
        this->x = x;
        this->y = new int(y);
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<"\n";
        if(y!=nullptr)
        cout<<"The value of y = "<<*y<<"\n";
        if(y==nullptr)
        cout<<"The value of y = "<<y<<"\n";
    }
    // Assignment to dynamic memeory
    void operator=(const algebra &obj)
    {
        if (this != &obj)
        {
            x = obj.x;
            if (y == nullptr && obj.y != nullptr)
            {
                y = obj.y;
            }
            if (y != nullptr && obj.y == nullptr)
            {
                delete y;
                y = nullptr;
            }
            if (y != nullptr && obj.y != nullptr)
            {
                *y = *(obj.y);
            }
        }
    }
};
int main()
{
    algebra a1(2, 4);
    algebra a2(8,9);
    a1.getData();
    a1=a2;
    a1.getData();


        return 0;
}