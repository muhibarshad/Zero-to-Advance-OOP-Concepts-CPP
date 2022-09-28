#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    // MUTATORS
    void setNumerator(int);
    void setDenominator(int);

    // ACCESSORS
    int getNumerator() const;
    int getDenominator() const;

    // CONSTRUCTORS
    Rational(int);
    Rational(int, int);

    // UNIARY_OPERATORS
    Rational &operator-();
    bool operator!() const;

    // LOGICAL_OPERATORS
    bool operator<(const Rational &) const;
    bool operator==(const Rational &) const;

    // BINARY_OPERATORS
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;

    // NON_MEMBER_FRIEND_FUNCTIONS
    friend istream &operator>>(istream &, Rational &);
    friend ostream &operator<<(ostream &, const Rational &);
};

// NON_MEMBER_FRIEND_FUNCTIONS
ostream &operator<<(ostream &out, const Rational &rational)
{
    out << rational.numerator << "/" << rational.denominator << "\n";
    return out;
}
istream &operator>>(istream &in, Rational &rational)
{
    cout << "Enter the rational number :"
         << "\n";
    in >> rational.numerator;
   rational.setNumerator(rational.numerator);
    cout << "/"
         << "\n";
    in >> rational.denominator;
    rational.setDenominator(rational.denominator);
    return in;
}

// MUTATORS
void Rational::setNumerator(int numerator)
{
    this->numerator = numerator;
}
void Rational::setDenominator(int denominator)
{
    this->denominator = denominator != 0 ? denominator : 1;
}
// ACCESSORS
int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }

// CONSTRUCTORS
Rational::Rational(int numerator = 0, int denominator = 0)
{
    setNumerator(numerator);
    setDenominator(denominator);
}
Rational::Rational(int numerator)
{
    setNumerator(numerator);
    setDenominator(1);
}

// BINARY_OPERATORS
Rational Rational::operator+(const Rational &rational) const
{
    Rational temp;
    temp.denominator = denominator * rational.denominator;
    temp.numerator = (numerator * rational.denominator) + (denominator * rational.numerator);
    return temp;
}
Rational Rational::operator-(const Rational &rational) const
{
    Rational temp;
    temp.denominator = denominator * rational.denominator;
    temp.numerator = (numerator * rational.denominator) - (denominator * rational.numerator);
    return temp;
}
Rational Rational::operator*(const Rational &rational) const
{
    Rational temp;
    temp.numerator = numerator * rational.numerator;
    temp.denominator = denominator * rational.denominator;
    return temp;
}
Rational Rational::operator/(const Rational &rational) const
{
    Rational temp;
    temp.numerator = numerator * rational.denominator;
    temp.denominator = denominator * rational.numerator;
    return temp;
}

// LOGICAL_OPERATORS
bool Rational::operator<(const Rational &rational) const
{
    return ((numerator * rational.denominator) < (denominator * rational.numerator));
}
bool Rational::operator==(const Rational &rational) const
{
    return ((numerator * rational.denominator) == (denominator * rational.numerator));
}

// BINARY_OPERATORS
Rational &Rational::operator-()
{
    numerator = numerator >= 0 && denominator > 0 ? -numerator : numerator;
    return *this;
}
bool Rational::operator!() const
{
    return ((numerator <= 0 && denominator > 0) || (numerator >= 0 && denominator < 0));
}

int main()
{
    Rational rational1, rational2;
    //======================================
    //****TESTING_ Setters or getters
    //======================================
    rational1.setNumerator(1);
    rational1.setDenominator(2);
    rational2.setNumerator(3);
    rational2.setDenominator(4);

    //======================================
    //****TESTING_ << or >> stream operators
    //======================================
    cout << rational1 << rational2 << "\n";
    cin >> rational1;
    cout << rational1 << "\n";
    cout << "-----------------------------"
         << "\n";

    //=====================================
    //****TESTING_ +,-,/,* binary operators
    //=====================================
    Rational addition = rational1 + rational2;
    Rational subtraction = rational1 - rational2;
    Rational multiplication = rational1 * rational2;
    Rational division = rational1 / rational2;
    cout << "The addition of rational 1 and rational 2 = " << addition << "\n";
    cout << "The subtraction of rational 1 and rational 2 = " << subtraction << "\n";
    cout << "The multiplication of rational 1 and rational 2 = " << multiplication << "\n";
    cout << "The division of rational 1 and rational 2 = " << division << "\n";
    cout << "-----------------------------"
         << "\n";

    //======================================
    //****TESTING_ < or == logical Operators
    //======================================
    cout << (rational1 < rational2) << "\n";
    cout << (rational1 == rational2) << "\n";
    cout << "-----------------------------"
         << "\n";

    //========================================
    //****TESTING_ - or ! uninary operators
    //========================================
    cout << -rational1 << "\n";
    cout << !rational1 << "\n";
    cout << "-----------------------------"
         << "\n";

    return 0;
}
