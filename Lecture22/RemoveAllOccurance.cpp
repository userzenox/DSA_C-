#include<iostream>
#include<vector>
using namespace std;

char MaxOccurance( string s){
    int arr[26] = {0};
    for(int i=0; i<s.length() - 1; i++){
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;

    }

    int max = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(max < arr[i]){
            ans = i;
            max = arr[i];
            
        }
    }
 
   char f = 'a' + ans;
     return f;
}

int main(){
    string s = "zey's zello zows zgoing";
    cout << s;

    cout << endl << MaxOccurance(s) << endl;
    return 0;
}