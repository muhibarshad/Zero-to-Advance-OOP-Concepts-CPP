#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class File
{
    string fileName;

protected:
    fstream file;

public:
    File()
    {
        cout << "Cons file\n";
    }
    void getFileName()
    {
        cout << "Enter the Address of the File :\n";
        cin >> fileName;
    }
    void openFile()
    {
        file.open(fileName, ios::binary | ios::in);
        try
        {
            if (!file)
            {
                throw "File Not Found\n";
            }
        }
        catch (const char *msg)
        {
            cout << msg << "\n";
            exit(0);
        }
        cout << "File opened Successfully\n";
    }
    ~File()
    {
        cout << "Des file\n";
    }
};

class Encryption : public File
{

    char *msg;
    int password;

public:
    Encryption() : File()
    {
        getFileName();
        menu();
        cout << "Enc Cons. \n";
    }
    void encryptedMsg()
    {
        cin.ignore();
        cout << "Enter the encrypted message\n";
        // getline(cin, msg);
        cin>>msg;
        cout << "Enter the password:\n";
        cin >> password;
    }
    void storingData()
    {
        // file.write(reinterpret_cast<char *>(&password), sizeof(int));
        file.write(reinterpret_cast<char *>(&msg), sizeof(string));
        cout << "Data_Encrypted Successfully\n";
        file.close();
    }
    void readingData()
    {
        // file.read(reinterpret_cast<char *>(&password), sizeof(int));
        file.read(reinterpret_cast<char *>(&msg),32);
        // cout << "The password = " << password << "\n";
        cout << "The Message = " << msg << "\n";
        file.close();
    }
    void menu()
    {
        openFile();
        int n;
        cout << "Enter 1 to Encrypt the Message:\n";
        cout << "Enter 2 to Decrypt  the Message:\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            encryptedMsg();
            storingData();
            break;
        }
        case 2:
        {
            readingData();
            break;
        }

        default:
            break;
        }
    }

    ~Encryption()
    {
        cout << "Enc Des. \n";
    }
};
int main()
{
    Encryption obj;
    return 0;
}