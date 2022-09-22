#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
    int z;
    // static constexpr double PI=3.14359;
public:
    algebra(int x = 0, int y = 0, int z = 0)
    {
        setX(x);
        setY(y);
        setZ(z);
        cout << "Consstructor Executed:"
             << "\n";
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setZ(int z) { this->z = z; }
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    void setData(int x, int y, int z)
    {
        setX(x);
        setY(y);
        setZ(z);
    }
    void putData()
    {
        cout << "The value of x = " << x << "\n";
        cout << "The value of y = " << y << "\n";
        cout << "The value of z = " << z << "\n";
    }
    ~algebra()
    {
        cout << "Destrcutor Executed:"
             << "\n";
    }

    // OPERATORS_OVERLOADING
    /*
    • Unary Operators:
- (minus), !, ++ (pre and post), -- (pre and post), ~ ( bitwise not) , & (address of)
• Binary Operators:
    1. Arithmetic -, +, *, /, % , +=, -=, *=, /=, %=
    2. Relational ==, !=, >=,<=, <, >
    3. Assignment =
    4. Logical &&, ||
    5. Subscript []
    6. Member access ->
    */

   
};
int main()
{
    algebra a1;
    algebra a2;
    a1.setData(1,2,3);
    a2.setData(4,5,6);
    a1.putData();
    a2.putData();

    //

    return 0;
}