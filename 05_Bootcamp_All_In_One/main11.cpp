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
    void input(const int &size)
    {
        file.open("student.txt", ios::out | ios::app);
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

            file << name << "\n";
            file << age << "\n";
            file << rollNo << "\n";
        }

        file.close();
    }
    void output(const int &size)
    {
        file.open("student.txt", ios::in);
        if (!file)
        {
            cout << "File Error";
            exit(0);
        }
        for (int i = 0; i < size; i++)
        {
            getline(file, name);
            file >> age;
            file.ignore();
            getline(file, rollNo);
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
    Student st;
    // st.input(3);
    // st.output(3);

    return 0;
}