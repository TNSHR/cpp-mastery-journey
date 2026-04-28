#Day 2 - Pointer to Pointer, Stack vs Heap, Memory leak
## 1. Pointer to Pointer
### Defination - A pointer to pointer stores the address of another pointer
###Example
```cpp
int a = 10;
int* p = &a;
int** pp = &p;
```
Memory Representation
a - value stored(10)
p - address of a
pp - address of p

Access Levels
p - address of a
*p - value of a
pp - address of p
*pp - address of a
**pp - value of a
Example usage
**pp = 50; 

Use Cases 
dynamic memory structures
2D arrays 
modifying pointer inside functions
Stack vs Heap Memory
int a = 10;
Characteristic
automatic allocation
fast access
limited size 
automatically freed
Heap Memory
int* p = new int(10);

Characteristics
dynamic allowcation
slower than stack
must be manually freed using delete
larger memory space

### Memmory leak
Memory leak occures when dynamically allowcated memory is not freed
int* p = new int(10);
//no delete -memory leak

Correct example
int* p = new int(10);
delete p;

Dangerous Case
int* p = new int(10);
p = new int(20);\

Why memory leak is Dangerous
wastes memory
reduce performance
can crash system

Key points
Pointer store address
Pointer to pointer allow multi-level access
Stack memory is automatic and fast
Heap memory is dynamic and must be managed
Always free Dynamically allowcated memory