/*Dynamic Objects when we pass to functions they always should be pass as by refernce
/*This code has three parts by three tests so you can uncommenntg the every test and check the outputs to understand
1:Pass by value  for dynamic objects
2:Pass by refernce for dynamic objects
3:Return value for dynamic objects
*/

#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    // setters
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    void setData(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // getters
    int getX() { return x; }
    int gety() { return y; }
    void getData()
    {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
    }
};

// Functions

// 1:Pass by value
bool passByValue(algebra *A, algebra *B)
{
    return A->getX() != B->getX() ? true : false;
}

// 2:Pass by refernce
void update(algebra *A, algebra *B)
{
  B->setX(B->getX()+100);
  B->setY(B->gety()+100);
}

// 3:Return value
algebra createCopy(const algebra *A)
{
    algebra *copy=new algebra;
    copy->setX(A->getX());
    copy->setY(A->gety());

    return copy;
}
int main()
{
    algebra *obj1 = new algebra;
    algebra *obj2 = new algebra;

    obj1->setData(1, 2);
    obj2->setData(3, 4);

    // Test:01
    cout << passByValue(obj1, obj2);

    //Test:02
    cout << "Before passing obj2 as a pointer to update function : " << endl;
    obj2->getData();
    update(obj1, obj2);
    cout << "After passing obj2 as a pointer to update function : " << endl;
    obj2->getData();


    //Test:03
    cout << "The object members :" << endl;
    algebra *copy1 =new algebra;

    copy1=createCopy(obj1);
    copy1->getData();

    delete obj1;
    delete obj2;
    delete copy;

    return 0;
}