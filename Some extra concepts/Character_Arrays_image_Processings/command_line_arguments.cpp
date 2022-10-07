#include<iostream>
#include<typeinfo>//give the dataType of varible (typeid(varibleName).name()--------except the strings)
using namespace std;
int main(int argc,char *argv[])
{
    
    int sum=0;
    cout<<"The total number of arguments are passed into the main function "<<argc<<endl;
    //Arguments that are passed are also includes the name of the .exe file
    cout<<"The arguments that are passed given as:"<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"Argument no "<<i<<" "<<argv[i]<<endl;
        sum+=atoi(argv[i]);
        /*Atoi:(alphanumberic to integer)
        1-Converts the only numbers string into the integer
        2-Coverts the alphabatic string into the 0 integer digit(falsy)
        */
    }
    cout<<"The sum of all the nuumbers strings = "<<sum<<endl;
    
    return 0;
}