#include<iostream>
using namespace std;

// Friend class is a special class that can access private & Protected member of a class. 

class X {
  private: 
    int x; 
    int y; 
  
 public:
    
   void show() {
    cout << "Value of x is :" << x << endl;
    cout << "Value of y is :" << y << endl;
   }
     
   friend class Y;


};

class Y {
   private: 
     int z; 

   public: 
     
     void set(X &obj) {
        obj.x = 20;
        obj.y = 19;
     }

     
};

int main() {
    X x;
    Y y;

    y.set(x);

    x.show();

    return 0; 
}