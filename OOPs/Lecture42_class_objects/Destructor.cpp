#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Hero{

    private:
    char level;

    public:
    int health;
  
    char *name;


    // Simple Constructor
    Hero(){
       cout << " Simple Constructor called" << endl; 
       name = new char[100];
    }

    Hero(int health, char level ){
        this-> level = level;
        this-> health = health;
     }
    
     //Copy constructor 
     Hero(Hero& temp){ 

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;
        cout << "Copy Constructor is called" << endl; 
        this->health = temp.health;
        this->level = temp.level;
     }
     void print() {
        cout << endl;
        cout << "[ Name: " << this->name << " ";
        cout << "health: " << this->health << " ";
        cout << "level: " << this->level << " ]";
        cout << endl;
    }
  void setHealth(int h){
      health = h;
  }
  
  void setLevel(char ch){
      level = ch;
  }

  void setName(char name[]) {
    strcpy(this->name, name);
}

    ~Hero(){
        cout << "DEstructor bhai called" << endl;
    }
    
};


int main() {
 // static - destructor is called automatecally 
    Hero a;

     // Dynamically - destructor has to be called by delete
    Hero *b = new Hero() ;
    //manually  called
     delete b;

 return 0;



}