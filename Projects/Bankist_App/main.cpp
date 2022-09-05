#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

#define interestRate 1.5
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
    void setMovementsAddress(double *movements) { this->movements = movements; }
    void setMovementsValue()
    {
        movements = new double[size];
        for (int i = 0; i < size; i++)
        {
            cin >> *(movements + i);
        }
    }

    void setData(string name, string userName, int pin, int size, double *movements, double totalBalance, double income, double outcome, double interest, bool sort)
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
    void calculateUserName()
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
    }

    // 2- Calculating Total Balance
    double calculateTotalBalance()
    {
        double total = calculateTotalIncome() - calculateTotalOutcome();
        totalBalance = total;
        return total;
    }

    // 3-Calculating Summary
    // a-Income
    double calculateTotalIncome()
    {
        double totalIncome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) >= 0)
                totalIncome += (*(movements + i));
        }
        income = totalIncome;
        return totalIncome;
    }
    // b-Outcome
    double calculateTotalOutcome()
    {
        double totalOutcome = 0.0;
        for (int i = 0; i < size; i++)
        {
            if (*(movements + i) < 0)
                totalOutcome += (abs(*(movements + i)));
        }
        outcome = totalOutcome;
        return totalOutcome;
    }
    // c-InterestRate
    double calculateTotalInterest()
    {
        double totalInterest = 0.0;
        for (int i = 0; i < size; i++)
        {
            double deposit = 0.0;
            if (*(movements + i) > 0)
            {
                deposit = *(movements + i) * (interestRate / 100);
                if (deposit >= 1)
                {
                    totalInterest += deposit;
                }
            }
        }
        interest = totalInterest;
        return totalInterest;
    }

    // 4-sortingAlgorithum
    void sortMovements()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (*(movements + j) > *(movements + j + 1))
                {
                    int temp;
                    temp = *(movements + j);
                    *(movements + j) = *(movements + j + 1);
                    *(movements + j + 1) = temp;
                }
            }
        }
    }
};

int main()
{
    /*------------Deafult Data------------------*/
    int noOfAccounts = 3;
    int *defaultPins = new int[noOfAccounts]{111, 222, 333};
    double *movementsAcc0 = new double[5]{2000, 1000, -500, 20000, -6000};
    double *movementsAcc1 = new double[5]{5000, -2000, 10000, 5000, -8000};
    double *movementsAcc2 = new double[5]{8000, 10000, 4000, -12000, -1000};
    
    /*------------ Deafult Accounts------------------*/
    //account-1
    account acc1;
    acc1.setName("Muhib Arshad");
    acc1.calculateUserName();
    acc1.setPin(defaultPins[0]);
    acc1.setSize(5);
    acc1.setMovementsAddress(movementsAcc0);
    acc1.calculateTotalBalance();
    acc1.calculateTotalIncome();
    acc1.calculateTotalOutcome();
    acc1.calculateTotalInterest();
    acc1.sortMovements();
    acc1.getData();

    //account-2
    account acc2;
    acc2.setName("Ali Abdullah");
    acc2.calculateUserName();
    acc2.setPin(defaultPins[1]);
    acc2.setSize(5);
    acc2.setMovementsAddress(movementsAcc1);
    acc2.calculateTotalBalance();
    acc2.calculateTotalIncome();
    acc2.calculateTotalOutcome();
    acc2.calculateTotalInterest();
    acc2.sortMovements();
    acc2.getData();

    //account-3
    account acc3;
    acc3.setName("Muhib Arshad");
    acc3.calculateUserName();
    acc3.setPin(defaultPins[0]);
    acc3.setSize(5);
    acc3.setMovementsAddress(movementsAcc2);
    acc3.calculateTotalBalance();
    acc3.calculateTotalIncome();
    acc3.calculateTotalOutcome();
    acc3.calculateTotalInterest();
    acc3.sortMovements();
    acc3.getData();

    /*------------RunTime Information------------------*/
    account *accounts=new account[noOfAccounts]{acc1,acc2,acc3};
    account currentUser;

    return 0;
}