
#include <iostream>
using namespace std;

void swap(int arr[], int size){
     int start = 0;
     int end = size-1;
      int next = 1;
      int start2 = 0;
      cout << endl;
      for(int i = 0; i<size ; i++){
          while (start2< end){
             
             swap(arr[start],arr[next]);
             start= start+2;
             next= next + 2;
             end--;
             start2++;
          }
      }
}

void print(int arr[], int size){
    for( int i=0; i<size; i++){
          cout << arr[i] << " " ;
    }

}

int main() {
    
    int num[6]= {3,5,6,7,3,2};
    int num2[5]= {3,5,6,7,3};

    print(num, 6);
    
    swap(num, 6);

    print(num, 6);

    cout<< endl;

      print(num2, 5);
    
    swap(num2, 5);

    print(num2, 5);
   
} 