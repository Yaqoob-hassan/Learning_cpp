#include<iostream>
using namespace std;


class Box {
  private: 
     int lenght;

  public:
     
     Box(int l) {
       lenght = l;
     }

     friend void showlenght(Box b);

};

void showlenght(Box b) {
  cout << "Lenght of box is :" << b.lenght << endl;
}


int main() {
  Box b(10);
  showlenght(b);


  return 0;

  
}

