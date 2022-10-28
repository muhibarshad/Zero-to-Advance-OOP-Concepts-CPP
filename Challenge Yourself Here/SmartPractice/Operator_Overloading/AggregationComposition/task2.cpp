#include <iostream>

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
class fiveLists
{
private:
    List *five[5];

public:
    fiveLists()
    {
        for (int i = 0; i < 5; i++)
            five[i] = new List{(rand() % (5 - 10) + 1) + 5};
    }
    void show()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << *(five[i]) << "\n";
        }
    }
    ~fiveLists()
    {
        for (int i = 0; i < 5; i++)
            delete five[i];
    }
};
int main()
{
    fiveLists l;
    l.show();
    return 0;
}