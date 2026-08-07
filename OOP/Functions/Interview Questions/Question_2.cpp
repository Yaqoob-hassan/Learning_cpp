// What will be the output of the following code. ? 
#include<iostream>
using namespace std;


class Base {
    public:  

      void virtual  func() {
        cout << "Base class. " << endl;
      }

     
};

class Derived : public Base {
  public: 
     void func()  {
        cout << "Derived class." << endl;
     }
 



};


void excecute(Base &obj) {
    obj.func(); 
}

int main() {
    Base b;
    excecute(b);

    Derived d;
    excecute(d);

    


    return 0; 
}


// Answer -- 

// The output of both will be base class. Even when we are calling with the child obj. 

// Overcome this problem we will write & in the execute fucntion so it pass it by refrence and keep track of address. 

// void excecute(Base &obj) {
//     obj.func(); 
// }

