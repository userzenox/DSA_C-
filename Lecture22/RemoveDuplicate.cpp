#include<iostream>
using namespace std;


 string RemoveDuplicates(string s){
    
    
   for(int i=0; i < s.length()-1; i++){
        if(s.length()==0){
            return {};
        }
        if(s[i]== s[i+1]  ){
            s.erase(i,2);
            // cout << s << " ";
            i=-1;
        }

    }
    return s;
 }

int main(){
    
    string s =  "aaaaa";
  cout << "Original string: " << s << endl;
    cout << "String after removing duplicates: " << RemoveDuplicates(s) << endl;
    return 0;
}