// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  6:54:00
// Question : FAST University Lab2 (OOP) : Instructor=> Mam Abeeda

/*
⦁	Exercise 1 [Input Array]:
Write a function int* InputArray(int& size) that asks user to enter size of required array, allocates the memory on heap, takes input in array and returns its pointer.
⦁	Exercise 2 [Output Array]:
Write a program void OutputArray(int* myArray, const int& size) that takes a pointer to an integer array and prints its data.
Write main function to test above functionality.
⦁	Exercise 3 [Compress Array]:
Write a function int* CompressArray(int* oiginalArr, int& size) that takes a sorted array and removes duplicate elements from this array.
Sample Run:
Input:
Enter Size of array: 10
Enter 10 elements: 1 2 2 2 3 3 3 3 3 7
Output
Array after Compression: 1 2 3 7

Your function will compress the original array, allocate new array of compressed size (compressed size is 4 in above example) on heap, copy updated array in new array and return the new array.
Take input from user by calling int* InputArray(int& size) (function you implemented in Exercise 1). Call CompressArray, call OutputArray(function you implemented in Exercise 2) to display the final output.
*/

#include <iostream>

using namespace std;

void input(int *arr, const int &size)
{
    cout << "Enter the elements in the array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}
void increasingArray(int *&arr, int &size)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
}
void compressingArray(int *&arr, int &size)
{
    int tempSize = 0;
    bool flag = false;
    int *temp = new int[tempSize];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j+1])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            increasingArray(temp, tempSize);
            temp[tempSize-1] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    size = tempSize;
}

void output(const int *arr, const int &size)
{
    cout << "The elements in the array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << "\n";
    }
}
int main()
{
    int size;
    cout << "Enter the size of the array = ";
    cin >> size;
    int *arr = new int[size];
    input(arr, size);
    compressingArray(arr, size);
    output(arr, size);

    return 0;
}