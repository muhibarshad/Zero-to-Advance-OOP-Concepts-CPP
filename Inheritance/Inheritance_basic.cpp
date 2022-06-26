//Basic Inheritance 
#include <iostream>
using namespace std;
class car
{
protected:
    string color;
    int noOfseats;
    string engine;
    string model;

public:
    car(string color_a = "Null", int noofSeats_a = 0, string engine_a = "NULL", string model_a = "NULL")
    {
        color = color_a;
        noOfseats = noofSeats_a;
        engine = engine_a;
        model = model_a;
    }
    void getter()
    {
        cout << "The color of the car = " << color << endl;
        cout << "The engine of the car = " << engine << endl;
        cout << "The no fo seats of the car = " << noOfseats << endl;
        cout << "The model of the car = " << model << endl;
    }
    ~car()
    {
        cout << "Destructor has been called:" << endl;
    }
};
/*======================================
Inhereted Class for the type of car
======================================*/
class type : public car
{
private:
    string name;
    string fuelType;
    string version;

public:
    type(string color_a = "Null", int noofSeats_a = 0, string engine_a = "NULL", string model_a = "NULL", string name_a = "NULL", string fuel_a = "NULL", string version_a = "NULL") : car(color_a, noofSeats_a, engine_a, model_a)
    {
        color = color_a;
        noOfseats = noofSeats_a;
        engine = engine_a;
        model = model_a;
        name = name_a;
        fuelType = fuel_a;
        version = version_a;
    }
    void getter()
    {
        car::getter();
        cout << "The name of the car = " << name << endl;
        cout << "The fuel type of the car = " << fuelType << endl;
        cout << "The version of the car = " << version << endl;
    }
};
int main()
{
    // car c1("Blue",2,"full spported","2018");
    // car c2;
    // c2.getter();
    // c1.getter();

    type c4("Blue",2,"full spported","2018","Mehran", "Petrol", "No version xd");
    c4.getter();

    return 0;
}