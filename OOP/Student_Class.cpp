/*
    PROGRAMMING QUESTION: Inheritance in C++ (Student & Marks System)

    1. Create a base class called `Student` with:
       - Data members: `name` (string), `rollnumber` (int)
       - A parameterized constructor to initialize `name` and `rollnumber`
       - A function `display_Info()` that prints the student's name and roll number
       - A destructor that prints a message like "Student object deleted"

    2. Create a derived class called `Mark` that inherits (publicly) from `Student`, with:
       - An additional data member: `marks` (int, out of 100)
       - A parameterized constructor that:
            * Takes rollnumber, name, and marks as parameters
            * Passes rollnumber and name to the base class constructor
              using constructor chaining (initializer list)
            * Initializes marks in its own body
       - A function `display()` that:
            * Reuses the inherited `display_Info()` function (don't repeat code)
            * Also prints the student's marks
       - A function `calculate_grade()` that uses if-else if-else conditions
         to print a grade based on marks:
              90-100 -> "A+"
              80-89  -> "A"
              70-79  -> "B"
              60-69  -> "C"
              50-59  -> "D"
              Below 50 -> "Fail"
         (Make sure boundary values, e.g. exactly 90, fall into the correct
          higher grade bucket - check your comparison operators carefully.)

    3. In main():
       - Create 2-3 Mark objects with different sample marks
       - For each object, call display() and calculate_grade()
       - Add blank lines (cout << endl;) between outputs for readability

    CONCEPTS PRACTICED:
    - Single inheritance (public)
    - protected access specifier
    - Parameterized constructors
    - Constructor chaining (calling base class constructor from derived class)
    - Destructors
    - Function reuse across base/derived classes (DRY principle)
    - if-else if-else conditional chains and boundary condition handling
*/


#include<iostream>
#include<string>
using namespace std;

class Student {
    protected:
      int rollnumber;
      string name;

    public:
    // parametrized constructor 
      Student(int r, string n) {
        rollnumber = r;
        name = n;
      }
     // Display function
     void display_Info() {
        cout << "student name is : " << name << endl;
        cout << "Student roll number is :" << rollnumber << endl;
     }

     ~Student() {
        cout << "Student object deleted." << endl;
     }
};

class Subject : public Student {
    protected:
    int chemistry;
    int  math;
    int  physics;
    int urdu;
    int english;

    public: 
    
    Subject(int r, string n) : Student(r, n) {
    }
    void marks_in_subject() {
        cout << "Enter marks in math :" ;
        cin >> math;
        cout << "Enter marks in physics :";
        cin >> physics;
        cout << "Enter marks in chemistry :";
        cin >> chemistry;
        cout << "Enter marks in urdu :";
        cin >> urdu;
        cout << "Enter marks in english :";
        cin >> english;
    }
   void display_info() {
    cout << "Student name is :" << name << endl;
    cout << "Student roll number is :" << rollnumber << endl;
    cout << "Marks in math is :" << math << endl;
    cout << "Marks in physics is :" << physics << endl;
    cout << "Marks in chemistry is :" << chemistry << endl;
    cout << "Marks in urdu is :" << urdu << endl;
    cout << "Marks in english is :" << english << endl;
   }

    // ~Subject()  {
    //     cout << "Subject object deleted." << endl;
    // }

};

//   void display() {
//        display_Info();
//        cout << "Student marks are : " << marks << '\n';
//     }

//     void calculate_grade() {
//         if(marks > 90) {
//             cout << "Your grade is : A+." << endl;
//         }
//         else if(marks > 80) {
//             cout << "Your grade is : A." << endl;
//         }
//         else if(marks > 70) {
//              cout << "Your grade is : B" << endl;
//         }
//         else if(marks > 60) {
//             cout << "Your grade is : C" << endl;
//         }
//         else if(marks > 50) {
//             cout << "Your grade is : D" << endl;
//         }
//         else {
//             cout << "Fail." << endl;
//         }
//     }


int main() {

    Subject s1(4550, "ALi");
    cout << "--- Student information. --- " << endl;
    s1.marks_in_subject();
    s1.display_info(); 
    cout << endl;

    return 0;
}