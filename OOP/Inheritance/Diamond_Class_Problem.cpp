
// ### Q6: Diamond Problem — Fix It
// Create a base class `Person` with a member `string name`.

// Create two classes `Student : public Person` and `Teacher : public Person`.

// Create a class `TeachingAssistant : public Student, public Teacher`.

// First, try compiling **without** 

#include<iostream>
using namespace std;


class Person{

  public: 
    string name; 

       

};

class Student : virtual public Person {

};

class Teacher :  virtual public Person {

};

class TeachingAssistant : public Student, public Teacher {

};

int main() {

    // TeachingAssistant t = "Ali";
    TeachingAssistant t;
    t.name = "ALi";

    return 0;
}

// The problems and bugs that occur during coding of this, has been added to interview_questions file in this folder.
// So, please check it out

