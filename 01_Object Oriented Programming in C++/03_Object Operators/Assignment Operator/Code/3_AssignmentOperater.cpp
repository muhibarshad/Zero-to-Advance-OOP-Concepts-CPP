/*In C++ how the class data members of one object to be copied to the another object data memebers*/;

#include <iostream>

using namespace std;

class algebra
{
public:
    int x;
    int y;

    void getData()
    {
        cout<<"The value of x ="<<x<<endl;
        cout<<"The value of y ="<<y<<endl;
    }
};

int main()
{
    algebra obj1;
    algebra *obj2=new algebra;

    obj1.x=1;
    obj1.y=2;

    //MEMEBER WISE COPYING
    cout<<"\t\tMEMEBER WISE COPYING :"<<endl;
    obj2->x=obj1.x;
    obj2->y=obj1.y;

    cout<<"The values in object 1 : "<<endl;
    obj1.getData();
    cout<<"The values in object 2 : "<<endl;
    obj2->getData();
    
    // Aggregate WISE COPYING
    cout<<"\t\tAggregate WISE COPYING :"<<endl;
    (*obj2)=obj1;

    cout<<"The values in object 1 : "<<endl;
    obj1.getData();
    cout<<"The values in object 2 : "<<endl;
    obj2->getData();

    delete obj2;
    obj2=nullptr;

    return 0;
}