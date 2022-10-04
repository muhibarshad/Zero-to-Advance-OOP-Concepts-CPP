// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  15:21:00
// Question : FAST University Lab4 (OOP) : Instructor=> Mam Abeeda

/*
Write a program that will read monthly sales into a dynamically allocated array. The program will input the size of the array from the user. It will call a function that will find the yearly sum (the sum of all the sales). It will also call another function that will find the average. Then it calls a display function that will display the total sales for the year and average monthly sale.

*/
#include <iostream>
#include <string>

using namespace std;

void myTokenizer(char *data, char **list_tokens, char delimiter)
{

    int rowIndex = 0;
    int size = 1;
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] != delimiter)
        {
            char *temp = new char[size + 1];
            for (int j = 0; j < size; j++)
            {
                temp[i] = list_tokens[rowIndex][j];
            }
            temp[size - 1] = data[i];
            temp[size] = '\0';
            delete[] list_tokens[rowIndex];
            list_tokens[rowIndex] = temp;
            size++;
        }
        if (data[i] == delimiter)
        {
            rowIndex++;
            size=1;
        }
    }
}
void print(char **matrix,int row)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;matrix[i][j]!='\0';i++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    string str;
    getline(cin, str);
    int size = 0;
    char delimeter;
    int row = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
        {
            delimeter = str[i];
            break;
        }
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == delimeter)
        {
            row++;
        }
    }

    cout << size << endl;
    cout << row << endl;
    char *data = new char[size];
    char **list_tokens = new char *[row];
    for (int i = 0; i < row; i++)
        list_tokens[i] = new char[1]{'\0'};

    myTokenizer(data, list_tokens, delimeter);
    print(list_tokens,row);

    delete[] data;
    data = nullptr;
    for (int i = 0; i < row; i++)
        delete[] list_tokens[i];
    delete[] list_tokens;
    list_tokens = nullptr;
    return 0;
}