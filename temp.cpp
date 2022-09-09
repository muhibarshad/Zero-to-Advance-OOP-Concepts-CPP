/*Write a C++ program to how to write the destructors of the class*/
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
    algebra(const algebra &);
    void setX(int);
    void setY(int);
    void setData(int, int);
    int getX();
    int getY();
    void getData();
    ~algebra();
    algebra sum(const algebra &obj)
    {
        return algebra(x + obj.x, y + obj.y);
    }
};
// default constructor
algebra::algebra()
{
    x = 0;
    y = 0;
    cout << "Default constructor should be called:" << endl;
}
// paremterized constructor
algebra::algebra(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "Parameterized Constructor should be called:" << endl;
}
// copy constructor
algebra::algebra(const algebra &temp)
{
    x = temp.x;
    y = temp.y;
    cout << "Copy constructor should be called:" << endl;
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

// destructor
algebra::~algebra()
{
    cout << "Destructor should be called" << endl;
}
int main()
{
    //for static object arrays
    const int size=3;
    algebra obj[size]={algebra(),algebra(1,2),algebra(obj[1])};

    //for dynamic object arrays
    algebra *obj2=new algebra[size]{algebra(),algebra(1,2),algebra(obj[1])};

    //for static object arrays
    obj[0].getData();
    obj[1].getData();
    obj[2].getData();

    //for dynamic object arrays
    (obj2+0)->getData();
    (obj2+1)->getData();
    (obj2+2)->getData();

        return 0;
}
