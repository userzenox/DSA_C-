#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    
    for(int i = 1 ; i<size; i++){
        if(key == arr[i]){
            return true;
        } 
        
    }
   return 0;
}

int main(){

    int arr[10] = {5,7,-2,10,22,-2,0,1,22,5};

    cout << "Enter the element to search for" << endl;
    int key;
    cin >> key;

   bool found = search(arr,10,key);

   if(found){
      cout << "Key is present" << endl;      
   }
   else{
      cout << "key is absent" << endl;
   }

   return 0;
}
