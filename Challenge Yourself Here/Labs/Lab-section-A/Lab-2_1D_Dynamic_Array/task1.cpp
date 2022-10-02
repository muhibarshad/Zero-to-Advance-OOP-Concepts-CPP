// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  6:17:00
// Question : FAST University Lab2 (OOP) : Instructor=> Mam Abeeda

/*
A  C++ program “Incrementer” creates a dynamic array of size 10. This function adds 3 to each element of the array. You have to add to the elements using pointer only. Array subscript notation cannot be used.
*/

#include <iostream>

using namespace std;

void incrementer(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) += 3;
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
    int size = 10;
    int *arr = new int[size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    incrementer(arr, size);
    print(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}
