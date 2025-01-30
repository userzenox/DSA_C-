#include<iostream>
using namespace std;
// coloumn wise
void printwave( int arr[3][4]){
          for(int col=0; col<4; col++){
               
               if(col%2==0){
                   for(int j=0; j<3; j++){
                          cout << arr[j][col] << " ";
                    }
               }
 
               else{
                 for(int j=2; j>=0; j--){
                      cout << arr[j][col] << " ";
                }
               }
           
          }
}
int main(){
     
     int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

        for(int row=0; row<3; row++){  // Loop through rows first
        for(int col=0; col<4; col++){  // Then loop through columns
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
     printwave(arr);

    return 0;
}