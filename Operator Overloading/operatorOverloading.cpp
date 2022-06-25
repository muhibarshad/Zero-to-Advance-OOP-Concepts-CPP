
#include <iostream>
using namespace std;
class add
{
private:
    int num1;

public:
    add(int n = 0)
    {
        num1 = n;
    }

    // //==============================================
    // // Tridational approach
    // //==============================================
    // add sum(add num)
    // {
    //     add temp;
    //     temp.num1 = num1 + num.num1;
    //     return temp;
    // }

    // //==============================================
    // // Operater Overloading
    // //==============================================
    // add operator +(add num)
    // {
    //     add temp;
    //     temp.num1 = num1 + num.num1;
    //     return temp;
    // }

    void printSum();

    ~add()
    {
        cout << "Destructor has been called:" << endl;
    }
};

void add::printSum()
{
    cout << "The sum of these two = " << num1 << endl;
}

int main()
{
    add n1(2);
    add n2(2);
    add total;

    // //==============================================
    // // Tridational approach
    // //==============================================
    // total = n1.sum(n2);
    // total = n2.sum(n1);
    // total.printSum();

    // //==============================================
    // // Operater overloading
    // //==============================================
    //  total = n1 + n2;
    //  total.printSum();

    return 0;
}