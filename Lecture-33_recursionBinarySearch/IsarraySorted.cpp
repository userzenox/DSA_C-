#include<iostream>
using namespace std;

bool isSorted(int arr[5], int size){
    //base case
    if(size == 0 || size ==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }else{
       
        return  isSorted(arr+1,size-1);
    }

    

}

int main(){
    
    int arr[5] = {1,2,2,4,5};

    int size= 5;

    bool ans = isSorted(arr,size);

    if(ans){
        cout << "array is Sorted  "<< endl;
    }
    else{
        cout << "array is Not Sorted  "<< endl;
    }

    return 0;
}