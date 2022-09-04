// Write a C++ program to in which make a copy of an array whose elements contain only the even elements of the array.
#include <iostream>
#include "DMA.h"

using namespace std;

int *even(int *arr, int size, int &sizeOfeven)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
            sizeOfeven++;
    }
    cout << "The size of even = " << sizeOfeven << endl;
    int *temp = new int[sizeOfeven];
    int loc = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(temp + loc) = *(arr + i);
            loc++;
        }
    }

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

    int *Even = even(arr, size, evenSize);
    cout << "The even Elements in the array are given as :" << endl;
    output(Even, evenSize);

    delete[] arr;
    delete[] Even;
    arr = nullptr;
    Even = nullptr;

    return 0;
}