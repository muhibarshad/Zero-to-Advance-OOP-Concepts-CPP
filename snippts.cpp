#include <iostream>
using namespace std;
int main()
{

    int size = 5;
    int *arr = new int[size]{1, 2, 3, 4, 5};

    int num;
    cout << "Enter the number how much size of array you wnat to cahnge :" << endl;
    cin >> num;

    int *temp = new int[size + num];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }

    //deleting the previous array
    delete[] arr;
    arr=temp;
    
    //giving values to increased indexs
    for(int i=size;i<size+num;i++){
        cin>>arr[i];
    }
    size+=num;

    delete[] arr;
    arr=nullptr;

    return 0;
}