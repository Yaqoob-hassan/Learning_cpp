# OOP Interview Questions & Answers

A set of Object-Oriented Programming interview questions, ranging from easy to advanced, with detailed answers and examples.

---

## 1. What is Object-Oriented Programming, and what are its four main pillars?

**Answer:** OOP is a programming paradigm based on the concept of "objects" — bundles of data (attributes) and behavior (methods) — rather than functions and logic alone. Its four pillars are:

- **Encapsulation** — bundling data and methods together, restricting direct access to internal state.
- **Abstraction** — hiding implementation complexity, exposing only essential features.
- **Inheritance** — allowing a class to acquire properties and behavior from another class.
- **Polymorphism** — allowing objects/methods to take multiple forms depending on context.

---

## 2. What is the difference between a class and an object?

**Answer:** A **class** is a blueprint or template that defines properties (fields) and behavior (methods). An **object** is a concrete instance of that class, with actual values stored in memory. Example: `Car` is a class; `myTesla` is an object of that class.

---

## 3. What is the difference between method overloading and method overriding?

**Answer:**
- **Overloading** — same method name, different parameter list, within the *same class*. Resolved at **compile time** (static polymorphism).
  ```java
  void display() { }
  void display(int age) { }
  ```
- **Overriding** — a subclass redefines a method with the *same signature* as its parent. Resolved at **runtime** (dynamic polymorphism).
  ```java
  class Animal { void sound() { } }
  class Dog extends Animal { void sound() { /* barks */ } }
  ```

---

## 4. What is the difference between an abstract class and an interface?

**Answer:** An **abstract class** can have both abstract (unimplemented) and concrete (implemented) methods, along with fields and constructors, but cannot be instantiated directly. An **interface** traditionally only declares method signatures (though modern languages allow default implementations), has no constructors, and a class can implement multiple interfaces but extend only one abstract class. Use an abstract class when subclasses share common state/behavior; use an interface to define a pure contract, especially across unrelated classes.

---

## 5. What is the difference between composition and inheritance?

**Answer:** Inheritance models an **"is-a"** relationship (a `Dog` **is an** `Animal`), while composition models a **"has-a"** relationship (a `Car` **has an** `Engine`). Composition is often preferred because it's more flexible — components can be swapped at runtime, and it avoids the tight coupling and fragility that deep inheritance chains introduce.

---

## 6. What is constructor overloading, and can a constructor be inherited? *(detailed)*

**Answer:** Constructor overloading means defining multiple constructors in the same class with different parameter lists, so an object can be initialized in different ways depending on what's passed in at creation time.

```java
class Person {
    String name;
    int age;

    Person(String name) {
        this.name = name;
        this.age = 0;
    }

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```

Calling `new Person("Ali")` uses the first constructor; `new Person("Ali", 25)` uses the second.

**Important distinction:** constructors have **no return type at all** — not even `void`. This is different from regular method overloading, where methods do have a return type (though overload resolution still ignores return type and looks only at the parameter list).

**Can a constructor be inherited? No.** This is a common interview trap. A subclass does **not** inherit its parent's constructors. Each class must define its own constructor(s). However, a subclass constructor can explicitly **call** the parent's constructor to initialize the inherited portion of the object — using `super(...)` in Java or a base-class initializer list in C++:

```java
class Employee extends Person {
    double salary;
    Employee(String name, int age, double salary) {
        super(name, age); // calls Person's constructor
        this.salary = salary;
    }
}
```

---

## 7. What is the Liskov Substitution Principle, and how can violating it break a program? *(detailed)*

**Answer:** The Liskov Substitution Principle (the "L" in SOLID) states that objects of a subclass should be usable anywhere the base class is expected, **without altering the correctness of the program**. It's not just about matching method signatures — the subclass must also preserve the *behavioral contract* of the base class.

**Classic violation — Rectangle/Square:**

