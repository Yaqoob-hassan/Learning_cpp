#include<iostream>
using namespace std;


class Point {
    private:   
       int x; 
       int y; 

    public:   
       
       Point() {
        x = 0; 
        y = 0; 

       }

      Point(int X, int Y)  {
        x = X; 
        y = Y; 
      }

      bool  operator == (Point p) {
         if( x == p.x && y == p.y) {
            cout << "Values are equals" << endl;
            return true;
         }
         else {
            cout << "Values are not equals." << endl;
            return false;
         }
      }
};  


int main() {
    Point p1(4, 5);
    Point p2(4, 7);

    p1 ==  p2; 




    return 0; 

    
}