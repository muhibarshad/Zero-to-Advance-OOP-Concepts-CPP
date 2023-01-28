#include <iostream>

using namespace std;

class Student
{
    string name = "Student";
    int age;
    const int id;

public:
    static int x;
    Student(int age, string name, int id) : age(age), name(name), id(id)
    {
    }
    Student(const Student &obj) : name(obj.name), age(obj.age), id(obj.id)
    {
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName() const
    {
        return name;
    }
    void print() const;
    ~Student()
    {
        cout << "Des of class\n";
    }
    static void printarray(const Student arr[], const int &size)
    {
        for (int i = 0; i < 3; i++)
            arr[i].print();
    }
    static void createObj()
    {
        if (x <= 3)
        {
            cout << "Object created\n";
            x++;
        }
    }
    
    

};
int Student::x = 0;
void Student::print() const
{
    cout << name << "\n";
    cout << age << "\n";
    cout << id << "\n";
}
int main()
{
    

    // Student obj(2, "Muhib", 6);
    // Student ob2(22, "Ali", 68);
    // obj.createObj();
    // Student::createObj();
    // ob2.createObj();
    // obj.createObj();
    // obj.createObj();
    // // // Student arr[3] = {Student(), Student("muhib", 3), Student(arr[1])};
    // // // Student::printarray(arr, 3);
    // // Student obj(20, "Muhib", 88);
    // // obj.print();
    // // cout << Student::x << "\n";
    // // // Student obj2 = obj;
    // // // obj2 = obj;
    // // // int x = 9;
    // // // int *ptr = &x;
    // // // cout << x << "\n";
    // // // cout << &x << "\n";
    // // // cout << ptr << "\n";
    // // // cout << *ptr << "\n";
    // // // cout << &ptr << "\n";
    // // // int *ptr = new int;
    // // // delete ptr;
    // // // ptr = nullptr;
    // // // cin >> *ptr;
    // // // cout << *ptr << "\n";
    // // // cout << ptr << "\n";
    // // // delete ptr;
    // // // cout << ptr << "\n";
    // // // cout << *ptr << "\n";
    // return 0;
}