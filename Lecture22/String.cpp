#include<iostream>
#include<algorithm>
using namespace std;

void reverseString( char name[], int n){
    int s= 0;
    int e = n-1;

    while(s<e){
        swap(name[s], name[e]);
        s++;
        e--;
    }
}

int length(char name[]) {
    int i = 0;
    while (name[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char name[20];
    // Null character = '\0'
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Your name is " << name << endl;
    

    // string length
    int string_length = length(name);
    cout << "The length of your name is " << string_length << endl;

    //reverse a string
      reverseString(name,string_length);

    cout << "Reverse string is - " << name << endl;



      
    
    return 0;
}