```java
class Rectangle {
    protected int width, height;
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int area() { return width * height; }
}

class Square extends Rectangle {
    @Override
    void setWidth(int w) { width = w; height = w; }  // keeps it "square"
    @Override
    void setHeight(int h) { width = h; height = h; }
}
```

Now consider code written against `Rectangle`:

```java
Rectangle r = new Square();
r.setWidth(5);
r.setHeight(10);
assert r.area() == 50;  // FAILS — area is actually 100
```

The caller reasonably expects that setting width and height independently gives an area of `width * height`. But because `Square` silently changes both dimensions together, the assumption breaks — even though `Square` "is-a" `Rectangle` syntactically. This is exactly what LSP warns against: **inheritance should reflect true behavioral substitutability, not just a shared interface.**

---

## 8. How does runtime polymorphism (dynamic dispatch) work internally?

**Answer:** When a class has virtual functions, the compiler gives every object of that class a hidden pointer called the **vptr** (virtual pointer). Each class with virtual functions gets one **vtable** — a table of function pointers to its actual (possibly overridden) implementations. The object's vptr points to its class's vtable. When you call a virtual method through a base-class reference or pointer, the call is resolved **at runtime** by following the vptr into the vtable and invoking the correct function for the object's *actual* type — not its declared type. This is what allows a `Animal ref = new Dog()` call to `ref.sound()` to correctly invoke `Dog`'s version.

---

## 9. What are the drawbacks of deep inheritance hierarchies, and how would you refactor around them? *(detailed)*

**Answer:**

- **Fragile base class problem** — a seemingly harmless change in a base class can silently break behavior several levels down the hierarchy, since subclasses often depend on implementation details, not just the interface.
- **Tight coupling** — subclasses are bound to their ancestors' internals, making the codebase harder to refactor safely.
- **Reduced runtime flexibility** — inheritance is a static, compile-time relationship. You can't change an object's "type" or swap behavior dynamically the way you can with composed objects.
- **The "gorilla/banana" problem** — you wanted one small piece of reusable behavior (the banana), but inheriting it drags in the entire ancestor chain and its baggage (the gorilla holding the banana, and the whole jungle behind it).
- **Diamond problem risk** — deep and multiple inheritance hierarchies increase the chance of ambiguous method resolution.
- **Harder testing** — behavior is smeared across many classes, so isolating a unit for testing becomes difficult.

**Refactor strategy — favor composition over inheritance:** Instead of a long "is-a" chain, build classes out of smaller, focused, swappable components ("has-a" relationships). For example, instead of `FlyingRobot extends Robot extends Machine`, give `Robot` a `MovementBehavior` component that can be swapped (`FlyBehavior`, `WalkBehavior`, etc.) at runtime — this is essentially the **Strategy design pattern**, a common real-world fix for over-deep inheritance trees.

---

## 10. What is the diamond problem in multiple inheritance, and how do different languages solve it?

**Answer:** The diamond problem occurs with multiple inheritance: class `A` is the base; classes `B` and `C` both inherit from `A`; class `D` inherits from both `B` and `C`. Since `B` and `C` each carry their own copy of `A`'s members, `D` ends up with **two separate, ambiguous copies of `A`** — the compiler can't tell which copy to use when `D` accesses a member that originated from `A`.

```
        A
       / \
      B   C
       \ /
        D
```

**C++ solution:** Use **virtual inheritance** — `class B : virtual public A` and `class C : virtual public A`. This tells the compiler that `B` and `C` should share a **single instance** of `A`, so `D` ends up with only one copy, resolving the ambiguity.

**Java/C# solution:** These languages sidestep the problem entirely by **disallowing multiple inheritance of classes** — a class can extend only one other class. They allow multiple inheritance only through **interfaces**. If two interfaces provide conflicting default method implementations, the compiler forces the implementing class to explicitly override and resolve the conflict — so ambiguity can never occur silently.

---

*Prepared as interview practice notes covering Encapsulation, Abstraction, Inheritance, and Polymorphism.*