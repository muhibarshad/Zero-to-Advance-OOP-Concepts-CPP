/*What is a this key Word in C++? Write a C++ program in which the setter function parameter name is same as the class data member name.What is the *this Pointer* in the C++?*/
/*The this keyword can be used for the two purposes firtsly to use the local variable names as same as the class data memebers name.Secondly it can be used for the function calls chaining in which the local object returns the refernce of the single object and in function chaining it updates the every previous function value also.*/

#include<iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
public:
    //setters
    void setX(int x)
    {
       this->x=x;
    }
    void setY(int y)
    {
        this->y=y;
    }
    void setData(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    //getters
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
    }

    //member functions
    algebra &value(int x)
    {
        this->x=x;
        return *this;
    }
    algebra &incrementValue(int y)
    {
        this->x++;
        this->y=y;
        return *this;
    }

};

int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.setData(1,2);
    obj2->setData(3,4);

    obj1.getData();
    obj2->getData();    

    obj1.value(100).incrementValue(200);
    obj1.getData();//101,200--->chaining is sequential and the changes made to the object’s data members retains for further chaining calls.


    return 0;
}