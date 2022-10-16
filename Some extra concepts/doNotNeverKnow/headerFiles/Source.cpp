#include <iostream>
#include "Rational.h"
using namespace std;



int main()
{
    Rational rational1(1,2), rational2(3,4);
    //======================================
    //****TESTING_ Setters or getters
    //======================================
   

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
