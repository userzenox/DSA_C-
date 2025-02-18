// Given an integer array arr[] of size n, find the inversion count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Note: Inversion Count for an array indicates that how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is maximum. 
// Input: arr[] = {4, 3, 2, 1}
// Output: 6

#include<iostream>
#include<vector>
using namespace std;

int combine(int *arr, int s, int e){
    int mid = s + (e - s)/2;
     int leng1 = mid -s +1;
     int leng2 = e - mid;

    vector<int> arr1(leng1), arr2(leng2);
    int k = s;
    for(int i=0; i<leng1; i++){
        arr1[i] = arr[k++];
    }
     
    k = mid+1;
    for(int i=0; i<leng2; i++){
        arr2[i] = arr[k++];
    }


    //merge
    int index1 = 0;
    int index2 = 0;
    int count = 0;
    k=s;
    while( index1<leng1 && index2<leng2){
        if(arr1[index1] < arr2[index2]){
             arr[k++] = arr1[index1++];
        }
        else{
            arr[k++] = arr2[index2++];
            count += (leng1 - index1);
        }
    }

    while(index1< leng1){
        arr[k++] = arr1[index1++];
    }
    while(index2< leng2){
        arr[k++] = arr1[index2++];
    }

    return count;

}

int MergeSort(int arr[], int s, int e){
    int ans=0;
    if(s>=e){
        return 0;
    }

    int mid = s + (e - s)/2;
    
  ans +=  MergeSort(arr,s,mid);

   ans += MergeSort(arr,mid+1,e);

    ans += combine(arr,s,e);
    return ans ;
}

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
       cout << array[i] << " ";
    }
    cout  << endl;
}

int main(){
    
    int arr[4] ={4,3,2,1};
    int size =4;
    int s=0;
    int e = 3;
   cout << MergeSort(arr,s,e);
     
 

    return 0;
}
