#include <iostream>

using namespace std;

class Rational
{
private:
    int p;
    int q;

public:
    Rational(int p = 0, int q = 0)
    {
        setP(p);
        setQ(q);
    }
    void setP(int p)
    {
        this->p = q != 0 && p == 0 ? 1 : p;
    }
    void setQ(int q)
    {
        this->q = p != 0 && q == 0 ? 1 : q;
    }
    int getP() const { return p; }
    int getQ() const { return q; }
    void setRational(int p = 0, int q = 0)
    {
        setP(p);
        setQ(q);
    }
    friend ostream &operator<<(ostream out, const Rational &obj)
    {
        out << "The value of P : " << obj.p << "\n";
        out << "The value of Q : " << obj.q << "\n";

        return out;
    }
    friend istream &operator<<(istream in, Rational &obj)
    {
        cout << "Enter the value of P : ";
        in >> obj.p;
        cout << "Enter the value of Q : ";
        in >> obj.q;

        return in;
    }

    // Code_Start_here
    bool operator==(const Rational &obj)
    {
        return (p == obj.p && q == obj.q);
    }
    Rational &operator++()
    {
        q = 1 * this->p;
        p = (1 * (this->p)) + (1 * (this->q));
        return *this;
    }
    Rational &operator--(int)
    {
        q = 1 * this->p;
        p = (this->p * 1) - (this->q * 1);
        return *this;
    }
    Rational operator+(const Rational &obj)
    {
        Rational temp = *(this);
        temp += obj;
        return temp;
    }
    Rational &operator+=(const Rational &obj)
    {
        this->p = this->p + obj.p;
        this->q = this->q + obj.q;
        return *this;
    }
    Rational &operator*=(const int &n)
    {
        this->p = this->p * n;
        this->q = this->q * 1;
        return *this;
    }
    Rational &operator/=(const int &n)
    {
        this->p = this->p * 1;
        this->q = this->q * n;
        return *this;
    }
    
};
int main()
{

    return 0;
}