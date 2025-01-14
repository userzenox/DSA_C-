
#include <iostream>
using namespace std;

int main(){

    int arr[8]= {1,4,4,5,3,7,2,6};
    int ans=0;

    for(int i=0;i<8; i++){
        ans = ans^arr[i];
        cout << ans << " ";
    }
   
     cout << endl;
     for(int i=1;i<8; i++){
       ans = ans^i; 
       cout << ans ;
    }
     
    cout <<endl << ans;
    return 0;
}