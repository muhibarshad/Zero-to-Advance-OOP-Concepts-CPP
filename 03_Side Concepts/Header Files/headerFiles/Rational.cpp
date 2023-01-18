#include"Rational.h"

// NON_MEMBER_FRIEND_FUNCTIONS
ostream& operator<<(ostream& out, const Rational& rational)
{
    out << rational.numerator << "/" << rational.denominator << "\n";
    return out;
}
istream& operator>>(istream& in, Rational& rational)
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
Rational Rational::operator+(const Rational& rational) const
{
    Rational temp;
    temp.denominator = denominator * rational.denominator;
    temp.numerator = (numerator * rational.denominator) + (denominator * rational.numerator);
    return temp;
}
Rational Rational::operator-(const Rational& rational) const
{
    Rational temp;
    temp.denominator = denominator * rational.denominator;
    temp.numerator = (numerator * rational.denominator) - (denominator * rational.numerator);
    return temp;
}
Rational Rational::operator*(const Rational& rational) const
{
    Rational temp;
    temp.numerator = numerator * rational.numerator;
    temp.denominator = denominator * rational.denominator;
    return temp;
}
Rational Rational::operator/(const Rational& rational) const
{
    Rational temp;
    temp.numerator = numerator * rational.denominator;
    temp.denominator = denominator * rational.numerator;
    return temp;
}

// LOGICAL_OPERATORS
bool Rational::operator<(const Rational& rational) const
{
    return ((numerator * rational.denominator) < (denominator * rational.numerator));
}
bool Rational::operator==(const Rational& rational) const
{
    return ((numerator * rational.denominator) == (denominator * rational.numerator));
}

// BINARY_OPERATORS
Rational& Rational::operator-()
{
    numerator = numerator >= 0 && denominator > 0 ? -numerator : numerator;
    return *this;
}
bool Rational::operator!() const
{
    return ((numerator <= 0 && denominator > 0) || (numerator >= 0 && denominator < 0));
}
