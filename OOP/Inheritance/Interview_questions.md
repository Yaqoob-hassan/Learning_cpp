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


## Q3: Constructor order with parameters + why initializer list is required

```cpp
#include<iostream>
using namespace std;

class Base {
  public:
    Base(int x) {
        cout << "Base constructor, x = " << x << endl;
    }
};

class Derived : public Base {
  public:
    Derived(int x, int y) : Base(x) {
        cout << "Derived constructor, y = " << y << endl;
    }
};

int main() {
    Derived d(5, 10);
    return 0;
}
```

**Output:**

**Why `Base(x)` must be called in the initializer list:**

The base class must be fully constructed *before* the derived class's constructor body starts running — there's no way around this in C++.

`Base` only defines a parameterized constructor (`Base(int x)`), so it has **no default constructor**. This matters because of a core C++ rule:

> **The compiler auto-generates a default constructor only if the class defines no constructor at all.** The moment you write even one constructor — parameterized or not — the compiler stops generating the default one.

Since `Base` only has `Base(int x)`, the *only* way to build a `Base` object is by supplying an `int`. So when `Derived` is constructed, the compiler needs to know exactly which `Base` constructor to call and with what value — and the **only valid place** to specify that is the initializer list:

```cpp
Derived(int x, int y) : Base(x) {   // tells the compiler how to build Base
    cout << "Derived constructor, y = " << y << endl;
}
```

If `: Base(x)` were removed, the compiler would try to silently call `Base()` (no arguments) before entering the constructor body — but since that doesn't exist, it's a **compile error**, not a warning.

**Rule of thumb:** As soon as a class defines any constructor, the compiler-provided default constructor disappears. If that constructor requires arguments, every derived class must explicitly supply them through the initializer list.  



## Q4: Function hiding vs function overriding (virtual keyword)

```cpp
#include<iostream>
using namespace std;

class Base {
  public:
    void show() { cout << "Base show()" << endl; }
};

class Derived : public Base {
  public:
    void show() { cout << "Derived show()" << endl; }
};

int main() {
    Base* b = new Derived();
    b->show();

    Derived d;
    d.show();

    return 0;
}
```

**Output:**


**Why `b->show()` prints `"Base show()"`:**

`b` is declared as `Base*`. Since `show()` is **not** marked `virtual`, the compiler decides which function to call based on the pointer's **declared type** (`Base*`), not the actual object it points to. This is called **static binding** — decided at compile time.

**Why `d.show()` prints `"Derived show()"`:**

`d` is declared directly as type `Derived` — no pointer, no `Base*` involved. The compiler looks at `d`'s own class and finds that `Derived` defines its own `show()`, so it calls that one directly. This has nothing to do with virtual/override — it's a normal, direct function call on an object of a known type.

**This is called function hiding, not overriding:**

Since `show()` isn't `virtual`, `Derived::show()` doesn't override `Base::show()` in the polymorphic sense — it simply **hides** the base version when accessed directly through a `Derived` object or pointer. But when accessed through a `Base*` pointer, the compiler falls back to whatever `Base*`'s declared type offers, because there's no virtual mechanism telling it to check the actual object type.

**What changes if `show()` is marked `virtual`:**

```cpp
class Base {
  public:
    virtual void show() { cout << "Base show()" << endl; }
};
```

Now the compiler defers the decision to runtime (**dynamic dispatch**) — it checks what object `b` actually points to (a `Derived` object), not just its declared pointer type. So `b->show()` would now print `"Derived show()"` instead of `"Base show()"`.

**Key takeaway table:**

| | Non-virtual (`show()`) | Virtual (`virtual show()`) |
|---|---|---|
| Binding | Static (compile-time) | Dynamic (runtime) |
| Decision based on | Pointer's declared type | Actual object type |
| `b->show()` result | Base's version | Derived's version | 



## Q5: Diamond Problem — Fix It

**Task:**
Create a base class `Person` with a member `string name`. Create two classes `Student : public Person` and `Teacher : public Person`. Create a class `TeachingAssistant : public Student, public Teacher`. First compile without `virtual` to observe the ambiguity error, then fix it using virtual inheritance.

---

### Step 1 — Broken version (without `virtual`)

```cpp
#include<iostream>
using namespace std;

class Person {
  public:
    string name;
};

class Student : public Person {

};

class Teacher : public Person {

};

class TeachingAssistant : public Student, public Teacher {

};

int main() {
    TeachingAssistant t;
    t.name = "Ali";   // triggers ambiguity

    return 0;
}
```

**Compiler error produced:**


**What went wrong:**
`TeachingAssistant` inherits from both `Student` and `Teacher`, and each of those separately inherited its own full copy of `Person`. This means `TeachingAssistant` ends up containing **two physically distinct copies** of `name` in memory — one reachable through the `Student` path, one through the `Teacher` path. When `t.name` is written, the compiler finds two equally valid candidates and has no way to determine which one is meant — hence "ambiguous." Both "candidate" notes point to the same source line (18) because both copies originate from the same declaration in `Person`; they are two separate runtime copies of the same member, reached via two different inheritance paths.

---

### Step 2 — Fixed version (with `virtual` inheritance)

```cpp
#include<iostream>
using namespace std;

class Person {
  public:
    string name;
};

class Student : virtual public Person {

};

class Teacher : virtual public Person {

};

class TeachingAssistant : public Student, public Teacher {

};

int main() {
    TeachingAssistant t;
    t.name = "Ali";   // now compiles successfully

    cout << "Name is: " << t.name << endl;

    return 0;
}
```

**What changed and why it works:**
Adding `virtual` to `Student`'s and `Teacher`'s inheritance from `Person` tells the compiler: *"if this class ends up part of a diamond, don't give it its own private copy of the base class — share a single copy across all virtual-inheritance paths."* As a result, `TeachingAssistant` now contains only **one** shared copy of `Person`, so `t.name` unambiguously refers to that single copy. No candidates conflict, and the code compiles and runs correctly.

---

**Key takeaway:**
The diamond problem occurs whenever a class inherits from two classes that share a common base, causing the base to be duplicated. `virtual` inheritance solves this by making all virtual-inheritance paths share exactly one instance of the common base class, eliminating the duplication and the resulting ambiguity.

