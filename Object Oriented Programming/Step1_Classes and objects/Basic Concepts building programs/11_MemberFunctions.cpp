/*Write a c++ program in to find distance between two points and take third point and find from where the distance from third point is closest*/
#include <iostream>
#include <cmath>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    // setters
    void setX(int);
    void setY(int);
    void setData(int, int);
    void setAlgebra(algebra);

    // getters
    int getX() const;
    int getY() const;
    void getData() const;
    algebra getAlgebra() const;

    // memberFunctions
    float calculateDistance(algebra);
    algebra closestPoint(algebra , algebra );
};

// SETTERS_scope_resolutions
void algebra::setX(int x) { this->x = x; }
void algebra::setY(int y) { this->y = y; }
void algebra::setData(int x, int y)
{
    this->x = x;
    this->y = y;
}
void algebra::setAlgebra(algebra obj)
{
    x = obj.x;
    y = obj.y;
}

// GETTERS_scope_resolutions
int algebra::getX() const { return x; }
int algebra::getY() const { return y; }
void algebra::getData() const
{
    cout << "The value of x = " << x << endl;
    cout << "The value of y = " << y << endl;
}
algebra algebra::getAlgebra() const
{
    return *this;
}

// Member Functions
float algebra::calculateDistance(algebra point)
{
    int d1 = point.x - x;
    int d2 = point.y - y;

    int temp = ((d1 * d1) + (d2 * d2));

    return sqrt(temp);
}

algebra algebra ::closestPoint(algebra p1, algebra p2)
{
    float d1 = calculateDistance(p1);
    float d2 = calculateDistance(p2);

    return d1 <= d2 ? p1 : p2;
}

int main()
{
    algebra point1, point2, point3;

    point1.setData(6, 9);
    point2.setData(12, 3);
    point3.setData(1, 15);

    cout << point1.calculateDistance(point2)<<endl;
    point1.closestPoint(point2,point3).getData();

    return 0;
}