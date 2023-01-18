/*There are many ways to achieve the exception handling.
   By simple try, throw any dataType , catch it
   By using multiple catches the throwed dataType matched catch block will exe.
   By using catch(...){} it can exe. default it can exe any throw which is firstly throwed
   BY throwing object use refernce of object in catch block then call the static attached error function
   By Inherited the Exception class to your error class and and pass the constructor msg to :exceptio(msg){} then override the virtual const char*what() const {} func by adding your won comments and then return the exception::what(); of the base class.
   By using system ddefaut inherited classes like bad_alloc , out_ofRange like
*/
