//============================================
//In isA relationship:
/*                   The class has a inheritance based relationship.
isA realtionship is basically used when we have use the full access to the base class and derived class
isA realtionship has the static binding(used during the compile time)
isA realtionship is used when the derived class is actually inherit the base class
*/                  
//============================================
#include <iostream>
using namespace std;
class car
{
private:
    int num;
public:

    car(int n=0)
    {
        num=n;
    }
    void body()
    {
        cout << "The body of the car is strong." << endl;
    }
    void window()
    {
        cout << "The window of the car is green" << endl;
    }
};
class myModifyication : public car
{
public:
    void name()
    {
        cout << "The name of the car = suzuki"<< endl;
    }
    void enginetype()
    {
        cout << "The engine type of the car V8_googles engine ....xd🤣"<<endl;
    }
};
int main()
{
    myModifyication c1;
    c1.name();
    c1.enginetype();
    c1.body();
    c1.window();
}