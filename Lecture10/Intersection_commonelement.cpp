
#include<iostream>
using namespace std;

int main(){
    int arr[5] = {4,6,65,10,3};
    int arr2[4] = {5,6,7,8};

    for(int i=0; i<5; i++){
          int element = arr[i];
          for(int j=0; j<4; j++){

            
            if(element< arr2[j]){
              break;
            }
            
            if( element == arr2[j]){
                cout << arr[i] << " ";
                arr2[j] = -5;
                break;
            }
          }
    }




    /* Optimissed solution*/
    // while(i<n && j<n) {

    //   if(arr[i] == arr2[j]){
    //       ans.push_back(arr[i]);
    //       i++;
    //       j++;
    //   }
    //   else if (arr[i] < arr2[j]){
    //     i++;
    //   }
    //   else{
    //     j++;
    //   }
    // }


    return 0;
}