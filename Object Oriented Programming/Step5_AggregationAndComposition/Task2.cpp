#include <iostream>
#include <string>
using namespace std;

class NumDays
{
private:
    int numOFhrs;
    double numOFdays;

public:
    NumDays(int numOFhrs) : numOFhrs(numOFhrs)
    {
        numOFdays = numOFhrs / 8.00;
    }
    void setHours(int numOFhrs)
    {
        this->numOFhrs = numOFhrs;
        numOFdays = numOFhrs / 8.0;
    }
    void setDays(double numOFdays)
    {
        this->numOFdays = numOFdays;
        numOFhrs = numOFdays * 8;
    }
    double getDays() const
    {
        return numOFdays;
    }
    int getHours() const
    {
        return numOFhrs;
    }
    NumDays operator+(const NumDays &obj)
    {
        return NumDays(numOFhrs + obj.numOFhrs);
    }
    NumDays operator-(const NumDays &obj)
    {
        return NumDays(numOFhrs - obj.numOFhrs);
    }
    NumDays operator++()
    {
        ++numOFhrs;
        setHours(numOFhrs);
        return *this;
    }
    NumDays operator++(int)
    {
        NumDays temp(*this);
        numOFhrs++;
        setHours(numOFhrs);
        return *this;
    }
    NumDays operator--()
    {
        --numOFhrs;
        setHours(numOFhrs);
        return *this;
    }
    NumDays operator--(int)
    {
        NumDays temp(*this);
        numOFhrs--;
        setHours(numOFhrs);
        return *this;
    }

    void putData()
    {
        cout << "Num of Hrs : " << numOFhrs << "\n";
        cout << "Num of days : " << numOFdays << "\n";
    }
};

class TimeOff
{
private:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

    string employeeName;
    int idNumber;

public:
    TimeOff(string employeeName,
            int idNumber,
            int maxSickHours,
            int takenSickHours,
            int maxVacHours,
            int takenVacHours,
            int maxUnpidHours,
            int takenUnpaidHours) : maxSickDays(maxSickHours),
                                    sickTaken(takenSickHours),
                                    maxVacation(maxVacHours),
                                    vacTaken(takenVacHours),
                                    maxUnpaid(maxUnpidHours),
                                    unpaidTaken(takenUnpaidHours)
    {
        this->employeeName = employeeName;
        this->idNumber = idNumber;
        setMaxVacation(maxVacHours);
    }

    void setEmployeeName(string employeeName)
    {
        this->employeeName = employeeName;
    }
    void setIdNumber(int idNumber)
    {
        this->idNumber = idNumber;
    }
    void setMaxSickDays(int maxSickHours)
    {
        maxSickDays.setHours(maxSickHours);
    }
    void setSickTaken(int takenSickHours)
    {
        sickTaken.setHours(takenSickHours);
    }
    void setMaxVacation(int maxVacHours)
    {
        if (maxVacHours > 240)
            maxVacHours = 240;
        maxVacation.setHours(maxVacHours);
    }
    void setVacTaken(int takenVacHours)
    {
        vacTaken.setHours(takenVacHours);
    }
    void setMaxUnpaid(int maxUnpidHours)
    {
        maxUnpaid.setHours(maxUnpidHours);
    }
    void setUnpaidTaken(int takenUnpaidHours)
    {
        unpaidTaken.setHours(takenUnpaidHours);
    }

    string getEmployeeName() const
    {
        return employeeName;
    }
    int getIdNumber() const
    {
        return idNumber;
    }
    double getMaxSickDays() const
    {
        return maxSickDays.getDays();
    }
    double getSickTaken() const
    {
        return sickTaken.getDays();
    }
    double getMaxVacation() const
    {
        return maxVacation.getDays();
    }
    double getVacTaken() const
    {
        return vacTaken.getDays();
    }
    double getMaxUnpaid() const
    {
        return maxUnpaid.getDays();
    }
    double getUnpaidTaken() const
    {
        return unpaidTaken.getDays();
    }
};

int main()
{
    cout << "Enter the number of months an employee has worked for the company ";
    int months;
    cin >> months;

    TimeOff obj("Muhib Arshad", 40, 8 * months, 20, 12 * months, 15, 30, 12);

    cout << "Maximum number of sick days:" << obj.getMaxSickDays() <<" days" "\n";
    cout << "Maximum number of vacation days:" << obj.getMaxVacation() <<" days" "\n";

    return 0;
}