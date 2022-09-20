#include <iostream>

using namespace std;

string wordByWord(const char input[], int &totalWords, string *&arr, bool flag)
{
    int curIndex = 0;
    int index = 0;
    string *temp = new string[totalWords]{};
    do
    {
        int count = 0;
        string searchWord;
        for (int i = 0; input[curIndex] != ' ' && input[curIndex] != '.' && input[curIndex] != ',' && input[curIndex] != '\''; curIndex++, i++)
        {
            searchWord.push_back(input[curIndex]);
        }
        if (searchWord != "" && flag == false)
        {
            totalWords++;
        }
        if (searchWord != "" && flag == true)
        {
            temp[index] = searchWord;
            index++;
        }
        curIndex++;
    } while (input[curIndex] != '\0');

    arr = temp;
}

int main()
{
    char input[2000] = "Earth is the third planet from the Sun and the only astronomical object known to harbour and support life. About one third of its surface is land consisting of continents and islands. The remaining two third is covered with water, mostly by oceans, seas, gulfs, and other salt water bodies, but also by lakes, rivers, and other freshwater, which together constitute the hydrosphere. Much of Earth's polar regions are covered in ice. Earth's outer layer is divided into several rigid tectonic plates that migrate across the surface over many millions of years, while its interior remains active with a solid iron inner core, a liquid outer core that generates Earth's magnetic field, and a convective mantle that drives plate tectonics. Earth's atmosphere consists mostly of nitrogen and oxygen. More solar energy is received by tropical regions than polar regions and is redistributed by atmospheric and ocean circulation. Greenhouse gases also play an important role in regulating the surface temperature. A region climate is not only determined by latitude, but also by elevation and proximity to moderating oceans, among other factors. Severe weather, such as tropical cyclones, thunderstorms, and heatwaves, occurs in most areas and greatly impacts life.";

    int totalWords = 0;
    int times = 0;
    bool flag = false;
    string *arr = nullptr;
    int *count=nullptr;

    wordByWord(input, totalWords, arr, flag);  // calculating_Num_ofWords
    count= new int[totalWords];
    wordByWord(input, totalWords, arr, !flag); // putting_words_to_arrays

    for (int i = 0; i < totalWords; i++)
    {
        times = 1;
        for (int j = i + 1; j < totalWords; j++)
        {
            if (arr[i] == arr[j])
            {
                times++;
                count[j] = -1;
            }
        }
        if (count[i] != -1)
        {
            count[i] = times;
        }
    }

    for (int i = 0; i < totalWords; i++)
    {
        if (count[i] != -1)
        {
            cout << arr[i] << " occurred " << count[i] << " times in this paragraph:"
                 << "\n";
        }
    }

    delete[] arr;
    delete[] count;
    count=nullptr;
    arr = nullptr;

    return 0;
}
