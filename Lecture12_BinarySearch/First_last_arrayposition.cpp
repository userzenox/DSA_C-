#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int FirstOccurance(int array[], int n ,int key){
      int start = 0;
      int end = n-1;
      int ans,mid =0;

      while( start <= end){

        mid = start + (end-start)/2;
        
        if (array[mid] == key){
            // cout << mid;
            ans = mid;
            end = mid - 1;
        }
        else if( key < array[mid] ){
            start = 0;
            end = mid - 1;
        }   
         else if(key > array[mid] ){
            start = mid + 1;
           
        } 
      }
   return ans;
}

int LastOccurance(int array[], int n ,int key){
      int start = 0;
      int end = n-1;
      int ans,mid =0;

      while( start <= end){

        mid = start + (end-start)/2;
        
        if (array[mid] == key){
            // cout << mid;
            ans = mid;
            start = mid + 1;
        }
        else if( key < array[mid] ){
            
            end = mid - 1;
        }   
         else if(key > array[mid] ){
            start = mid + 1;
            
        } 
      }
   return ans;
}


int main(){

     int arr1[6] = {2,6,6,6,6,22};

     printArray(arr1, 6);

     int index =  FirstOccurance(arr1,6,6);
     cout << endl<< "First Index " << index ;

    int index2 =  LastOccurance(arr1,6,6);
    cout << endl<< "Last Index " << index2 ;
        
    return 0;
}