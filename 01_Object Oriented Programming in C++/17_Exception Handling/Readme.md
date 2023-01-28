# Why we need Exception handling?

`Error handling` in `C programming` is not natively supported, but programmers can access low-level error information through return values. When an error occurs, C functions typically return a value such as `-1` or `NULL`. Programmers can then check these values and take appropriate action. However, using **control structures** like `if-else statements` to handle errors can be unreliable. For example, a function that calculates the quotient of a division operation may `return 0` when a division-by-zero error occurs. But since 0 is also a valid quotient, it's hard for the calling program to determine if an error has occurred. In these cases, more advanced `error handling` techniques are necessary.

# Exceptions

> `C++` offers an exception handling mechanism to handle errors or unexpected events that occur during program execution. These exceptions are **run-time errors** or abnormal conditions that the program encounters. **Exception handling** in `C++` is an advantage over `C`, as it provides a structured way to handle such situations.

`C++` provides the following specialized `keywords` for this purpose.

- **try** : represents a block of code that contains success scenario code or it
  can throw an exception in case of error.
- **catch** : represents a block of code that is executed when a particular
  exception is thrown. It contains alternate scenario code.
- **throw** : Used to throw an exception.

_The try and catch keywords come in pairs,If an exception is thrown from a function and there is no catch block to handle it, the program will crash with an error message indicating that the exception was not handled._



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-1.png" style="height: 30vh; padding-left: 40vh;">
    
</p>



## Important Points

- Exceptions can be of any type such as `int`, `float`, `char*`, or `class objects`.
- The `catch block` must be parameterized with the relevant data type of the exception thrown.
- Multiple `catch blocks` with different parameters can be used and the appropriate one will execute based on the type of exception thrown.
- A **function** can either handle exceptions by including local `try-catch blocks` or throw them to be handled by the caller.

### Default Catch-block

A `catch block` with the **ellipsis (...)** will catch any type of exception thrown. It can be used as a **default handler** for any unhandled exceptions. Example: `catch(...)` Default exception handling.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-2.png" style="height: 60vh; padding-left: 70vh;">
    
</p>



## Object Oriented Approach for Exceptions

In `C++`, we can use classes to create **custom exception types** that can be thrown and caught in a more readable and organized way. Instead of throwing raw `integers` or `strings`, we can create a class that represents a specific type of exception and throw an `object` of that `class`.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-3.png" style="height: 70vh; padding-left: 80vh;">
    
</p>



## System defined exception Classes

> In `C++`, there are several **built-in exception** classes that can be used to handle specific types of errors. These classes are defined in the `<stdexcept>` header file.

1. `bad_alloc`: This exception is thrown by the new operator when memory allocation fails.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-4.png" style="height: 30vh; padding-left: 40vh;">
    
</p>



2. `bad_cast`: This exception is thrown by the dynamic_cast operator when a cast is not valid.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-5.png" style="height: 40vh; padding-left: 50vh;">
    
</p>



3. `bad_typeid`: This exception is thrown by the typeid operator when it is used with a null pointer.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-6.png" style="height: 30vh; padding-left: 40vh;">
    
</p>



4. **logic_error**: This is a base class for other exception classes that indicate errors in program logic.
   **invalid_argument**: This exception is thrown when an invalid value is passed to a function.



<p align="center">
    <img src="/04_Material/CodeSnaps/exception-7.png" style="height: 40vh; padding-left: 50vh;">
    
</p>



5.  `underflow_error`: This exception is thrown when the result of an arithmetic operation is smaller than the smallest number that can be stored in a given numeric type.



 <p align="center">
    <img src="/04_Material/CodeSnaps/exception-8.png" style="height: 30vh; padding-left: 40vh;">
    
</p>



6. `length_error`: This exception is thrown when an `object's size` exceeds its allowed maximum range.
7. `out_of_range`: This exception is thrown when a value, such as a `subscript` into an `array`, exceeds its allowed range of values.
8. `runtime_error`: This is a `base class` for other exception classes that indicate `execution-time` errors.
9. `overflow_error`: This exception is thrown when the result of an *arithmetic operation* exceeds the largest number that can be stored in a given numeric type.
