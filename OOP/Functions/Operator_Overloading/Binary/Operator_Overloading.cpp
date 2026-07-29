#include<iostream>
using namespace std; 


class Complex {
   
    private:   
       int real;  
       int image;  

    public :  
    Complex() {
        real = 0;
        image = 0; 
    }
       
    Complex(int r, int i) {
        real = r; 
        image = i; 
    }

    void print() {
        cout << " -------------------------------------- " << endl;
        cout << "Afte adding real values. We have result :" << real << endl;
        cout << "Afer adding image values. We have result :" << image << endl;
         cout << " -------------------------------------- " << endl; 
    }

    Complex operator + (Complex c) {
        Complex temp;

        temp.real = real + c.real;
        temp.image = image + c.image;
        return temp; 
    }


}; 


int main() {
     
    Complex C1(4, 5);
    Complex C2(2, 8);
    Complex C3 = C1 + C2; 

    C3.print(); 


    return 0; 

}