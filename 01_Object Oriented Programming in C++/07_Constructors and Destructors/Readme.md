# Constructors and Destructors

### Defination:

> It is a function.It does not have any `return type`(like int,void). It has same name as of its class.They can never be called instead(they can be more than two ) are called and executed automaticallu on the time of creation oof object.Their main purpose to initialze the data members of an object being created.

Every object will be called only once in its lifetime by the constructor until it is destroyed. The compiler gives us a default constructor, but it initializes the data members with garbage values. If any one of the constructors is written, then the compiler does not give its default constructor. Constructors are of three types:

- Default Constructor
- Parameterized Constructor
- Copy Constructor
