#include<iostream>
using namespace std;

  bool isPresent( int arr[][4], int target, int row, int col){
     
     for(int row=0; row<3; row++){
       for(int col=0; col<4; col++){
            if(arr[row][col] == target){
                return 1;
            }
       }
   }
   return 0;
}



int main(){
   
    //Create 2D array
    int arr[3][4];
   
   //hardcore entry
//    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};  // row wise entry

    // int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};




   //taking input  "Row wise"
   for(int row=0; row<3; row++){
       for(int col=0; col<4; col++){
        cin >> arr[row][col];
       }
   }

    //Taking input "column wise"
    // for(int col=0; col<4; col++){  // Loop through columns first
    //     for(int row=0; row<3; row++){  // Then loop through rows
    //         cin >> arr[row][col];
    //     }
    // }

    //Printing
    for(int row=0; row<3; row++){  // Loop through rows first
        for(int col=0; col<4; col++){  // Then loop through columns
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    
    cout << "Enter the element to search" << endl;
    int target;
    cin >> target;

    if(isPresent(arr, target,3,4)){
        cout << "element found" << endl;
    }else{
        cout << "not found;";
    }

    return 0;
}
