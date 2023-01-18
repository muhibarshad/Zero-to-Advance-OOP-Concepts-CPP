//@muhib7353
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

// Global Variables
ofstream out;
ifstream in;

// Function_ProtoTypes
void spaces();
char display();
void CIPHER_DICHPER();
void backSpace(char *&, int &);
void print(char *, const int &);
void gettingMessage(char *&, int &);
void writting(char *&, int &, const char &);
void encrptingMessage(char *, const int &);

// MAIN
int main()
{
    CIPHER_DICHPER();
    return 0;
}
//================================================
//****************USER_INTERFACE******************
//================================================
void spaces()
{
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }
}
char display()
{
    spaces();
    char ch;
    cout << "\t\t\tPress \'e\' to Encrypt the message" << endl;
    cout << "\t\t\tEnter \'d\' to Decrypt the messege" << endl;
    cout << "\t\t\tEnter \'q\' to exit" << endl;
    ch = getch();
    ch = tolower(ch);
    while (ch != 'e' && ch != 'd' && ch != 'q')
    {
        cout << "Invalid Input! Enter AGAIN: ";
        ch = getch();
        ch = tolower(ch);
    }
    system("cls");
    return ch;
}
void print(char *chArr, const int &size)
{
    for (int i = 0; i < size; i++)
    {
        cout << chArr[i];
    }
    cout << endl;
}

//================================================
//******************ENCRYPTION********************
//================================================
// Bacspace_and_input_Functionality
void backSpace(char *&chArr, int &size)
{
    if (size >= 0)
    {
        char *temp = new char[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = chArr[i];
        }
        temp[size - 2] = '\0';
        size--;
        delete[] chArr;
        chArr = temp;
    }
}
void writting(char *&chArr, int &size, const char &ch)
{
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
}

// WritingMessage _and_ EncrytingMessage
void gettingMessage(char *&chArr, int &size)
{
    char ch;
    spaces();
    cout << "\t\tEnter the message that you want to encrypt:\n\n\t\t";
    do
    {
        ch = getch();
        if (ch == 8)
        {
            backSpace(chArr, size);
        }
        if (ch >= 32 && ch <= 126)
        {
            writting(chArr, size, ch);
        }
        system("cls");
        spaces();
        cout << "\t\tEnter the message that you want to encrypt:\n\n\t\t";
        print(chArr, size);

    } while (ch != 13);
}
void encrptingMessage(char *chArr, const int &size)
{
    int code;
    int randomPin = (rand() % 99) + 1;
    char codeStr;
    char pinStr;
    cout << "\n\t\tSet your  3 digit encrepted code :\n\n\t\t";
    cin >> code;
    while (code <= 0 || code > 999)
    {
        cout << "\n\t\tInvaid code limit : Please enter the 3 didgit code\n";
        cin >> code;
    }
    cout << "\n\t\t\t Encrpyting......\n";
    out.open("encrypted.txt");
    pinStr = randomPin + 200;
    codeStr = 143 + (code - randomPin);
    out << pinStr << codeStr;
    for (int i = 0; i < size; i++)
    {
        char temp = (chArr[i] - randomPin) + code;
        out << temp;
    }
    out.close();

    Sleep(3 * 1000);
    system("cls");
    spaces();
    cout << "\t\t\t Your Message encrypted Successfully.\n";
    CIPHER_DICHPER();
}

//================================================
//******************DECRYPTION********************
//================================================
void Decrption()
{
    system("cls");
    spaces();
    string path;
    int code = 0;
    char codeStr;
    char codePin;
    int attempts = 3;
    bool flag = false;

    cout << "\t\t Paste the file path whose is to be decrepted\n\n\t\t";
    getline(cin, path);
    in.open(path);
    spaces();
    cout << "\t\t The ecrypted message is here:\n\n\t\t";
    while (!in.eof())
    {
        char ch;
        in >> ch;
        cout << ch;
    }
    in.close();

    in.open(path);
    for (int i = 0; i < 2; i++)
    {
        char temp;
        in >> temp;
        i == 0 ? codePin = temp : codeStr = temp;
    }
    codePin = codePin - 200;
    codeStr = (codeStr - 143) + codePin;
    // cout << static_cast<int>(codeStr) << "\n";
    in.close();

    do
    {
        cout << "\n\n\t\t Enter the code to decrypt it:\n\n\t\t";
        cin >> code;
        attempts--;

        // if (code == static_cast<int>(codeStr))
        // {
            in.open(path);
            cout << "\t\t";
            for (int i = 0; !in.eof(); i++)
            {
                char ch;
                in >> ch;
                if (i >= 2)
                {
                    ch = (ch + codePin) - codeStr;
                    cout << ch;
                }
            }
            in.close();
            flag = true;
        // }
        // else
        // {
        //     cout << "\t\t Error: Code is wrong : Try Again( " << attempts << " Attempts Left)\n";
        // }

        if (attempts == 0)
        {
            flag = true;
            cout << "\t\t You are a cheater! Go out.\n";
        }
        cin.ignore();
    } while (flag == false);
    CIPHER_DICHPER();
}

// HeartEngine_ofProgram
void CIPHER_DICHPER()
{
    char event = display();
    switch (event)
    {
    case 'e':
    {
        int size = 1;
        char *chArr = new char[size]{'\0'};
        gettingMessage(chArr, size);
        encrptingMessage(chArr, size);
        break;
    }
    case 'd':
    {
        Decrption();
        break;
    }
    case 'q':
    {
        cout << "Quiting..........";
        Sleep(3 * 1000);
        spaces();
        system("cls");
        cout << "\t\t\t Follow us at Github @muhib7353 \n";
        break;
    }
    }
}
