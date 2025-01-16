#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int binarysearch(int array[], int n ,int key){
      int start = 0;
      int end = n-1;
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


int main(){

     int arr1[6] = {2,4,6,7,9,22};
     int arr2[5] = {2,3,9,10,23};
     
     printArray(arr1, 6);

     int index =  binarysearch(arr1,6,22);
     cout << endl<< index ;
        

       int index2 =  binarysearch(arr2,5,234);
       cout << endl<< index2 <<endl;

     printArray(arr2, 5);
    
    return 0;
}