#include<iostream>
using namespace std;

int main(){
    int arr[10];

    cout <<"address of first memory block is" << arr << endl;
    cout <<"address of first memory block is" << &arr[0] << endl;

    return 0;
}