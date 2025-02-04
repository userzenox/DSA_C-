//Pointer Character Array
#include<iostream>
using namespace std;

int main(){
    
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout << arr << endl;  // here the address is printed
    cout << ch << endl;    // here the string is printed

    char *c =  &ch[0];    
    cout << c << endl;  

    char temp ='z';
    char *p = &temp;
    cout << p << endl;

     
    return 0;
}