#include<iostream>
#include<vector>
using namespace std;

string reverse(string temp){
   int s=0;
    int e=temp.length() - 1;
   
    while(s<e){
        swap(temp[s], temp[e]);
        s++;
        e--;
    }
    return temp;
}

string wordReverse(string s){
    string temp;
    string temp2;
   
   for( int i=0; i<s.size(); i++){
      
   
      if(s[i] == ' ' || i == s.size() - 1){
           if( i == s.size() - 1){
                temp += s[i];
           }
            temp2 = temp2 + reverse(temp) + " " ;
           
            
             temp = " ";
            
      }
      else{
          temp += s[i];
      }
     
   }
   
   return temp2;
}

int main(){
    string s = "hey hello hows going";
    cout << s;

    cout << endl << wordReverse(s) << endl;
    return 0;
}