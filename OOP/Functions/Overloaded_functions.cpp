//  Code taken from my Books.cpp 
// Function overloading is performed in this code
// The display function is used in three ( 3 ) different way. 

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
    if(book.availabile_copies ==  0) {
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
        cout << "You cant return book." << endl; 
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

void copy_book(Books &to ) {
        to.total_copies += 1;
        to.availabile_copies += 1; 

        cout << "Total copies are now :" << to.total_copies << endl;
        cout << "Availaible copies are now :" << to.availabile_copies << endl;

        cout << "Sended book to " << to.title << endl;
}


void transferBooks(Books &from, Books &to) {
     cout << " ------------------------------------------------- " << endl; 
    int copies; 
    while(true) {

        cout << "How many copies to transfer  :" ; cin >> copies; 

        if( copies < 0 || copies > from.availabile_copies  ) {
            cout << "Not availaible that much copy." << endl;
            continue;
        }
        break;
    }

    for(int i = 0; i < copies; i ++) {
        BorrowBook(from);
        copy_book(to); 
    }

   


 cout << " ------------------------------------------------- " << endl; 

}


void display(Books &book) {
    cout << "Title of the books is :" << book.title << endl;
   cout << "Availaible copies are :" << book.availabile_copies << endl;
}

void display(Books &book, int count) {
    // cout << "How many of " << book.title << " do you want :";
    // cin >> count; 

   if(count >  book.availabile_copies) {
    cout << "Sorry, that much copy of " << book.title << " is not availaible " << endl;
    cout << "Currently there are only " << book.availabile_copies << " availaible " << endl;
   }

}


void display(Books &book, Books &b) {
    cout << "Title of Book is " << book.title << endl; 

    cout << "Title of Books is :" << b.title << endl;
}


int main() {
    Books b1, b2; 
    b1.title = "Prince"; 
    b2.title = "Power"; 
    
    BorrowBook(b1); 

    ReturnBook(b1); 
    
    Status(b1); 

    transferBooks(b1, b2); 
    
    display(b1); 

    display(b1, 88); 

    display(b1, b2); 

    return 0; 

}