/*Write a C++ program  in which convert an array to even array*/
#include <iostream>
#include "DMA.h"

using namespace std;

int *even(int *arr, int &size)
{
    int evenSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
            evenSize++;
    }
    int *temp = new int[evenSize];
    int loc = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(temp + loc) = *(arr + i);
            loc++;
        }
    }
    delete[] arr;
    size = evenSize;
    return temp;
}
int main()
{
    int size = 0, evenSize = 0;
    cout << "Enter the size of the array:" << endl;
    cin >> size;

    int *arr = new int[size];
    input(arr, size);
    output(arr, size);

    arr = even(arr, size);
    cout << "The even Elements in the array are given as :" << endl;
    output(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}