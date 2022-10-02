// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  22:53:00
// Question : FAST University Lab-3 (OOP) : Instructor=> Mam Abeeda

/*
Write a function int** AddMatrix(int** A, int** B, const int& rows, const int& cols) that creates a new matrix result of size rowsxcols, adds matrix A and B and saves the result in matrix result and returns the result pointer. Test your function in main().
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

int **addMatrix(int **matrix1, int **matrix2, const int &row, const int &col)
{
    int **temp = new int *[row];
    for (int i = 0; i < row; i++)
        temp[i] = new int[col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return temp;
}

int main()
{
    int row, col;
    cout << "Enter the number of rows:";
    cin >> row;
    cout << "Enter the number of columns:";
    cin >> col;
    int **matrix1 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix1[i] = new int[col];
    }
    int **matrix2 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix2[i] = new int[col];
    }
    input(matrix1, row, col);
    output(matrix1, row, col);
    input(matrix2, row, col);
    output(matrix2, row, col);
    int **sumMatrix = addMatrix(matrix1, matrix2, row, col);
    output(sumMatrix, row, col);
    for (int i = 0; i < row; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    matrix1 = nullptr;
    for (int i = 0; i < row; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    matrix2 = nullptr;
    for (int i = 0; i < row; i++)
    {
        delete[] sumMatrix[i];
    }
    delete[] sumMatrix;
    sumMatrix = nullptr;

    return 0;
}