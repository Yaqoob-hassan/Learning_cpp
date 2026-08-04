#include<iostream>
using namespace std;


class Character {
  protected: 
     string name;
     int health;
     int attackPower; 
   
   public: 
      
      Character(string n, int h, int ap) {
        name = n;
        health = h;
        attackPower = ap;
      }

      int virtual attack() {
        cout << name << " attack for " << attackPower << " damage." << endl;
        return attackPower;     
    }

    int  virtual takeDamage(int damage) {
        health = health - damage;
        cout << "Remaining health is : " << health << endl;

        if (health < 0) {
            cout << "Character is dead." << endl;
        }
        return health; 
    }
    bool virtual isAlive() {
        return ( health > 0 ); } 

    virtual ~Character() {
        cout << "Destructor of Character." << endl;
    }


}; 

class Warrior: public Character {

  public: 
    Warrior(string n, int h, int ap) :Character(n, h, ap) {}

    int attack() override {
         
           int baseDamage = Character:: attack(); 
           int bonusDamage = baseDamage + 10; 
           return bonusDamage;  


    }
}; 


class healer : public Character {
    public:  
      
      

}; 










int main() {
    Character* ch[1];

    ch[0] = new Warrior("Thanos", 100, 44);

    for(int i = 0; i < 1; i++) {
        ch[i]->attack();
    }

    return 0; 

}