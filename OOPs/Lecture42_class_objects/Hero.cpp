#include <vector>
#include <iostream>
using namespace std;

// its a class file that is to be imported in other files

class Hero {
    // Properties

    public:
    char level;
    int health;
    private:
    char name[100];
  

    void print(){
        cout << level << endl;
    }
};