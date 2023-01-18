#include<iostream>
using namespace std;
int main()
{
    char ch[]={'A','L','I',0,'A','B','D','U','L','L','A','H'};
    cout<<ch<<endl;//Ali
    char ch1[]={'A','L','I','\0','A','B','D','U','L','L','A','H'};
    cout<<ch1<<endl;//Ali
    char ch2[]={'A','L','I',' ','A','B','D','U','L','L','A','H','\0'};//string
    cout<<ch2<<endl;//Ali Abdullah
    char ch3[]={'A','L','I',' ','A','B','D','U','L','L','A','H'};//char array
    cout<<ch3<<endl;//Ali
    for(int i=0;i<sizeof(ch);i++){
        cout<<ch[i];//aliabdullah-----ignores the zero
    }
    cout<<endl;
    
    //Another Imporatnt point 
    int x='3'+0;//converted the char to its ascii and then add to 1
    int y='A'+0;//converted the char to its ascii and then add to 1
    int z=0-'9';//converted the char to its ascii and then add to 1
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;
    cout<<"Z = "<<z<<endl;

    return 0;
}