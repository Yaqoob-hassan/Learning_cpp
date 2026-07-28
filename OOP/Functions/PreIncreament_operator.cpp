#include<iostream>
using namespace std;


class PreIncreament {
   private :
      int number;  

   public:   
      
      PreIncreament() {
        number = 0; 
      }

      PreIncreament(int n) {
        number = n;
      }

      PreIncreament operator ++() {
        PreIncreament temp; 
        
        temp.number = ++number; 
        return temp; 
      }

      

      void print() {
        cout << " ------------------------------------ " << endl;
        cout << "Pre  increament." << endl;
        cout << "Value of integer is :" << number << endl;
         cout << " ------------------------------------ " << endl;
      }

}; 




int main() {
    PreIncreament p(4);
    
    ; 
   

    p.operator++();

    p.print(); 
    
   


    return 0; 
}