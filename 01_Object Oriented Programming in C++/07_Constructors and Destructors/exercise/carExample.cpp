#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    Car(int, string, int);
    Car(int, string);
    Car(const Car &);

    void setYearModel(int);
    void setMake(string);
    void setSpeed(int);
    void setData(int, string, int);

    int getYearModel();
    string getMake();
    int getSpeed();
    void getData();

    void putData();
    void accelerate();
    void brake();

    ~Car();
};

// Overloaded_constructor
Car::Car(int yearModel = 0, string make = "", int speed = 0)
{
    setYearModel(yearModel);
    setMake(make);
    setSpeed(speed);
}

// Parameterized Constructor
Car::Car(int yearModel, string make)
{
    setYearModel(yearModel);
    setMake(make);
    setSpeed(0);
}

// COPY_CONSTRUCTOR
Car::Car(const Car &cpyObj)
{
    yearModel = cpyObj.yearModel;
    make = cpyObj.make;
    speed = cpyObj.speed;
}

// SETTERS
void Car::setYearModel(int yearModel) { this->yearModel = yearModel; }
void Car::setMake(string make) { this->make = make; }
void Car::setSpeed(int speed) { this->speed = speed; }

// GETTERS
int Car::getYearModel() { return yearModel; }
string Car::getMake() { return make; }
int Car::getSpeed() { return speed; }

// IMPLEMENTATION

void Car::setData(int yearModel, string make, int speed)
{
    setYearModel(yearModel);
    setMake(make);
    setSpeed(speed);
}

void Car::getData()
{
    cout << "Enter the year Model of the car : ";
    cin >> yearModel;
    cout << "Enter the make of the car : ";
    cin.ignore();
    getline(cin, make);
    cout << "Enter the speed of the car : ";
    cin >> speed;
}

void Car::putData()
{
    cout << "The year Model of the car : " << yearModel << "\n";
    cout << "The make of the car : " << make << "\n";
    cout << "The speed of the car : " << speed << "\n";
}

void Car::accelerate() { speed += 5; }
void Car::brake() { speed -= 5; }

// DESTRUCTOR
Car::~Car()
{
    cout << "DESTRUCTOR EXECUTED." << endl;
}

//===============================
//*************Main*************
//===============================
int main()
{
    // INILIAZING
    const int size = 5;
    Car car[size];

    // DECLARING
    car[0].setData(2021, "Suzuki Alto", 40);
    car[0].accelerate();
    car[0].getData();
    car[1].setData(2015, "Toyota Camry", 45);
    car[2].setData(2011, "Honda Accord", 80);
    car[3].setData(2012, "Toyota Prius", 60);
    car[4].setData(2018, "Daihatsu Boon", 55);

    // FORMATTING
    cout << left;
    cout << setw(20) << "Year Model" << setw(25) << "Make" << setw(10) << "Speed"
         << "\n";

    // DISPLAYING
    for (auto &obj : car)
    {
        cout << setw(20) << obj.getYearModel() << setw(25) << obj.getMake() << setw(10) << obj.getSpeed()
             << "\n";
    }

    return 0;
}