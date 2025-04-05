#include <vector>
#include <iostream>
using namespace std;
#include "Hero.cpp"

//Here class hero is imported from different file

class Empty {
  
};

int main() {
    Hero h1; 
    Empty h2;
    cout << "size : " << sizeof(h1) << endl;
    cout << "size : " << sizeof(h2) << endl;
    

    cout << "Health is : " << h1.health << endl;

    cout << "Level is : " << h1.level << endl;
    
    return 0;
}