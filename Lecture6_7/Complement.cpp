#include<iostream> 
#include<math.h>
using namespace std;

int decimal_binary(int a){
    int i,ans=0;
    while(a!=0){

      int bit = a&1;
       ans = (bit * (pow(10,i))) + ans;
       a = a >> 1;
       i++;
       }
      return ans;
}
int main() {
    int n;
   cin >> n ; 
   int m =n;

    cout <<  decimal_binary(n) << endl;
        int mask = 0;
        
        if(n==0){
            cout <<  1;
        }
        while(m!=0){
            mask = (mask << 1) | 1;
            // cout <<  mask << endl;
            m = m >> 1;
        }

        int ans = (~n) & mask;
        int z = decimal_binary(ans);
         cout << ans << endl << z;
         
  
    
}