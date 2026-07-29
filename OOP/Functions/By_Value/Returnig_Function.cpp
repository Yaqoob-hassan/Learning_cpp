#include<iostream>
using namespace std;

float lbs_To_kgs(float lbs) {
    cout << "Converting LBS to KGS :" << endl; 
    cout << lbs * 2.2 << endl;
    return lbs* 2.2; 
}


int main() {
    
    float lbs; 

    cout << "Enter value to convert :"; 
    cin >> lbs;

    lbs_To_kgs(lbs);
    

    return 0; 
}