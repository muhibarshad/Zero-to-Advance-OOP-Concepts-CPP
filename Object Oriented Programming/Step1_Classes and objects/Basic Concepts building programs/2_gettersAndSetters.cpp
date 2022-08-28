
/*Write a C++ program how to write the getters and setters of the class data members.
 */
#include <iostream>

using namespace std;

class mobileOptions
{
private:
    int brightnessValue;
    string screenWallper;
    float todaysTemp;
    char userPassword[20];

public:
    // setters and setData
    void setBrightnessValue(int bright)
    {
        brightnessValue = bright;
    }
    void setScreenWallper(string wallpaper)
    {
        screenWallper = wallpaper;
    }
    void setTodaysTemp(float temp)
    {
        todaysTemp = temp;
    }
    void setUserPassword(char pass[])
    {
        for (int i = 0; i < 20; i++)
            userPassword[i] = pass[i];
    }
    void setData(int bright, string wallPa, float temp, char password[])
    {
        brightnessValue = bright;
        screenWallper = wallPa;
        todaysTemp = temp;
        for (int i = 0; i < 20; i++)
            userPassword[i] = password[i];
    }

    // getters and getData
    int getBrightnessValue()
    {
        return brightnessValue;
    }
    string getScreenWallper()
    {
        return screenWallper;
    }
    float getTodaysTemp()
    {
        return todaysTemp;
    }
    string getUserPassword()
    {
        return userPassword;
    }
    void getData()
    {
        cout << "The brightness value  of the mobile = " << brightnessValue << endl;
        cout << "The screen Wallpaper of the mobile = " << screenWallper << endl;
        cout << "The todays temperature = " << todaysTemp << endl;
        cout << "The user password = " << userPassword << endl;
    }
    
};
int main()
{
    mobileOptions oppo;

    oppo.setData(78, "floating river", 34.7, "hubco123");
    oppo.getData();

    oppo.setTodaysTemp(40);
    oppo.getData();

    cout << oppo.getUserPassword();
    oppo.setBrightnessValue(90);

    oppo.getData();

    return 0;
}