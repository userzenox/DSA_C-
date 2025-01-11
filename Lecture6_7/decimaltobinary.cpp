
#include <iostream>
#include <math.h>
using namespace std;

int main() {

    int n,i;
    int ans = 0;
    cout << "Enter a number";
    cin >> n ; 
   
    while(n!=0){
        int bit = n&1;
         ans = (bit * ( pow(10,i))) + ans;
        n = n >> 1;
        i++;
    }
cout << ans << endl;



}