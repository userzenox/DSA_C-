#include<iostream>
using namespace std;

void Merge( int *arr, int s, int e){
    int mid = s + (e - s)/2;
    int len1 = mid -s+1;
    int len2 = e - mid;


    int *first = new int[len1];
    int *second = new int[len2];


    // k is the main index array
    int k=s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

     k = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    //Merge
    int index1 =0;
    int index2 =0;
    k = s;
    while(index1<len1 && index2 <len2){

        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
       
    }

    while(index1 < len1){
        arr[k++] = first[index1++];
    }
    
    while(index2 < len2){
        arr[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void MergeSort( int *arr, int s, int e){
      //base case
      if(s >= e){
         return ;
      }
      int mid = s + (e - s)/2;
      //left part sort
      MergeSort(arr,s,mid );

      //right part sort
      MergeSort(arr,mid+1,e);

      Merge(arr,s,e);
}

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
       cout << array[i] << " ";
    }
    cout  << endl;
}

int main(){
    
    int arr[5] ={23,45,7,5,12};
    int size =5;
    int s=0;
    int e = 4;
    MergeSort(arr,s,e);
     
    printArray(arr,size);

    return 0;
}