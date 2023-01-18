Key points of the c++
   to get teh answer in floating we divide the varibales are also in float as 
         float 50.0/100.0;


getline(cin,name,'0') is used to wrire the line and it terminates to store the multiline string at the enter of 0
auto is used to store the auto dataTyoe
assignment operaters are also very important 
cerr is used to display the error 


	//This is used to print the line with the characters
    char ch[13];
    cin.get(ch,13);
    cout<<ch;



	//This is used to print the line with the characters and terminates at 's'
    char ch[13];
    cin.get(ch,13,'s');
    cout<<ch;

                                 "Cin.ignore"
//cin.getline is also same as the get but it removes the terminating character but get leaves it
	int x;
	cin>>x;
	string name;
	getline(cin,name);
	return 0;
	/*If we use the cin and after it the string to print with the getline function
	then you use the cin.ignore after the cin because when we use the cin
	and press the enter the new line character \n is stored in the buffer and 
	program stops taking input at the buffer values and so if we want to flush the 
	buffer and continue to taking the input than we should must write the cin.ignore 
	() so enjoy the program the problem is solved
	*/

  "Assign"
  string equals;
   equals.assign(20,'A');
   cout<<equals;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

                      "Rand"
	int randomvalues=time(0);//Get the time function to continue it
	srand(randomvalues);//get 
	//the seedvalue random always different on every execuation from time (0)
    cout<<rand()%8<<" "<<rand()%9;//Generate 
	//the random value from the seed value of srand

}


 simple notes:

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int ch='A';
	cout<<setprecision(3)<<showpoint<<right<<endl;
	cout<<setw(6)<<static_cast<float>(ch);
	int b=8;
	int a=9;
	bool ss=true;
	if(ss==false)
	{
		cout<<"thanks";//0 means that it is false so it does not print it if we add as 56 then it takes 
		//as a true so it prints it if we write as a+b then it as consider as a 8+9=17 17 as a true
	}
	return  0;
}



//Amazing features
a---for to print like a hacking
1c------blue
2c----green
3c----red
4c---light blue
5c---purple
see the picture on the folder where you understand all about the consloe colors
system("color 7c")----------to print in the different color
system("color 0c")--------------same as above
system("cls")--to clear the screen
system("pause:)-----------------------to pause the screen
//	system("C:\\WINDOWS\\System32\\shutdown /s");-------------for shutting down





<!----------IOMANIP---------------!>
ALL BULIT IN FUNCTIONS
SETFILL('*')
cout<<15<<Endl;--------to prin the the number how many times
<1-------cctype----1>
All bulit in functions in it
as iscntrl('\t')------is a control character that controls somethinng like the whitespace detectsthe strings is ended at that poin t 
C++ isalpha()
checks if given character is alphabet or not

C++ isblank()
checks if given character is a blank character

C++ iscntrl()
checks if given character is control character

C++ isdigit()
Checks if given character is a digit or not

C++ isgraph()
checks if given character is graphic or not

C++ islower()
checks if given character is lowercase

C++ isprint()
check if given character is printable or not

C++ ispunct()
check if given character is punctuation character

C++ isspace()
check if given character is whitespace character

C++ isupper()
check if given character is uppercase or not

C++ isxdigit()
checks if given character is hexadecimal character

C++ tolower()
Converts a given character to lowercase

C++ toupper()
Converts a given character to uppercase




switch(c>d?7:8)---------is valid beacuse it returns a integer and its input depends upon the input as integer or character


getch()
this function is used to as two purposes;;;;;;;;;;;;;;one purpose is to end the program when user enter any key ......second purpose when the user enter 
any key then it will store the ascii value of that character and when we display it it will display it ascii value so it is also used in passowords also
like ch[x]=getch().........under loop so when user enter the keys it stores in the getch and when we display the character array than it will disply its values;
like as simple program:
	int size=10;
	char ch[size];
	int x;
	cout<<"Enter the password:"<<endl;
	for(x=0;x<size;x++)
	{
		ch[x]=getch();//store the valuess of input in the getch() 
		cout<<"*";//disply the * as passwor is running
	}
	ch[x]='\0';//its means that at x=10 value is null character
	cout<<endl;
	cout<<"You have entered the hidden password:"<<endl;
	for(x=0;ch[x]!='\0';x++)
	{
		cout<<ch[x];
	}
	getch();
	final_computer=computer_play(add);
	final_user=user_play(sum);
	if(final_computer>final_user)
	{
		cout<<endl<<endl<<endl<<endl;
		cout<<"Computer wins the game"<<endl;
	}
	else if(final_computer<final_user)
	{
		cout<<endl<<endl<<endl<<endl;
		cout<<"You wins the game"<<endl;		
	}
	else
	{
	    cout<<endl<<endl<<endl<<endl;
		cout<<"The match is tie!"<<endl;
	}

//Conio.h
LIST OF INBUILT C FUNCTIONS IN CONIO.H FILE:
    Functions Description
  clrscr() This function is used to clear the output screen.
  getch() It reads character from keyboard
  getche() It reads character from keyboard and echoes to o/p
                      screen
  textcolor() This function is used to change the text color
  textbackground() This function is used to change text background
kbhit() is used to enter any keyboard key is hit
exit(0 or 1) is used to terminate the program when the exit function is used  


to know the length of the array the logic is as sizeof(arr)/sizeOfint;
sleep(x)------function can be supported by <unisted.h> library take parameter in seconds
usleep(x)------can aslo be used for the sleep but take parameter in milliseconds





        Most important logic____________
    bool flag =false;
    for(int i=0;ch[i]!='\0' && !flag;i++)
    {
        if(ch[i]==se)
        {
            index=i;
            flag=true;
        }
    }

#include<dos.h>
dealy(millisecond)
sleep(millisecond)
sound(int frequency)
nosiund();



#define in C++
 using namespace std;
#define PI 3.14
#define CIRC(d) (PI*d)
int main() {
cout « "Please supply a diameter
« endl;
int d;
cin >> d;
float circumference CIRC(d);
cout << circumference << endl;|
return 0;

}

it is basically a preprocesor directive and gives as the value of define in a code where we should to be want



extra important Concepts:
Enum used for fixed initilizations and also be used for the 
Union struct to get the maximum attribute size of bytes
static varibles can be used in the place of global variables
recursive function
file handling 
all notes
