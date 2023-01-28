# C++ Templates

**C++ templates** are a powerful feature of the C++ programming language that allow for the creation of `generic functions and classes`. They allow programmers to write code that can work with a wide range of types, without the need for `explicit type declarations`.

# Defining Templates

Templates in C++ are defined using the keyword **"template"** followed by **angle brackets** (< and >) that enclose the type(s) that the template will work with. For example, the following is a simple template for a function that finds the maximum of two values:

<p align="center">
    <img src="/04_Material/CodeSnaps/Template1.png" style="height: 60vh; padding-left: 60vh;">
 </p>

In this example, the template keyword is followed by the type parameter "typename T", which represents the type that the `function` will work with. The function itself takes two arguments of type T and returns the maximum of the two.

# Using Templates

When the function is called, the compiler will automatically generate a version of the function for the specific types passed as arguments. For example, the following call to the max() function will generate a `version` of the function that takes two integers and returns an integer:

 <p align="center">
    <img src="/04_Material/CodeSnaps/Template2.png" style="height: 60vh; padding-left: 60vh;">
 </p>

Templates can also be used to create **generic classes**. For example, the following is a simple template for a stack class:

 <p align="center">
    <img src="/04_Material/CodeSnaps/Template3.png" style="height: 70vh; padding-left: 80vh;">
 </p>

In this example, the `Stack class` is defined with a single type parameter "typename T", which represents the type of the elements stored in the stack. The class has an array of elements of type T, and a variable "top" that keeps track of the top element of the stack. The class has three member functions: push, which adds an element to the stack; pop, which removes the top element from the stack; and empty, which returns true if the stack is empty.

When an object of the Stack class is created, the compiler will automatically generate a version of the class for the specific type passed as the **template argument**. For example, the following code creates a stack of integers:

<p align="center">
    <img src="/04_Material/CodeSnaps/Template4.png" style="height: 50vh; padding-left: 50vh;">
 </p>

Templates can also have `multiple type parameters`, for example:

 <p align="center">
    <img src="/04_Material/CodeSnaps/Template5.png" style="height: 50vh; padding-left: 50vh;">
 </p>

C++ also allows for `non-type template parameters`, for example:

 <p align="center">
    <img src="/04_Material/CodeSnaps/Template6.png" style="height: 50vh; padding-left: 50vh;">
 </p>

# Conclusions

Templates are a very powerful feature in C++, but they can also make the code `more complex`, especially when dealing with template specialization and overloading. Furthermore, the compilation time can increase when using templates, especially when using a large number of templates or when using templates with complex types.

In conclusion, C++ templates are a **powerful**.
