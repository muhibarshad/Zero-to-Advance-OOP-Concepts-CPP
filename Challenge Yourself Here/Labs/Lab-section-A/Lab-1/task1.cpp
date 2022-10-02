// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:28:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda
/*
Write the C++ code for a function swap(), which swaps the values of two integer variables.
Note: you cannot create global variables, and cannot pass integer variables by reference in the function.
*/
#include <iostream>
void swap(int *&var1, int *&var2)
{
    int *temp = var1;
    var1 = var2;
    var2 = temp;
}
void print(int *a, int *b)
{
    std::cout << "The value of a = " << *a << "\n";
    std::cout << "The value of b = " << *b << "\n";
}
int main()
{
    int *var1 = new int{2};
    int *var2 = new int{3};

    std::cout << "Before swaping:\n";
    print(var1, var2);

    swap(var1, var2);

    std::cout << "After swaping:\n";
    print(var1, var2);

    delete var1;
    var1=nullptr;
    delete var2;
    var2=nullptr;

    return 0;
}
