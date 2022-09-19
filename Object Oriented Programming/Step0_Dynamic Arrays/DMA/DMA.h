#include <iostream>
namespace dma
{
    void allocateMemory(int *&arr, int size)
    {
        arr = new int[size];
    }

    void deallocateMemory(int *&arr)
    {
        delete[] arr;
        arr = nullptr;
    }

    void input(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = (rand() % 10) + 1;
            // cin >> *(arr + i);
        }
    }

    void output(const int *arr, const int size)
    {
        std::cout << "The elements in the array :"
                  << "\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

};
