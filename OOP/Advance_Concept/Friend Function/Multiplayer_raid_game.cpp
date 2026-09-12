#include<iostream>
using namespace std;


// Create a class Player with private members:
// string playerName
// int health (starts at 100, max is always 100)
// int potionsHeld
// int monstersDefeated (starts at 0)
// bool isAlive (starts at true)

class Player {

   private: 
      string playerName;
      int health = 100;
      int potionHeld; // Healing potions the player has in his bag
      int monsterDefeated = 0;
      bool isAlive = true;

    public: 
       // Create a constructor that initializes playerName
       // and potionsHeld (health always starts at 100, monstersDefeated at 0, isAlive at true).
        
       Player(string PN, int ph) {
        playerName = PN;
        potionHeld = ph;
       }

// Create these friend functions:
// void attackMonster(Player &p, int monsterDamage, int monsterDifficulty)

// If p.isAlive is false, print a message that a dead player can't attack, and return immediately.

// Reduce p.health by monsterDamage.

// If p.health drops to 0 or below, set p.health = 0, set p.isAlive = false,

//  print a "wiped" message, and return — a defeated monster shouldn't be counted if the player died in the same fight.

// Otherwise (player survived the hit), the player defeats the monster: increase p.monstersDefeated by 1.

// If monsterDifficulty is greater than 7 (a "hard" monster), the player earns a bonus potion for the win — increase 

// p.potionsHeld by 1.

friend void attackMonster(Player &p, int monsterDamage, int monsterDifficulty);


};

    void attackMonster(Player &p, int monsterDamage, int monsterDifficulty) {
        if(p.isAlive == false) {

            cout << "Player is dead. " << endl;
            return;
        }

        p.health -= monsterDamage;
        cout << "Player survive the hit. " << endl;
        p.monsterDefeated += 1;


        if(p.health <= 0) {
            p.isAlive = false;

            cout << "Player is dead." << endl;
            return;
        }
        else {
             p.health -= monsterDamage;
        cout << "Player survive the hit. " << endl;
        p.monsterDefeated += 1;
        }

        if(monsterDifficulty > 7) {
            cout << "Bonus round." << endl;
            cout << "Player is rewarded with a extra potion Held." << endl;
            p.potionHeld += 1;
            return;
        }
        
    }

    