
#include <iostream>
using namespace std;

int main() {
     int amount;
     cout << "enter the amount" << endl;
     cin >> amount;
    int count;
     switch(1){
        case 1: count = amount/100;
               cout << "no of 100 rs required is " << count << endl;
               amount = amount - count*100;
              
        case 2: count = amount/50;
               cout << "no of 50 rs required is " << count << endl;
               amount = amount - count*50;
        case 3: count = amount/20;
               cout << "no of 20 rs required is " << count << endl;
               amount = amount - count*20;
        case 4: count = amount/10;
               cout << "no of 10 rs required is " << count << endl;
               amount = amount - count*10; 
               break;                      
     } 

}