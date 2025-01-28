#include<iostream>
using namespace std;

 bool checkEqual( int a[26], int b[26]){
    for(int i=0; i<26; i++){
        if(a[i]!= b[i]){
            return 0;
        }
    }
    return 1;
 }

bool Permutation( string s1, string s2){
     int count[26] = {0};
     for( int i=0; i<s2.length(); i++){
           int index = s2[i] - 'a';
           count[index]++;
     }

     //now Transverse the array
     int i=0, count2[26] = {0};
     while( i<s2.length() && i<s1.length() ){
           int index = s1[i] - 'a';
          
            count2[index]++;
            i++;
     }
     if(checkEqual(count,count2)){
        return 1;
     }
     // here i value is 2.
     while( i< s1.length()){
        // next char
       
       int index = s1[i] - 'a';
       count2[index]++;

       char oldChar = s1[i - s2.length()];
       index = oldChar - 'a';
       count2[index]--;
       i++;

       if(checkEqual(count,count2)){
        return 1;
     }
     }
     
    return 0;
}

int main(){
    string s1 = "eidbacoo";
    string s2= "ab";
    cout << s1;
    cout << s2;

    cout << endl << Permutation(s1,s2) << endl;
   
    return 0;
}