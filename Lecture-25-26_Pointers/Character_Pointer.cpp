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
    cout << *p << endl;


    char s[] = "hello"; // Declares and initializes an array of characters 's' with the string "hello".
char *pp = s; // Initializes the pointer 'p' to point to the first element of the array 's'.
cout << s[0] << " " << pp[0] << " " << pp[0]; // Prints the first character of the array 's' and the first character pointed to by 'p'.


     
    return 0;
}