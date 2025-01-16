#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int binarysearch(int array[], int s, int e,int key){
      int start = s;
      int end = e;
      int mid =0;

      while( start <= end){
        // mid = (start+end)/2;
        //can be written as to avoid crossing the limit 2^31 - 1

        mid = start + (end-start)/2;
        
        if (array[mid] == key){
            // cout << mid;
            return mid; 
            
        }
        else if( key < array[mid] ){
            
            end = mid - 1;
        }   
         else if(key > array[mid] ){
            start = mid + 1;
            
        } 
      }
   return -1;
} 


int getpivot(int array[], int n){
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

 int find_position(int array[], int n, int k ){
    int pivot = getpivot(array,n);
    if ( k >= array[pivot] && k<= array[n-1]){
           return binarysearch( array, pivot , n-1, k);
    }
    else{
        return binarysearch(array,0, pivot-1,k);
    }
}

int main(){

     int arr[5] = {7,9,1,2,3};

     printArray(arr, 5);

     cout << find_position(arr,5,2);

    return 0;
}