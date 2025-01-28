#include<iostream>

using namespace std;

string removeOccurance( string s, string part){
    while( s.length()!=0 && s.find(part) < s.length()){
          s.erase(s.find(part), part.length());
    }
   return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part= "abc";
    cout << s;

    // cout << endl << s.find(part);

    // s.erase(s.find(part), part.length());
    // cout << endl << s;

    cout << endl << removeOccurance(s,part) << endl;
   
    return 0;
}