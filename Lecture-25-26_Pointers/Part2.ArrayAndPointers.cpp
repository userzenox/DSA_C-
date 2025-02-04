#include<iostream>
using namespace std;

int main(){
    int arr[10]={2,3,4,5};

    cout <<"address of first memory block is" << arr << endl;

    cout <<"address of first memory block is" << &arr[0] << endl;


    
    cout << "Value at zeroth location of *arr - " << *arr << endl;
    cout << "Value of *arr + 1 - " << *arr + 15 << endl;
    cout << "Value at first location of *(arr + 1) - " << *(arr +1) << endl;

    //array can be also written as 
     int i=2;
      cout << "arr is the array " << i[arr] << endl;
      cout << "arr is the array " << *(i+ arr)<< endl;

      int *p = &arr[0];
      cout << "value of *p " << *p <<endl; 
      cout << "value of p " << p << "  it is the address of value stored"<<endl;
      cout << "value of &p " << &p <<endl;
      cout << "value of arr " << arr <<endl;
      cout << "value of &arr " << &arr <<endl;
      cout << "value of *arr " << *arr <<endl;


      int temp[10] = {1,2};
cout << sizeof(temp) << endl;
cout << " 1st " << sizeof(*temp) << endl;
cout << " 2nd " << sizeof(&temp) << endl;

int *ptr = &temp[0];
cout << sizeof(ptr) << endl;
cout << sizeof(*ptr) << endl;
cout << sizeof(&ptr) << endl;


//error
// arr = arr + 1;


//but in case of pointer it will not show error
p = p+1;
cout << p;


    return 0;
}