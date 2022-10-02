// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:31:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda
/*
⦁	Introduce 2 variables i (int), j (float) and initialize to 5, 1.5 respectively.
⦁	Introduce 2 variables xPtr (int*), yPtr (float*) and assign address of i, j respectively.
⦁	Print values of i, j and addresses in xPtr, yPtr.
⦁	xPtr ++;  yPtr ++;
⦁	Print addresses in xPtr,yPtr.
⦁	xPtr --; yPtr --;
⦁	Print addresses in xPtr, yPtr.
⦁	xPtr = xPtr + 3; yPtr = yPtr + 4;
⦁	Print addresses in xPtr, yPtr.

*/

#include <iostream>
using namespace std;
int main()
{
    int i = 5;
    float j = 1.5;
    int *xPtr = &i;
    float *yPtr = &j;
    cout << "i = " << i << "\n";
    cout << "j = " << j << "\n";
    cout << "xPtr = " << xPtr << "\n";
    cout << "yPtr = " << yPtr << "\n";
    xPtr++;
    yPtr++;
    cout << "xPtr = " << xPtr << "\n";
    cout << "yPtr = " << yPtr << "\n";
    xPtr--;
    yPtr--;
    cout << "xPtr = " << xPtr << "\n";
    cout << "yPtr = " << yPtr << "\n";
    xPtr = xPtr + 3;
    yPtr = yPtr + 4;
    cout << "xPtr = " << xPtr << "\n";
    cout << "yPtr = " << yPtr << "\n";

    return 0;
}