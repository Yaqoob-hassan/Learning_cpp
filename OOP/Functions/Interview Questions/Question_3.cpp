//  What will be the output of the following code ? 



#include<iostream>
using namespace std;

class Engine {
  public:
    Engine() {
        cout << "Engine created." << endl;
    }
    ~Engine() {
        cout << "Engine destroyed." << endl;
    }
};

class Wheels {
  public:
    Wheels() {
        cout << "Wheels created." << endl;
    }
    ~Wheels() {
        cout << "Wheels destroyed." << endl;
    }
};

class Car {
    Engine e;
    Wheels w;
  public:
    Car() {
        cout << "Car created." << endl;
    }
    ~Car() {
        cout << "Car destroyed." << endl;
    }
};

int main() {
    Car c;
    cout << "-----" << endl;
    return 0;
}


/*  Answer -- 

Build Engine   →  [Engine]
Build Wheels   →  [Engine][Wheels]
Build Car body →  [Engine][Wheels][Car] 

Destruction is like unstacking — you must remove the top box first, you can't pull the bottom one out while others sit on it: 

Destroy Car    →  [Engine][Wheels]        (Car's own destructor body runs first)
Destroy Wheels →  [Engine]                (then members destroyed in reverse)
Destroy Engine →  [] 
*/