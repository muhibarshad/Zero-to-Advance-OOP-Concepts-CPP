#include <iostream>

using namespace std;

class Engine
{
private:
    string speed;
    int model;
public:
    Engine(string speed, int model) : speed(speed), model(model) {}
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
};
