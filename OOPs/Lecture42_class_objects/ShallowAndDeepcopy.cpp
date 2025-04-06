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
    
};


int main() {


     //swalllow copy
     Hero hero1;
     
     hero1.setHealth(12) ;
     hero1.setLevel('D') ;
     char name[7] = "Babber";
     hero1.setName(name);

     hero1.print();

//using default copy construtor
  
Hero hero2(hero1);
hero2.print();

hero1.name[0] = 'G';
hero1.print();
hero2.print();

cout << endl << "Next is assignment operator" ;
hero1.print();
hero2.print();
    hero1 = hero2;
    hero1.print();
hero2.print();
    return 0;



}