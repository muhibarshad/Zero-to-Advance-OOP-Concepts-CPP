#include <iostream>

using namespace std;

class A
{
public:
	virtual void func() = 0;
};
class B : public A
{
public:
	void print()
	{
		cout << "B\n";
	}
	void func()
	{
		cout << "A\n";
	}
};
int main()
{
	B obj;

	return 0;
}