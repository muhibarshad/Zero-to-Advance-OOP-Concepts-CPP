#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;	// To hold a number of feet
	int inches; // To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches &right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator+(const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator-(const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator*(const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator++()
	{
		++inches;
		simplify();
		return *this;
	}

	FeetInches operator++(int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator--()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator--(int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator>(const FeetInches &right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator<(const FeetInches &right)
	{
		return !(*this > right);
	}

	bool operator>=(const FeetInches &right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator<=(const FeetInches &right)
	{
		return !(*this >= right);
	}

	bool operator==(const FeetInches &right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator!=(const FeetInches &right)
	{
		return !(*this == right);
	}

	friend ostream &operator<<(ostream &, const FeetInches &);
	friend istream &operator>>(istream &, FeetInches &);
};

ostream &operator<<(ostream &out, const FeetInches &obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream &operator>>(istream &in, FeetInches &obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

// ROOM DIMENSION
class RooomDimension
{
private:
	FeetInches length;
	FeetInches width;

public:
	RooomDimension(int feetLength, int inchesLength, int feetWidth, int inchesWidth) : length(feetLength, inchesLength), width(feetWidth, inchesWidth) {}

	void setLength(int feetLength, int inchesLength)
	{
		length.setFeet(feetLength);
		length.setInches(inchesLength);
	}
	void setWidth(int feetWidth, int inchesWidth)
	{
		width.setFeet(feetWidth);
		width.setInches(inchesWidth);
	}
	int getLength() const
	{
		return length.getFeet();
	}
	int getWidth() const
	{
		return width.getFeet();
	}
	FeetInches getArea() const
	{
		return FeetInches(length.getFeet() * width.getFeet(), length.getInches() * width.getInches());
	}
	void display() const
	{
		cout << "The length = " << length << "\n";
		cout << "The width = " << width << "\n";
	}
};
class RoomCarpet
{
private:
	RooomDimension &roomSize;
	float costPerSquareRoot;

public:
	RoomCarpet(RooomDimension &roomSize, float costPerSquareRoot) : roomSize(roomSize), costPerSquareRoot(costPerSquareRoot) {}

	void setRoomSize(RooomDimension &roomSize)
	{
		this->roomSize = roomSize;
	}

	void setCost(float costPerSquareRoot)
	{
		this->costPerSquareRoot = costPerSquareRoot;
	}

	float getCostPerSquareRoot() const
	{
		return costPerSquareRoot;
	}
	RooomDimension getRoomSize() const
	{
		return roomSize;
	}

	double totalCostCarpet() const
	{
		return roomSize.getLength() * roomSize.getWidth() * costPerSquareRoot;
	}

	void display() const
	{
		cout << "The costPerSquareRoot = " << costPerSquareRoot << "\n";
		cout << "The roomSize has length :" << roomSize.getLength() << "  width :" << roomSize.getWidth() << "\n";
	}
};

int main()
{

	RooomDimension obj(11, 14, 9, 14);
	obj.display();

	RoomCarpet obj2(obj, 80);
	cout <<"The total cost of carpet = "<<obj2.totalCostCarpet() << "\n";
	obj2.display();
}