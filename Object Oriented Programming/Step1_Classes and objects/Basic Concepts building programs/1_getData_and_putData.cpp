
/*Write a C++ program how to putData into dataMembers of a class that is private and getData from them
 */
#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
    float z;

public:
    void putData(int xA, int yA, int zA)
    {
        x = xA;
        y = yA;
        z = zA;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
        cout<<"The value of z = "<<z<<endl;
    }
};

int main()
{
    algebra equation1;
    
    //Test 01:
    equation1.putData(1,2,3);
    equation1.getData();
    

    return 0;
}