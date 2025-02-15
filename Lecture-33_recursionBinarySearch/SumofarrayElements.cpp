#include<iostream>
using namespace std;

int sum(int arr[5], int size){
     
    //base case
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }

   int remainingPart = sum(arr+1, size-1);
   int sum = arr[0] + remainingPart;
   return sum;
}
     


int main(){
    
    int arr[5] = {1,2,2,4,5};

    int size= 5;

     cout <<  sum(arr,size) << endl;

    return 0;
}