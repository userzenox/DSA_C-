#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout  << endl;
}

int InsertionSort(int arr[], int size){
     int j;
    for(int i=0;i<size;i++){
         int temp = arr[i];
        for( j=i-1; j>=0 ;j--){
         if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
               
         }
         else{
            break;
         }
        }
        arr[j+1] = temp;
    }
    return 0;
}

int main(){
     int arr[5] = {45, 68, 33, 654, 65};
     printArray(arr, 5);
     InsertionSort(arr, 5);
     printArray(arr, 5);
     return 0;
}
