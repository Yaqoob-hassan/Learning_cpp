#include<iostream>
using namespace std;


struct Distance {
   int feet; 
   float inches; 
};


void display(Distance); 

int main() {

    Distance d1, d2;

    cout << "Enter feet :"; cin >> d1.feet; 
    cout << "Enter inches :"; cin >>  d1.inches; 

    cout << endl;

    cout << "Enter feet d2 :"; cin >> d2.feet; 
    cout << "Enter inches d2 :";
    cin >>  d2.inches; 

    display(d1); 

    display(d2);

    return 0; 

}

void display(Distance dd) {
    cout << dd.feet << ", " << dd.inches << endl;
}