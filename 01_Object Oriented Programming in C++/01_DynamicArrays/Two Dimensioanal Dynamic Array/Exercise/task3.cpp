// Author: Muhib Arshad (@muhib7353 everywhere)
// Date and Time: 2 October , 20222  23:04:00
// Question : FAST University Lab-3 (OOP) : Instructor=> Mam Abeeda

/*
Write a program which takes input of number of rows in 2D array from the user and then asks user to enter numbers from 0 to n where n is equal to number of rows and find out factors of each number. Numbers entered should be greater than 6 and less than 100. If the number does not fall in this range, program should alert user to re-enter the number. Create factors array for each number in above allocated 2D array and store that number on 1st index of factors array. Your program should also de-allocate acquired dynamic memory at the end of the life cycle.

Sample Output:

Enter Number between 6 and 100: 12
Enter Number between 6 and 100: 5
Wrong input. Please re-enter the number
Enter Number between 6 and 100: 7

Following are the factors of numbers entered:

Factors of 12 are 1,2,3,4,6,12
Factors of 10 are 1, 2,5,10

*/
#include <iostream>

using namespace std;

int main()
{
    int row;
    cout << "Enter the number of rows";
    cin >> row;
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[1];

    for (int i = 0; i < row; i++)
    {
        cout << "Enter the number between the 6 and 100:";
        cin >> matrix[i][0];
        while (matrix[i][0] < 6 || matrix[i][0] > 100)
        {
            cout << "Wrong input. Please re-enter the number";
            cin >> matrix[i][0];
        }
    }

    for (int i = 0; i < row; i++)
    {
        int col = 1;
        for (int j = 1; j <= matrix[i][0]; j++)
        {
            if (matrix[i][0] % j == 0)
            {
                int *temp = new int[col + 1];
                for (int k = 0; k < col; k++)
                {
                    temp[k] = matrix[i][k];
                }
                temp[col] = j;
                delete[] matrix[i];
                matrix[i] = temp;
                col++;
            }
        }
        cout << "The factors of "<<matrix[i][0]<<" are ";
        for (int j = 1; j < col; j++)
        {
            cout << "\t" << matrix[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;

    return 0;
}