# Friend in OOP — Key Points & Notes 


- `friend` is **not a member** of the class, even though it can access its private data.
- Friendship is **not mutual**: if class A is a friend of class B, B is not automatically a friend of A.
- Friendship is **not inherited**: a derived class does not automatically inherit the friends of its base class.
- Friendship is **granted by the class itself**, not taken by the outsider — a class decides who its friends are.
- It can be a **friend function** (a global/standalone function or a member function of another class) or a **friend class** (the entire class becomes a friend).

---

## Interview-Level Questions and Answers

### Q1. What is a friend function in C++?
**Answer:** A friend function is a function that is not a member of a class but is granted access to the class's private and protected members. It is declared inside the class using the `friend` keyword but defined outside like a normal function.

---

### Q2. Is a friend function a member of the class?
**Answer:** No. A friend function is not a member of the class. It does not have a `this` pointer, and it must be called like a normal function, not with the dot (`.`) or arrow (`->`) operator on an object, unless it explicitly takes an object as a parameter.

---

### Q3. Is friendship in C++ mutual?
**Answer:** No. Friendship is one-directional. If class A declares class B as a friend, class B can access A's private members, but A cannot access B's private members unless B also explicitly declares A as a friend.

---

### Q4. Is friendship inherited?
**Answer:** No. Friendship is not inherited. If a base class has a friend, that friend does not automatically become a friend of the derived class.

---

### Q5. Can a friend function be declared as private or public inside a class?
**Answer:** It doesn't matter where you write the `friend` declaration (in the private, public, or protected section) — the access specifier has no effect on a friend declaration because the friend function itself is not a member of the class.

---

### Q6. What is a friend class? Give an example use case.
**Answer:** A friend class is a class that is given access to the private and protected members of another class. It's commonly used when two classes are tightly coupled and need to share internal data, such as a `LinkedList` class and its `Iterator` class.

---

### Q7. Can a friend function access private members of multiple classes?
**Answer:** Yes. A single function can be declared as a friend in more than one class, in which case it can access the private members of all those classes.

```cpp
class B; // forward declaration

class A {
    int a = 10;
    friend void show(A, B);
};

class B {
    int b = 20;
    friend void show(A, B);
};

void show(A x, B y) {
    cout << x.a << " " << y.b;
}
```

---

### Q8. Why is the `friend` keyword often used with operator overloading?
**Answer:** Some operators (like `<<` for `cout` or `>>` for `cin`) must be defined as non-member functions because the left-hand operand is not an object of your class (it's `ostream`/`istream`). To let this non-member function access your class's private data, it is declared as a friend.

```cpp
class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    friend ostream& operator<<(ostream& out, const Point& p);
};

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
```

---

### Q9. Does using `friend` violate encapsulation?
**Answer:** It's a controlled and intentional exception to encapsulation, not a complete violation. Encapsulation still holds for everyone else — only the explicitly named friend gets access, and that access is decided and controlled by the class itself, not forced from outside.

---

### Q10. Can a friend function be virtual?
**Answer:** No. Since a friend function is not a member of the class, it cannot be declared `virtual`. Virtual functions must be class members because virtuality relies on the class's vtable mechanism.