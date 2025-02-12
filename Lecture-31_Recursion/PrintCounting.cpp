#include<iostream>
using namespace std;


// Tail Recurssion
void print(int n){
     if(n==0){
        return ;
     }
     cout << n << " ";
      print(n-1);
}

//Head recursion

void print2(int n){
    if(n==0){
       return ;
    }
   
     print2(n-1);

     cout << n << " ";
}


int main(){
     
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    print(n);
    cout << "Tail recursion" << endl;
    cout << endl;
    cout << "Head recursion" << endl;
    print2(n);
    return 0;
}