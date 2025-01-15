#include<iostream>
using namespace std;

void printArray(int array[],int n ){
    for(int i=0; i<n; i++){
        cout << array[i]<< " ";
    }
    cout<< endl;
}


int main(){
     int s;
     cout << "enter the triplet sum you want";
     cin >> s;
    int arr[10]= {5,2,7,1,5,6,3,5,7,6};
    int res[100]={};
    int l=0;
   
    for(int i=0; i<9; i++){
        //  cout << endl;
       for(int j=i+1; j<10; j++){
            // cout << endl;
             
        for(int k=j+1; k<10; k++){
            //  cout << " " << i << " " << j  << " " << k << " ";
            if (arr[i]+arr[j]+arr[k] == s){
              
                 res[l] = arr[i];
                 res[l+1] = arr[j];
                 res[l+2] = arr[k];
                 l= l+3;
            }
        }
        }
       }
   
   
    printArray(res, 20);
    return 0;
}