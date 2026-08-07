// What is the exact output of this program, in order? Explain why the constructor
//  and destructor calls happen the way they do.


#include<iostream>
using namespace std;

class Base {
  public: 
    Base() {
        cout << "Constructor of Base." << endl;
    }
    ~Base() {
        cout << "Destructor of Base." << endl;
    } 
}; 

class Derived : public Base {
  public: 
    Derived() {
        cout << "Constructor of Derived." << endl; 
    }
    ~Derived() {
        cout << "Destructor of Derived." << endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; 

    return 0; 
}

// ANSWER -- 
// As the base class dont have virtual destructor, so the compiler has skip the derived class destructor. 
// To solve this, just write 
// virtual ~Base();  --- Answer  