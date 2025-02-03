#include<iostream>
using namespace std;

int main(){
    int arr[10]={2,3,4};

    cout <<"address of first memory block is" << arr << endl;

    cout <<"address of first memory block is" << &arr[0] << endl;


    
    cout << "Value of *arr - " << *arr << endl;
    cout << "Value of *arr + 1 - " << *arr +1 << endl;

    return 0;
}