#include<iostream>
using namespace std;
#include<cstring>

class Address
{
    int houseNo;
    char blockNo;
    char town[30];
    char city[30];

public:
    Address(int h, int b, char *t, char *c) // Parameterized constructor
    {
        houseNo = h;
        blockNo = b;
        strcpy(town, t); // strcpy( ) is a built - in function used
        //to copy one string(character array) to another, However, we can also define our own function.strcpy(city, c);
    }
    friend ostream &operator<<(ostream &out, const Address &a)
    {
        out << "House No:" << a.houseNo << '\n';
        out << "Block No:" << a.blockNo << '\n';
        out << "Town:" << a.town << '\n';
        out << "City:" << a.city << '\n';
        return out;
    }
};

class Employee
{
static int employeeCount; // To Assign employeeID
int employeeID;
char name[50];
Address address;
int salary;
public:
// Parameterized Constructor to initialize the Address of the employee

Employee(int s, char *n, int h, char b, char *t, char *c)
: address(h,b,t,c)
{
employeeID = employeeCount;
strcpy(n, name);
salary = s;
employeeCount++;
}
friend ostream& operator << (ostream &out, const Employee &a)
{
out << "Employee No:" << a.employeeID << '\n';
out << "Name :" << a.name << '\n';
out << "Salary:" << a.salary << '\n';
out << "Address\n" << a.address; // Calls the stream operator from Address class
return out;
}
};
int Employee :: employeeCount = 1;

int main()
{
    char name[]="Waleed";
    char town[]="Johar Town";
    char city []="Lahore";

Employee Emp_1(100000,name,46,'H',town,city);
cout<<Emp_1;
return 0;

}

