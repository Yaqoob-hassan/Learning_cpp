//  What will be the output of the following code ? 

#include<iostream>
using namespace std;

class Battery {
  public:
    Battery()  { cout << "Battery created." << endl; }
    ~Battery() { cout << "Battery destroyed." << endl; }
};

class Vehicle {
  public:
    Vehicle()  { cout << "Vehicle created." << endl; }
    ~Vehicle() { cout << "Vehicle destroyed." << endl; }
};

class ElectricCar : public Vehicle {
    Battery b;
  public:
    ElectricCar()  { cout << "ElectricCar created." << endl; }
    ~ElectricCar() { cout << "ElectricCar destroyed." << endl; }
};

int main() {
    ElectricCar ec;
    cout << "-----" << endl;
    return 0;
}

/* Answer -  

Base class is ALWAYS constructed first — before any member of the derived class, no matter what.


Vehicle created.
Battery created.
ElectricCar created.
-----
ElectricCar destroyed.
Battery destroyed.
Vehicle destroyed.

*/ 

// Now, answer this question..  

class P {
  public:
    P()  { cout << "P created" << endl; }
    ~P() { cout << "P destroyed" << endl; }
};

class Q {
  public:
    Q()  { cout << "Q created" << endl; }
    ~Q() { cout << "Q destroyed" << endl; }
};

class X : public P {
    Q q;
  public:
    X()  { cout << "X created" << endl; }
    ~X() { cout << "X destroyed" << endl; }
};

int main() {
    X x;
}