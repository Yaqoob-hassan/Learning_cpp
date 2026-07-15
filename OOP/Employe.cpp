#include<iostream>
using namespace std;

class Employe {
    private :
    int emp_id;
    string emp_name;

    public: 
    

    void emp_data() {
        cout << "Enter employe name :" ;
        cin >> emp_name;

        cout << "Enter employe id :" ; cin >> emp_id;
    }


};

int main() {
    Employe e1;

    e1.emp_data();

    return 0;
    
}