#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    
    int c;
    //  c = cin.get();
    //  cout << "After using Getin " << c << endl;

    
    
    // to find if the character is lower case upper case or number
    char ch;
    cin >> ch;
    
    if(ch >= 'A' && ch <= 'Z' ){
        cout << "it is a capital letters";
    }
   else if(ch >= 97 && ch <= 122 ){
        cout << "it is a small letters";
    }
   else if(ch >= '1' && ch <= '9' ){
        cout << "it is a  number";
    }
    else{
        cout<< "enter a valid character"<< endl;
    }
    

    char z;
    cin >> z;
    if( z == 122 ){
        cout << "working" ;
    }
    else{
        cout<< "not working";
    }
    
    // int a;
    // cin >> a ; 
    
    // if(a>0){
    //     cout<< "a is positive number";
    // }
    // else if(a<0){
    //     cout << "a is negative number";
    // }
    // else {
    //     cout << "a is zero";
    // }

 /* Patterns*/
     int n;
       cin >> n;
       int i=1;
      
       while(i<=n){
        
         int j=1;
        while(j<=n){
             cout << j ;
             j= j+1;
        }
         cout << endl;
         i=i+1;
       
       }
   
    return 0;

}
