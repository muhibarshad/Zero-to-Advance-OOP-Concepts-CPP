#include <iostream>

using namespace std;

class Box
{
private:
    double length, breadth, height;
    static int objectCount;

public:
    Box() : length(0), breadth(0), height(0) {}
    Box(double length, double breadth, double height) : length(length), breadth(breadth), height(height) {}
    void setLength(double length) { this->length = length; }
    void setbreadth(double breadth) { this->breadth = breadth; }
    void setheigth(double heigth) { this->height = heigth; }
    double getLength() { return length; }
    double getbreadth() { return breadth; }
    double getheigth() { return height; }
    void print()
    {
        cout << "The length of the object = " << length << "\n";
        cout << "The breadth of the object = " << breadth << "\n";
        cout << "The height of the object = " << height << "\n";
    }
    static int getCount()
    {
        return objectCount;
    }
    double getVolume()
    {
        return (length * breadth) * height;
    }
    double getArea()
    {
        return length * breadth;
    }
    friend void print_surfaceArea(const Box &b1)
    {
        cout << "The surface area of the box = " << (2 * (b1.length * b1.breadth) + 2 * (b1.length * b1.height) + 2 * (b1.breadth * b1.height));
    }
    friend void double_data_members(double &length, double &breadth, double &height)
    {
        length += length;
        breadth += breadth;
        height += height;
    }
};
int Box::objectCount=1;
int main()
{
    Box b(2, 2, 2);
    b.print();
    cout << Box::getCount();
    return 0;
}