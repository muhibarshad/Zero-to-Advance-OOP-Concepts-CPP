#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Cuboids
{
private:
    float height;
    float width;
    float depth;

public:
    // CONSTRUCTORS
    Cuboids(float, float, float);
    Cuboids(float, float);
    Cuboids();

    // MUTATORS
    void setHeight(float);
    void setWidth(float);
    void setDepth(float);

    // ACCESSORS
    float getHeight() const;
    float getWidth() const;
    float getDepth() const;

    // IMPLEMENTED_MEMBER_FUNCTIONS
    void setCuboids(float, float, float);
    void getCuboids();
    void putCuboids() const;

    float getSurfaceArea() const;
    float getVolume() const;
    float getSpaceDiagonal() const;
    void putCubiodsInfo() const;

    // DESTRUCTOR
    ~Cuboids();
};

// MUTATORS
void Cuboids::setHeight(float height)
{
    this->height = height > 0 && height < 35.00 ? height : 1;
}
void Cuboids::setWidth(float width)
{
    this->width = width > 0 && width < 35.00 ? width : 1;
}
void Cuboids::setDepth(float depth)
{
    this->depth = depth > 0 && depth < 35.00 ? depth : 1;
}

// ACCESSORS
float Cuboids::getHeight() const { return height; }
float Cuboids::getWidth() const { return width; }
float Cuboids::getDepth() const { return depth; }

// CONSTRUCTORS
Cuboids::Cuboids(float height, float width, float depth)
{
    setHeight(height);
    setWidth(width);
    setDepth(depth);
}
Cuboids::Cuboids(float height, float width)
{
    setHeight(height);
    setWidth(width);
    setDepth(1);
}
Cuboids::Cuboids()
{
    setHeight(1);
    setWidth(1);
    setDepth(1);
}

// DESTRUCTOR
Cuboids::~Cuboids()
{
    cout << "DESTRUCTOR EXECUATED." << endl;
}

// IMPLEMENTED_MEMBER_FUNCTIONS
void Cuboids::setCuboids(float height, float width, float depth)
{
    setHeight(height);
    setWidth(width);
    setDepth(depth);
}
void Cuboids::getCuboids()
{
    cout << "Enter the Cuboid\'s height :";
    cin >> height;
    cout << "Enter the Cuboid\'s width :";
    cin >> width;
    cout << "Enter the Cuboid\'s depth :";
    cin >> depth;
}
void Cuboids::putCuboids() const
{
    cout << "The Cuboid\'s height =" << height << "\n";
    cout << "The Cuboid\'s width =" << width << "\n";
    cout << "The Cuboid\'s depth =" << depth << "\n";
}

float Cuboids::getSurfaceArea() const
{
    return 2 * (height * width) + 2 * (height * depth) + 2 * (width * depth);
}
float Cuboids::getVolume() const
{
    return height * width * depth;
}
float Cuboids::getSpaceDiagonal() const
{
    return sqrt(pow(height, 2) + pow(width, 2) + pow(depth, 2));
}
void Cuboids::putCubiodsInfo() const
{
    putCuboids();
    cout << "The Cuboid\'s surface area =" << getSurfaceArea() << "\n";
    cout << "The Cuboid\'s volume =" << getVolume() << "\n";
    cout << "The Cuboid\'s space diagonal =" << getDepth() << "\n";
}

int main()
{
    // INITLIZING_CUBOIDS
    Cuboids cube[4];

    // DECLARING_CUBOIDS
    cube[0].setCuboids(4, 3, 6);
    cube[1].setCuboids(0, 2.2, 4.3);
    cube[2].setCuboids(15.8, 56.2, 5.9);
    cube[3].setCuboids(90, 30.6, 40.8);

    // FORMATTING_DATA
    cout << left;
    cout << setw(10) << "HEIGHT" << setw(10) << "WIDTH" << setw(10) << "DEPTH" << setw(17) << "SURFACE_AREA" << setw(13) << "VOLUME" << setw(16) << "SPACE_DIAGONAL"
         << "\n";

    // DISPLAYING_CUBOIDS
    for (const auto &cube : cube)
    {
        cout << setw(10) << cube.getHeight() << setw(10) << cube.getWidth() << setw(10) << cube.getDepth() << setw(17) << cube.getSurfaceArea() << setw(13) << cube.getVolume() << setw(16) << cube.getSpaceDiagonal() << "\n";
    }

    return 0;
}
