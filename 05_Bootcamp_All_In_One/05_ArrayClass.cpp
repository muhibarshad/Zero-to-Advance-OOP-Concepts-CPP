#include <iostream>

using namespace std;

class Array
{
    int *arr;
    int size;

public:
    Array(int size = 0) : size(size)
    {
        arr = new int[size];
        cin >> *this;
        cout << *this;
    }
    Array(const Array &obj) : size(obj.size)
    {
        arr = new int[obj.size];
        for (int i = 0; i < size; i++)
            arr[i] = obj.arr[i];
        cout << *this;
    }
    Array &operator=(const Array &obj)
    {
        if (&obj != this)
        {
            if (size != obj.size)
            {
                size = obj.size;
                delete[] arr;
                arr = new int[size];
            }
            for (int i = 0; i < size; i++)
                arr[i] = obj.arr[i];
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Array &obj)
    {
        cout << "The entries in the array = \n";
        for (int i = 0; i < obj.size; i++)
            out << obj.arr[i] << "\n";
        return out;
    }
    friend istream &operator>>(istream &in, Array &obj)
    {
        cout << "Enter the entries in the array = \n";
        for (int i = 0; i < obj.size; i++)
            in >> obj.arr[i];
        return in;
    }
    int operator[](const int &index) const
    {
        if (index >= 0 && index < size)
            return arr[index];
        exit(0);
    }
    int &operator[](const int &index)
    {
        if (index >= 0 && index < size)
            return arr[index];
        exit(0);
    }
    ~Array()
    {
        delete[] arr;
    }
};
int main()
{
    Array arr(3);
    arr[2] = 100;
    cout << arr[2] << "\n";
    cout << arr;

    return 0;
}