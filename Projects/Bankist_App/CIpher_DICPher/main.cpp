#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

void spaces()
{
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }
}
int display()
{
    spaces();
    int n;
    cout << "\t\t\tEnter 1 to Encrypt the message" << endl;
    cout << "\t\t\tEnter 2 to Decrypt the messege" << endl;
    cin >> n;
    while (n != 1 && n != 2)
    {
        cout << "Invalid Input! Enter AGAIN: ";
        cin >> n;
    }
    cout << endl;
    system("cls");
    return n;
}
void print(char *chArr, const int &size)
{
    for (int i = 0; i < size; i++)
    {
        cout << chArr[i];
    }
    cout << endl;
}
void encryptMessage(char *&chArr, int &size)
{
    char ch;
    do
    {
        ch = getch();
        char *temp = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = chArr[i];
        }
        temp[size - 1] = ch;
        temp[size] = '\0';
        size++;
        delete[] chArr;
        chArr = temp;
        system("cls");
        spaces();
        cout << "\t\t\t Enter the message:\n\n\n\t\t";

        print(chArr, size);
    } while (ch != 13);
}

int main()
{
    int event = display();
    ofstream out;
    ifstream in;
    switch (event)
    {
    case 1:
    {
        spaces();
        cout << "\t\t\t Enter the message :";
        int size = 1;
        int code;
        char *chArr = new char[size]{'\0'};
        encryptMessage(chArr, size);
        spaces();
        cout << "\t\t\t Enter your encrepted code :\n\t\t\t";
        cin >> code;

        cout << "\t\t\t Encrpyting......\n";
        out.open("encrypted.txt");
        for (int i = 0; i < size; i++)
        {
            char temp=chArr[i] + ((987%89)*700)%34+56;
            out << temp;
        }

        // Sleep(3 * 1000);
        system("cls");
        spaces();
        cout << "\t\t\t Your Message encrypted Successfully.\n";
        break;
    }
    case 2:
    {
        break;
    }
    }

    return 0;
}