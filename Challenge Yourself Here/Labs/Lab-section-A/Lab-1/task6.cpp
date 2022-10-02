// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  5:45:00
// Question : FAST University Lab1-1 (OOP) : Instructor=> Mam Abeeda

/*
Create two float pointers in the main function and write C++ code for the following functions and call them in order from main.
1- A function allocate(), which creates dynamic variables length and width and assigns their addresses to pointers created in main.
2- A function input() that takes input from the user in already created dynamic variables length and width.
3- A function Print() that prints values of dynamic variables length and width.
4- A function Area() that takes dynamic variables as parameters and returns the area of the rectangle.
5- A function deallocate() which deallocates the memory of dynamic variables length and width and update pointers too.
*/
#include <iostream>
void allocate(float *&length, float *&width)
{
    length = new float;
    width = new float;
}
void deallocate(float *&length, float *&width)
{
    delete length;
    length = nullptr;
    delete width;
    width = nullptr;
}
void input(float *length, float *width)
{
    std::cout << "Enter the length :\n";
    std::cin >> *length;
    std::cout << "Enter the widths :\n";
    std::cin >> *width;
}
void output(float *length, float *width)
{
    std::cout << "The length :\n"
              << *length << "\n";
    std::cout << "The width :\n"
              << *width << "\n";
}
void area(float *length, float *width)
{
    std::cout << "The Area :\n"
              << (*width) * (*length) << "\n";
}

int main()
{
    float *length=nullptr;
    float *width=nullptr;
    allocate(length, width);
    input(length, width);
    output(length, width);
    area(length, width);
    deallocate(length, width);
    return 0;
}
