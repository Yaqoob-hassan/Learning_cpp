#include<iostream>
using namespace std;

class Shape {
 public: 
    virtual double area() = 0;
    virtual void display() = 0;


};

class Circle : public Shape {
  private : 
    double radius; 

    public: 
       
      Circle(double r) {
        radius = r;
      }

      double area() override {
        return 3.14 * radius * radius;
      }

      void display() override {
        cout << "Circle with radius " << radius << " has area : " << area() << endl;
      }
};

int main() {
    Shape* shapes[1];

    shapes[0] = new Circle(7);

    for(int i = 0; i < 1; i++ ) {
        shapes[i]->display();
    }


    return 0; 


}