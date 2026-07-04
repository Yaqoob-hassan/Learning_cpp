#include<iostream>
using namespace std;


class Book {
 private:

 string book_name;
 string book_author;
 int total_copies;
 int availaible_copies = 10;

 public:

 void bookName() {
    cout << "Enter the book name : ";
    getline(cin, book_name);
 }

 void bookAuthor() {
    cout << "Enter book author :";
    getline(cin, book_author);
 }

 void totalCopies() {
    cout << "Enter total copies : " ;
    cin >> total_copies;
 }

 int availaibleCopies() {
    cout << "Availaible copies of books are : " << availaible_copies;
 }

 void borrow_book(){
    if (availaible_copies == 0) {
        cout << "Book not availaible" << endl;
    }
    else {
    
        availaible_copies = availaible_copies - 1;

          cout << "Book left are :" << availaible_copies << endl;


    }
 }

 void display() {
    cout << "Book name is :" << book_name << endl;
    cout << "Book author is :" << book_author << endl;
    cout << "Total copies are :" << total_copies << endl;
    cout << "Availaible copies are : " << availaible_copies << endl;
 }

};

int main() {
    char ch;
    Book b1;

      b1.bookName();
        cout << endl;
    
        b1.bookAuthor();
        cout << endl;

        b1.totalCopies();
        cout << endl;

        b1.availaibleCopies();
        cout << endl;

    while(1) {
        cout <<  " --- Library Management system : --- " << endl;
        cout << "Do you want to borrow the book" << endl;
        cin >> ch;
        if(ch == 'y'){
            b1.borrow_book();
        }
        else {
            b1.availaibleCopies();
        }


        




    }
     

    
  




    return 0;



}