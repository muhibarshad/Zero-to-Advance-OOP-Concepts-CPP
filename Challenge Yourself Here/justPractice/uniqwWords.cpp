#include <iostream>

using namespace std;

int main()
{
    char input[2000] = "Earth is the third planet from the Sun and the only astronomical object known to harbour and support life. About one third of its surface is land consisting of continents and islands. The remaining two third is covered with water, mostly by oceans, seas, gulfs, and other salt water bodies, but also by lakes, rivers, and other freshwater, which together constitute the hydrosphere. Much of Earth's polar regions are covered in ice. Earth's outer layer is divided into several rigid tectonic plates that migrate across the surface over many millions of years, while its interior remains active with a solid iron inner core, a liquid outer core that generates Earth's magnetic field, and a convective mantle that drives plate tectonics. Earth's atmosphere consists mostly of nitrogen and oxygen. More solar energy is received by tropical regions than polar regions and is redistributed by atmospheric and ocean circulation. Greenhouse gases also play an important role in regulating the surface temperature. A region climate is not only determined by latitude, but also by elevation and proximity to moderating oceans, among other factors. Severe weather, such as tropical cyclones, thunderstorms, and heatwaves, occurs in most areas and greatly impacts life.";

    int curIndex = 0;
    do
    {
        char ch[] = "";
        for (int i = 0; input[curIndex] != ' ' && input[curIndex] != '.' && input[curIndex] != ','; curIndex++, i++)
        {
            ch[i] = input[curIndex];
            if (input[curIndex + 1] == ' ' || input[curIndex] == '.' || input[curIndex] == ',')
            {
                ch[i + 1] = '\0';
            }
        }
        cout << ch;
        curIndex++;
    } while (input[curIndex] != '\0');
    return 0;
}