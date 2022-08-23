<p align="center">
    <img src="/Some%20extra%20concepts/logo.jpg" style="height: 60vh; padding-left: 50vh;">
</p>

# Zero to Advance OOP Course in C++
>This course helps you to cover all `OBJECT-ORIENTED-PROGRAMMING` concepts .By providing proper documentation of example codes with testing portions, attached slides with every topic, external links thats help to get benefit from them without straggling on internet a lot of hours 🤔.The one plus point for you is that every thing is in the complete `road-map` means you go through step by step without jumping to mixed topics.✨
# Contents
1. [Dynamic Arrays](#dynamic-arrays)       
2. [Core Concepts](#core-concepts)             
3. [Classes and Objects](#classes-and-objects)       

# Dynamic Arrays

# Core Concepts
  A langugae which containes these four segments is referrred as ***Object-Oriented-Programming*** language.
 * ## Classes and object :
    Classes have no exixtence in the memeory,its only a blueprint.When we make an object of that class ,then it should having the some memeory.Class is an user defined-data-Type, called as ***ABSTRACT_DATA_TYPE***.
 * ## Data hiding and Encapsulation:
    Data is hided from every another object is data hiding .All the memebers of a class including data members and member functions are closed in a class like a capsule is referred to as Encapsulation.This feature opens the new term named as `Abstraction` means all the inner details are completetly ifnored and we focus on the working of the software.
 * ## Inheritance:
    ***Do not reinvent the wheel***.In programming the term used as : **Do not repeat the code⛔**.Inheritance has the code reuse-ability.Some features are inherited from the base class and given to the derived class.If any language does not support the inheritance then its not calle the Object oriented programming language its called the ***Object-Based-Language**.
 * ## Polymorphism
  Define as : Single interface having multiple functionalities.(same name different behaviour).
  It has two types :
   * Static
      Function overloading is done in static polymorphism.It has be achieved on the compile time also called the ***compile_time_binding***. 
   * Dynamic
      Function overriding is done in the dynamic polymorphism.It has be achieved on the run time also called the ***Run_Time_binding***.


# Classes and Objects
  [What are classes  👀 ❓](#classes-and-object)
  ## Basic Syntx of class:
  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/class1.png" style="height: 40vh; padding-left: 50vh;">
 </p>

  ## Basic Syntx of object:
  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/obj.png" style="height: 40vh; padding-left: 50vh;">
 </p>
 
  we cannot access the dataMemebers of the class outside the class .Their members are by `default-private`.So when we want to access them .The error should come as 

  <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/error1.png" style="height: 40vh; padding-left: 50vh;">

 >so when we want to access them outside the class,we use the `access-identifiers`.

 ## Access-Identifiers
  There are there Access specifiers.
* ###  Public
     Members declerad as private are only accessible within the class.
* ### Private
     Memebers of public are accessible from anywhere(accissble through the object).
* ### Protected
     Members are only accessible in child class.

 Result:
    <p align="center">
    <img src="/Some%20extra%20concepts/codeSnaps/result_class.png" style="height: 60vh; padding-left: 50vh;">

   ### Note:
   >The address of a class is same as the address of the first dataMemeber of the class

 ## Summary:
  * To practice real-world examples [class and object examples](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/)
  * To go through slides [Class and object slides](/Some%20extra%20concepts/Slides/classes.pdf)
  * For reading more concepts explore this page [Deep learn class and objects](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/) 



  
 