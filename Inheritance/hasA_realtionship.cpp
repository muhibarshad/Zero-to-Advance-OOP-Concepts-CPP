//===============================================================
//In hasA relationship:
/*                   The class has a object based relationship.
isA realtionship is only used when we have actually want to access the only some member function of the base class
isA realtionship has the dynamic binding(used during the run time)
isA realtionshiop is used when you can't want to inherit something only wnat to use some features of that class
*/
//===============================================================
#include<iostream>
using namespace std;
class car
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
    void body()
    {
        cout << "The body of the car is strong." << endl;
    }
    void window()
    {
        cout << "The window of the car is green" << endl;
    }
};
class mycar
{
private:
    car features;
public:
     void color()
     {
        features.name();
        cout << "The color of the my car =  black " << endl;
     }
     void model()
     {
        features.enginetype();
        cout << "The model of my car = 2015 " << endl; 
     }
     
};
int main()
{

   mycar mc;
   mc.color();
   mc.model();

    return 0;
}