#include <iostream>

using namespace std;

class Algebra
{
private:
    int x;
    int y;
    static int z;
public:
    // non-statuc_member_functions
    Algebra(int x = 0, int y = 0)
    {
        setX(x);
        setY(y);
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setData(int x, int y)
    {
        setX(x);
        setY(y);
    }
    int getX() { return x; }
    int getY() { return y; }
    void getData()
    {
        cout << "x = " << x << "\t y=" << y << "\n";
    }

    // static_member_functions
    static void setZ(int z){Algebra::z=z;}
    static int getZ(){return Algebra::z;}

    ~Algebra()
    {
        cout << "Destructor exectued:"
             << "\n";
    }
};
int Algebra::z;//can be initlized to 0 by deafult
int main()
{
    Algebra::setZ(100);

    Algebra obj1,obj2;

    obj1.setZ(200);

    cout<<Algebra::getZ()<<"\n";//200

    obj2.setZ(300);

    cout<<obj1.getZ()<<"\n";//300


    return 0;
}
