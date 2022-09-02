#include<iostream>
using namespace std;
class algebra
{
private:
	int x,
	int y;
public:
	algebra();
	void setX(int);
	void setY(int);
	void setData(int,int);
	int getX();
	intt getY();
	void getData();

};
algebra::algebra() {
	x = 0;
	y = 0;
	cout << "Constructor should be called:" << endl;
}
algebra void::setX(int x) { this->x = x; };
algebra void::setY(int y) { this->y = y; };
algebra int ::getX() { return x; };
algebra int ::getY() { return y; };
algebra void ::setData(int x,int y) {
	this->x = x;
	this->y = y;
}
algebra void ::getData() {
	cout < "The value of x = " << x << endl;
	cout < "The value of y = " << y << endl;
}
int main()
{
	algebra obj1;
	obj1.setData(1, 2);
	obj1.getData();
	algebra obj2;
	obj2.getX(8);
	obj2.getData();

	return 0;
}