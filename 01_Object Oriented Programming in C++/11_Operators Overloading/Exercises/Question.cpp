
// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  16:28:00
// Question : @Abdul Amteen PUCIT ptrofessor Assignemnt Operator Overloading
/*
. Class MyList discussed in today's class (code is already shared). Overload following operators:
. Equality Operator [==, compare two list, if both lists have same size and same elements at
corresponding positions return true, otherwise return false
. Non Equality Operator [!=, compare two list, if both lists have same size and same elements at
corresponding positions return false, otherwise return true
. Binary plus equal operator [+=, add elements of second list at the end of first list, so that first list will
contain elements of both first and second list. Check if size of first list is large enough to contain
elements of first list as well as second list then simply add elements at the end, otherwise first
increase size of first list then add elements of second list
Write member function to:
. sort elements & return current object
. find element & return true or false
. elementAt, return element existing at index (passed as parameter), assume index is smaller than
current size
. positionOf, return index of element (element is passed as parameter), assume element exist in the
list, therefore match all elements and return index of matching element
*/
#include <iostream>

using namespace std;

class MyList
{
private:
    int size;
    int *myList;

public:
    MyList(int size = 0)
    {
        setSize(size);
        myList = new int[size];
    }
    void setSize(int size)
    {
        this->size = size;
    }
    void setArrayElement(int *MyList, const int &index, const int &element)
    {
        myList[index] = element;
    }
    void setArray()
    {
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                cin >> myList[i];
            }
        }
        else
        {
            cout << "Fisrt size of the array atleat one:\n";
        }
    }
    int getSize() const
    {
        return size;
    }
    void getArray()
    {
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                cout << myList[i] << "\n";
            }
        }
        else
        {
            cout << "Fisrt set size of the array at least one:\n";
        }
    }
    ~MyList()
    {
        delete[] myList;
        myList = nullptr;
    }
    bool operator==(const MyList &obj) const
    {
        bool flag = true;

        if (size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (myList[i] != obj.myList[i])
                {
                    cout << myList[i] << "\n";
                    flag = false;
                }
            }
        }
        return flag;
    }
    bool operator!=(const MyList &obj) const
    {
      return !(operator==(obj));
    }
};
int main()
{
    MyList list1, list2;
    list1.setSize(1);
    list2.setSize(1);
    list1.setArray();
    list2.setArray();
    cout << (list2 == list1) << "\n";
    cout << (list2 != list1) << "\n";

    return 0;
}