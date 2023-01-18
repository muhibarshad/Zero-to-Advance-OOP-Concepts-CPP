#include<iostream>

using namespace std;
class List
{
private:
    int *list = nullptr;
    int count;

public:
    List(const int &count) : count(count)
    {
        list = new int[count];
        for (int i = 0; i < count; i++)
        {
            list[i] = (rand() % (99 - 10) + 1) + 10;
        }
    }
    friend ostream &operator<<(ostream &out, const List &list)
    {
        for (int i = 0; i < list.count; i++)
        {
            out << list.list[i] << "   ";
        }
        return out;
    }
    ~List()
    {
        delete list;
    }
};
class fiveLists_
{
private:
 List* arr[5];
public:
    fiveLists_()
    {
        for(int i=0;i<5;i++)
            arr[i]=nullptr;
    }
    void addList(int listnumber,int size)
    {
        arr[listnumber]=new List{size};
    }
    void removeList(int listNumber)
    {
        delete arr[listNumber];
        arr[listNumber]=nullptr;
    }
    void show()
    {
        for(int i=0;i<5;i++)
        {
            if(arr[i]!=nullptr)
            {
                cout<<*(arr[i])<<"\n";
            }
            else
            {
                cout<<"Empty List "<<i<<"\n";
            }
        }
    }
    ~fiveLists_()
    {
           for(int i=0;i<5;i++)
        {
            if(arr[i]!=nullptr)
            {
                delete arr[i];
            }
        }
    }

};
int main()
{
  fiveLists_ list1;
  list1.addList(0,5);
  list1.addList(2,10);
  list1.addList(4,15);
  list1.removeList(2);
  list1.show();

    return 0;
}