/*Scope Resolution operater (::) define the scope of anything at any place .Used to access the gloabal varables with the same name ,access the class memeber functions outside the the class ,usedin namespaces and in the inheritance*/
// syntx:
// returnType className :: functionName (parameters) {}
#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;

public:
    // setters
    void setX(int);
    void setY(int);
    void setData(int, int);
    void setAlgebra(algebra);

    // getters
    int getX() const;
    int getY() const;
    void getData() const;
    algebra getAlgebra() const;

    // memberFunctions are here
    //.........
};

// SETTERS_scope_resolutions
void algebra::setX(int x) { this->x = x; }
void algebra::setY(int y) { this->y = y; }
void algebra::setData(int x, int y)
{
    this->x = x;
    this->y = y;
}
void algebra::setAlgebra(algebra obj)
{
    x = obj.x;
    y = obj.y;
}

// GETTERS_scope_resolutions
int algebra::getX() const { return x; }
int algebra::getY() const { return y; }
void algebra::getData() const
{
    cout << "The value of x = " << x << endl;
    cout << "The value of y = " << y << endl;
}
algebra algebra::getAlgebra() const
{
    return *this;
}

int main()
{
    algebra obj1;
    obj1.setData(1, 2);
    obj1.getData();

    algebra obj2;
    obj2.setAlgebra(obj1);
    obj2.getData();

    obj1.getAlgebra().setX(8);
    obj1.getData();

    return 0;
}