# Aggregatatoion

Like we previously discussed, classes have relationships between them, similar to the real world. The life of creation and death, and ownership depends on the situation we use and the relationship, such as "has-a," "uses-a," "is-a," etc. One of these relationships is called aggregation.

- The part (member) is part of the object (class)
- The part (member) can belong to more than one object (class) at a time
- The part (member) does not have its existence managed by the object (class)
- The part (member) does not know about the existence of the object (class)

## Basic Concept:

When we want to use some properties and methods of an external class object in a parent class object, aggregation is used. The used class has no knowledge about its usage in the parent class. In this relationship, the parent class knows about the presence of the used class, but the used class does not know about it. The life of creation of both classes is totally independent. When the parent class is destroyed, the used class still remains.

## When to use

When we want to use the same class as a data member in multiple classes or want to use some properties and methods of that class, aggregation is used. For example, an engine of an automobile is used in different cars like Audi, Mahindra, and Civic. All three cars use the same engine. Then we use the aggregation of the engine class in these cars. The engine class is totally unaware of the presence of the cars, but the cars know about the presence of the engine.

## How to use

In order to use the pointer or a reference & of a used object or the pointer `*` address of the used object in the parent class, we use `aggregation`. This reference refers to the used class object in the parent class. The reference or alias `&` actually have just a different name for the original object, we are actually using the `same address value`. When the reference variable is destroyed, it doesn't mean that the actual class is also destroyed, only this reference variable having the address of the referred class is destroyed. And with a `pointer`, we pass the address of the `aggregated object`, we use its address and manipulate it.

  <p align="center">
    <img src="/04_Material/CodeSnaps/aggregation.png" style="height: 70vh; padding-left: 0vh;">
 </p>

## Aggregation by `refernce & `

```cpp
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
    const Engine &engine;//use reference of Engine
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
```

## Aggregation by `Pointer * `

```cpp
#include "iostream"

using namespace std;

class Teacher
{
	int eCode;
	string tName;

public:
	Teacher(int eCode, string tName)
	{
		this->eCode = eCode;
		this->tName = tName;
	}

	void teacherInfo()
	{
		cout << "e-code = " << eCode << "\tt-name = " << tName << endl;
	}
};

class Department
{
	int dNo;
	string dName;

	Teacher* teacher;	//holds a reference to Teacher : Aggregation (week binding)

public:
	Department(int dNo, string dName, Teacher* teacher)
	{
		this->dNo = dNo;
		this->dName = dName;

		this->teacher = teacher;	//data member teacher holds the reference/address of a Teacher
	}

	void departmentInfo()
	{
		cout << "d-no = " << dNo << "\td-name = " << dName << endl;

		if (teacher != NULL)			//if teacher exists
			teacher->teacherInfo();		//display teacher information
	}
};

int main()
{
	Teacher t(100, "Khan");

	Department d(1, "DIT", &t);			//&t reference of teacher

	d.departmentInfo();

	return 0;
}
```
