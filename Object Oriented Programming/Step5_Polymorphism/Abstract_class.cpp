//===============================================
/*Pure virtual functions are to be such that we soud not make an object of the that class
but we can use the methods in the inherited classes ,not make the object of the virtual class
in the herited class so ,it should be isA relationship not the hasA
*/
//===============================================
#include<iostream>
using namespace std;
class base
{
public:
   virtual void message()=0;//pure Virtual function
   void bas(){
    cout<<"This is a base class:"<<endl;
   }
};
class derived1 :public  base
{
public:
        void message(){
        base:bas();
        cout<<"This is a derived 1 class"<<endl;
    }

};
class derived2 :public base
{
public:
    void message(){
        cout<<"This is a derived 2 class"<<endl;
    }
};
int main(){

    base *ptr1=new derived1;
    base *ptr2=new derived2;
    ptr1->message();
    ptr2->message();

    return 0;
}