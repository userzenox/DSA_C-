#include <vector>
#include <iostream>
using namespace std;


class Hero{

    private:
    char level;

    public:
    int health;
    char name[100];
    
    void print(){
        cout << level << endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }
    
    void setLevel(char ch){
        level = ch;
    }
};


int main() {
      
   
    //static allocation
       Hero r; 
       cout << "Health is : " << r.health << endl;
    cout << "Hero's class : " << r.getLevel() << endl;

    //dynamically
    
       Hero *h = new Hero;
       (*h).health = 80;
    (*h).setLevel('A');
       cout << "Health is : " << (*h).health << endl;
    cout << "Hero's class : " << (*h).getLevel() << endl;
    return 0;
}