#include<iostream>
using namespace std;

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
       cout << array[i] << " ";
    }
    cout  << endl;
}

void sort(int arr[], int n){
    if(n<=1){
        return ;
    }

    sort(arr,n-1);

    // int last = arr[n-1];
    // int j = n-2;
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right to make room for the last element
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
  
     

int main(){
    
    int arr[5] = {6,23,543,2,45};
    int length = 5;

    printArray(arr,length);

    sort(arr,length);

    printArray(arr,length);

    return 0;
}