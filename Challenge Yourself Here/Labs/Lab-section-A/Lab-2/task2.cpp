// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  6:25:00
// Question : FAST University Lab2 (OOP) : Instructor=> Mam Abeeda

/*
Fibonacci sequence is a sequence in which every number after the first two is the sum of the two preceding ones. Write a C++ program that takes a number n from user that is size and populate a dynamic array with first n Fibonacci numbers. De-allocation is also required.
For example:
For n=10
Fibonacci Numbers: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

*/
#include <iostream>

using namespace std;

void fibonacci(int *arr, const int size)
{
    *(arr - 1) = 0;
    *(arr) = 1;
    for (int i = 1; i < size; i++)
    {
        *(arr + i) = *(arr + (i - 1)) + *(arr + (i - 2));
    }
}
void print(const int *arr, const int size)
{
    cout << "The elements in the array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << "\n";
    }
}
int main()
{
    int n;
    cout << "Enter the n :";
    cin >> n;
    int *fibonaci = new int[n];
    fibonacci(fibonaci, n);
    print(fibonaci, n);

    delete[] fibonaci;
    fibonaci = nullptr;

    return 0;
}