// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  22:13:00
// Question : FAST University Lab-3 (OOP) : Instructor=> Mam Abeeda

/*
Write a menu driven C++ program to do following operation on two-dimensional array A of size m x n. You should use user-defined functions which accept 2-D array A, and its size m and n as arguments. The options are:
• To input elements into matrix of size m x n
• To display elements of matrix of size m x n
• Sum of all elements of matrix of size m x n
• To display row-wise sum of matrix of size m x n
• To display column-wise sum of matrix of size m x n
• To create transpose of matrix B of size n x m

*/
#include <iostream>
#include <iomanip>

using namespace std;
void input(int **matrix, const int &row, const int &col)
{
    cout << "Enter the elements in the matrix:\n";
    for (int i = 0; i < row; i++)
    {
        // cout << "Enter the row 1:\n";
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
            // cin >> matrix[i][j];
        }
    }
}
void output(int **&matrix, const int &row, const int &col)
{
    cout << "The elements in the matrix:\n";
    for (int i = 0; i < row; i++)
    {
        cout << left;
        for (int j = 0; j < col; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << "\n";
    }
}
void sum(int **matrix, const int &row, const int &col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += matrix[i][j];
        }
    }
    cout << "The sum of all elements in the matrix = " << sum << "\n";
}
void rowSum(int **matrix, const int &row, const int &col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += matrix[i][j];
        }
        cout << "The sum of all elements in the row = " << i + 1 <<": "<< sum << "\n";
    }
}
void columnSum(int **matrix, const int &row, const int &col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += matrix[j][i];
        }
        cout << "The sum of all elements in the column = " << i + 1 <<": " << sum << "\n";
    }
}
void transpose(int **matrix, const int &row, const int &col)
{
    cout << "The transpose of the matrix:\n";
    for (int i = 0; i < col; i++)
    {
        cout << left;
        for (int j = 0; j < row; j++)
        {
            cout << setw(5) << matrix[j][i];
        }
        cout << "\n";
    }
}

int main()
{
    int row, col;
    bool flag = false;
    cout << "Enter the number of rows:";
    cin >> row;
    cout << "Enter the number of columns:";
    cin >> col;
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[col];

    do
    {
        int n;
        cout << "Enter 1 for the input:\n";
        cout << "Enter 2 for the output:\n";
        cout << "Enter 3 for the row sum:\n";
        cout << "Enter 4 for the column sum:\n";
        cout << "Enter 5 for the transpose:\n";
        cout << "Enter 6 for the whole sum:\n";
        cout << "Enter 7 for the exit:\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            input(matrix, row, col);
            break;
        }
        case 2:
        {
            output(matrix, row, col);
            break;
        }
        case 3:
        {
            rowSum(matrix, row, col);
            break;
        }
        case 4:
        {
            columnSum(matrix, row, col);
            break;
        }
        case 5:
        {
            transpose(matrix, row, col);
            break;
        }
        case 6:
        {
            sum(matrix, row, col);
            break;
        }
        case 7:
        {
            flag = true;
            break;
        }
        }
    } while (flag == false);

    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;

    return 0;
}