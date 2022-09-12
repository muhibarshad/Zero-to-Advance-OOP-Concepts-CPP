#include<iostream>
#include"add.h"

int main()
{
    std::cout<<"Hello World\n";
    std::cout<<add::sum(2,2)<<"\n";
    std::cout<<sub::sum(2,2)<<"\n";
    std::cout<<::sum(2,2)<<"\n";
}
