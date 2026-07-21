// Create a structure called time. Its three members, all type int, should be called hours,
// minutes, and seconds. Write a program that prompts the user to enter a time value in
// hours, minutes, and seconds. This can be in 12:59:59 format, or each number can be
// entered at a separate prompt (“Enter hours:”, and so forth). The program should then
// store the time in a variable of type struct time, and finally print out the total number of
// seconds represented by this time value:
// long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds


#include<iostream>
using namespace std;


struct Time
{
    int hours;
    int minutes;
    int seconds;
   
    void Enter_time() {

        cout << "Enter hours ( 0 -- 24 ) :";
        cin >> hours;  

        

        cout << "Enter minutes :";
        cin >> minutes; 

        cout << "Enter seconds :";
        cin >> seconds;  
    }


    void display() {
        cout << hours << ":" << minutes << ":" << seconds << endl;

    }
    int  total_secs() {
        long total_sec =   hours*3600 + minutes*60 + seconds; 
        return total_sec;


     }


};




int main() {
    Time t1;

    t1.Enter_time();

    t1.display();
    
    cout << t1.total_secs(); 

    return 0; 
    
}
