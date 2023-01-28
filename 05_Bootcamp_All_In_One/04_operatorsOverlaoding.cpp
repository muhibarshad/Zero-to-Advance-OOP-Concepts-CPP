#include <iostream>

using namespace std;

class Algebra
{
  int x, y;

public:
  Algebra(int x = 0, int y = 0) : x(x), y(y) {}
  Algebra& operator+=(const Algebra &obj)
  {
    x += obj.x;
    y += obj.y;
    return *this;
  }

  friend ostream &operator<<(ostream &out, const Algebra &obj)
  {
    out << "the value of x = " << obj.x << "\n";
    out << "the value of y = " << obj.y << "\n";
    return out;
  }
  Algebra &operator++()
  {
    x++;
    y++;
    return *this;
  }
  Algebra operator++(int)
  {
    Algebra temp = *(this);
    x++;
    y++;
    return temp;
  }
};

int main()
{

  Algebra obj(1, 2);
  Algebra obj1(3, 4);
  Algebra obj2(5, 6);
  cout << (obj++) << "\n";
  cout << obj << "\n";
  cout << (++obj) << "\n";
  cout << (obj) << "\n";

  return 0;
}