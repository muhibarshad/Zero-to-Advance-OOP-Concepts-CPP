/*Write a C++ program to increase rows of 2D-Arrays during runTime*/
#include<iostream>
#include<iomanip>

using namespace std;

void inputDynamicArray(int **&matrix, int row, int col)
{
    cout<<"The random elements in the array :"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // matrix[i][j]=(rand()%10)+1;
            cin>>matrix[i][j];
        }
    }
}

void outputDynamicArray(int **&matrix, int row, int col)
{
    cout<<"The elements in the array :"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<left;
        for (int j = 0; j < col; j++)
        {
            cout<<setw(5)<<matrix[i][j];
        }
        cout<<endl;
    }
}

void increaseRows(int **&matrix,int row,int col){

    int num;
    cout<<"Enter the number of rows that you want to increase:"<<endl;

    


}
int main()
{
    int row=4;
    int col=5;
    int **matrix=new int *[row];
    for(int i=0;i<row;i++){
        matrix[i]=new int[col];
    }

  


    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}