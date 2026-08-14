// ### Q4: Hierarchical Inheritance — Payment System
// Create a base class `Payment` with a function `processPayment(double amount)` that prints `"Processing payment of <amount>"`.

// Create two derived classes that each inherit from `Payment` and **override** `processPayment()` with their own specific message:
// - `CreditCardPayment` — prints something mentioning "credit card"
// - `UpiPayment` — prints something mentioning "UPI"

// In `main()`, create one object of each derived class and call `processPayment()` on both.

// ---

#include<iostream>
using namespace std;

class payment {
 

 public: 

    virtual void processPayment(double amount) {
         if(amount <  0) {
    cout << "Amount must be greater than zero." << endl;
    return; }
         cout << " -------------------------------- " << endl;
        cout << "Processing payment of: " << amount  << endl;
    }

    virtual ~payment() {
        cout << " -------------------------------- " << endl;
        cout << "Payment destructor." << endl;
    }

};


class CreditCard : public payment{

  public: 
   
    void processPayment(double amount) override {
           if(amount <  0) {
    cout << "Amount must be greater than zero." << endl;
    return;
 }

        cout << " -------------------------------- " << endl;
       cout << "Payment processing with credit card: " << amount << endl;
}
    ~CreditCard() {
        cout << " -------------------------------- " << endl;
    cout << "Credit Card destructor." << endl;
}
};

class UpiPayment : public payment{
   
    public: 
       void processPayment(double amount) override {
         if(amount <  0) {
    cout << "Amount must be greater than zero." << endl;
    return; } 
        
        cout << " -------------------------------- " << endl;
        cout << "Payment processing with UPI." << endl;
        cout << "The amount is : " << amount << endl;
       }

    ~UpiPayment() {
        cout << " -------------------------------- " << endl;
        cout << "Destrucotor of UpiPayment." << endl;
    }
};

int main() {
    payment* p = new CreditCard;
    payment* p1 = new UpiPayment;
    payment* p2 = new payment;




    p->processPayment(21);
    p1->processPayment(44);
    p2->processPayment(444);


    delete p;
    delete p1;
    delete p2;
    
    return 0;
}


