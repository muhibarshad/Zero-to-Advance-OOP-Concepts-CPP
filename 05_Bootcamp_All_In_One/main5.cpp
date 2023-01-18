#include <iostream>

using namespace std;
class SoundRange
{
    int z;

public:
    SoundRange(int z = 30) : z(z)
    {
        cout << "Cons of SoundRange\n";
    }
    void setSoundRange(int z)
    {
        this->z = z;
    }
    ~SoundRange()
    {
        cout << "Des of SoundRange\n";
    }
};
class Driving
{
    int x;

public:
    Driving(int x = 0) : x(x)
    {
        cout << "Cons of Drving:\n";
    }
    void driving()
    {
        cout << "This car has an driving system:\n";
    }
    ~Driving()
    {
        cout << "Des of Drving\n";
    }
};
class Car
{
    int y;
    SoundRange *sound;
    Driving *drive; 

public:
    Car(int x, int y) : y(y)
    {
        drive = nullptr;
        cout << "Cons of Car:\n";
        sound = new SoundRange(x);
    }
    void createDrive(int z)
    {
        drive = new Driving(z);
    }
    void deleteDrive()
    {
        delete drive;
    }
    void car() const
    {
        cout << "This is a car\n";
    }
    ~Car()
    {
        delete sound;
        cout << "Des of Car\n";
    }
};
int main()
{

    Driving drive(150);

    Car car(100, 200);
    car.createDrive(100);

    drive.driving();
    car.deleteDrive();

    return 0;
}