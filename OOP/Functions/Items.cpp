#include<iostream>
using namespace std; 


struct Items {
    string name;
    int quantity = 0;
    int lowStockThreshold = 10;

}; 


  void restock(Items &items, int amount) {
        if(amount < 0) {
            cout << "There is no need to restock." << endl; 
            return; 
        }
        items.quantity += amount; 

        cout << items.name << " quantity are " << items.quantity << endl;
    }

    void sell(Items &items, int amount) {
        if(amount > items.quantity) {
            cout << "Not suffient quantity." << endl;
            return;
        }
        items.quantity -= amount;
        cout << items.name << " quantity left are :" << items.quantity << endl;
    }

    void checkStock(Items &items) {
        if(items.quantity <  items.lowStockThreshold) {
            cout << "we are running out of stock." << endl;
            cout << "Restock them." << endl;
            return; 
        }

        cout << items.name << " quantity left are :" << items.quantity << endl; 
        cout << "Stock left are :" << items.lowStockThreshold << endl; 

    }
    
    void transfer(Items &from, Items &to) {
        int amount; 
        while(true) {
            cout << "Enter amount to transfer :" << endl;
            cin >> amount; 

            if(amount < 0) {
                cout << "Amount must be greater than zero." << endl;
                continue; }
                break;
        }

        sell(from, amount);
        restock(to, amount); 

    }

int main() {
    Items t1, t2; 
    t1.name = "Biscit";
    t2.name = "Candy";  
    restock(t1, 10); 
    sell(t1, 2);
    // checkStock(t1);

    transfer(t1, t2); 


    return 0; 
}