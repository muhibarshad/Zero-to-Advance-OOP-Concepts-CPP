 # Binding

- Compile Time
- Run Time(Polymorphism)
  - Abstract class

## Compile Time Binding

- Also Known as `early binding` or `static binding`
- Call the functions on object according to the type of object.
- Cannot change `compile time binding` of `static objects`.
- Can be changed for `pointers` or `reference` to objects.

### Object slicing

`Object slicing` occurs when a derived class object is assigned to a base class object, causing loss of data specific to the derived class. To avoid this, use `pointers` or `references`.

### base and derived pointer

A **base pointer** is a pointer variable of a base class type that can point to an object of the base class or any of its derived classes. This is known as polymorphism, which means that a **single pointer** can be used to refer to objects of different types at `runtime`.

### base and derived references

A `base reference` is a reference variable of a base class type that can refer to an object of the **base class** or any of its derived classes. This is also known as polymorphism, which means that a single reference can be used to refer to objects of different types at `runtime`.

### Important Note👀

- Every `derived` **is a**  `base` but every `base` **is not a** `derived`.
- `Derived pointer` **can't** point to `base object` same in case of `references`
- But if you really want to point derived pointer to base object,so for that that you have to do **Down Casting or Dynamic casting**.`Dynamic casting` will only work correctly in case of pointers for the references there is no way to do it.

//inheritance-6(photo)

### Summary

- - A `static object` of a base class can only call **base class functions**.
- A `static object` of a derived class can call both derived class functions and `inherited functions`.
- When a base class `static object` is **assigned** to a `derived class` static object, `slicing` occurs and only the base data is **copied** into the base object.
- Attempting to **assign** a `derived class` static object to a `base class` static object results in an **error** and an explicit cast is required.
- A base `class pointer` or `reference` can call base class functions when **pointing or referring** to a base class object.
- A `base class pointer` or `reference `can **only call** `base class` functions when pointing or referring to a derived class object.
  Attempting to use a `derived class pointer` or `reference` **to refer** to a base class object **results** in an **error** and an explicit cast is required.
- A derived class pointer or reference can call both derived class functions and inherited functions when pointing or referring to a derived class object.

### Example Code

```cpp
#include <iostream>

class Base {
public:
    int x;
    Base(int x) : x(x) {}
};

class Derived : public Base {
public:
    int y;
    Derived(int x, int y) : Base(x), y(y) {}
};

int main() {
    Derived d(1, 2);
    Base b = d;  // Object slicing occurs here
    std::cout << "b.x: " << b.x << std::endl;
    //std::cout << "b.y: " << b.y << std::endl;  // Error: 'y' is not a member of 'Base'

    Derived* dp = &d;
    Base* bp = dp;  // Base pointer can point to Derived object
    std::cout << "bp->x: " << bp->x << std::endl;
    //std::cout << "bp->y: " << bp->y << std::endl;  // Error: 'y' is not a member of 'Base'

    //but Note
    // Derived *ptr=new  Base(2);
    //Error:Every derived is a base but every base is not a derived.
//Allowed if explicit cast(dynamic casting by which derived class pointer can also point to base class object) made


    Derived& dr = d;
    Base& br = dr;  // Base reference can refer to Derived object
    std::cout << "br.x: " << br.x << std::endl;
    //std::cout << "br.y: " << br.y << std::endl;  // Error: 'y' is not a member of 'Base'

    return 0;
}

```

## Runtime Binding

Poly means **Many** Morphism mean **Forms**

### why we need it?

- `Polymorphism` allows for the same base **type behavior** to be changed according to the object of the derived class.
- With `polymorphism`, objects can be commanded and used without knowing their types explicitly.
- `Polymorphism` allows for programs to be extended with more functionalities through derived classes.
- A single array of the base class can be used to **collect all different objects** of the `derived class`.
- The base class represents a larger set for all objects (base and derived) which allows for more **flexibility and reusability** in the code.

### conditions

1. Only base class inherited functions can be called through `base pointer`.
2. Override base class function in derived classes.
3. Change Compile time binding of functions to Run time binding,
   i) `Run time binding`: Call functions **according to object type not pointer type**.
   ii) Make functions `virtual` in base class.
   - Inherited as `virtual` in all derived classes, no need to make virtual again.
   - All `virtual functions` binding change to `runtime`.

### Example Code

```cpp
class Shape {
public:
    virtual void Draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Rectangle: public Shape {
public:
    void Draw() {
        cout << "Drawing a rectangle." << endl;
    }
};

class Circle: public Shape {
public:
    void Draw() {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shape1 = new Rectangle();
    Shape* shape2 = new Circle();
    shape1->Draw(); // Output: "Drawing a rectangle."
    shape2->Draw(); // Output: "Drawing a circle."
    return 0;
}

```

## Abstract class

### Defination

An `abstract class` is a class that cannot be instantiated and is used as a base for other classes that provide specific implementations of the `abstract class's` functions. It is defined using the `virtual keyword` and can have both pure virtual functions **(indicated by = 0)** and **non-pure virtual functions** (with implementation).

### Why we need it?

- **To provide a common interface for related classes:** An `abstract class` can define a **common interface** that must be implemented by its derived classes. This allows for a consistent way of interacting with objects of different types that share a **common interface**.

- **To define a base class for a hierarchy of classes:** An `abstract class` can be used as the base class for a hierarchy of classes that represent different levels of abstraction or **different implementations of a common concept**.

### Example code

```cpp
class Animals {
public:
    virtual void MakeNoise() = 0;
    virtual void Move() = 0;
};

class Dog : public Animals {
public:
    void MakeNoise() { cout << "Woof!" << endl; }
    void Move() { cout << "Running" << endl; }
};

class Cat : public Animals {
public:
    void MakeNoise() { cout << "Meow!" << endl; }
    void Move() { cout << "Walking" << endl; }
};

```
