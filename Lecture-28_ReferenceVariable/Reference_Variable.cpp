#include<iostream>
using namespace std;

int & func(int a) {
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n) {
    int* ptr = &n;
    return ptr;
}


void update2( int &n){
    n++;
}

void update( int n){
    n++;
}

int main(){
    int i =5;
    int &j = i;
   
    cout << j << endl;
    i++;
    cout << j << endl;
    cout << i << endl;
    
    int n=5;

    // cout << "before " << n << endl;
    // update(n);
    // cout << "after " << n << endl;


    cout << "before " << n << endl;
    update2(n);
    cout << "after " << n << endl;
    
    int a =10;
     
    cout <<func( a) << endl;

   cout << fun(a) ;


    return 0;
}