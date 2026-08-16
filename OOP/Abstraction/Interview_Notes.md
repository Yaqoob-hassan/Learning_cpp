## Abstraction vs. Encapsulation — Detailed Comparison

These two concepts are closely related and often used together, but they answer **different questions**, and mixing them up is one of the most common conceptual mistakes in OOP interviews.

### Encapsulation — "How do I protect the data?"

Encapsulation is about **bundling data and the functions that operate on it together into a single unit (a class)**, and **restricting direct access** to that data from outside code. It's achieved using access specifiers (`private`, `protected`) combined with public getter/setter functions.

**The core purpose:** prevent outside code from directly reading or modifying an object's internal state in uncontrolled ways — forcing all interaction to go through controlled, validated entry points.

```cpp
class BankAccount {
  private:
    double balance;   // hidden — cannot be accessed directly from outside

  public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;   // controlled, validated access
    }
    double getBalance() {
        return balance;   // controlled read access
    }
};

int main() {
    BankAccount acc;
    // acc.balance = -9999;   // ❌ not allowed — balance is private
    acc.deposit(500);          // ✅ must go through the controlled function
}
```

### Abstraction — "How do I hide complexity and show only what matters?"

Abstraction is about **hiding the internal implementation details of how something works, and exposing only a simple, essential interface** to the user. It's achieved in C++ primarily using abstract classes and pure virtual functions.

**The core purpose:** let the user of a class interact with *what it does*, without needing to know or care *how it does it* internally.

```cpp
class Shape {
  public:
    virtual double area() = 0;   // WHAT every shape must be able to do
    // HOW each shape calculates it is completely hidden from the caller
};

class Circle : public Shape {
    double radius;
  public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14159 * radius * radius;   // the "how" — hidden implementation detail
    }
};

int main() {
    Shape* s = new Circle(5);
    cout << s->area();   // caller just asks "what's the area?" — doesn't see the formula at all
}
```

### Side-by-side comparison

| | Encapsulation | Abstraction |
|---|---|---|
| Question it answers | How do I protect the data? | How do I hide complexity? |
| Focus | Data + controlled access | Implementation details + simplified interface |
| Achieved via | `private`/`protected` + getters/setters | Abstract classes + pure virtual functions |
| What it hides | The actual data values | The actual logic/implementation |
| Real-world analogy | A locked box — you can only interact with it through the slot provided | A car's dashboard — you press pedals without knowing engine mechanics |

### Why they're often confused

Both involve "hiding" something, which is why people conflate them. But the key distinction is: **encapsulation hides data (state)**, while **abstraction hides implementation (behavior/logic)**. A class can have strong encapsulation (all data private, accessed only via functions) while still being poorly abstracted (its public functions expose confusing, low-level operations) — and vice versa. They're complementary but separate principles.

## Debugging Note: Removing `override` does NOT make a derived class use the base class's default function

### The problem

**Task requirement:** in a partial-abstraction exercise, one derived class should override a virtual function (`show_detail()`), and the **other** derived class should use the base class's default implementation instead.

**Mistaken attempt:**
```cpp
class Employee {
  public:
    virtual double calculateSalary() = 0;
    virtual void show_detail() {
        cout << "Details on Salary :" << endl;
    }
};

class FullTimeEmployee : public Employee {
    double salary = 2120;
  public:
    double calculateSalary() override {
        return salary;
    }

    // Attempted to "opt out" of overriding by just removing the `override` keyword:
    void show_detail() {
        cout << "Full Time Employee Details :" << endl;
        calculateSalary();
    }
};
```

**Why this doesn't work as intended:**

Removing the `override` keyword does **not** stop the function from overriding the base class's version. `override` is only a compiler safety-check — it verifies that the function you're writing genuinely matches a real virtual function in the base class (catching typos or signature mismatches). It has **no effect** on whether overriding actually occurs. Overriding happens automatically, keyword or not, any time a derived class defines a `virtual` function with a matching name and signature.

Since `FullTimeEmployee::show_detail()` still has its **own full function body** here, it still overrides the base version in behavior — calling `show_detail()` on a `FullTimeEmployee` object still runs this custom version, not the base class's default message.

### The actual fix

To make a derived class genuinely use the base class's default implementation, **don't define the function at all in that derived class** — remove the entire function block, not just the keyword:

```cpp
class FullTimeEmployee : public Employee {
    double salary = 2120;
  public:
    double calculateSalary() override {
        return salary;
    }

    // show_detail() is NOT redefined here at all —
    // this class will automatically use Employee's default version
};
```

Now, calling `show_detail()` on a `FullTimeEmployee` object automatically falls back to `Employee::show_detail()`'s implementation, since `FullTimeEmployee` never provides its own.

### Key takeaway

**Function overriding in C++ is determined by whether a matching function is redefined in the derived class — not by the presence or absence of the `override` keyword.** `override` is purely a compile-time safety net for catching mistakes; it doesn't control the override mechanism itself. If you genuinely want a derived class to inherit a base class's default behavior for a specific virtual function, the correct approach is to simply not write that function in the derived class at all.

