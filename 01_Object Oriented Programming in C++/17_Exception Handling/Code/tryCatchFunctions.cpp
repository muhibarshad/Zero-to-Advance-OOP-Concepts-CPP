#include <iostream>

using namespace std;

float divide(float x, float y)
{
    if (y != 0)
        cout << "Divsion  = " << x / y << "\n";
    else
        throw y;
}

int main()
{
    int x, y;
    cout << "Enter the two numbers :\n";
    cin >> x >> y;
    try
    {
        divide(x, y);
    }
    catch (float i)
    {
        cout << "Caught y =  " << i << " could not be be divisible\n";
    }

        return 0;
}