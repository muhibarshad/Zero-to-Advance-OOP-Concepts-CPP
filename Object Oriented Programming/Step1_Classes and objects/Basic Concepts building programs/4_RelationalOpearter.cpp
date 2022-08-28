/*Can we compare the reational operaters (==,!=,<=,>=) to compare two object data members ? 
*/

#include<iostream>

using namespace std;

class algebra
{
public:
    int x;
    int y;
public:
    
    void setData(int xA,int yA)
    {
        x=xA;
        y=yA;
    }
    void getData()
    {
        cout<<"The value of  x = "<<x<<endl;
        cout<<"The value of  y = "<<y<<endl;
    }

    //getters
    int getX(){ return x;}
    int getY(){ return y;}
};
int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.setData(5,6);
    obj2->setData(6,5);
     
    //  //Test:01
    // cout<<obj1.getX()!=obj2->getX();
    // /*error: no match for 'operator!=' (operand types are 'std::basic_ostream<char>' and 'int')
    // cout<<obj1.getX()!=obj2->getX();*/
    
    //  //Test:02
    // cout<<*(obj2)==obj1;
    // //Compile time error Operation not defined

    // Results:So its mean we will never compare the data member wise or agrement wise
    delete obj2;
    obj2=nullptr;



    return 0;
}