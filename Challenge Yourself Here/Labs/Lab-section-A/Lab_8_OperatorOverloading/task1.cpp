#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int real = 0, int imag = 0) : real(real), imag(imag) {}
    friend istream &operator>>(istream &in, Complex &obj)
    {
        cout << "Enter the real part of the complex number :";
        in >> obj.real;
        cout << "Enter the imaginary part of the complex number :";
        in >> obj.imag;
        return in;
    }
    friend ostream &operator<<(ostream &out, Complex &obj)
    {
        if (obj.real != 0 && obj.imag != 0)
        {
            out << obj.real;
            obj.imag >= 0 ? cout << "+" : cout << "-";
            cout << obj.imag<< "i"
                 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }

        return out;
    }
    Complex operator-(const Complex &obj) const
    {
        return Complex(real - obj.real, imag - obj.imag);
    }
    bool operator==(const Complex &obj) const
    {
        return (real == obj.real && imag == obj.imag);
    }
    bool operator!=(const Complex &obj) const
    {
        return !(*this == obj);
    }
};
int main()
{
    Complex C1;
    Complex C2(5, 6);
    Complex C3;

    cout << "Input a complex number" << endl;
    cin >> C3;

    cout << C1 << C2 << C3;

    if (C1 == C2)
        cout << "C1 == C2" << endl;
    else
        cout << "C1 != C2" << endl;

    if (C1 != C3)
        cout << "C1 != C3" << endl;
    else
        cout << "C1==C3" << endl;

    Complex C4 = C2 - C3;
    cout << C4;

    system("pause");
    return 0;
}
