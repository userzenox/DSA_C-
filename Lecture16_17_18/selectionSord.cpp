#include<iostream>
using namespace std;

void printArray(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout << "printing done" << endl;
}

int Selectionsort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return 0;
}

int main(){
     int arr[5] = {45, 65, 33, 654, 65};
     printArray(arr, 5);
     Selectionsort(arr, 5);
     printArray(arr, 5);
     return 0;
}
