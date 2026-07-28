#include<iostream>
using namespace std;


class Number {
    private :   
       int number; 
    
       public : 
          
         Number() {
            int number = 0; 
         }

         Number(int n) {
            number = n; 
         }

         bool operator - (Number nu) {
            if( number < 0 ) {
                cout << "Number is negative : " << number <<  endl;
                return true;
            }
            else {
                cout << "Number is positive :  " << number << endl;
                return false;
            }

         }
};


int main() {
  Number n1 = -4; 
  Number n2 = 100;
  Number n3 = -150; 
  
  n1.operator-(n1); 

  n2.operator-(n2); 

  n3.operator-(n3); 

     
    return 0; 
}
