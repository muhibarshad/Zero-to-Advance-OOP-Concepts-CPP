#include <iostream>

using namespace std;

int main()
{
    int size = 5;
    int sum=0;
    
    //Allocating the memory
    int *arr = new int[size]{1,2,3,4,5};

    //sum of array
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    cout<<"The sum of all the elements in the array is = "<<sum<<endl;
    
    //Delloacting the memory
    delete[] arr;
    arr = nullptr;

    return 0;
}