
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

    // setters
    void setBrightnessValue()
    {
        cin >> brightnessValue;
    }
    void setScreenWallper()
    {
        cin >> screenWallper;
    }
    void setTodaysTemp()
    {
        cin >> todaysTemp;
    }
    void setUserPassword()
    {
        cin.getline(userPassword, 20);
        cin.ignore();
    }

    // getters
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
    
    //setData and getData
    void setData(int bright, string wallPa, float temp, char password[])
    {
        brightnessValue = bright;
        screenWallper = wallPa;
        todaysTemp = temp;
        for (int i = 0; i < 20; i++)
            userPassword[i] = password[i];
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
   
    oppo.setTodaysTemp();
    oppo.getData();

    cout<<oppo.getUserPassword();
    oppo.setBrightnessValue();

    oppo.getData();


    return 0;
}