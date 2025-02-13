#include<iostream>
using namespace std;

int factorial(int n){

    //Base case
    if(n == 0){
        return 1;
    }

    // int small = factorial(n-1);
    // int big = n* small;
    //  cout << "value " << small << " " << big << endl;
    // return big;

    return n * factorial(n-1);
}

int main(){
    
    int n;
    cout << "intput the number";
    cin >> n;

    int ans = factorial(n);

    

    cout << ans << endl;

    return 0;
}