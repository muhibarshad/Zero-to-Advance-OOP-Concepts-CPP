#include <iostream>

using namespace std;

class algebra
{
private:
    int size;
    int *arr;

public:
    algebra()
    {
        size = 0;
        arr = nullptr;
    }
    algebra(int size)
    {
        this->size = size;
        if (size > 0)
        {
            arr = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                arr[i] = i + 1;
            }
        }
        else
        {
            arr = nullptr;
        }
    }
    void getData()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    // Assignment to dynamic memeory
    int &operator[](const int &i)
    {
        if (i >= 0 && i < size)
            return arr[i];
    }
    const int &operator[](const int &i) const
    {
        if (i >= 0 && i < size)
            return arr[i];
    }
};
int main()
{
    algebra a1(5);
    a1.getData();
    cout << "\n";
    a1[2] = 100;
    a1.getData();
    cout << "\n";
    cout << a1[3] << "\n";

    const algebra a2(10);
    cout << a2[9] << "\n";
    // a2[2]=100; cannot do this

    algebra *aptr = new algebra(5); // creates array inside object
    aptr[3] = 100;                  // wrong as aptr is pointer
    (*aptr)[3] = 100;               // first dereference the pointer then access data
    aptr[0][3] = 100;

    return 0;
}