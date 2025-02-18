#include<iostream>
using namespace std;

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
       cout << array[i] << " ";
    }
    cout  << endl;
}

void sort(int arr[], int n){
        if(n == 0 || n==1){
            return ;
        }

       for(int i=0; i<n-1;  i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
       }

        sort(arr,n-1);
       
}

int main(){
    
    int arr[5] = {6,23,543,2,45};
    int length = 5;

    printArray(arr,length);

    sort(arr,length);

    printArray(arr,length);

    return 0;
}