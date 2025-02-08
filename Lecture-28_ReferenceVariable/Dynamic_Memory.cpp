#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    int sum =0;
    for(int i =0; i<n; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int main(){
    int i = 10;
    char ch = 'q';
     cout <<"size of integer " <<sizeof(i) << endl;
     cout <<"size of char " << sizeof(ch) << endl;

     char *c = &ch;
     cout << "size of a pointer - " << sizeof(c)<< endl;
     
     int n;
     cout << "Enter number of elements in an array" << endl;
     cin >> n;

     //variable size array
     int *arr = new int[n];

     //taking input in  array
     cout << "enter the elements" << endl;
     for (int i=0; i<n;i++){
        cin >> arr[i];
     }

     int ans = getSum(arr,n);

     cout << "answer is " << ans << endl;

    return 0;
}