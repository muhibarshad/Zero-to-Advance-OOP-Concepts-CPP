#include <iostream>
using namespace std;
class phoneDetails
{
private:
    string name;
    int  RAM;
    float processor;
    char battery;
public:
//==============================================
//Overloaded constructor
/*The sum of the 
1-deafult constructor 
2-Paramterized Constructor
*/
//==============================================

phoneDetails(string Name="NULL",int ram=0,float process=0.0,char batt=' ')
{
   name=Name;
   RAM=ram;
   processor=process;
   battery=batt;
}

//==============================================
//Copy constructor
//==============================================

phoneDetails(phoneDetails &mob)
{
   name=mob.name;
   RAM=mob.RAM;
   processor=mob.processor;
   battery=mob.battery;
}

void getData();

//==============================================
//Calling destructor
//==============================================

~phoneDetails()
{
    cout<<"Destructor has been called:"<<endl;
}

};

//==============================================
//Accessing the functions of the class outside the class
//==============================================

void phoneDetails::getData()
{
   cout<<"The name of the Phone = "<<name<<endl;
   cout<<"The Ram of the Phone = "<<RAM<<endl;
   cout<<"The Processor of the Phone = "<<processor<<endl;
   cout<<"The Battery of the Phone = "<<battery<<endl;
}

//Main
int main()
{
    phoneDetails d1;//deafult constructor
    phoneDetails d2("Iphone",8,2.8,'1');//parameterized constructor
    phoneDetails d3(d2);//copy constructor

    d1.getData();
    d2.getData();
    d3.getData();
    
    return 0;
}