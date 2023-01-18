#include <iostream>
#include <cmath>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setDay(int day)
    {
        this->day = day >= 1 && day <= 31 ? day : 1;
    }
    void setMonth(int month)
    {
        this->month = month >= 1 && month <= 12 ? month : 1;
    }
    void setYear(int year)
    {
        this->year = year >= 1900 ? year : 1900;
    }
    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }
    Date(int day, int month, int year)
    {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    Date(int month, int year) : day(1)
    {
        setMonth(month);
        setYear(year);
    }
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    friend ostream &operator<<(ostream &out, const Date &obj)

    {
        const string arr[12] = {"January", "Feburay", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        out << arr[obj.month - 1] << " " << obj.day << ", " << obj.year << "\n";
        return out;
    }
    friend istream &operator>>(istream &in, Date &obj)
    {
        cout << "Enter Day:",
            in >> obj.day;
        cout << "Enter month:",
            in >> obj.month;
        cout << "Enter year:",
            in >> obj.year;
        return in;
    }
    Date &operator++()
    {
        if (day == 30 && (month >= 1 && month < 12))
        {
            day = 1;
            ++month;
        }
        else if (day == 30 && month == 12)
        {
            day = 1,
            month = 1,
            ++year;
        }
        else
        {
            ++day;
        }
        return *this;
    }
    Date &operator++(int)
    {
        if (day == 30 && (month >= 1 && month < 12))
        {
            day = 1;
            month++;
        }
        else if (day == 30 && month == 12)
        {
            day = 1,
            month = 1,
            year++;
        }
        else
        {
            day++;
        }
        return *this;
    }
    Date &operator--()
    {
        if (day == 1 && (month > 1 && month <= 12))
        {
            day = 30;
            --month;
        }
        else if (day == 1 && month == 1)
        {
            day = 30;
            month = 12;
            --year;
        }
        else
        {
            --day;
        }
        return *this;
    }
    Date &operator--(int)
    {
        if (day == 1 && (month > 1 && month <= 12))
        {
            day = 30;
            month--;
        }
        else if (day == 1 && month == 1)
        {
            day = 30;
            month = 12;
            year--;
        }
        else
        {
            day--;
        }
        return *this;
    }
    int operator-(const Date &obj2)
    {
        return ((((obj2.year - year) * 365)) + ((obj2.month - month) * 30) + ((obj2.day - day)));
    }
    bool operator+()
    {
        return ((day == 5 && month == 2) || (day == 23 && month == 3) || (day == 1 && month == 5));
    }
};

int main()
{

    return 0;
}