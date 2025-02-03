
#include<iostream>
#include<vector>
using namespace std;


void print(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout  << endl;
}

bool check(int arr[], int n){
    int count=0;
    for( int i=0;i<n; i++){
        if(arr[i] > arr[i+1]){
                count++;
        }
    }
    if(arr[n-1] > arr[0]){
        count++;
    }
    if(count>1){
        return false;
    }
    return true;
}


int main(){

    int arr[5] = {4,5,1,2,3};

    print(arr,5);

     cout << endl << "is is sorted array " << check(arr,5);
     return 0;
}