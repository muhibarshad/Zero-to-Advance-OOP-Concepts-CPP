#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    string name;
    int age;

    ifstream fin("test.txt");
    // ifstream fin("test.txt",ios::in);
    try
    {
        if (!fin)
            throw "File Error :File not foundn\n";
    }
    catch (const char *msg)
    {
        cout << msg << "\n";
        exit(0);
    }
    fin >> name >> age;
    do
    {
        cout << name << " \t " << age << endl;
        fin >> name >> age;
    } while (!fin.eof());

    fin.close();
    return 0;
}