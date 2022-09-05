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

    // 4-sortingAlgorithum(selection-sort)
    void sortMovements()
    {
        int min_index;
        for (int i = 0; i < size - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (*(movements + j) < *(movements + min_index))
                {
                    min_index = j;
                }
            }
            int temp;
            temp = *(movements + i);
            *(movements + i) = *(movements + min_index);
            *(movements + min_index) = temp;
        }
    }
};

int main()
{

    /*=============================Already DEFAULT ACCOUNTS IN BANKIST=========================*/

    /*------------Deafult Data------------------*/
    int noOfAccounts = 3;
    int *defaultPins = new int[noOfAccounts]{111, 222, 333};
    double *movementsAcc0 = new double[5]{2000, 1000, -500, 20000, -6000};
    double *movementsAcc1 = new double[5]{5000, -2000, 10000, 5000, -8000};
    double *movementsAcc2 = new double[5]{8000, 10000, 4000, -12000, -1000};
    /*------------RunTime Information------------------*/
    account *accounts = new account[noOfAccounts];
    account currentUser;

    /*------------ Deafult Accounts------------------*/
    // account-1
    accounts[0].setName("Muhib Arshad");
    accounts[0].calculateUserName();
    accounts[0].setPin(defaultPins[0]);
    accounts[0].setSize(5);
    accounts[0].setMovementsAddress(movementsAcc0);
    accounts[0].calculateTotalBalance();
    accounts[0].calculateTotalIncome();
    accounts[0].calculateTotalOutcome();
    accounts[0].calculateTotalInterest();
    accounts[0].sortMovements();
    accounts[0].getData();
     
    // account-2
    accounts[1].setName("Ali Abdullah");
    accounts[1].calculateUserName();
    accounts[1].setPin(defaultPins[1]);
    accounts[1].setSize(5);
    accounts[1].setMovementsAddress(movementsAcc1);
    accounts[1].calculateTotalBalance();
    accounts[1].calculateTotalIncome();
    accounts[1].calculateTotalOutcome();
    accounts[1].calculateTotalInterest();
    accounts[1].sortMovements();
    accounts[1].getData();

    // account-3
    accounts[2].setName("Bilal Sharafat");
    accounts[2].calculateUserName();
    accounts[2].setPin(defaultPins[2]);
    accounts[2].setSize(5);
    accounts[2].setMovementsAddress(movementsAcc2);
    accounts[2].calculateTotalBalance();
    accounts[2].calculateTotalIncome();
    accounts[2].calculateTotalOutcome();
    accounts[2].calculateTotalInterest();
    accounts[2].sortMovements();
    accounts[2].getData();

    /*=============================LOGICAL PORTION STARTS HERE=========================*/




    //Deallocating memeory-To avoid memeory leakages 
    delete[] movementsAcc0;
    movementsAcc0=nullptr;
    delete[] movementsAcc1;
    movementsAcc0=nullptr;
    delete[] movementsAcc2;
    movementsAcc0=nullptr;
    delete[] accounts;
    accounts=nullptr;

    return 0;
}