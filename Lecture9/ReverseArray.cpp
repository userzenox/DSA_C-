#include<iostream>
using namespace std;

void reverse(int array[], int n){
     int start = 0;
     int last = n-1;
    
     while(start<=last) {
        swap(array[start], array[last]);
         start++;
         last--;

     }
}

void printArray(int array[],int n ){
    for(int i=0; i<n; i++){
        cout << array[i]<< " ";
    }
    cout<< endl;
}


int main(){
     int arr[5] = {4,6,2,8,3};
       int brr[6] = {14,16,12,15,18,13};

       reverse(arr,5);
       reverse(brr,6);

       printArray(arr,5);
       printArray(brr,6);
       
return 0;
}