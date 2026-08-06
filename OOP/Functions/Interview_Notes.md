# OOP Interview Preparation — Polymorphism, Inheritance, Encapsulation, Memory Management

A set of 30 conceptual questions (Easy → Intermediate → Hard) covering core OOP concepts in C++, with clear explanations and examples.

---

## 🟢 Easy

### 1. What is the difference between a class and an object?
A **class** is a blueprint/template — it defines what data (member variables) and behavior (member functions) something will have, but takes no memory on its own. An **object** is an actual instance created from that class, which occupies real memory.

Example: `Car` is a class describing what a car has (speed, color, `drive()`). `Car myCar;` creates an actual object in memory.

### 2. What is encapsulation, and why is it useful?
Encapsulation means **bundling data and the functions that operate on that data into a single unit (a class)**, and **restricting direct access** to the internal data using access specifiers (`private`/`protected`) — exposing controlled access through public methods instead.

**Why it matters:** it prevents outside code from putting an object into an invalid state, hides implementation details so they can change later without breaking other code, and reduces accidental misuse of internal data.

### 3. What access specifiers exist in C++, and what does each control?
- **`private`** — accessible only from within the same class.
- **`protected`** — accessible within the same class and any derived (child) classes.
- **`public`** — accessible from anywhere the object is visible, including outside the class (e.g., in `main()`).

### 4. Compile-time polymorphism vs runtime polymorphism
- **Compile-time (static) polymorphism:** the compiler decides which function to call *while compiling* the code, based on function signatures. Achieved via **function overloading** and **operator overloading**.
- **Runtime (dynamic) polymorphism:** the decision of which function to call is made **while the program is executing**, based on the actual object type. Achieved via **virtual functions** and **method overriding**.

Example: calling `attack()` through a `Character*` pointer that actually points to a `Warrior` or `Mage` object — the correct overridden version runs, decided at runtime.

### 5. What is method overloading?
Multiple functions with the **same name** but **different parameter lists** (different number or types of parameters) within the same scope. The compiler picks the correct one based on the arguments passed, at compile time.

```cpp
int add(int a, int b);
int add(int a, int b, int c);
double add(double a, double b);
```

### 6. What is method overriding?
A **derived class provides its own implementation** of a function that already exists as `virtual` in the base class — with the exact same name, return type, and parameters. When called through a base class pointer/reference pointing to a derived object, the derived version executes instead of the base version. Which version runs is decided at **runtime**.

### 7. What does the `virtual` keyword do?
Marking a function `virtual` in the base class tells the compiler to use **dynamic dispatch** for that function — meaning that when called through a base class pointer/reference, the actual object's type (not the pointer's declared type) determines which version of the function runs. Without `virtual`, the call is resolved at compile time based purely on the pointer's declared type (static binding).

### 8. What is a pure virtual function, and what does it do to a class?
A pure virtual function is declared with `= 0` and has **no implementation** in the base class:
```cpp
virtual void send() = 0;
```
Adding even one pure virtual function makes the entire class an **abstract class** — you cannot create objects of it directly (`new BaseClass()` will not compile). Any derived class must override **all** pure virtual functions to become a concrete (instantiable) class.

### 9. Stack objects vs heap objects
- **Stack:** `Character c("Shadow", 100, 45);` — memory is automatically managed; the object is destroyed automatically when it goes out of scope (e.g., when the function returns). Fast, but limited lifetime and size.
- **Heap:** `Character* c = new Character("Shadow", 100, 45);` — memory persists until explicitly freed with `delete`. Gives more control over lifetime (object can outlive the function it was created in) but requires manual cleanup, or it leaks memory.

### 10. `new` and `delete`
`new` allocates memory on the heap and returns a pointer to it. `delete` frees memory that was allocated with `new`. Every `new` should have a matching `delete`, or the memory leaks.

---

## 🟡 Intermediate

### 11. What is a vtable?
A **virtual table** is a hidden, compiler-generated array of function pointers, created **once per class** that has virtual functions. Each entry points to the correct implementation of a virtual function **for that class**.

### 12. What is a vptr?
A **virtual pointer** — a hidden pointer stored inside **every object** of a class that has virtual functions. It points to that object's class's vtable. This is how the object "knows" which class's virtual functions it should use, even when accessed through a base class pointer.

