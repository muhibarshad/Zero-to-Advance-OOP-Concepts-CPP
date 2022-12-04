/*modes to open
  ios::in,
  ios::out,
  ios::ate,
  ios::app,
  ios::binary
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class File
{
    string _fileAddress;

protected:
    fstream _file;

public:
    File(string file = "") : _fileAddress(file) {}
    void setFile()
    {
        string file;
        cout << "Enter the address of the record file :\n";
        cin >> file;
        this->_fileAddress = file;
    }
    void writeInFile()
    {
        _file.open(_fileAddress, ios::out | ios::app);
        try
        {
            if (!_file)
                throw "File Error :\n";
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            exit(0);
        }
        cout << " File opened Successfully in Write mode :\n";
    }
    void readFromFile()
    {
        _file.open(_fileAddress, ios::in);
        try
        {
            if (!_file)
                throw "File Error :\n";
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            exit(0);
        }
        cout << " File opened Successfully in Read mode :\n";
    }
    string getFileAddress() const
    {
        return _fileAddress;
    }
    int numberOfRecords() const
    {
        int number;
        cout << "How many records want to enter ?\n";
        cin >> number;
        return number;
    }
    ~File() { cout << "Des. of file\n"; }
};
class StudentRecord : public File
{
    string _name;
    string _CNIC;
    string _department;
    int _age;

public:
    StudentRecord()
    {
        setFile();
        fileMode();
    }
    StudentRecord(string fileAddress) : File(fileAddress) {}
    StudentRecord(string fileAddress, string name = "", string CNIC = "",
                  int age = 0,
                  string department = "") : File(fileAddress), _name(name), _CNIC(CNIC), _age(age), _department(department)
    {
        setFile();
        fileMode();
    }
    ~StudentRecord()
    {
        cout << "Des. of Student Record:\n";
    }
    void fileMode()
    {
        int n;
        do
        {
            cout << "Are you want to Write or read the file :\n";
            cout << "Enter 1 For to open in write mode :\n";
            cout << "Enter 2 For to open in read mode:\n";
            cout << "Enter 0 to exit:\n";
            cin >> n;
            switch (n)
            {
            case 1:
            {
                writeInFile();
                writeRecords();
                _file.close();
                break;
            }
            case 2:
            {
                readFromFile();
                readRecords();
                _file.close();
                break;
            }
            case 0:
            {
                cout << "Exit Successfully\n";
                break;
            }
            default:
            {
                cout << "Error : Wrong Input\n";
                break;
            }
            }
        } while (n != 0);
    }
    void writeRecords()
    {
        int size = numberOfRecords();
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the Record number " << i + 1 << ":\n";
            cout << "Enter the name of the Student :\n";
            cin.ignore();
            getline(cin, _name);
            cout << "Enter the CNIC of the Student : \n";
            getline(cin, _CNIC);
            cout << "Enter the Department of the Student : \n";
            getline(cin, _department);
            cout << "Enter the age of the Student : \n";
            cin >> _age;

            _file << _name << "\n"
                  << _CNIC << "\n"
                  << _department << "\n"
                  << _age << "\n\n";
        }
    }
    void readRecords()
    {
        getline(_file, _name);
        getline(_file, _CNIC);
        getline(_file, _department);
        _file >> _age;
        _file.ignore();
        _file.ignore();
        int n = 1;
        while (!_file.eof())
        {

            cout << "---------RECORD OF THE STUDENT  " << n << " --------------\n";

            cout << "The name of the student = " << _name << "\n";
            cout << "The CNIC of the student = " << _CNIC << "\n";
            cout << "The department of the student = " << _department << "\n";
            cout << "The age of the student = " << _age << "\n\n";
            getline(_file, _name);
            getline(_file, _CNIC);
            getline(_file, _department);
            _file >> _age;
            _file.ignore();
            _file.ignore();

            n++;
        }
    }
};

int main()
{
    StudentRecord record;

    return 0;
}