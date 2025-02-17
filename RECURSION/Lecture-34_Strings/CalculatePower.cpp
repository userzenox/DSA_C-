#include<iostream>
using namespace std;

int power(int a, int b){
    if(b == 0){
        return 1;
    }

    int temp = power(a, b / 2);
    temp = temp * temp;

    if(b % 2 == 0){
        return temp;
    }
    else{
        return a * temp;
    }
}

int main(){
    int a = 2;
    int b = 5;
    
    int ans = power(a, b);
    cout << ans;

    return 0;
}
