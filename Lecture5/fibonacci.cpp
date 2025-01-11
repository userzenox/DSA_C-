
#include <iostream>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  int a=0,b=1,sum=0;
  cout << 0;
  for(int i=1; i<=n; i++){
    
    sum = a+b; 
   cout<< " " << b ;
    a=b;
    b=sum;
  
    
       }

}