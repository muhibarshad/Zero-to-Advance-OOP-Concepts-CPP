#include <iostream>

using namespace std;

class myArray
{
    int size; // Array size
    int *ptr; // Pointer for dynamic 1-D Array
public:
    myArray()
    {
        size = 0;
        ptr = nullptr;
    }
    myArray(int size);
    myArray(int *arr, int size);
    myArray(const myArray &); // copy constructor
    ~myArray();
    myArray &operator=(const myArray &); // Assignment
    int &operator[](const int i);
    const int &operator[](const int i) const;
    myArray &operator++();            // increment data of all elements
    myArray operator++(int);          // increment data of all elements
    bool operator==(const myArray &); // compare size and data of all elements
    bool operator!=(const myArray &);
    friend istream &operator>>(istream &, myArray &);       // take size and data from console
    friend ostream &operator<<(ostream &, const myArray &); // Print data of array on console
    myArray operator+(const myArray &);                     // Return array containing data of both arrays merged
    friend myArray operator+(const int, const myArray &); // add int value to all elements of array
};

