#include "iostream"

using namespace std;

//Declaration of class Algebra
class Algebra
{
	//data members of the class
	int a, b;

	//static data member to keep the count of objects 
	static int S;

public:
	Algebra();								//default constructor
	Algebra(int, int);						//parameterized constructor
	Algebra(const Algebra&);				//copy constructor
	~Algebra();								//destructor

	void input();							//to take input for object's data
	void print() const;						//Function to display object's data on screen

	void setData(int, int);					//Function to set object's data

	void setA(int);							//setter for data member A
	int getA() const;						//getter for data member A

	void setB(int);							//setter for data member B
	int getB() const;						//setter for data member B

	Algebra add(const Algebra&) const;						//function to add two objects and return their result
	bool searchArray(const Algebra ar[], int size) const;	//search the left-hand side object in the array passed as argument

	//static member functions to set/get the value S data member.
	//'this' does not exist in static member functions.
	static void setS(int);
	static int getS();	
};

//Definations of class Algebra's members

//static data members are intiliazed with 0 automatically
int Algebra::S;

//static member functions to set the value of S static data member.
void Algebra::setS(int S)
{
	//this->S = S;		Error: 'this' may only be used inside a nonstatic member function

	Algebra::S = S;
}

//static member functions to get the value of S static data member.
int Algebra::getS()
{
	return S;
}

//Default Constructor
Algebra::Algebra()
{
	this->a = this->b = 0;
}

//Parameterized Constructor
Algebra::Algebra(int a, int b)
{
	this->a = a;
	this->b = b;
}

//Copy Constructor
Algebra::Algebra(const Algebra& obj)
{
	this->a = obj.a;
	this->b = obj.b;
}

//Destructor
Algebra::~Algebra()
{
	//cout << "Desstructor" << endl;
}

//setter for data member a
void Algebra::setA(int a)
{
	this->a = a;
}

//getter for data member a
int Algebra::getA() const
{
	return this->a;
}

//setter for data member b
void Algebra::setB(int b)
{
	this->b = b;
}

//getter for data member b
int Algebra::getB() const
{
	return this->b;
}

//Function to set object's data
void Algebra::setData(int a, int b)
{
	this->a = a;
	this->b = b;
}

//Function to take input for object's data
void Algebra::input()
{
	cout << "Enter a = ";
	cin >> this->a;

	cout << "Enter b = ";
	cin >> this->b;
}

//Function to display object's data on screen
void Algebra::print() const
{
	cout << "a = " << this->a << "\tb = " << this->b << endl;
}

//function to add two objects and return their result
Algebra Algebra::add(const Algebra& obj) const
{
	return Algebra(a + obj.a, b + obj.b);
}

//search the left hand side object in the array passed as argument 
bool Algebra::searchArray(const Algebra ar[], const int size) const
{
	for (int i = 0; i < size; i++)
	{
		if ((a == ar[i].a) && (b == ar[i].b))
			return true;
	}

	return false;
}

int main()
{
	cout << Algebra::getS() << endl;	//access the static member function with its class name

	Algebra::setS(9);					//access the static member function with its class name

	cout << Algebra::getS() << endl;	//access the static member function with its class name

	Algebra obj1;

	cout << obj1.getS() << endl;		//static members can also be accessed with objects. 

	return 0;
}