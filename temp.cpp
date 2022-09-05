#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

#define interestRate 1.5
#define noOfYears 3
#define minmumBalanceForInterest 200
class account
{
private:
    string name;
    string userName;
    int size;
    int pin;
    double *movements;
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
        size = 0;
        totalBalance = 0.0;
        income = 0.0;
        outcome = 0.0;
        interest = 0.0;
        sort = false;
        movements = nullptr;
    }
    // parameterized constructor
    account(string name, string userName, int pin, int size, double totalBalance, double income, double outcome, double interest, bool sort, double *movements)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size = size;
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
        size = temp.size;
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
    void setMovementsAddress() { this->movements = movements; }
    void setMovementsValue()
    {
        movements = new double[size];
        for (int i = 0; i < size; i++)
        {
            cin >> *(movements + i);
        }
    }

    void setData(string name, string userName, int pin, int size, double totalBalance, double income, double outcome, double interest, bool sort, double *movements)
    {
        this->name = name;
        this->userName = userName;
        this->pin = pin;
        this->size = size;
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
    double *getMovementsAddress() { return movements; }
    void getMovementsValue()
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(movements + i) << endl;
        }
    }
    void getData()
    {
        cout << "The name of the user = " << name << endl;
        cout << "The userName of the user = " << userName << endl;
        cout << "The pin of the user = " << pin << endl;
        cout << "The total Balance of the user = " << totalBalance << endl;
        cout << "The income of the user = " << income << endl;
        cout << "The outcome of the user = " << outcome << endl;
        cout << "The interest of the user = " << interest << endl;
        cout << "The movements of the user = " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << *(movements + i) << endl;
        }
        cout << endl;
    }

    // destructor
    ~account()
    {
        cout << "Destructor called:" << endl;
    }

    // Member Functions

    // 1-Calculating UserName
    string calculateUserName()
    {

        userName = "";
        userName.push_back(tolower(name[0]));
        bool flag = false;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] == ' ')
            {
                flag = true;
            }
            if (name[i] != ' ' && flag == true)
            {
                userName.push_back(tolower(name[i]));
                flag = false;
            }
        }
        return userName;
    }

    // 2- Calculating Total Balance
    void calculateTotalBalance()
    {
        double total;
        for (int i = 0; i < size; i++)
        {
            total += (*(movements + i));
        }

        totalBalance= total;
    }

    // 3-Calculating Summary
    // a-Income
    void calculateTotalIncome()
    {
        double totalIncome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) >= 0)
                totalIncome += (*(movements + i));
        }
        income= totalIncome;
    }
    // b-Outcome
    void calculateTotalOutcome()
    {
        double totalOutcome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) < 0)
                totalOutcome += (abs(*(movements + i)));
        }
        outcome= totalOutcome;
    }
    // c-InterestRate
    void calculateTotalInterest()
    {
        calculateTotalBalance();
        int balance = totalBalance;
        interest= balance > minmumBalanceForInterest ? balance * interestRate * noOfYears : 0.0;
    }
};

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

    ////Test Part 03:
    account acc1;
    acc1.setSize(5);
    cout << acc1.getSize() << endl;
    cout << "Set values:" << endl;
    acc1.setMovementsValue();
    cout << "get values:" << endl;
    acc1.getMovementsValue();
    cout << "Total balance:" << endl;
    acc1.calculateTotalBalance();
    acc1.calculateTotalIncome() ;
    acc1.calculateTotalOutcome();
    acc1.calculateTotalInterest();
    cout<<acc1.getTotalBalance()<<endl;
    cout<<acc1.getIncome()<<endl;
    cout<<acc1.getOutcome()<<endl;
    cout<<acc1.getInterest()<<endl;

    return 0;
}