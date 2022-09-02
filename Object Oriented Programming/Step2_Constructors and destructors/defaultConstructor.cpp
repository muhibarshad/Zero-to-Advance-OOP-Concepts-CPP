#include <iostream>
using namespace std;
class algebra
{
private:
	int x;
	int y;

public:
	algebra();
	void setX(int);
	void setY(int);
	void setData(int, int);
	int getX();
	int getY();
	void getData();
};
algebra::algebra()
{
	x = 0;
	y = 0;
	cout << "Constructor should be called:" << endl;
}
void algebra::setX(int x) { this->x = x; };
void algebra::setY(int y) { this->y = y; };
int algebra::getX() { return x; };
int algebra::getY() { return y; };
void algebra ::setData(int x, int y)
{
	this->x = x;
	this->y = y;
}
void algebra ::getData()
{
	cout << "The value of x = " << x << endl;
	cout << "The value of y = " << y << endl;
}
int main()
{
	algebra obj1;
	obj1.setData(1, 2);
	obj1.getData();
	algebra obj2;
	obj2.setX(8);
	obj2.getData();

	return 0;
}