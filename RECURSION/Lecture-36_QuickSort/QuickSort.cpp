#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int s, int e){
     
    int pivot = arr[s],count=0;
    for(int i=s+1; i <= e; i++){
        if(arr[i] <=  pivot){
            count++;
        }
     }

     int pivotIndex = s+ count;
    swap(arr[s],arr[pivotIndex]);

    //sort the two sides

    int i=s, j=e;
   

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}


void QuickSort(int arr[], int s, int e){
       if(s >= e){
        return ;
       }
   
       int p = partition(arr,s,e);
            // cout << p << " ";

       QuickSort(arr,s,p-1);     
       QuickSort(arr,p+1,e);     

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
    QuickSort(arr,s,e);
     
    printArray(arr,size);

    return 0;
}