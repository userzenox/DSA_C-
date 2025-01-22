
#include<iostream>
#include<vector>
using namespace std;


void print(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout  << endl;
}

void rotate(int arr[], int size, int m){
    int arr3[size]={};
     for(int i =0;i<size;i++){
          arr3[(i+m) % size] = arr[i];
     }

     print(arr3,size);
}

int main(){

    int arr[5] = {1,3,5,7,9};
    print(arr,5);
    
    int m;
    cout<< "By how much do you want to shift the array";
    cin >> m;

    rotate(arr,5,m);

    return 0;
}