### 13. Early binding vs late binding
- **Early binding (static binding):** the function call is resolved at **compile time**. Used for regular functions and overloaded functions.
- **Late binding (dynamic binding):** the function call is resolved at **runtime**, based on the actual object type, via the vtable/vptr mechanism. Used for virtual functions called through base class pointers/references.

Example: `ch[i]->attack()` where `ch[i]` is a `Character*` actually pointing to a `Warrior`, `Mage`, or `Healer` object — the correct overridden `attack()` runs, decided at runtime. This is late binding.

### 14. Why does a base class need a virtual destructor?
If you `delete` an object through a **base class pointer** that actually points to a **derived class object**, and the base class destructor is **not virtual**, only the base class's destructor runs — the derived class's destructor is **skipped entirely**. This causes a memory leak (any heap resources the derived class allocated never get freed) and can leave the object partially destroyed.

Marking the base destructor `virtual` ensures the correct destructor chain runs: derived class destructor first, then the base class destructor.

### 15. Can a constructor be virtual?
No. Virtual dispatch relies on the object's vptr already being set up — but the vptr isn't initialized until the constructor actually runs. There's no valid object yet for a "virtual" lookup to work on, so C++ doesn't allow virtual constructors.

### 16. Abstract class with one pure virtual function + regular virtual functions
Having even **one** pure virtual function makes the class abstract — regardless of how many other regular virtual functions it also has. You cannot create an object of it directly (`new` on it will not compile). Only classes with **zero** pure virtual functions (all inherited pure virtuals overridden) can be instantiated.

### 17. Derived class doesn't override all pure virtual functions
The derived class **remains abstract** too — it inherits the unimplemented pure virtual function(s), so it still cannot be instantiated directly. This continues down the inheritance chain until some class provides implementations for all pure virtual functions.

### 18. Deep copy vs shallow copy
This applies when **copying an object** that contains a pointer to heap-allocated memory.

- **Shallow copy:** copies the pointer's *value* (the address) — both the original and the copy now point to the **same** memory. If one object modifies or deletes that memory, it affects the other — a common source of crashes (double-free, dangling pointers).
- **Deep copy:** allocates **new**, separate memory for the copy and copies the actual data into it. Each object has an independent copy — modifying one doesn't affect the other.

### 19. What is a memory leak?
Memory that was allocated with `new` (on the heap) but never freed with `delete` — the program loses track of it, so it stays reserved for the lifetime of the program, wasting memory. Common cause: forgetting to call `delete` on a pointer, or losing the only reference to a heap object before deleting it (e.g., overwriting a pointer without deleting the old memory first).

### 20. `delete` vs `delete[]`
- `delete ptr;` — frees memory for a **single** object allocated with `new`.
- `delete[] ptr;` — frees memory for an **array** of objects allocated with `new Type[size]`.

Using the wrong one causes **undefined behavior** — for an array of objects, using plain `delete` typically only calls the destructor of the first element and can corrupt memory, potentially causing crashes.

---

## 🔴 Hard

### 21. What happens step-by-step when calling a virtual function through a base pointer?
1. The base class pointer holds the memory address of the actual (derived) object.
2. That object contains a hidden **vptr**, set during construction to point to its own class's **vtable**.
3. When the virtual function is called, the program follows the vptr to find the correct vtable.
4. It looks up the function's slot in that vtable and retrieves the function's address.
5. It jumps to and executes that function — which is the derived class's overridden version, since it's that class's vtable being used.

No new object is created during this process — it's purely a lookup of an existing function address.

### 22. Why can't a pure virtual function be called directly on an abstract class?
Because it has **no implementation** — there's no code to execute. You *can* call it through scope resolution from within a derived class (`Base::pureVirtualFunc()`), but only if the base class actually **provided a body** for it (a pure virtual function *can* have a body, even though it still forces subclasses to override it — a rare but valid pattern used occasionally, e.g., for a default fallback implementation).

### 23. What is object slicing?
When a **derived class object is assigned or copied into a base class object by value** (not by pointer/reference), only the base class portion is copied — the derived-specific data and its vtable/vptr are "sliced off" and lost.

