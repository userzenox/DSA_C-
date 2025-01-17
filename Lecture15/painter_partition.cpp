#include<iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid) {
   
    int time = 0;
   int countpainters =1;
   for(int i=0; i<n; i++){
         if(arr[i] + time <= mid){
            time  += arr[i];
         }
         else{
              countpainters++;
              if( countpainters > m || arr[i] > mid){
                return false;
              }
              time = arr[i];
         }
   }
   return true;
}

int allocatetime(int arr[], int n, int m) {
   int s = 0;
   int ans = 0;
   int sum = 0;
   for(int i = 0; i < n; i++) {
      sum = sum + arr[i];
   }
   int e = sum;
   int mid = s + (e - s)/2;

   while(s <= e) {
      if(ispossible(arr, n, m, mid)) {
         ans = mid;
         e = mid - 1;
      } 
      else {
         s = mid + 1;
      }
      mid = s + (e - s)/2;
   }
   return ans;
}

int main() {
   int arr[4] = {5, 5, 5, 5};
   int n = 4;  // Number of boards
   int m = 2;  // Number of painters

   cout << "minimum time taken is: " << allocatetime(arr, n, m) << endl;

   return 0;
}
