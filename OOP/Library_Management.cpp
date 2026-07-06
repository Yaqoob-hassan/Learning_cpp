#include<iostream>
using namespace std;


class Book {
 private:

 string book_name; //  Book name 
 string book_author; // Book Author 
 int total_copies; //  Total copies
 int availaible_copies = 10; //  Availaible copies of that book 

 public:
  // Default  constructor 
  Book() {
  book_name = "Prince";
  book_author = "Leonardo";
  total_copies = 10;
  availaible_copies = 10;

 }
// Default constructor 
//  Book(){
//     bookName();
//     bookAuthor();
//     totalCopies();
//     availaibleCopies();

//  }
 // parametrized constrcutir 
 Book( string b, string a, int tc, int ac){
    book_name = b;
    book_author = a;
    total_copies = tc;
    availaible_copies = ac;

 }

 // Copy constructor 
 Book(Book &b) {
    book_name = b.book_name;
    book_author = b.book_author;
    total_copies = b.total_copies;
    availaible_copies = b.availaible_copies;
 }

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

 void availaibleCopies() {
    cout << "Availaible copies of books are : ";
    cin >> availaible_copies;
 }

 void issue_book(){
    if (availaible_copies == 0) {
        cout << "Book not availaible" << endl;
    }
    else {
    
        availaible_copies = availaible_copies - 1;

          cout << "Book left are :" << availaible_copies << endl;


    }
 }

 bool return_book() {
    availaible_copies = availaible_copies + 1;
    return true;
 }

 void display();

};

void Book :: display() {
   cout << "Book name is :" << book_name << endl;
    cout << "Book author is :" << book_author << endl;
    cout << "Total copies are :" << total_copies << endl;
    cout << "Availaible copies are : " << availaible_copies << endl;
}


class Library {
   private:

   int book[10];

   int count = 0;
   string book_name;
   string author_name;

   public:

   void add_book() {
      cout << "Enter book name :";
      cin >> book_name;

      cout << "Enter author name :";
      cin >> author_name;

   }

}

int main() {
     int n;
    // Parametrized Constructor 
  //  Book b1( "ALi", "Aslam", 15, 2);
   
   // Copy Constructor 
   // Book b2 = b1;
   // Default constructor 
  //  Book b3;
   
  // Displaying it 
   // b1.display();
 
   // cout << endl;
   // Displaying Copy Constructor 
   //b2.display();
   //cout << endl;
    
   // Displaying Default Constructir 
   /// b3.display();

   Book b1;


    while(1) {
        cout << endl;
        cout << "--- Library management system. --- " << endl;
        cout << "Select any one option. " << endl;
        cout << "1. Do you want to borrow book." << endl;
        cout << "2. Do you want to return book." << endl;
        cout << "3.Display all results." << endl;
        cout << "4.Enter 4 to exit from program." << endl;
        cout << endl;
        cin >> n;

        if(n == 4) {
        break;
        }

      switch(n) {
        case 1:
        b1.issue_book();
        break;

        case 2 :
        b1.return_book();
        break;


        case 3:
        b1.display();
        break;
    }
  

    }
  




    return 0;



}