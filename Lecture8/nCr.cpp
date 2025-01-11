
#include <iostream>
#include<math.h>
using namespace std;

int factorial(int a){
    int fact=1;
    for(int i=1 ; i<=a; i++){
        fact = fact * i ;
    }
    return fact;
}

int nCr(int n, int r){
    int result,num,denom;
     num = factorial(n);
     denom = factorial(r) * factorial(n-r);
 
    result = (num/denom);
    return result;
}

int main() {
     int n,r;

     cin >> n >> r;

     cout<< "nCr is" << nCr(n,r)<< endl;
     cout<< "fact of n is " << factorial(n);
     return 0; 
}