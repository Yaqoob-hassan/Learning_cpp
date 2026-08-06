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


class Healer : public Character {
    public:  
      Healer(string n, int h, int ap) : Character(n, h, ap) {}

      int attack() override {
        int healamount = 25; 
        health = health + healamount;
        cout << name << " heal for 25hp. Health is now " << health << endl;
        return 0;  
      }
      

}; 

class Mage: public Character {
   public: 

   Mage(string n, int h, int ap) : Character(n, h, ap) {}

     int attack() override {
        int basePower = Character::attack();
        int bonusPower = basePower + basePower; 
        return bonusPower;
     }
}; 










int main() {
    Character* ch[3];
    Character* target = new Character("Dragon", 100, 24);

    for(int i = 0; i < 2; i++) {
        target[i]->attack(); 
    }

    ch[0] = new Warrior("Thanos", 100, 44);
    ch[1] = new Healer("Alpha",100, 45 );
    ch[2] = new Mage("Beta", 100, 21);

    // for(int i = 0; i < 3; i++) {
    //     ch[i]->attack();
    // } 



    for(int i = 0; i < 3; i++) {
        delete ch[i];
    }

    return 0; 

}