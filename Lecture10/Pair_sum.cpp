#include<iostream>
using namespace std;

void printArray(int array[],int n ){
    for(int i=0; i<n; i++){
        cout << array[i]<< " ";
    }
    cout<< endl;
}


int main(){
     
    int arr[6]= {5,2,7,1,8,6};
    int res[100]={};
    int k;
    int s = 7;
    for(int i=0; i<5; i++){
       
       for(int j=i+1; j<6; j++){
        if(arr[i] + arr[j] == s){
            res[k] = arr[i];
            res[k+1] = arr[j];
            k=k+2;
        }
       }
    }
   
    printArray(res, 5);
    return 0;
}