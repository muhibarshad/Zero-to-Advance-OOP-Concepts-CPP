#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

class account
{
private:
    string name;
    string userName;
    int size;
    int pin;
    double *movements = new double[size];
    double totalBalance;
    double income;
    double outcome;
    double interest;
    bool sort;

public:
    // default constructor
    account()
    {
        name = "";
        userName = "";
        pin = 0;
        size=0;
        totalBalance = 0.0;
        income = 0.0;
        outcome = 0.0;
        interest = 0.0;
        sort = false;
        movements = nullptr;
    }
    // parameterized constructor
    account(string name, string userName, int pin,int size, double totalBalance, double income, double outcome, double interest, bool sort, double *movements)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size=size;
        this->totalBalance = totalBalance;
        this->income = income;
        this->outcome = outcome;
        this->interest = interest;
        this->sort = sort;
        this->movements = movements;
    }
    // copy constructor
    account(const account &temp)
    {
        name = temp.name;
        userName = temp.userName;
        pin = temp.pin;
        size=temp.size;
        totalBalance = temp.totalBalance;
        income = temp.income;
        outcome = temp.outcome;
        interest = temp.interest;
        sort = temp.sort;
        movements = temp.movements;
    }
    // setters
    void setName(string name) { this->name = name; }
    void setUserName(string userName) { this->userName = userName; }
    void setPin(int pin) { this->pin = pin; }
    void setSize(int size) { this->size = size; }
    void setTotalBalance(double totalBalance) { this->totalBalance = totalBalance; }
    void setIncome(double income) { this->income = income; }
    void setOutcome(double outcome) { this->outcome = outcome; }
    void setInterest(double interest) { this->interest = interest; }
    void setSort(bool sort) { this->sort = sort; }
    void setMovements(double *movements) { this->movements = movements; }
    void setData(string name, string userName, int pin, int size, double totalBalance, double income, double outcome, double interest, bool sort, double *movements)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size=size;
        this->totalBalance = totalBalance;
        this->income = income;
        this->outcome = outcome;
        this->interest = interest;
        this->sort = sort;
        this->movements = movements;
    }

    // getters
    string getName() { return name; }
    string getUserName() { return userName; }
    int getPin() { return pin; }
    int getSize() { return size; }
    double getTotalBalance() { return totalBalance; }
    double getIncome() { return income; }
    double getOutcome() { return outcome; }
    double getInterest() { return interest; }
    bool getSort() { return sort; }
    double *getMovements() { return movements; }
    void getData()
    {
        cout<<"The name of the user = "<<name<<endl;
        cout<<"The userName of the user = "<<userName<<endl;
        cout<<"The pin of the user = "<<pin<<endl;
        cout<<"The total Balance of the user = "<<totalBalance<<endl;
        cout<<"The income of the user = "<<income<<endl;
        cout<<"The outcome of the user = "<<outcome<<endl;
        cout<<"The interest of the user = "<<interest<<endl;
        cout<<"The movements of the user = "<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<*(movements+i)<<endl;
        }
        cout<<endl;
    }

    // destructor
    ~account()
    {
        cout << "Destructor called:" << endl;
    }
};
string calculateUserName(string name)
{
    char userName[]={tolower(name[0])};
    int count=1;
    for(int i=0;name[i]!='\0';i++)
    {
        if(name[i]==' ')
        {
            userName[count]=tolower(name[i+1]);
            count++;
        }
    }
    userName[sizeof(userName)/sizeof(char)+1]='\0';

    return userName;
}
int main()
{


    ////test part 01;
    // int totalAccounts=3;
    // account acc1;
    // account acc2;
    // account acc3;
    // account *accs=new account[totalAccounts]{acc1,acc2,acc3};
    // for(int i=0;i<totalAccounts;i++)
    // {
    //     (accs+i)->getData();
    // }

    ////Test:pqrt -2
    // account temp;
    // double arr[]={1,2,3,4,5};
    // temp.setData("Muhib Arshad","ma",1111,5,0,0,0,0,false,arr);
    // temp.getData();
    
    ////Test part 03;
    cout<<calculateUserName("Muhib Arshad Khan")<<endl;

    return 0;
}