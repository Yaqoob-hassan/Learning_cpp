#include<iostream>
using namespace std;


class Rectangle {
    private: 
       float width;
       float height;
       float area;
    public: 
       
      Rectangle(float w, float h) {
        width = w;
        height = h;
      }

      friend void calculateArea(Rectangle r);
      friend void display(Rectangle r);
};
// float area = r.width * r.height;
// Creates a temporary local variable, Works, but wastes the member variable

// void calculateArea(Rectangle r) {
//     area = r.width * r.height;
//     cout << "Width is :" << r.width << endl;
//     cout << "Height is : " << r.height << endl;
//     cout << "Area is :" << area << endl;
// }

void calculateArea(Rectangle r) {
    r.area = r.width * r.height;
 
}

void display(Rectangle r) {
    cout << "Width is :" << r.width << endl;
    cout << "Height is : " << r.height << endl;
    cout << "Area is :" << r.area << endl;
    
}

// r.area = r.width * r.height;
// Stores the result inside the object, --> Better

int main() {
    Rectangle r1(14,12);

    calculateArea(r1);

    display(r1);

    return 0;
}