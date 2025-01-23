#include<iostream>
#include<vector>
using namespace std;

void addarray(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i=n-1, j=m-1,sum,carry=0;
    while(i>=0 && j>=0){
        sum = arr1[i]+ arr2[j]+carry;
         carry = sum/10;
        sum = sum % 10;
        arr3[i] = sum;

        i--;
        j--;
    }

    //first case
    while(i>=0){
        int sum = arr1[i]+ carry ;
        carry = sum/10;
        sum = sum % 10;
        arr3[i] = sum;   
        i--; 
    }

      while(j>=0){
        int sum = arr2[j]+ carry ;
        carry = sum/10;
        sum = sum % 10;
        arr3[j] = sum;    
        j--;
    }

    //case3
    while(carry!=0){
        int sum = carry;
        carry = sum/10;
        sum = sum% 10;
        if(i!=0){
             arr3[i] = sum;  
        }
        else{
            arr3[j] = sum;  
        }
    }

}

void print(int array[], int size){
     for(int i=0; i<size; i++){
        cout << array[i] << " ";
     }
     cout  << endl;
}

int main(){

    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[5] = {};
    

    addarray(arr1,5,arr2,3,arr3);
    print(arr3,5);
    return 0;
}