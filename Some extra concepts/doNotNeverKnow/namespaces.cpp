#include<iostream>
#include"add.h"

int main()
{
    std::cout<<"Hello World\n";
    std::cout<<add::sum(2,2)<<"\n";
    std::cout<<sub::sum(2,2)<<"\n";
    std::cout<<::sum(2,2)<<"\n";
}

//Calling the namespace function inside it gives the its local same name function but if we use the scope resolution operaor with it then its fund it in teh global scope abd print it 

// nested namespaces as (namespace goo::foo)

//=================================
//======Best_Practice___________
//=================================
//make the prototypes of all the namepace in the add.h file the make functions in the add.cpp then add the "add.h" header file into the main.