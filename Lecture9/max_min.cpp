#include <iostream>
using namespace std;

int getMaxUsingFunction(int arr[], int size){
    int maxi = INT_MIN;
   for(int i=0; i<size ; i++){
        maxi = max(maxi,arr[i]);
        }
        return maxi;
    }

    
int getMax(int num[], int n){
    int max = 0;
    cout<< max;
    for(int i=0; i<n ; i++){
        if(num[i] > max){
            max = num[i];
        }
    }

    return max; 
}

int getMin(int num[], int n){
    int min = INT_MAX ;
  
    for(int i=0; i<n ; i++){
        if(num[i] < min){
            min = num[i];
        }
    }

    return min; 
}

int main() {
      
      int size;
      cin >> size;

      int num[100];

      // taking input in array
      for(int i = 0; i<size; i++){
        cin >> num[i];
      }

cout << "Maximum value is " << getMax(num,size) << endl;
cout << "Minimum value is " << getMin(num,size) << endl;
cout << "maximum value is " << getMaxUsingFunction(num,size) << endl;


return 0;   
}
