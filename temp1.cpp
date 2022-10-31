#include <iostream>

using namespace std;

class Engine
{
private:
    string speed;
    int model;

public:
    Engine(string speed, int model) : speed(speed), model(model) {}
    friend ostream &operator<<(ostream &out, const Engine &engine)
    {
        out << "The speed of the engine :" << engine.speed << "\n";
        out << "The model of the engine :" << engine.model << "\n";
        return out;
    }
};
class Car
{
private:
    const Engine &engine;
    string name;
    int price;

public:
    Car(const Engine &engine, string name, int price) : engine(engine)
    {
        this->name = name;
        this->price = price;
    }
    friend ostream &operator<<(ostream &out, const Car &car)
    {
        out << "The name of the car :" << car.name << "\n";
        out << "The price of the car :" << car.price << "\n";
        out << "The specifications of the engine :\n"
            << car.engine << "\n";
        return out;
    }
};
int main()
{
    Engine engine("200Km/h", 2002);
    {
        Car car(engine, "Mehran", 200);
        cout << car << "\n";
    }                       // this object destroys out of block
    cout << engine << "\n"; // but the engine object still remains

    return 0;
}