// 5. Create a structure of type date that contains three members: the month, the day of the
// month, and the year, all of type int. (Or use day-month-year order if you prefer.) Have
// the user enter a date in the format 12/31/2001, store it in a variable of type struct date,
// then retrieve the values from the variable and print them out in the same format.

#include<iostream>
using namespace std;

struct Date {
  int month;
  int day;
  int year; 

  void Enter_DOB() {
    cout << "Enter Date of birth in this formate 12/31/2001 :" << endl;
    cout << "Enter month : ";  
    cin >> month;
    cin.ignore(1, '/');

    cout << "Enter day : " ; 
    cin >> day;
    cin.ignore(1, '/');

    cout << "Enter year : "; 
    cin >> year;

      
  }

  void display() {
    cout << "Date of birth is : " << month << "/" << day << "/" << year ;

  }
};

int main() {
    Date d1; 
    d1.Enter_DOB();
    d1.display(); 

    return 0; 
}