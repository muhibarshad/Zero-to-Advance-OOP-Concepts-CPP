#include <iostream>
using namespace std;
class increment
{
private:
    int num;

public:
    increment(int n = 0)
    {
        num = n;
    }
    void input()
    {
        cout << "Enter the number that you want to incrment:" << endl;
        cin >> num;
    }
    //==============================================
    // Pre-Increment
    //==============================================
    void operator ++()
    {
          ++num;
    }
    //==============================================
    // Post-Increment
    //==============================================
    void operator ++(int)
    {
        num++;
    }
    void output()
    {
        cout << "The number after the 1 increment is :";
        cout << num << endl;
    }
    ~increment()
    {
        cout << "Destructor has been Called:" << endl;
    }
};
int main()
{
    increment num1;
    num1.input();
    //==============================================
    // Pre-Increment
    //==============================================
    ++num1;
    num1.output();
    //==============================================
    // Post-Increment
    //==============================================
    num1++;
    num1.output();

    return 0;
}