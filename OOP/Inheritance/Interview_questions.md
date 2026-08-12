## Q1: Difference between Inheritance and Composition

**Inheritance ("is-a" relationship):**
A class acquires the properties and behavior of another class through the `: public` mechanism. The derived class *becomes* a specialized version of the base class.

Example: A `Dog` **is an** `Animal`.

```cpp
class Animal {
  public:
    void eat() { cout << "Eating." << endl; }
};

class Dog : public Animal {
  public:
    void bark() { cout << "Barking." << endl; }
};
```

**Composition ("has-a" relationship):**
A class contains an object of another class as a data member. The containing class *owns* the other object, but is not a specialized version of it.

Example: A `Car` **has an** `Engine`.

```cpp
class Engine {
  public:
    void start() { cout << "Engine starting." << endl; }
};

class Car {
    Engine e;   // Car HAS an Engine
  public:
    void drive() {
        e.start();  // must be called explicitly through the member
        cout << "Car driving." << endl;
    }
};
```

**Key takeaway:**
| | Inheritance | Composition |
|---|---|---|
| Relationship | is-a | has-a |
| Access to other class's members | Automatic (inherited) | Must call explicitly through the object |
| Flexibility | Fixed at compile time | Can swap the contained object at runtime |
| Coupling | Tighter | Looser |



## Q2 : Why does C++ support multiple inheritance while Java/C# don't?

**C++'s approach:**
C++ allows a class to inherit from more than one base class at the same time:

```cpp
class D : public B, public C { };
```

This is powerful but risky — if `B` and `C` both inherit from the same base class `A`, `D` ends up with two separate copies of `A`'s members (the **diamond problem**), causing ambiguity errors. C++ accepts this risk and gives developers the `virtual` keyword as a tool to resolve it when it happens:

```cpp
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };  // only ONE shared copy of A now
```

**Java/C#'s approach:**
Java and C# decided this risk wasn't worth it, so they simply **don't allow a class to inherit from more than one class at all**. Instead, they let a class implement **multiple interfaces**:

```java
class D implements InterfaceB, InterfaceC { }
```

Since interfaces only declare method signatures (no actual data/state to duplicate), the diamond problem can never occur — there's nothing to be ambiguous about.

**Key takeaway:**
C++ chose to allow the risky feature (multiple class inheritance) and hand developers a tool (`virtual`) to manage the risk. Java/C# chose to design the risk away entirely by restricting multiple inheritance to interfaces only.