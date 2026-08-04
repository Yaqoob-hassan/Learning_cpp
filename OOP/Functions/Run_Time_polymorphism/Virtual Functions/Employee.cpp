#include<iostream>
using namespace std;

class Employee {
    private: 
      int monthly_salary = 41111;
  public: 
     virtual int  calculate_salary() {
        cout << "Calculating salary." << endl;
        return monthly_salary; 
     }

    virtual ~Employee() {
        cout << "Employee destructor." << endl;
    } 
};  

class Full_Time_Emp : public Employee {
   private:  
      int  monthly_salary; 

    public:  
        Full_Time_Emp(double s) : monthly_salary(s) {}

       int calculate_salary() override {
        cout << "Your monthly salary is :" << monthly_salary << endl;
        return monthly_salary;
       }

    ~Full_Time_Emp() {
        cout << "Full time Emp destructor." << endl;
    }
    
};


class Part_Time_Emp : public Employee {
   private: 
     int  rate = 25; 
     int  hourly;
    
    public:  
     
    Part_Time_Emp(int h) {
        hourly = h;
    }
       int calculate_salary() override {
        cout << "Your salary is :" << hourly * rate; 
        cout << endl;
        return hourly * rate; 
       }

    ~Part_Time_Emp() {
        cout << "Part Time Emp destructor." << endl;
    }
};

int main() {
    Employee* emp[3];

    emp[0] = new Full_Time_Emp(55000);
    emp[1] = new Part_Time_Emp(56);
    
    for(int i = 0; i < 2; i++) {
        cout << "------------------------------" << endl; 
        emp[i]->calculate_salary();
    }

    for(int i = 0; i < 2 ; i++) {
        delete emp[i];
    }


    return 0;



}


