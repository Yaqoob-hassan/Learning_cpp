#include <iostream>
#include <string>
using namespace std;

// ======================
// Base Class
// ======================
class Student {
protected:
    int rollnumber;
    string name;

public:
    // Parameterized Constructor
    Student(int r, string n) {
        rollnumber = r;
        name = n;
    }

    // Display Student Information
    void display_Info() {
        cout << "Student Name      : " << name << endl;
        cout << "Roll Number       : " << rollnumber << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student object deleted." << endl;
    }
};

// ======================
// Derived Class
// ======================
class Subject : public Student {
protected:
    int math;
    int physics;
    int chemistry;
    int urdu;
    int english;

public:
    // Constructor
    Subject(int r, string n) : Student(r, n) {
        math = physics = chemistry = urdu = english = 0;
    }

    // Input Marks
    void marks_in_subject() {
        cout << "Enter Marks in Math: ";
        cin >> math;

        cout << "Enter Marks in Physics: ";
        cin >> physics;

        cout << "Enter Marks in Chemistry: ";
        cin >> chemistry;

        cout << "Enter Marks in Urdu: ";
        cin >> urdu;

        cout << "Enter Marks in English: ";
        cin >> english;
    }

    // Display Subject Information
    void display_subject() {
        display_Info();      // Reuse Parent Function

        cout << "Math Marks        : " << math << endl;
        cout << "Physics Marks     : " << physics << endl;
        cout << "Chemistry Marks   : " << chemistry << endl;
        cout << "Urdu Marks        : " << urdu << endl;
        cout << "English Marks     : " << english << endl;
    }

    // Total Marks
    int total_mark_obtained() {
        return math + physics + chemistry + urdu + english;
    }

    // Destructor
    ~Subject() {
        cout << "Subject object deleted." << endl;
    }
};

// ======================
// Multilevel Derived Class
// ======================
class Result : public Subject {
private:
    float percentage;

public:
    Result(int r, string n) : Subject(r, n) {
        percentage = 0;
    }

    // Calculate Percentage
    void calculate_percentage() {
        int obtained = total_mark_obtained();
        percentage = (obtained / 500.0f) * 100;
    }

    // Calculate Grade
    void calculate_grade() {

        if (percentage >= 90)
            cout << "Grade             : A+" << endl;

        else if (percentage >= 80)
            cout << "Grade             : A" << endl;

        else if (percentage >= 70)
            cout << "Grade             : B" << endl;

        else if (percentage >= 60)
            cout << "Grade             : C" << endl;

        else if (percentage >= 50)
            cout << "Grade             : D" << endl;

        else
            cout << "Grade             : Fail" << endl;
    }

    // Display Complete Result
    void display_result() {

        display_subject();

        cout << "----------------------------------" << endl;

        cout << "Total Marks       : "
             << total_mark_obtained() << " / 500" << endl;

        calculate_percentage();

        cout << "Percentage        : "
             << percentage << "%" << endl;

        calculate_grade();
    }

    // Destructor
    ~Result() {
        cout << "Result object deleted." << endl;
    }
};

// ======================
// Main Function
// ======================
int main() {

    Result s1(4550, "Ali");
    Result s2(4551, "Ahmed");

    cout << "========== Student 1 ==========\n";

    s1.marks_in_subject();
    cout << endl;
    s1.display_result();

    cout << "\n\n";

    cout << "========== Student 2 ==========\n";

    s2.marks_in_subject();
    cout << endl;
    s2.display_result();

    return 0;
}