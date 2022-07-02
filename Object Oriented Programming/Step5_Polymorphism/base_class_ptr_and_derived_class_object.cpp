//==================================================
/*when we make the base class pointer and the object as the derived class
Then we think that we have the access to the derived class but not actually
we have only access to the base class .
it is likely to be such that we are sitting in the suzuki and pointing to the civic but we have no access to the civic car .
*/
//==================================================
#include <iostream>
using namespace std;
class car
{
private:
    int num;

public:
    car(int n = 0)
    {
        num = n;
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
        cout << "The name of the car = suzuki" << endl;
    }
    void enginetype()
    {
        cout << "The engine type of the car V8_googles engine ....xd🤣" << endl;
    }
};
int main()
{
    car *ptr;
    ptr = new myModifyication();

    ptr->body();
    ptr->window();

    // but not access as to derived class
    //  ptr->name();
    //  ptr->enginetype();
}