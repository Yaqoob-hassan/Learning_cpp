#include<iostream>
using namespace std; 



class PostIncreament {
   private:  
     int numbers;  

    public:   
       PostIncreament() {
        numbers = 0; 
      }

      PostIncreament(int n) {
        numbers = n;
      }

      PostIncreament operator ++ () {
        PostIncreament temp;
        temp.numbers = numbers++;
        return temp; 
      }

      void print() {
        cout << " ------------------------------------ " << endl;
        cout << "Post increament." << endl;
        cout << "Value of integer is :" << numbers << endl;
        cout << " ------------------------------------ " << endl;
        
      }

       
}; 




int main() {
    
    PostIncreament p1(0); 
    p1.operator++(); 
 
    
    p1.print(); 


    return 0; 
}