#include <vector>
#include <iostream>
using namespace std;


class Hero{

    private:
    char level;

    public:
    int health;
    char name[100];

    // Simple Constructor
    Hero(){
       cout << " Simple Constructor called" << endl; 
    }

    //Parameterised Constructor
    Hero(int health){
        cout << "this -> " << this << endl;
       //in object property health the parameter value gets stored
        this-> health = health;
     }
    
     Hero(int health, char level ){
        this-> level = level;
        this-> health = health;
     }
    
    void getlevel(){
          cout <<"Hero Level is " <<level << endl;
     }
    
};


int main() {
   
   Hero mage(10);
   cout << "Address of rama " << &mage << endl;
    cout << "health of rama is " << mage.health << endl;
    mage.getlevel() ;

    Hero figther(80,'S');
    cout << "Address of rama " << &figther << endl;
    cout << "health of rama is " << figther.health << endl;
    figther.getlevel();
    return 0;
}