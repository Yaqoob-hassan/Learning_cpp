








// In main():
// Create three accounts with different starting balances
// Perform at least four transfers between different pairs of accounts, including:
// One transfer under $1000 (no fee)
// One transfer over $1000 (fee applies)
// One transfer that should fail due to insufficient funds
// Apply interest to at least one account
// Display all three accounts' final states

// Create a class Account with private members:
// string ownerName
// double balance
// int accountNumber
// double totalFeesCharged (starts at 0)

#include<iostream>
using namespace std;

class Account {
    private: 
       string OwnerName;
       double balance;
       int AccountNumber;
       double TotalFeeCharge = 0;

    public: // Create a constructor that initializes ownerName, balance,
           //  and accountNumber (fees start at 0)

        Account(string ON, double bl, int AN, double TFC) {
            OwnerName = ON;
            balance = bl;
            AccountNumber = AN;
            TotalFeeCharge =TFC = 0;
        }
        
// Create these friend functions (not member functions):
// void transfer(Account &from, Account &to, double amount)
// Deducts amount from from.balance and adds it to to.balance
// If the transfer amount is greater than $1000,
//  charge a 2% fee on the transfer amount, deducted from the sender's balance, and add that fee to from.totalFeesCharged 
// If from.balance is insufficient (including the fee), print an error message and do not perform the transfer at all
        friend void transfer(Account &from, Account &to, double amount);

        friend void interest(Account &acc, float rate);

 

       friend void display(Account &acc);
 


        
    };

    void transfer(Account &a1, Account &a2, double amount) {

        if(amount < 0) {
            cout << endl;
                cout << " ------------------ TRANSFERING AMOUNT ----------------- " << endl;

            cout << "Can't transfer money less than zero." << endl;
            return;
        } 

        if(amount > 1000) {

            cout << endl;
            cout << " ------------------ TRANSFERING AMOUNT ----------------- " << endl;

            double fee = amount * 0.02;

            double TotalAmount = amount + fee;

            if(a1.balance < TotalAmount) {
                cout << "Your balance is not that much." << endl;
                return;
            }

            a1.balance -= TotalAmount;
            a2.balance += amount;

           a1.TotalFeeCharge += fee;

           cout << "Transaction Successful." << endl;

        }

        if(amount <= 1000) {
            cout << endl;
                cout << " ------------------ TRANSFERING AMOUNT ----------------- " << endl;
            double fee = 0;

            double TotalAmount = amount + fee;

            if(a1.balance < TotalAmount) {
                cout << "Your balance is not that much." << endl;
                return;
            }

            
            a1.balance -= TotalAmount;
            a2.balance += amount;

           a1.TotalFeeCharge += fee;

           cout << "Transaction Successful." << endl;
        }

        }

// void applyInterest(Account &acc, float rate)
// Adds interest to the account balance based on rate (percentage, e.g., 5 means 5%)


      void interest(Account &a2, float rate) {
        cout << endl; 
        cout << " --------------- INTEREST RATE --------------------- " << endl;

        double decimalRate = rate / 100;

        double interestRate = a2.balance * decimalRate;
        
        a2.balance += interestRate;

        cout << "The account balance is now :" << a2.balance << endl;
        cout << "The account number is :" << a2.AccountNumber << endl;
      }
      
// void display(Account acc)
// Prints owner name, account number, balance (formatted to 2 decimal places), and total fees charged
      void display(Account &acc) {
        cout << endl; 
        cout << " ---------- DISPLAYING ACCOUNT INFORMATION ----------------- " << endl;
        cout << "Account owner name is :" << acc.OwnerName << endl;
        cout << "Account balance is : " << acc.balance << endl;
        cout << "Account Number is :" << acc.AccountNumber << endl;
        cout << "Account fee is :" << acc.TotalFeeCharge << endl;
      }

    

// In main():
// Create three accounts with different starting balances
// Perform at least four transfers between different pairs of accounts, including:
// One transfer under $1000 (no fee)
// One transfer over $1000 (fee applies)
// One transfer that should fail due to insufficient funds
// Apply interest to at least one account
// Display all three accounts' final states

    int main() {

     Account A("Usman", 1500, 145, 0);
     Account B("Uzair", 950, 170, 0 );
     Account C("Ramsha", 750, 111, 0);


     transfer(A, B, 410);

     transfer(B, C, 1111);
     
     transfer(C, A, 90000);

     interest(A, 140);

     display(A);

     display(B);

     display(C);





        return 0;
    }

