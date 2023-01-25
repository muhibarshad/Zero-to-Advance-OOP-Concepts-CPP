#include <iostream>

using namespace std;

template <typename t>
class Algebra
{
    t a, b;
    Algebra(int, int);
    <template><typename t1> friend ostream operator<< &(ostream &out, const Algebra<t1> obj)
    {
    }
};
template <typename t>
Algebra<t>::Algebra(int a, int b) : a(a), b(b){}

<template><typename t>
ostream operator<< &(ostream &out, const Algebra<t> obj)
{
}

template <typename t1, typename t2>
t1 add(t1 x, t2 y)
{
    return x + y;
}
int main()
{
    Algebra<char> obj;
    cout << add<int, float>('a', 1) << "\n";

    return 0;
}