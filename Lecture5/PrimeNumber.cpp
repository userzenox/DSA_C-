

#include <iostream>
using namespace std;

int main() {
   
   int n;
   cin >> n;
int count;
   for( int i=1;i<=n;i++){
     
     if(n%i == 0){
        count ++;
        cout << "it is divisible by" << i <<endl;
      }
      else{
        cout << "it is not divisible by" << i <<endl;
      }
      }

    if(count == 2){
        cout << " it is a prime number" <<endl ;
    }
    else{
        cout << "it is not a prime number" <<endl;
    }

}