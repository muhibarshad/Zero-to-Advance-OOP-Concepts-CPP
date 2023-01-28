# Object RelationShips

In daily life, we see that everything is connected to one another. For example, leaves are connected to branches and branches are connected to a tree. The life of leaves depends on their attachment to the branches. Similarly, a human has a heart, a car uses fuel, and a cat is an animal. In programming, every class is connected to another related class with different relationships. There are two major types of relationships in this case.

1. `has-a` relationship
2. `is-a` realtioship

# has-a relatioship

It means to keep the object of one class in another class. It is called container-ship or possession. In a "has-a" relationship, we can say that a parent class has a child class. The child class can be totally dependent or independent on the creation or destruction of the main class. This relationship is further divided into two more subtypes.

1. [Composition (Strong RelationShip)](/01_Object%20Oriented%20Programming%20in%20C%2B%2B/13_Object%20RelationShips/02_Composition/)
1. [Aggregation (Week RelationShip)](/01_Object%20Oriented%20Programming%20in%20C%2B%2B/13_Object%20RelationShips/01_Aggregation/)

## Important Points

- It is always a good practice to pass the aggregated object as `const` to avoid accidentally changing its properties and methods by using its public methods. This can be done by using `const` keyword with them, to ensure that the aggregated object is not modified. This helps in keeping the integrity of the object and reducing the chances of bugs in the code.

- From an `abstraction` standpoint, it is primarily recommended to use references and aggregation. In the main function, we simply pass the aggregated object's name without the use of the `&` sign. This way, the user is not exposed to the concepts of aggregation and composition.

- "It is important to note that the `has-a` relationship type cannot be determined solely based on data types. For example, just because you see `Array *arr;` does not necessarily mean that it is an aggregation relationship. It could also be used for dynamic composition, as in `arr = new Array[5]`. To truly determine the relationship, one should examine the class constructor to see if addresses are being copied or used for dynamic purposes."
