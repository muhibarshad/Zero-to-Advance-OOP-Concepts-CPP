#include <iostream>
using namespace std;
class complex
{
private:
    int real;
    int imag;

public:
    complex(int real_a = 0, int imag_a = 0)
    {
        real = real_a;
        imag = imag_a;
    }
    void input()
    {
        cout << "Enter the real part of the complex number:" << endl;
        cin >> real;
        cout << "Enter the imaginary part of the complex number:" << endl;
        cin >> imag;
    }
    complex operator+(const complex& num)
    {
        complex temp;
        temp.real = real + num.real;
        temp.imag = imag + num.imag;
        return temp;
    }
    void output()
    {
        if (imag < 0)
        {
            cout << "The sum of these two complex numbers = " << real << imag << "i" << endl;
        }
        else
        {
            cout << "The sum of these two complex numbers = " << real << "+" << imag << "i" << endl;
        }
    }
};
int main()
{
    complex num1, num2, sum;
    num1.input();
    num2.input();
    sum = num1 + num2;
    sum.output();

    return 0;
}