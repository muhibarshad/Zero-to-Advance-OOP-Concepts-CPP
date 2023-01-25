#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    string name;
    int age;
    string rollNo;
    fstream file;

public:
    Student(string name = "", int age = 0, string rollNo = "") : name(name), age(age), rollNo(rollNo)
    {
        cout << "Cons of Student\n";
    }
    void input(Student *arr, const int &size)
    {
        file.open("student.txt", ios::binary | ios ::app);
        if (!file)
        {
            cout << "File Error";
            exit(0);
        }
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the name of the student :" << i + 1 << "\n";
            getline(cin, name);
            cout << "Enter the age of the student :" << i + 1 << "\n";
            cin >> age;
            cout << "Enter the roll no of the student :" << i + 1 << "\n";
            cin.ignore();
            getline(cin, rollNo);

            file.write(reinterpret_cast<char *>(this), sizeof(*this));
        }

        file.close();
    }
    void output(const int &size)
    {
        file.open("student.txt", ios::binary | ios::in);
        if (!file)
        {
            cout << "File Error";
            exit(0);
        }
        for (int i = 0; i < size; i++)
        {
            file.read(reinterpret_cast<char *>(this), sizeof(*this));
            cout << "The name of the student : " << name << "\n";
            cout << "The age of the student : " << age << "\n";
            cout << "The roll no of the student : " << rollNo << "\n";
        }

        file.close();
    }

    ~Student()
    {
        cout << "Des of Student \n";
    }
};
int main()
{
    return 0;
}