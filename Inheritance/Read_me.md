
#//=============================
#//Constructors Inheritance
#//=============================
<!-- When The derived class has no any constructor than ,only the default constructor of base class is 
called always not the paramterized cinstructor.
When we make an object of the derived class than firstly the default constructor of the base class is 
called than the deafult constructor of the derived class will called.
When we make an object and pass argument to the parameterized constructor than firstly the default constructor 
of the base class is called than the parameterized construstor of the derived class will called.So remember that 
in paramterized derived class calling not the parameterized constructor of he base class.okay!
So to solve this problem use the syntx as 
derived(int n):base(n)
{

} -->




#/*=============
#Overriding the function members
# =============*/
<!-- Supppose We have two public same name member functions in the base and derived class.
now derived class is inherited publicly from the base class.
we use that member function in the object of derived class.So ,which member function can be callled?
Ans:The member function of the derived class will be called ,remember that always the new modifiaction in the cars
we feel during driving after the modification not the previous one .This process is called the 
overriding of the member functions . -->
