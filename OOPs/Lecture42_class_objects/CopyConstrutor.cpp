#include <vector>
#include <iostream>
using namespace std;

class Hero{

    private:
    char level;

    public:
    int health;
   //  char name[100];
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
        cout << "Copy Constructor is called" << endl; 
        this->health = temp.health;
        this->level = temp.level;
     }
     void print(){
       cout << endl;
       cout << "name: " << this->name << endl;
        cout << "Health is " << health << endl;
        cout << "Level is "  << level << endl;
     }

  void setHealth(int h){
      health = h;
  }
  
  void setLevel(char ch){
      level = ch;
  }
    
};


int main() {
  
    Hero tank(100, 'A');
      tank.print();

// Copy constructor
    Hero gloo(tank);
     gloo.print();

     //swalllow copy
     


  


    return 0;
}