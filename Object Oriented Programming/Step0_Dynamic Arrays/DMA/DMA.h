#include<iostream>
using namespace std;

void input(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}
void output(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << endl;
    }
}