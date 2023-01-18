#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string name;
    int age;

    ofstream fout("test.txt");
    // ofstream fout("test.txt",ios::out);
    try
    {
        if (!fout)
            throw "File Error!:404 File not Found";
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        exit(0);
    }
    while (cin >> name >> age)
    {
        fout << name << "\t" << age << endl;
    }
    fout.close();

    return 0;
}