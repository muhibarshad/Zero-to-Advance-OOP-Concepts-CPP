#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cout << "Enter the two numbers :\n";
    cin >> x >> y;
    try
    {
        if (y != 0)
            cout << "Divsion  = " << x / y << "\n";
        else
            throw y;
    }
    catch (int i)
    {
        cout << "Caught y =  " << i << " could not be be divisible\n";
    }
    return 0;
}