```cpp
Warrior w("Thanos", 100, 44);
Character c = w;  // SLICING — c is now just a plain Character, Warrior-specific behavior is gone
c.attack();        // calls Character::attack(), NOT Warrior::attack()
```
This silently breaks polymorphism — always use pointers or references (`Character*` or `Character&`) to preserve polymorphic behavior.

### 24. Virtual function without `override`, with a mismatched signature
If the derived function's signature doesn't exactly match the base virtual function (e.g., wrong parameter type), it does **not** count as overriding — it's treated as a completely separate, unrelated function that happens to share a name. Without `override`, this mismatch compiles silently, and calling the function through a base pointer will call the **base class's original version**, not your intended derived version — a hard-to-spot bug. Adding `override` forces the compiler to verify the match and throw a compile error if it doesn't, catching the mistake immediately.

### 25. Performance cost of virtual functions
Each virtual function call requires an extra memory lookup (following the vptr to the vtable, then to the function) compared to a direct function call, which the compiler can resolve immediately. This also can prevent certain compiler optimizations like inlining.

**When it matters:** extremely performance-critical code with virtual calls in tight loops executed millions of times (e.g., game engines, real-time systems).
**When it doesn't matter:** the vast majority of general application code — the overhead is a few nanoseconds and is negligible compared to the flexibility polymorphism provides.

### 26. What is RAII?
**Resource Acquisition Is Initialization** — a C++ pattern where a resource (heap memory, file handle, network connection, etc.) is acquired in an object's **constructor** and automatically released in its **destructor**. Since C++ guarantees destructors run when an object goes out of scope, this ties resource cleanup to object lifetime, eliminating the need for manual `delete` calls and preventing leaks even if an exception is thrown. Smart pointers (`unique_ptr`, `shared_ptr`) are built on this principle.

### 27. Can a static member function be virtual?
No. `virtual` functions rely on a specific **object instance's** vptr to determine which version to call — but `static` functions belong to the **class itself**, not to any particular object, and are called without an object instance. Since there's no vptr to look up (no object involved), the two concepts are fundamentally incompatible.

### 28. Calling a virtual function from inside a base class's constructor/destructor
Polymorphic dispatch does **not** work as expected here. During a base class's constructor, the derived class's portion of the object hasn't been constructed yet (and its vptr hasn't been set to the derived class's vtable yet) — so calling a virtual function inside the base constructor will call the **base class's version**, even if a derived class overrides it. The same applies in reverse during destruction — by the time the base destructor runs, the derived part has already been destroyed, so virtual calls resolve to the base version again. This is a common source of subtle bugs.

### 29. Raw pointers vs smart pointers for polymorphic heap objects
Raw pointers (`Character*`) require **manual** `delete` calls — forgetting one causes a memory leak (a mistake made multiple times during practice today). Smart pointers like `unique_ptr<Character>` or `shared_ptr<Character>` automatically call `delete` when the pointer goes out of scope (via RAII), eliminating manual cleanup entirely and preventing leaks even if an exception occurs mid-function. `unique_ptr` also fully supports polymorphism — a `unique_ptr<Character>` can hold a `Warrior`, `Mage`, etc., and virtual dispatch still works normally.

### 30. Design scenario — adding rotation to some shapes without breaking others
Best approach: **don't add a rotation parameter to the base `Shape` class** (that would force every shape, including ones that don't need it, to carry unused data/logic). Instead:
- Create an intermediate abstract class, e.g. `RotatableShape : public Shape`, that adds a `rotationAngle` member and a `rotate()` method, while still implementing/overriding `draw()` to account for rotation.
- Shapes that need rotation (e.g., `RotatableRectangle`) inherit from `RotatableShape`; shapes that don't (e.g., `Circle`, which looks the same rotated) continue inheriting directly from `Shape`.
- The existing `vector<Shape*>` and polymorphic `draw()` calls continue working unchanged, since `RotatableShape` still *is* a `Shape` — this follows the **Liskov Substitution Principle** (a subclass should be usable anywhere its base class is expected, without breaking existing code).

---

*Compiled from a hands-on C++ practice session covering Employee/Notification/Character exercises — polymorphism, inheritance, encapsulation, abstraction, and memory management fundamentals.*