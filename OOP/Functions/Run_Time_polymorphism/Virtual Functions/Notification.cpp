#include<iostream>
using namespace std;


class Notification {
  public: 
     
     void virtual send() = 0; 


     int virtual getPriority() = 0;
     
     virtual ~Notification() {
        cout << "Notification destructor." << endl;
     }
};  


class EmailNotification : public Notification {
 
   private: 
     string email;  
     string message; 

   public:  

      EmailNotification(string e, string mess) {
        email = e; 
        message = mess; 
      }
      
     void send() override {
        cout << "sending email [" << email << "] to " << " :" << message << endl;     
    }

    int getPriority() override {
        cout << "Priority 1." << endl;
        return 1; 
    }



}; 

class SMSNotification : public Notification {

  private:  
     
    string  number; 
    string message; 

  public:  
      
   SMSNotification(string   n, string mes) {
    number = n; 
    message = mes; 
   } 
    
     void send() override {
         cout << "Message sent to phone number :" << number << endl; 
         cout << "Message is :" << message << endl;
     }

     int getPriority() override {
        cout << "Priority is : 02" << endl;
        return 2; 
     }



}; 

int main() {
    Notification* notification[2];

    notification[0] = new EmailNotification("myaqoobh13@gmail.com","visit lahore" );

    notification[1] = new SMSNotification("+923349533858" , "How are u ?");
    
    for(int i = 0; i < 2; i++) {
        cout << " --------------------------------------- " << endl; 
        notification[i]->send(); 
        notification[i]->getPriority(); 
        cout << endl; 
    }

    for(int i = 0; i < 2; i++) {
        delete notification[i];
    }
    

     

    return 0; 


}