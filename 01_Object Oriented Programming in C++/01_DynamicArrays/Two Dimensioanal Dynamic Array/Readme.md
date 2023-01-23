## Two Dimensional Dynamic arrays

**Firtsly**, In Two Dimensional Dynamic arrays, make an array of pointers (every element of array contains the address of first element of each row of matrix) which is stored to the pointer in stack, beacuse this pointer stores the address of first pointer of array, this pointer is the Double Pointer.

   <p align="center">
    <img src="/04_Material/CodeSnaps/2d-1.png" style="height: 40vh; padding-left: 50vh;">
 </p>
  **Secondly**, Make a new array on heap (column) from the every element(single-pointer) of the pointers array, that conatains the address of the first element of its column on the stack.

   <p align="center">
    <img src="/04_Material/CodeSnaps/2d-2.png" style="height: 50vh; padding-left: 50vh;">
 </p>

**Thirdly**, our 2D-array is allocated.Now perform all the tasks on it.

   <p align="center">
    <img src="/04_Material/CodeSnaps/2d-3.png" style="height: 70vh; padding-left: 50vh;">
 </p>

**At Last**, Deallocate all the columns on the heap. Then delete the pointers array.
Then make the matrix pointer to null (pointing to the nothing).

```cpp
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
```

## How to change the size of rows or columns of 2D-arrays at run-time ? How to increase or decrease the size of 2D-arrays dynamically ?

You can understand the one example of how to increase the size of columns and then do others operations by following it.

### Steps:(To increase the rows dynamically)

**Firstly**: Make the new 2D-Dynamic array.

   <p align="center">
    <img src="/04_Material/CodeSnaps/temp2-1.png" style="height: 50vh; padding-left: 50vh;">
 </p>

**Secondly**: Make the `temp` 2D-Dyanmic array.

   <p align="center">
    <img src="/04_Material/CodeSnaps/temp2-2.png" style="height: 60vh; padding-left: 50vh;">
 </p>

**Thirdly**: Copy the pervious 2d-array to temp array. Delete the previous 2D-Array and give pointer of temp array to previous array.

   <p align="center">
    <img src="/04_Material/CodeSnaps/temp2-3.png" style="height: 70vh; padding-left: 50vh;">
 </p>

**At Last**: Add new elements in the array.Finally, dellocate the array.

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int row=3;
    int col=3;

    //Allocating the memory
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

   cout << "Random elements in the array :" << endl;
    for (int i = 0; i < row; i++)
    {
        // cout<<"Enter the row "<<i+1<<" :"<<endl;
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
            // cin>>matrix[i][j];
        }
    }

   int num;
    cout << "Enter the number of rows that you want to increase:" << endl;
    cin >> num;

    //increase the size of the rows
    int **temp = new int *[row + num];
    for (int i = 0; i < row + num; i++)
    {
        temp[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = temp;


    //Entering elements in the increased rows
    for (int i = row; i < row + num; i++)
    {
        // cout<<"Enter the row "<<row+1<<" :"<<endl;
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (rand() % (100 - 90)) + 1 + 90;
            // cin>>matrix[i][j];
        }
    }
    row += num;

   cout << "The elements in the array :" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << left;
        for (int j = 0; j < col; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    //Dellocating the memory
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}

```