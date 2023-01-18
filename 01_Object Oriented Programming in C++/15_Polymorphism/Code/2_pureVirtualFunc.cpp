// pure Virtaual functions

#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    Point(int x = 1, int y = 2) : x(x), y(y) { cout << "Cons. of Point\n"; }
    ~Point() { cout << "Des. of Point\n"; }
    void setX(int x = 0) { this->x = x; }
    void setY(int y = 0) { this->y = y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class Shape
{
protected:
    Point *p;

public:
    Shape(int x = 0, int y = 0)
    {
        p = new Point(x, y);
        cout << "Cons. of shape\n";
    }
    void setPoint(int x = 0, int y = 0)
    {
        p->setX(x);
        p->setY(y);
    }
    Point getPoint() const
    {
        return *p;
    }
    virtual ~Shape()
    {
        delete p;
        cout << "Des. of Shape\n";
    }
    virtual void draw() = 0;
};
class Circle : public Shape
{
    int radius;

public:
    Circle(int x = 0, int y = 0, int radius = 1) : Shape(x, y), radius(radius) { cout << "Cons. of Circle\n"; }
    ~Circle() { cout << "Des. of circle\n"; }
    void draw()
    {
        cout << "Draw the Circle at the points of \n\t x= " << p->getX() << " ; y= " << p->getY() << "\n\t Radius = " << radius << "\n";
    }
};
class Rectangle : public Shape
{
    int length, width;

public:
    Rectangle(int length = 0, int width = 0) : length(length), width(width)
    {
        delete p;
        p = new Point[4];
    }
    ~Rectangle()
    {
        delete[] p;
        cout << "Des. of Rectangle\n";
    }
    void draw()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "Point " << i + 1 << " x = " << p[i].getX() << " \n";
            cout << "Point " << i + 1 << " y = " << p[i].getY() << " \n";
        }
        cout << "Draw the Rectangle having the length of " << length << "  and width of " << width << "\n";
    }
};
int main()
{

    int size = 0;
    int x;
    cout << "How many shapes are you want to draw (as a Circle orrectangle) \n";
    cin >> size;
    Shape **shape = new Shape *[size];
    int y = 0;
    while (y < size)
    {
        cout << "Press 1 to draw Circle \n";
        cout << "Press 2 to draw Rectangle\n";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            shape[y] = new Circle(2, 3, 5);
            shape[y]->draw();
            break;
        }
        case 2:
        {
            shape[y] = new Rectangle(7, 9);
            shape[y]->draw();
            break;
        }

        default:
            break;
        }

        y++;
    }

    for (int i = 0; i < size; i++)
        delete shape[i];
    delete shape;

    return 0;
}