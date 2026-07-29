#include<iostream>
using namespace std;

struct Account {
   string owner;
   double balance = 22; 
};


void deposit(Account &acc, double amount) {
    if (amount < 0) {
        cout << "Amount must be greater than 0." << endl;
        return;
    }
    acc.balance += amount;
    cout << acc.owner << "'s balance is now: " << acc.balance << endl;
}

void Withdraw(Account &acc, double amount) {
    if (amount > acc.balance) {
        cout << "Cant withdraw due to lack of balance." << endl;
        return;
    }
    acc.balance -= amount;
    cout << acc.owner << "'s balance is now: " << acc.balance << endl;
}


void Transfer_amount(Account &from, Account &to) {
    double amount;

    while (true) {
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount < 0) {
            cout << "Amount must be greater than zero." << endl;
            continue;
        }
        break;
    }

    Withdraw(from, amount);   
    deposit(to, amount);      
}

int main() {
    Account a1, a2;
    a1.owner = "Yaqoob";
    a2.owner = "Ahmed";

    deposit(a1, 20);      
    Withdraw(a1, 10);      

    Transfer_amount(a1, a2);   

    cout << "Final balances -> " << a1.owner << ": " << a1.balance 
         << " | " << a2.owner << ": " << a2.balance << endl;

    return 0;
}