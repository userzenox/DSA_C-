
#include <iostream>
using namespace std;

int main() {
  
  int n=1; 
  cin >> n ;
  int i=1 ;

  while(i<=n ){
            
        int j =1;
        while(j<=n-i+1){
            cout << j;
            j = j+1;
        }

        //star
        int star = i-1;
        while(star){    
          cout << "*";
          star = star-1;
        }

         int star2 = i-1;
        while(star2){    
          cout << "*";
          star2 = star2-1;
        }

       int k=i;
       while(k<=n){
        cout<< n-k+1;
        k = k+1;
       }



      i= i+1;
      cout << endl;
  }
}