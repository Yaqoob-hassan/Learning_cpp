// ### Q2: Multilevel Inheritance — Employee Hierarchy
// Create three classes in a chain:
// - `Person` — has `name` (string), and a function `setName()` and `getName()`
// - `Employee : public Person` — adds `employeeId` (int), with `setId()` and `getId()`
// - `Manager : public Employee` — adds `teamSize` (int), with `setTeamSize()` and a function `showDetails()` that prints name, employee ID, and team size all together

// In `main()`, create a `Manager` object, set all the values, and call `showDetails()`.

// ---


#include<iostream>
using namespace std;

class Person {
   protected: 
      string name; 


    public: 

       void setName() {
         cout << "------------------------------ " << endl;
        cout << "Enter your name :" ; 
        cin >> name; 
       }

       void getName() {
         cout << "------------------------------ " << endl;
        cout << "Person name is : " << name << endl;
       }
}; 

class Employee : public Person  {
    protected: 
      int employeeID; 

      public: 
         void setId() {
             cout << "------------------------------ " << endl;
            cout << "Enter employee ID :" ; 
            cin >> employeeID;
         }

         void getid() {
             cout << "------------------------------ " << endl;
            cout << "Employee Id is : " << employeeID << endl;
         }
};

class Manager : public Employee {
    private: 
      int TeamSize; 

    public: 
       void SetTeamSize() {
         cout << "------------------------------ " << endl;
        cout << "Enter team size  :" ;
        cin >> TeamSize; 
       }

       void showDetail() {
        cout << "------------------------------ " << endl;
        cout << "Employee name is :" << name << endl;
        cout << "Employee Id is : " << employeeID << endl;
        cout << "Team size is :" << TeamSize << endl;
       }
};


int main() {
    Manager m1;
    m1.setName(); 
    m1.getName(); 

    m1.setId(); 
    m1.getid(); 

    m1.SetTeamSize(); 

    m1.showDetail(); 

    return 0; 
}