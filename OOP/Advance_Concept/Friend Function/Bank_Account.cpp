// Create a class Account with private members:
// string ownerName
// double balance
// int accountNumber
// double totalFeesCharged (starts at 0)

// Create a constructor that initializes ownerName, balance,
//  and accountNumber (fees start at 0)

// Create these friend functions (not member functions):
// void transfer(Account &from, Account &to, double amount)
// Deducts amount from from.balance and adds it to to.balance
// If the transfer amount is greater than $1000,
//  charge a 2% fee on the transfer amount, deducted from the sender's balance, and add that fee to from.totalFeesCharged
// If from.balance is insufficient (including the fee), print an error message and do not perform the transfer at all

// void applyInterest(Account &acc, float rate)
// Adds interest to the account balance based on rate (percentage, e.g., 5 means 5%)
// void display(Account acc)
// Prints owner name, account number, balance (formatted to 2 decimal places), and total fees charged


// In main():
// Create three accounts with different starting balances
// Perform at least four transfers between different pairs of accounts, including:
// One transfer under $1000 (no fee)
// One transfer over $1000 (fee applies)
// One transfer that should fail due to insufficient funds
// Apply interest to at least one account
// Display all three accounts' final states

#include<iostream>
using namespace std;

class Account {
    private: 
       string OwnerName;
       double balance;
       int AccountNumber;
       double TotalFeeCharge = 0;

    public: //  Constructor 

        Account(string ON, double bl, int AN, double TFC) {
            OwnerName = ON;
            balance = bl;
            AccountNumber = AN;
            TotalFeeCharge =TFC = 0;
        }
        
        // Functions 
        friend void transfer(Account &from, Account &to, double amount);

// Deducts amount from from.balance and adds it to to.balance
// If the transfer amount is greater than $1000,
//  charge a 2% fee on the transfer amount, deducted from the sender's balance, and add that fee to from.totalFeesCharged
// If from.balance is insufficient (including the fee), print an error message and do not perform the transfer at all
        
    };

    void transfer(Account &a1, Account &a2, double amount) {
        if(amount < 0) {
            cout << "Can't transfer money less than zero." << endl;
            return;
        } 

        if(amount > 1000) {
            double tax = amount * 0.02;
        }
    }

