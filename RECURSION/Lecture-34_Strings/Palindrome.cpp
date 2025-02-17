#include<iostream>
using namespace std;

bool palindrome(string name, int s , int e){
    //base case
    if(s >e){
        return true;
    }

    if(name[s] == name[e]){
         return palindrome(name,s+1,e-1);
    }
    else{
        return false;
    }
    

}

int main(){
    
    string name ="abccba";
    int s =0;
    int e = name.length()-1;
    bool ans = palindrome(name,s,e);
    if(ans){
        cout << "its a palindrome string";
    }else{
        cout << "Not a palindrome string";
    }
    return 0;
}