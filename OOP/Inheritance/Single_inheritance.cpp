#include<iostream>
using namespace std;


class Account {
  protected: 

    double balance = 0; 

  public: 
      
    void deposit(double amount) {
        if(amount < 0) {
            cout << " --------------------------------------- " << endl;
            cout << "Amount must be greater than zero. " << endl;
            return; 
        }
        else {
            cout << " -------------------------------------- " << endl;
        cout << "deposit is send successfully." << endl;
        balance += amount;
        }  
    }


    
}; 

class SavingAccount : public Account {
   private: 
     double interestRate = 2.5;

    public: 
       
       double InterestRate() {
        cout << " ------------------------------------- " << endl;
           double interestAmount = balance * interestRate; 
           balance += interestAmount;
           return interestAmount;
       }

       void show_balance() {
        cout << " ----------------------------------- " << endl;
        cout << "Your current balance is : " << balance << endl;
       }


};

int main() {
    SavingAccount s1;
    s1.deposit(100);
    s1.show_balance(); 

    s1.InterestRate();
    s1.show_balance(); 

    return 0; 

}