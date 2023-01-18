#include <iostream>

using namespace std;

class List
{
private:
    int *list=nullptr;
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
    friend ostream& operator <<(ostream& out,const List& list )
    {
        out<<"The elements in the List :\n";
        for(int i=0;i<list.count;i++)
        {
            out<<list.list[i]<<"\n";
        }
        return out;
    }
    ~List()
    {
        delete list;
    }
};
int main()
{
    List list1(10);
    cout<<list1;
    return 0;
}