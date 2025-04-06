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


    static int timeToComplete;  // this doesnot depent on anything be it health or level

    // //Static Function
    // static int random(){
    //    cout << "Static function running " << endl;
    // //    cout << name << endl;
    //    cout << timeToComplete  << endl;
    // }
    
    static int random2(){
        return timeToComplete;
     }
};
 
int Hero::timeToComplete = 5;

int main() {
   
cout << Hero::timeToComplete << endl;
Hero::timeToComplete = 10;
cout << Hero::timeToComplete << endl;

//

// cout << Hero::random() << endl;

Hero::timeToComplete = 20;
cout << Hero::random2() << endl;

 return 0;



}