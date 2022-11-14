#include <iostream>

using namespace std;

class Array
{
private:
    int *arr;
    int size;

public:
    Array()
    {
        size = 1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const int &size) : size{size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    // PARAMETERIZED_CONSTRUCTOR
    Array(const int &size, const int _arr[]) : size{size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = _arr[i];
        }
    }
    // COPY_CONSTRUCTOR
    Array(const Array &obj) : size{obj.size}
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    // OVERLOADED_ASSIGNMENT OPERATOR
    Array operator=(const Array &obj)
    {
        if (&obj != this)
        {
            size = obj.size;
            delete[] arr;
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    // OVERLOADED _SUBSCRIPT OPERATOR(For the R-value)
    int operator[](const int &index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        cout << "Array Index is Out-of-Bound" << endl;

        exit(0);
    }
    // OVERLOADED _SUBSCRIPT OPERATOR(For the L-value and R-value)
    int &operator[](const int &index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        cout << "Array Index is Out-of-Bound" << endl;

        exit(0);
    }

    void putData()
    {
        cout << "Put the data in the all array elements of size " << size << ": \n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void getData()
    {
        cout << "The data in the all array elements of size " << size << ": \n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\n";
        }
    }
    ~Array()
    {
        delete[] arr;
    }
};
int main()
{
    int a[5] = {5, 4, 3, 2, 1};

    Array obj1, obj2(7), obj3(5, a), obj4(obj3);
    const Array objc(5, a);

    obj4[3] = 9;

    cout << obj4[3] << endl;

    cout << objc[4] << endl;
    return 0;
}