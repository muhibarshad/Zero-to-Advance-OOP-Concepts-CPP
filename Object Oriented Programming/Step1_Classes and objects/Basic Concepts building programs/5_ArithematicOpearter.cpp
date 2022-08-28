/*Can we compare the use the arithematic operaters (+,-,*,/,%) to perform arithematic calculations between two object data members ? 
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
    obj2->setData(1,2);
     
    //  //Test:01
    // //Member Wise
    // cout<<obj1.getX()+obj2->getX()<<endl;
    // cout<<obj1.getY()+obj2->getY()<<endl;
    
    //  //Test:02
    // //Agremeent Wise
    // cout<<*(obj2)+obj1<<endl;
    // //Compile time error Operation not defined


   //Results:We can perform the matematical opaertions on the object adat memebers only member wise not agremnet wise.

    delete obj2;
    obj2=nullptr;



    return 0;
}