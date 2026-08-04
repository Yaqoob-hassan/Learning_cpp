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

int main() {
    Notification* notification[1];

    notification[0] = new EmailNotification("myaqoobh13@gmail.com","visit lahore" );
    
    for(int i = 0; i < 1; i++) {
        cout << " --------------------------------------- " << endl; 
        notification[i]->send(); 
        notification[i]->getPriority(); 
        cout << endl; 
    }

    for(int i = 0; i < 1; i++) {
        delete notification[i];
    }
    

     

    return 0; 


}