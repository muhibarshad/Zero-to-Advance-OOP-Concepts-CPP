# Dynamic Arrays

> Dynamic memory allocation is the process of changing the size of the memory space during the run-time.

## Why we need it ?

Suppose you are coding an account creating application like Facebook.Users can create or delete accounts.In your database all the accounts can be stored in an array of **Users**.Suppose
at morning the users of your application are **5** `{'Hamza','Abbas','Ali','Ayesha','Fatima','Mujeeb'}`.At evening a boy named **_Ali_** wants to delete his account due to some reasons.When he deletes his account then at position of ali, `index` becomes empty . like this `{'Hamza','Abbas','','Ayesha','Fatima','Mujeeb'}`.Till the size of array is **5**.Now **Ali** again wants to creates his account, so we want to add it on `run-time` **How can we increase the size of array?🤔**

The main problem here is that when we delete the account in our memory, the size of array is still **5** meaning that our memory is being wasted . And when we add an account, then how can we increase the size of array? To resolve such problems we need  a way to increase or decrease `dynamiclly`  the size of our array/arrays during `run-time`.It is not possible with the `static` array, the size of which is always constant.in this way, `DYNAMIC MEMORY ALLOCATION (DMA)` is introduced.

## Before Starting Something its better to know (HEAP or STACK):

There are two types of memory in our computers, **_Heap and Stack_**.During Dynamic Memory Allocation, we make a pointer of our variable its can be formed on the stack.(storing the address of our varible only) and its value can be stored at the heap.

In `static memory`, all the varibles and arrays are formed in the memory (stack) at the `compile-time`, so after execution all the variables and arrays are destroyed from the memory (stack) by the compiler itself.
But in `Dynamic Memory`, all the variable and array `values` are formed in the memory (heap) at the run-time. So compiler didn't make that memory! we `developers` made it during the execuation time. So it's our responsibilty to destroy them from the memory after using. Otherwise, `memory-leakage` can arise and our program can `crash`.

One more important concept about the dynamic memory allocation:
In local functions we make a varaible and it goes out from the execution stack after being called. So we cannot use its value further more. To store its value, we make a variable on heap and its pointer on stack and return the pointer from the function and store it in in the main stack pointer variable. Now, your memory cannot leak.The main advantage is that your pointer will never become a dangling pointer. And your heap value can never be formed without its pointer.

> Making a dynamic memory is called allocating the memory.
> Deleting a dynamic memory is called dellocating the memory.

## Dangling Pointer

A pointer that is pointing to such memory in the heap that does not exist!
