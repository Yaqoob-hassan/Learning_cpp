// ### Q3: Multiple Inheritance — Smart Device
// Create two base classes:
// - `WifiEnabled` with a function `connectWifi()` that prints a connection message
// - `BatteryPowered` with a function `checkBattery()` that prints a battery level message

// Create a class `SmartWatch` that inherits from **both**, and adds its own function `showTime()`.

// In `main()`, create a `SmartWatch` object and call all three functions (`connectWifi()`, `checkBattery()`, `showTime()`).

// ---

#include<iostream>
using namespace std;

class WifiEnabled {
   public: 

      void connectWifi() {
        cout << "Wifi is connected sucessfully." << endl;
      }

};

class BatteryPowered {
    protected:
      int battery =  45;

   public: 
     void checkBattery() {
         cout << "Battery level is : " << battery << endl;
     }
      
}; 

class SmartWatch: public WifiEnabled, public BatteryPowered {
    private: 
       double time = 10.30;

   public: 
      void showTime() {
        cout << "The current time is : " << time << " AM" <<  endl;
      }
 

};

int main() {
    SmartWatch s1; 
    s1.connectWifi();
    s1.checkBattery();
    s1.showTime();


    SmartWatch s2;
    s2.checkBattery(); 


    return 0;
}
