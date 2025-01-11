
#include <iostream>
using namespace std;

void printArray(int array[], int size){
     for(int i = 0; i<size; i++){
        cout << array[i] << " ";
     }
     cout << "printing done" << endl;
}

int sum(int arr[], int size){
  int sum;
    for(int i=0; i<=size; i++){
        sum = sum + arr[i];
    }
    cout<< "running" << endl;
    return sum;
}

int main() {
    
     int n;
     cin >> n;
     int arr[n] = {3,4};

     printArray(arr, n);
      
    arr[n] = {0};
    cout << arr[1] << endl;


    int arrsize = sizeof(arr)/ sizeof(int);
    cout << "Size of fifth is " << arrsize << endl;


    //Character array
    char ch[5] = {'a', 'b', 'c' , 'r', 'p'};
    //  printArray( ch, 5); not possible as ch is character type but function declaration is of array type
    cout << ch[3];
   

      cout << endl << "Sum of arrays" << endl;
      cout << sum(arr,5);
 return 0;
}