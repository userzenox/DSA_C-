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
class Empty {
  
};

int main() {
    Hero rocky; 
    
    rocky.health = 80;
    rocky.setLevel('A');

    cout << "Health is : " << rocky.getHealth() << endl;
    cout << "Hero's class : " << rocky.getLevel() << endl;

    
    return 0;
}