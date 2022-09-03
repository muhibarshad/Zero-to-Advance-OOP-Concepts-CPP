/*How we make the dynamic objects of class and how to access their data members of taht dynamic object🙄❓*/



#include <iostream>

using namespace std;

class algebra
{
public:
    int y;
    int x;
    int add;
};

int main()
{
    //Alloacting the memory
    algebra *sum = new algebra;

    //Arrow operaters pointing the members on the heap(->)
    sum->x = 3;
    sum->y = 4;
    sum->add = sum->x + sum->y;
    
    //Derefernce and userd the dot opearter(.)
    cout << "The sum of " << (*sum).x << " and " << (*sum).y << " = " << (*sum).add << endl;
    
    //delloacting the memory
    delete sum;
    sum=nullptr;

    return 0;
}