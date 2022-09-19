/*Write a function that doubles an array by duplicating items in the array and 
returns doubled array. This function will not change the original array, make careful selection of 
function parameters.
For example:
Original array: {4,2,1,9,1,3,6}
Doubled array: {4,4,2,2,1,1,9,9,1,1,3,3,6,6}
The above is a special case of a procedure called up sampling, where you are increasing the 
number of samples in a signal
*/
#include <iostream>
#include "DMA.h"

int *doublingArray(const int *arr, const int size, int &doubleSize)
{
    doubleSize = size * 2;
    int *temp = new int[doubleSize]{0};
    for (int i = 0, j = 0; i < doubleSize;i++, j++)
    {
        temp[i] = arr[j];
        temp[++i] = arr[j];
    }
    return temp;
}

int main()
{
    int size = 10;
    int *arr;
    dma::allocateMemory(arr, size);
    dma::input(arr, size);
    dma::output(arr, size);

    int doubleSize = 0;
    int *doubleArr = doublingArray(arr, size, doubleSize);
    dma::output(doubleArr, doubleSize);

    dma::deallocateMemory(arr);
    dma::deallocateMemory(doubleArr);

    return 0;
}