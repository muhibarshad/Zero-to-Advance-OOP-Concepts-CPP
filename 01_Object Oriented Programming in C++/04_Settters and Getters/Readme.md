# Setters and Getters

**_Why we need setters and getters_** ? What is the importance of getters and setters in the real world? For example, in mobile phones, when we want to increase the brightness, we don't have to navigate through the entire settings menu, we can simply use a getter and setter to change the brightness directly. **\*NO\*\*** .We only use setters when we want to change the value of brightness, and we use getters when we want to retrieve information, such as a phone number. Getters and setters allow us to easily access and update individual data members or groups of data members.

## Setters

> Used to set or update values of individual data members or a complete object.

### Basic Syntax:

- **_Void setVariableName (varaibleDataType parameterName){ variableName = ParameterName;}_**
   <p align="center">
   <img src="/Some%20extra%20concepts/codeSnaps/setters.png" style="height: 60vh; padding-left: 50vh;">
</p>

## Getters

> Used to get values of indiviual or complete object .

### Basic Syntax:

- **_returnType getVariableName (){ return variableName;}_**
     <p align="center">
     <img src="/Some%20extra%20concepts/codeSnaps/getters.png" style="height: 60vh; padding-left: 50vh;">
  </p>

  ## SetData and getData

Getters and setters are also member functions of a class. They allow for the setting and retrieval of the class' data members.

```cpp
/*Write a C++ program that demonstrates how to store data in private data members of a class using setters and retrieve the data using getters.
 */
#include <iostream>

using namespace std;

class algebra
{
private:
    int x;
    int y;
    float z;

public:
    void putData(int xA, int yA, int zA)
    {
        x = xA;
        y = yA;
        z = zA;
    }
    void getData()
    {
        cout<<"The value of x = "<<x<<endl;
        cout<<"The value of y = "<<y<<endl;
        cout<<"The value of z = "<<z<<endl;
    }
};

int main()
{
    algebra equation1;

    //Test 01:
    equation1.putData(1,2,3);
    equation1.getData();
    return 0;
}
```

### Practice exapmles:

- [Getters and Setters in C++ ](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/2_gettersAndSetters.cpp)
- [getData and setData in C++ ](/Object%20Oriented%20Programming/Step1_Classes%20and%20objects/Basic%20Concepts%20building%20programs/1_getData_and_putData.cpp)
