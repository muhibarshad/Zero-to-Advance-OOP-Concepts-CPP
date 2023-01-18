#include <iostream>

using namespace std;

class Account
{
    string *arr;
    int totalAcc;

public:
    Account(int totalAcc = 3) : totalAcc(totalAcc)
    {
        arr = new string[totalAcc]{"Ali", "muhib", "Usama"};
        if (totalAcc)
            menu();
    }
    void setAccounts()
    {
        for (int i = 0; i < totalAcc; i++)
        {
            cout << "Enter the name of the Account " << i + 1 << " : \n";
            cin >> arr[i];
        }
    }
    void getAccounts() const
    {
        for (int i = 0; i < totalAcc; i++)
        {
            cout << "The name of the Account " << i + 1 << " : " << arr[i] << "\n";
        }
    }
 void createAccount()
    {
        string *temp = new string[totalAcc + 1];
        for (int i = 0; i < totalAcc; i++)
            temp[i] = arr[i];
        cout << "Enter the New Account no " << totalAcc + 1 << " Name :\n";
        cin >> temp[totalAcc];
        delete[] arr;
        arr = temp;
        totalAcc++;
    }
    void deleteAccount(string nameAcc)
    {
        string *temp = new string[totalAcc - 1];
        for (int i = 0, j = 0; i < totalAcc; i++)
        {
            if (arr[i] != nameAcc)
            {
                if (j < totalAcc - 1)
                {
                    temp[j] = arr[i];
                }
                j++;
            }
        }
        delete[] arr;
        arr = temp;
        totalAcc--;
    }
    void menu()
    {
        bool flag = 0;
        do
        {
            int n;
            string nameDel;
            cout << "Enter 1 to Create a new Account  \n";
            cout << "Enter 2 to delete an account \n";
            cout << "Enter 3 to display all accounts \n";
            cout << "Enter 0 to exit \n";
            cin >> n;
            switch (n)
            {
            case 1:
            {
                createAccount();
                break;
            }

            case 2:
            {
                cout << "Enter the name of account :\n";
                cin >> nameDel;
                deleteAccount(nameDel);
                break;
            }
            case 3:
            {
                getAccounts();
                break;
            }
            case 0:
            {
                flag = 1;
                cout << "Quiting..............\n";
            }
            }

        } while (!flag);
    }
    int getTotalAccount() const
    {
        return totalAcc;
    }

    ~Account()
    {
        delete[] arr;
    }
};
int main()
{
    Account facebook;

    return 0;
}