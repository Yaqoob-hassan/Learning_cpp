#include<iostream>
using namespace std;

int factorial(int n) {
    if ( n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

void display(int n) {

    if(n == 0) {
        return;
    }

    for(int i = 0; i < n ; i++) {
        cout << "factorial of " << n << " is " << endl;
    }
}

int main() {
   factorial(5);

   
   return 0;
}