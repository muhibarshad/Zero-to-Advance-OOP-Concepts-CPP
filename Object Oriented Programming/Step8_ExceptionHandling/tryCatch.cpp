#include <iostream>

using namespace std;

int main()
{
    cout << "Code start here\n";
    try
    {
        cout << "First line executed:\n";
        throw 90;
        cout << "This line cannot be executed due to incedently throwing an error\n";
    }
    catch (double i)
    {
        cout << "The execption of line " << i << " can be executed\n";
    }
    cout << "Code ends here\n";
    return 0;
}