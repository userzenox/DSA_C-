#include<iostream>
using namespace std;

void print(int arr[], int n) {
    cout << "Size of array is " << n << endl;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}


bool search(int arr[], int size, int key){

    print(arr,size);
    //base cose
    if(size==0){
        return 0;
    }

    if(arr[0] == key){
        return true;
    }

   return search(arr+1,size-1,key);

}


int main(){

     int arr[5] = {1,3,5,2,6};
     int size =5;
     int key = 7;
     bool ans = search(arr,size,key);
     if(ans){
        cout << "Number is present";
     }
     else {
        cout << " Number is absent";
     }

    return 0;
}