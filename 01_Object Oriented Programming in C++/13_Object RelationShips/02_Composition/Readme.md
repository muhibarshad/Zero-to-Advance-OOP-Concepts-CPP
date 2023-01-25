# Composition

## Defination

> It is case where one `object(part)` is a** part** of another `object(whole)`.It is also known as `part-whole relationship`.It is** strong relationship** because ownership is involved.

<p align="center">
    <img src="/04_Material/CodeSnaps/composition.png" style="height: 70vh; padding-left: 0vh;">
 </p>

### To qualify for composition 😎 ?

> 1. The part(`member`) is part of the object(`class`).

#### explanation

As in the picture, `class B` is a part of `class A`, it means that `class B` behaves as a data member for `class A`. This is an example of `aggregation,` where `class B` is being used by `class A` but `class B` is independent of `class A` and can exist on its own.

> 2. The part(member) can only belong to one object(class) at a time.

#### explanation

As in the above picture, it is clear that `class B` is a private data member of `class A`, so it can not be a data member of another class at the same time. This makes sense, since `class B` is a part of `class A` and cannot be shared with another class. This relationship between `class A` and `class B` is an example of aggregation, where `class B` is used by `class A` but is independent and can exist on its own.

> 3. The part(member) has its existence managed by the object(class).

#### explanation

When `object` of** A** is created `object` of
** B** is created inside** A** too.
When `object` of** A** is destroyed part
`object` of** B** is also destroyed.

> 4. The part(member) does not know about the existence of the object(class).

#### explanation

The creation and destruction of `class B` (a data member of `class A`) does not affect or control the creation and destruction of an object of `class A`. This is an important aspect of `aggregation`, where the lifetime of the contained class `(class B)` is independent of the containing class `(class A)`. The containing class `(class A)` may create and destroy instances of the contained class `(class B)` as needed, but the contained class `(class B)` can also exist independently and potentially be used by other classes.

## why there is a need of composition ? 👀

<p align = "center">
<img src = "/04_Material/CodeSnaps/composition1.png" style = "height: 70vh; padding-left: 50vh;">
</p>

### Note

In the above picture :
Single `class` **person** controls every thing.

##### Disadvantages

- Not scalable
- Error prone
- Not reusable in other `class`
- Redefine all `attributes` and `functions` separately for other classes
- For example student, doctor teacher, and patient

<p align = "center">
<img src = "/04_Material/CodeSnaps/composition2.png" style = "height: 70vh; padding-left: 50vh;">
</p>

### Note

In the above picture :
-Design separate `classes`(name, date, address, person).

- Add `objects`(name, date, address) as `variables` in `class`(** person**).

##### Advantages

- Scalable
- Less Error prone
- Reusable in other `classes` such as
  student, doctorand teacher, patient
- No need to redefine all `attributes` and
  `functions` separately for other classes

### calling sequence 👀

<p align = "center">
<img src = "/04_Material/CodeSnaps/composition3.png" style = "height: 70vh; padding-left: 50vh;">
</p>

-`Default constructor`: in **same order** as defined objects in `class`
1)name 2)date 3)address 4)person

- `Destructor`: in **reverse order** as defined objects in class
  1)person 2)address 3)date 4)name
- `Parametrized constructor`: called in **order of member initializer syntax**
  : dateofBirth(d, m, y), pname(fn, ln), paddress(city, country, street, house)
  1)date 2)name 3)address 4)person

```cpp

#include<iostream>
using namespace std;
#include<cstring>

class Address
{
    int houseNo;
    char blockNo;
    char town[30];
    char city[30];

public:
    Address(int h, int b, char* t, char* c) // Parameterized constructor
    {
        houseNo = h;
        blockNo = b;
        strcpy(town, t); // strcpy( ) is a built - in function used
        //to copy one string(character array) to another, However, we can also define our own function.strcpy(city, c);
    }
    friend ostream& operator<<(ostream& out, const Address& a)
    {
        out << "House No:" << a.houseNo << '\n';
        out << "Block No:" << a.blockNo << '\n';
        out << "Town:" << a.town << '\n';
        out << "City:" << a.city << '\n';
        return out;
    }
};

class Employee
{
    static int employeeCount; // To Assign employeeID
    int employeeID;
    char name[50];
    Address address;
    int salary;
public:
    // Parameterized Constructor to initialize the Address of the employee

    Employee(int s, char* n, int h, char b, char* t, char* c)
        : address(h, b, t, c)
    {
        employeeID = employeeCount;
        strcpy(n, name);
        salary = s;
        employeeCount++;
    }
    friend ostream& operator << (ostream& out, const Employee& a)
    {
        out << "Employee No:" << a.employeeID << '\n';
        out << "Name :" << a.name << '\n';
        out << "Salary:" << a.salary << '\n';
        out << "Address\n" << a.address; // Calls the stream operator from Address class
        return out;
    }
};
int Employee::employeeCount = 1;

int main()
{
    char name[] = "Waleed";
    char town[] = "Johar Town";
    char city[] = "Lahore";

    Employee Emp_1(100000, name, 46, 'H', town, city);
    cout << Emp_1;
    return 0;

}


```
