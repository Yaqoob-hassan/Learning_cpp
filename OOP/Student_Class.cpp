#include<iostream>
using namespace std;

class student {
   private:

    int regno;
    string name;
    string department;

    public:

    void Regno() {
        cout << "Enter your registration number :";
        cin >> regno;
    }

    void Name() {
        cout << "Enter your name :";
        cin >> name;
    }

    void Department();
      
    void display();

};

void student :: display() {
        cout << "Registration no is :" << regno << endl;
        cout << "Registration no is :" << name << endl;
        cout << "Registration no is :" << department << endl;
}

void student :: Department() {
        cout << "Enter your department :";
        cin >> department;
}

int main() {
    student s1;

    s1.Regno();
    s1.Name();
    s1.Department();


    s1.display();
    

    return 0;
}