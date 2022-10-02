// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:28:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda
/*Given two integers x and y, find their sum using pointers.
 */

#include <iostream>
int main()
{
    int *x =new int{2};
    int *y = new int{3};
    std::cout << "Thier sum = " << (*x+*y) << "\n";

    delete x;
    x=nullptr;
    delete y;
    y=nullptr;
    return 0;
}