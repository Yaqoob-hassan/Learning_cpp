#include<iostream>
using namespace std;

class Animal {
public: 
  virtual void makeSound() = 0;
};

class Cat : public Animal {

   public:
     void makeSound() override {
        cout << "Cat is making sound." << endl;
     }

};

class Dog: public Animal {
    public: 
       void makeSound() override {
        cout << "Dog is making sound." << endl;
       }
};

int main() {
    Animal* ani[2];

    ani[0] = new Cat;
    ani[1] = new Dog;

    for(int i = 0; i < 2; i++) {
        ani[i]->makeSound();
        cout << endl;
    }
    return 0;
}