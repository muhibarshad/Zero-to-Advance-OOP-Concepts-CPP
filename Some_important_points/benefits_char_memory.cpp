/*In 1 byte(8 bits ) we can actually store the numbers from 0 to 255 and -127 to 129 in unsigned
so to reduce memeory use the character dataTye if we have any number in the range of that 
*/
#include<iostream>
using namespace std;
int main()
{
    // unsigned
    unsigned char ch1=0,ch2=30,ch3=150,ch4=257,ch5=-34,ch6=-120,ch7=-127,ch8=-129;
    //To get the values as : range more than the 127 and less than 255 than minus the digit from the
    //
    cout<<ch1<<endl;
    cout<<ch2<<endl;
    cout<<ch3<<endl;
    cout<<ch4<<endl;
    cout<<ch5<<endl;
    cout<<ch6<<endl;
    cout<<ch7<<endl;
    cout<<ch8<<endl;
    cout<<int(ch1)<<endl;
    cout<<int(ch2)<<endl;
    cout<<int(ch3)<<endl;
    cout<<int(ch4)<<endl;
    cout<<int(ch5)<<endl;
    cout<<int(ch6)<<endl;
    cout<<int(ch7)<<endl;
    cout<<int(ch8)<<endl;
    cout<<int(ch1+ch2+ch3+ch4+ch5+ch6+ch7+ch8)<<endl; 
    char ch10=int(20);
    cout<<ch10<<endl;
    cout<<int(ch10)<<endl;

    // //signed
    // char ch1=0,ch2=30,ch3=150,ch4=255,ch5=-34,ch6=-120,ch7=-127,ch8=-129;
    // cout<<ch1<<endl;
    // cout<<ch2<<endl;
    // cout<<ch3<<endl;
    // cout<<ch4<<endl;
    // cout<<ch5<<endl;
    // cout<<ch6<<endl;
    // cout<<ch7<<endl;
    // cout<<ch8<<endl;
    // cout<<int(ch1)<<endl;
    // cout<<int(ch2)<<endl;
    // cout<<int(ch3)<<endl;
    // cout<<int(ch4)<<endl;
    // cout<<int(ch5)<<endl;
    // cout<<int(ch6)<<endl;
    // cout<<int(ch7)<<endl;
    // cout<<int(ch8)<<endl;
    // cout<<int(ch1+ch2+ch3+ch4+ch5+ch6+ch7+ch8)<<endl;



    return 0;
}