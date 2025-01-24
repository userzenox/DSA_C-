#include <iostream>
#include <algorithm>
using namespace std;

char lowercase(char c){
    char ch;
    if(c >= 'a' && c <= 'z'){
        ch = c;
    } else if(c >= 'A' && c <= 'Z'){
        ch = c - 'A' + 'a';
    } 
    return ch;
}

bool checkPalindrome(char name[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        if (name[s] != name[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

void reverseString(char name[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        swap(name[s], name[e]);
        s++;
        e--;
    }
}

int length(char name[]) {
    int i = 0;
    while (name[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char name[20];
    // Null character = '\0'
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Your name is " << name << endl;
    
    // Calculate the length of the string
    int string_length = length(name);
    cout << "The length of your name is " << string_length << endl;

    // Reverse the string
    reverseString(name, string_length);
    cout << "The reversed string is " << name << endl;

    // Check if the original string is a palindrome
    bool isPalindrome = checkPalindrome(name, string_length);
    cout << "Is the string a palindrome? " << (isPalindrome ? "Yes" : "No") << endl;


    //convert to lower case 
    char c;
      cout << "Enter a charaqcter - ";
      cin >> c;
     
     cout << "its Lower case is - " <<  lowercase(c);

    return 0;
}
