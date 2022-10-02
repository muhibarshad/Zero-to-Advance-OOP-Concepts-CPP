// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:38:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda
/*
What is wrong with the following code?
double *firstPtr = new double; //Line 1
double *nextPtr = new double; //Line 2
*firstPtr = 62; //Line 3
nextPtr = firstPtr; //Line 4
delete firstPtr; //Line 5
delete nextPtr; //Line 6
firstPtr = new double; //Line 7
*firstPtr = 28; //Line 8
cout << *firstPtr << " " << *nextPtr << endl; //Line 9

*/

#include <iostream>
using namespace std;
int main()
{

    double *firstPtr = new double; // Line 1
    double *nextPtr = new double;  // Line 2
    *firstPtr = 62;                // Line 3
    nextPtr = firstPtr;            // Line 4
    delete firstPtr;               // Line 5
    firstPtr = nullptr;
    delete nextPtr;
    nextPtr = nullptr;                            // Line 6
    firstPtr = new double;                        // Line 7
    *firstPtr = 28;                               // Line 8
    nextPtr = firstPtr;                           // Line 4
    cout << *firstPtr << " " << *nextPtr << endl; // Line 9
    delete firstPtr;                              // Line 5
    firstPtr = nullptr;
    delete nextPtr;
    nextPtr = nullptr;

    return 0;
}
