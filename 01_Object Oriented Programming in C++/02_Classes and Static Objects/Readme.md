# Classes and Static Objects

[What are classes 👀 ❓](#classes-and-object)

## Basic Syntx of class:

  <p align="center">
    <img src="/04_Material/CodeSnaps/class1.png" style="height: 40vh; padding-left: 50vh;">
 </p>

## Basic Syntx of object:

  <p align="center">
    <img src="/04_Material/CodeSnaps/obj.png" style="height: 40vh; padding-left: 50vh;">
 </p>

we cannot access the dataMemebers of the class outside the class .Their members are by `default-private`.So when we want to access them .The error should come as

  <p align="center">
    <img src="/04_Material/CodeSnaps/error1.png" style="height: 40vh; padding-left: 50vh;">

> so when we want to access them outside the class,we use the `access-identifiers`.

## Access-Identifiers

There are there Access specifiers.

- ### Public
  Memebers of public are accessible from anywhere(accissble through the object).
- ### Private
  Members declerad as private are only accessible within the class.
- ### Protected
  Members are only accessible in child class.

Result:

<p align="center">
<img src="/04_Material/CodeSnaps/result_class.png" style="height: 60vh; padding-left: 50vh;">

### Note:

> The address of a class is same as the address of the first dataMemeber of the class
