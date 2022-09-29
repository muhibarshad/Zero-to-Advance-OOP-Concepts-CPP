
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
void completeSentence(char *&str, const char currentLetter, int &totalLetters)
{
    char *temp = new char[totalLetters + 1];
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp[i] = str[i];
    }
    temp[totalLetters - 1] = currentLetter;
    temp[totalLetters] = '\0';
    delete[] str;
    str = temp;
    totalLetters++;
}
int main()
{
    int totalLetters = 1;
    long int startTime = time(0);

    char *str = new char[totalLetters]{'\0'};
    char currentLetter = '\0';
    while (currentLetter != 13)
    {
        while (!kbhit())
        {
            system("cls");
            long int currentTime = time(0);
            cout << "Time Passed away   = " << currentTime - startTime << "\n";
            system("cls");
            cout << "\n\n";
            cout << "Total Letters you have written = " << totalLetters - 1 << "\n";
            cout << "\n\n\n\n\n";
            for (int i = 0; str[i] != '\0'; i++)
            {
                cout << str[i];
            }
            completeSentence(str, currentLetter, totalLetters);
        }
        currentLetter = getch();
    }
    delete[] str;
    str = nullptr;

    return 0;
}
