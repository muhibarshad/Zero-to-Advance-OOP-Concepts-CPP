#include <iostream>
using namespace std;
int main()
{
    int row = 3;
    int col = 3;

    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
        }
    }

    for(int i=0;i<row;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix=nullptr;

    return 0;
}