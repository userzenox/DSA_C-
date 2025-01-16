#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int pivot(int array[], int n){
    int s= 0;
    int e = n-1;
    int mid = s+ (e-s)/2;
     
     while(s<e){

    if ( array[mid] >= array[0]){
        s = mid+1;
     }
     else{
        e = mid;
     }
      mid = s+ (e-s)/2;
    }
    return s;
}




int main(){

     int arr[6] = {8,10,17,1,3};

     printArray(arr, 5);

     cout << pivot(arr,5);

    return 0;
}