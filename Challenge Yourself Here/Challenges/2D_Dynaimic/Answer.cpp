/*
Write a program that performs following string manipulations: You cannot change
prototype of any function.
1. Write a function that takes two strings i.e., str1 and str2 then appends str1 at the end of str2.
void StringConcatenate (char *str1, char *str2) ;
Note: Do not use any extra string inside the function.
2. Write a function that takes a string and if it finds more than one occurrences of a character in the
string, it removes the extra occurrences.
Void CompressString(char*);
For example:
String: “abadca” String after compression: “abdc”
String: “aaaaaaabbaad” String after compression: “abd”
Note: Do not use any extra string inside the function.
3. Write a function that takes a sentence and returns its inverse.
Char* ReverseSentence(char*)
String: “I am Pakistani”
After calling Reverse Sentence
String: “Pakistani am I” (Do not change the original string)
4. Write a function that takes a 2d-array of singular words and convert each singular word of array
to a plural word.
void pluralWords(char **s, int wordCount);
a. Append ‘es’ in following cases
1. If a word ends with letter ‘h’ and second last letters are ‘c’ or ‘s’
2. If last letter is ‘x’ or ‘is’
Tax – Taxes
Analysis – Analyses
Ellipsis – Ellipses
3. If last letter is ‘s’ or ‘z’ and second last letter is not vowel a
4. If the word ends in ‘ato’
Potato – Potatoes
Tomato – Tomatoes
b. If last letter is ‘z’ and second last letter is vowel ‘a’ or ‘e’ then append ‘zes’
Quiz – Quizzes
c. If last letter is ‘s’ and second last letter is vowel ‘a’ or ‘e’ the append ‘ses’
Gas – Gasses
d. If the noun ends with ‘ff’ then append ‘s’
Staff – Staffs
Stuff – Staffs
Lay-off – Lay-offs
Object Oriented Programming (CS-217) Spring 2021 Section A, B
National University of Computer and Emerging Sciences, Lahore
e. If the noun ends with ‘f’ or ‘fe’, the f is changed to ‘ve’ before adding the ‘s’ to form the
plural version.
Wife – Wives,
Wolf – Wolves
f. If the singular noun ends in ‘on’, then ‘‘on’’ is changed to ‘a’.
Phenomenon – Phenomena
Criterion – Criteria
1. If the singular noun ends in ‘us’, then ‘us’ is changed to ‘i’.
Cactus – Cacti
Focus – Foci
g. If last letter is ‘y’ and second last letter is vowel then append ‘s’ otherwise ‘ies’
City – Cities
Puppy – Puppies
Ray – Rays
Roy – Boys
h. For all other options append ‘s’
 Input array After function call Array should contain
Student
Party
Quiz
Wolf
Students
Parties
Quizzes
Wolves
Carefully reallocate memory to store plural words.
- You cannot change the function prototypes given in the questions.
- You cannot use break or goto statements. Breaks are allowed in switch cases.
- Built-in string functions are not allowed.
- Do not use new/extra strings wherever mentioned in the questions.

*/

#include <iostream>
#include <conio.h>

using namespace std;
void output(char *str, const int size)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }
    cout << "\n";
}
void input(char *&str, int &size)
{
    char ch;
    do
    {
        ch = getch();
        if ((ch >= 32 && ch <= 126))
        {
            char *temp = new char[size + 1];
            for (int i = 0; str[i] != '\0'; i++)
            {
                temp[i] = str[i];
            }
            temp[size - 1] = ch;
            temp[size] = '\0';
            delete[] str;
            str = temp;
            size++;
            system("cls");
            output(str, size);
        }
        if (ch == 8)
        {
            char *temp = new char[size - 1];
            for (int i = 0; i < size - 1; i++)
            {
                temp[i] = str[i];
            }
            temp[size - 2] = '\0';
            delete[] str;
            str = temp;
            size--;
            system("cls");
            output(str, size);
        }

    } while (ch != 13);
}

int  StringConcatenate(char *&str1, char *str2)
{
    int newSize = 1;
    char *temp = new char[1]{'\0'};
    for (int i = 0; str1[i] != '\0'; i++)
    {
        temp[i] = str1[i];
        newSize++;
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        temp[newSize] = str2[i];
        newSize++;
    }
    delete[] str1;
    str1=temp;
    return newSize;

}
int main()
{
    int size1 = 1;
    int size2 = 1;
    char *str1 = new char[size1]{'\0'};
    char *str2 = new char[size2]{'\0'};
    cout << "Enter the string 1 :\n";
    input(str1, size1);
    cout << "Enter the string 2 :\n";
    input(str2, size2);
    output(str1, size1);
    output(str2, size2);
    int joinedArray=StringConcatenate(str1,str2);
    output(str1,joinedArray);
    delete[] str1;
    str1 = nullptr;
    delete[] str2;
    str2 = nullptr;

    return 0;
}
