
#include<iostream>
using namespace std;

class Player {

   private: 
      string playerName;
      int health = 100;
      int potionHeld; // Healing potions the player has in his bag
      int monsterDefeated = 0;
      bool isAlive = true;

    public: 
        
       Player(string PN, int ph) {
        playerName = PN;
        potionHeld = ph;
       }

friend void attackMonster(Player &p, int monsterDamage, int monsterDifficulty);
friend void UsepotionHeld(Player &p);
friend void revive(Player &p, Player &healer);
friend void display(Player &p);

};

    void attackMonster(Player &p, int monsterDamage, int monsterDifficulty) {
        if(p.isAlive == false) {

            cout << "Player is dead. " << endl;
            return;
        }

        p.health -= monsterDamage;
        if(p.health <= 0) {
            p.isAlive = false;
            cout << "Player is dead." << endl;
            p.health = 0;
            return;
        }
        else {
           cout << "Player survive the hit." << endl;
           p.monsterDefeated += 1;
           
              if(monsterDifficulty > 7) {
                cout << "Bonus round." << endl;
                p.potionHeld += 1;
              }

            }
        }

        void UsepotionHeld(Player &p) {
            if(p.isAlive == false ) {
                cout << "Player is dead. Cant use the healing potion." << endl;
                return;
            }

            if(p.potionHeld == 0) {
                cout << "Cant increase health. As potion health is zero." << endl;
                return; 
            }
            else {
                p.potionHeld -= 1;
                p.health += 30;
                if(p.health > 100) {
                    p.health = 100;
                }

                cout << "Current health is :" << p.health << endl;
                return;
            }
        }

        void revive(Player &p, Player &healer ) {

            if(p.isAlive == true) {
                cout << "Player is alive. There is no need to revive." << endl;
                return;
            }

            if(p.isAlive == false & healer.potionHeld >= 2) {  
                 cout << "Player is revive now. " << endl;
                 cout << " 2 Potion Held have been detected from you." << endl;
                 p.potionHeld -= 2;
                 p.health = 100;
                 return;
            }
            else {
                cout << "Player can't be revive." << endl;
            }
        }

        void display(Player &p) {
            cout << " ------------------------------------------- " << endl;
            cout << "Player name is :" << p.playerName << endl;
            cout << "Player health is : " << p.health << endl;
            cout << "Healing potion player have is :" << p.potionHeld << endl;
            cout << "Player is alive :" << p.isAlive << endl;
            cout << "Monster defeated by player is :" << p.monsterDefeated << endl;

        }
      

                int main() {
            Player p1("Shadow", 4 );
            Player p2("Monster", 8);

            attackMonster(p1,50  ,6);

            UsepotionHeld(p1);

            revive(p1, p2);
            

            display(p1);



            return 0;


        }
    