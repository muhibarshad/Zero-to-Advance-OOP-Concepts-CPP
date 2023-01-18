// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  6:38:00
// Question : FAST University Lab2 (OOP) : Instructor=> Mam Abeeda

/*
Write a C++ program that declares and initializes a float array dynamically and finds the index of the first occurrence of the second largest element in the array.
For Example:

Input:
Please enter size: 5
Please enter elements: 1.5
7.8
3.2
9.0
7.1

Output:
Second Largest element is: 7.8
Index of second largest element is: 1

*/
#include <iostream>

using namespace std;

float largest(const float *arr, const int &size)
{
    float largest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
void secondLargest(const float *arr, const int &size)
{
    float large = largest(arr, size);
    float *temp = new float[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != large)
        {
            temp[i] = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == largest(temp, size - 1))
        {
            cout << "The second largest element = " << largest(temp, size) << "\n";
            cout << "The second largest element  index = " << i+1 << "\n";
        }
    }
    delete[] temp;
}

int main()
{
    int size = 5;
    cout << "Enter teh size \n";
    // cin >> size;
    float *arr = new float[size]{7.8,
                                 3.2,
                                 9.0,
                                 7.1};
    secondLargest(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}