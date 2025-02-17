#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout  << endl;
}

int Bubblesort(int arr[], int size){
     
     for(int i=1; i<size;i++){
       bool swapped = false;
       for( int j=0; j<(size-i); j++ ){
          if(arr[j]> arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped = true;
           }
       }
       if(swapped == true){
          break;
       }
     }
    return 0;
}

int main(){
     int arr[5] = {45, 68, 33, 654, 65};
     printArray(arr, 5);
     Bubblesort(arr, 5);
     printArray(arr, 5);
     return 0;
}
