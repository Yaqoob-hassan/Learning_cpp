#include<iostream>
using namespace std;


struct Books {
   string title; 
   int availabile_copies = 5;
   int total_copies = 5;
   int borrow_books = 0; 
};  

void BorrowBook(Books &book) {
     cout << " ------------------------------------------------- " << endl; 
    if(book.availabile_copies < 0) {
        cout << "Sorry, we are not availaible." << endl;
       return;   
    }

    book.availabile_copies -= 1; 
    book.borrow_books += 1; 

    cout << "Books left are : " << book.availabile_copies << endl;
     cout << " ------------------------------------------------- " << endl; 


}

void ReturnBook(Books &book) {
     cout << " ------------------------------------------------- " << endl; 
    if(book.availabile_copies == book.total_copies) {
        cout << "You cant return the book" << endl;
        return; 
    }
    book.availabile_copies += 1;
    cout << "Book return successfully." << endl;
    cout << "Book copies are :" << book.availabile_copies << endl;
     cout << " ------------------------------------------------- " << endl; 

}

void Status(const Books &book) {
    cout << " ------------------------------------------------- " << endl; 
    cout << "Total copies  are :" << book.total_copies << endl;
    cout << "Availaible copies are :" << book.availabile_copies << endl;
    cout << "Total time borrow book are :" << book.borrow_books << endl;
     cout << " ------------------------------------------------- " << endl; 
}

void transferBooks(Books &from, Books &to) {
     cout << " ------------------------------------------------- " << endl; 
    int copies; 
    while(true) {

        cout << "How many copies to transfer  :" ; cin >> copies; 

        if( copies < 0 || copies > from.availabile_copies ) {
            cout << "Not availaible that much copy." << endl;
            continue;
        }
        break;
    }

    for(int i = 0; i <= copies; i ++) {
        BorrowBook(from);
        ReturnBook(from); 
    }

   


 cout << " ------------------------------------------------- " << endl; 

}


int main() {
    Books b1, b2; 
    BorrowBook(b1); 

    ReturnBook(b1); 
    
    Status(b1); 

    transferBooks(b1, b2); 


    return 0; 

}