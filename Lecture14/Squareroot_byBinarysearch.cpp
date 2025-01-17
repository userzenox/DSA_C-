#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int Squareroot(int array[], int n){
    long long  int start = 0;
      int end = n-1;
    long long  int mid =0;
     long long int ans=0;
      while( start <= end){
        // mid = (start+end)/2;
        //can be written as to avoid crossing the limit 2^31 - 1

        mid = start + (end-start)/2;
        
        int square = mid*mid;
       
        if(square == n){
            return mid;
        }
        if(square< n){
            ans = mid;
            start = mid +1; 
        }
        else{
            end = mid -1;
        }
      }
   return ans;
}

double decimal(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i = 0; i<precision; i++){
        factor = factor/10;
        for(double j=0; j*j < n ; j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

     int arr1[6] = {1,2,3,4,5,6};
     int arr2[5] = {2,3,9,10,23};
     
     printArray(arr1, 6);
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
     int squareroot =  Squareroot(arr1,n);
     cout << endl<< " squareroot is " << squareroot ;
        
     double morePrecision = decimal( n,3, squareroot); 
     cout << endl << "with decimal is" << morePrecision;
    
    return 0;
}