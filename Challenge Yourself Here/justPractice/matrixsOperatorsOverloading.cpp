/*1. Create a class named 'Matrix3By3' with only data members, an integer type 2D array of size 3 by 3. Write following member functions :
➔ Non - parameterized constructor, initialize matrix elements randomly with positive values smaller than 10
➔ Parameterized constructor(with 2D array of 3x3 as parameter), copy values in matrix from passed array
➔ Matrix3By3 &setIJElement with three parameters, i &j position and value to set at specified position, check position is valid, otherwise ignore.At the end return current object from function
➔ int getIJElement to return specified element from matrix, if position is valid
➔ int *getIthRow, check if position is valid, declare a new array of size 3 and copy elements of ith row in array and return the array, otherwise return null
➔ int *getIthColumn, check if position is valid, declare a new array of size 3 and copy elements of ith column in array and return the array, otherwise return null
➔ Matrix3By3 transpose, using a temporary variable swap elements of matrix such that result will be transpose of current matrix, finally return current matrix int main()
{
    Matrix3By3 m;
    m.show();
    cout << "--------------\n";
    m.transpose().show();
    cout << "--------------\n";
    m.setIJElement(1, 1, 0).show();
    int *c = m.getIthRow(1);
    cout << "--------------\n";
    printArray(c, 3);
    delete[] c;
    c = m.getJthColumn(1);
    cout << "--------------\n";
    printArray(c, 3);
    delete[] c;
    return 0;
}
Resource Person : Abdul Mateen
                      Sample Output : 2 8 1 8 6 8 2 4 7 -- -- -- -- -- -- --2 8 2 8 6 4 1 8 7 -- -- -- -- -- -- --2 8 2 8 0 4 1 8 7 -- -- -- -- -- -- --8 0 4 -- -- -- -- -- -- --8 0 8 OOP Fall 2021 2. Extend matrix class and overload following operators :
➔ Matrix3By3 operator+ to add two matrices into a new matrix and return new matrix
➔ Matrix3By3 & operator+= to add two matrices into
                          first matrix,
    don’t take new matrix and return current object
➔ Matrix3By3
    operator*,
    to multiply two matrices into
        a new matrix and return new matrix
➔ Matrix3By3 &
        operator*= to multiply current matrix
            with integer k,
    that is multiply all elements of matrix with
        integer k and return current object int
        main()
{
    srand(time(0));
    Matrix3By3 m1, m2;
    m1.show();
    cout << "--------------\n";
    m2.show();
    cout << "--------------\n";
    (m1 + m2).show();
    cout << "--------------\n";
    (m1 * m2).show();
    cout << "--------------\n";
    (m2 *= 3).show();
    cout << "--------------\n";
    (m1 += m2).show();
    return 0;
}
3. Create a class Student with following data members:
- roll no [integer with values in range 1-50, default value 1]
- semester no [integer with values 1-8, default value 0)
- cgpa [float with values 0 to 4, default value 0)
- noOfCourses [static array of size 8 having number of courses studied in each
semester]
- gps [dynamic float 2d array of pointers (pointer array of size 8) to store
grade points of each course in each semester]
Add following member functions:
- Parameterized constructor, with single parameter roll no, assign roll no,
set semester no to 0, set cgpa to 0, store 0 in all indexes of array no of courses,
and store null in all elements of pointer array cgpa
- setSemesterNo, function will receive two parameters: semester no and no
of courses in current semester. Assign semester no to data member semester no.
Resource Person: Abdul Mateen
Sample Output:
5 2 5
5 4 5
2 1 2
--------------
5 1 4
5 2 4
3 2 2
--------------
10 3 9
10 6 9
5 3 4
--------------
50 19 38
60 23 46
21 8 16
--------------
15 3 12
15 6 12
9 6 6
--------------
20 5 17
20 10 17
11 7 8
OOP Fall 2021
store no of courses at relevant index according to semester no. Declare array
against relevant pointer according to semester no and no of courses
- setGP, function will receive float array having having grade points in all
subjects of current semester. Copy grade points into relevant row of 2D array
- showSummary, function will print students summarized record. Print
student’s roll no, current semester and CGPA with appropriate captions (headings/
labels for roll no, semester no and cgpa)
- showDetail, function will print students record in detail. Print complete
students record, including grade points in all semesters
- Copy Constructor, to create copy of existing object*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
class Matrix3by3
{
    // private:
    int matrix[3][3];

public:
    Matrix3by3()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = (rand() % 10);
            }
        }
    }
    Matrix3by3(const int matrix[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }
    Matrix3by3 setIJElement(int i, int j, int value)
    {
        if ((i >= 0 && i <= 3) && (j >= 0 && j <= 3))
        {
            matrix[i][j] = value;
        }
        return *this;
    }
    int getIJElement(int i, int j) const
    {
        if ((i >= 0 && i <= 3) && (j >= 0 && j <= 3))
        {
            return matrix[i][j];
        }
    }
    int *getIthRow(int i) const
    {
        if (i >= 0 && i <= 3)
        {
            int *arr = new int[3];
            for (int j = 0; j < 3; j++)
            {
                arr[j] = matrix[i][j];
            }

            return arr;
        }
        else
        {
            return nullptr;
        }
    }
    int *getJthColumn(int i) const
    {
        if (i >= 0 && i <= 3)
        {
            int *arr = new int[3];
            for (int j = 0; j < 3; j++)
            {
                arr[j] = matrix[j][i];
            }

            return arr;
        }
        else
        {
            return nullptr;
        }
    }
    Matrix3by3 transpose()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = i; j < 3; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        return *this;
    }
    void show() const
    {
        cout << left;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << setw(5) << matrix[i][j];
            }
            cout << "\n";
        }
    }

    static printArray(const int *arr, const int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    Matrix3by3 operator+(const Matrix3by3 &matrix) const
    {
        Matrix3by3 temp = *this;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.setIJElement(i, j, this->matrix[i][j] + (matrix.getIJElement(i, j)));
            }
        }
        return temp;
    }

    Matrix3by3 &operator+=(const Matrix3by3 &matrix)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                this->matrix[i][j] += matrix.getIJElement(i, j);
            }
        }
        return *this;
    }

    Matrix3by3 operator*(const Matrix3by3 &matrix) const
    {
        Matrix3by3 temp = *this;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temp.setIJElement(i, j, temp.getIJElement(i,j)+(this->matrix[i][k] * (matrix.getIJElement(k, j))));
                }
            }
        }
        return temp;
    }

    Matrix3by3 &operator*=(const int &n)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] *= n;
            }
        }
        return *this;
    }
};
int main()
{
    // Matrix3by3 m;
    // m.show();
    // cout << "--------------\n";
    // m.transpose().show();
    // cout << "--------------\n";
    // m.setIJElement(1, 1, 0).show();
    // int *c = m.getIthRow(1);
    // cout << "--------------\n";
    // Matrix3by3::printArray(c, 3);
    // delete[] c;
    // c = m.getJthColumn(1);
    // cout << "--------------\n";
    // Matrix3by3::printArray(c, 3);
    // delete[] c;

    // srand(time(0));
    Matrix3by3 m1, m2;
    m1.show();
    cout << "--------------\n";
    m2.show();
    cout << "--------------\n";
    (m1 + m2).show();
    cout << "--------------\n";
    (m1 * m2).show();
    cout << "--------------\n";
    (m2 *= 3).show();
    cout << "--------------\n";
    (m1 += m2).show();

    return 0;
}