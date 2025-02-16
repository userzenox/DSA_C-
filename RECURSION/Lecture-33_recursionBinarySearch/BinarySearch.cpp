#include<iostream>
using namespace std;

void print(int arr[], int s, int e) {

    for(int i=s; i<e; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}


bool Binarysearch(int arr[], int s, int e, int k){

    print(arr,s,e);
    //base cose
    if(s > e){
        return 0;
    }

    int mid = s + (e - s)/2;
    if(arr[mid] == k){
        return true;
    }
    if(arr[mid] <k){
       return Binarysearch(arr,mid+1,e,k);
    }
    if(arr[mid] >k){
       return Binarysearch(arr,s,mid-1,k);
    }

}


int main(){

     int arr[16] = {1,3,5,7,9,12,16,19,24,28,36,47,58,78,544,564};
     int s=0;
     int e=15;
     int key = 324;
     bool ans = Binarysearch(arr,s,e,key);
     if(ans){
        cout << "Number is present";
     }
     else {
        cout << " Number is absent";
     }

    return 0;
}