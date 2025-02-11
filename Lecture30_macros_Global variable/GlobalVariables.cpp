#include<iostream>
using namespace std;

int score = 15;// globle variable
void a(int &i){
    i++;
    
    cout << i << endl;
    cout << score << endl;
}

void b(int &i){ 
    cout << score << endl;
    cout << i << endl;
}

int main(){
    
    int i =5;
    a(i);
    cout << i << endl;
    cout << score << endl; 
    return 0;
}