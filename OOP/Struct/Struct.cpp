// Write a program that uses a structure called point to model a point. Define three points,
// and have the user input values to two of them. Then set the third point equal to the sum
// of the other two, and display the value of the new point. Interaction with the program
// might look like this:
// Enter coordinates for p1: 3 4
// Enter coordinates for p2: 5 7
// Coordinates of p1+p2 are: 8, 11


#include<iostream>
using namespace std;

struct Point
{
    int x; // Two varaibles 
    int y; // As int has 4 bytes so total memory will be consume 8 bytes 

    void Enter_coordinate() { // Function to enter coordinates  
        cout << "Enter x coordiantes :" ;
        cin >> x ;
        cout << "Enter y coordinates :"; cin >> y ;
    }

    void display(string name )  { // Displaying Coordinates  
        cout << "Coordinates for : "<< name << " are :" << x << ", " << y << endl;
    }
    void sum_display() {  // Displaying Sum of P3 
        cout << "Coordinatea for p1 + p2 are :" << x << ", " << y << endl;
    }
};


int main() {
    Point p1, p2, p3; // Three objects    ---[ one object 8 bytes ] --> [ second 8 bytes ] -- > [ third 8 bytes ]
    p1.Enter_coordinate();
    p2.Enter_coordinate();

    p1.display("p1");
    p2.display("p2");

    p3.x  = p1.x + p2.x; 
    p3.y = p1.y + p2.y; 
    p3.sum_display(); 


    



    return 0;
}
