
#include <iostream>
using namespace std;
class car
{
public:
    car()
    {
        cout << "The name of the car is mehran:" << endl;
    }
    void currentPrice()
    {
        cout << "The current price of the mehran is 2000000" << endl;
    }
};

class modifyCar:public car
{
public:
    void currentPrice()
    {
      cout << "After the five years now the current price of mehran is 4000000"<<endl;
    }
};
int main()
{
    modifyCar c1;
    c1.currentPrice();
    //Firstly call the default constructor of the base class then call the modify new member function 
    // of the derived class.

    return 0;
}