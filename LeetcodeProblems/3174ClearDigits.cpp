// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            int count1=0,count2=0;
            for(int i=0; i< s.size(); i++){
                if(s[i] >= 48 && s[i] <= 57 ){
                    int k =i+1, j=i+1;
    
                    
                    while (s[j] >= 'a' && s[j] <= 'z' && k< s.size()){
                        k++;
                        count1++;
                       }
                    while( s[j] >= 'a' && s[j] <= 'z' && j>0){
                        j--;
                        count2++;
                       }   
    
                if(count1 > count2){
                     s.erase(s.begin()+i,s.begin()+j);
                }else{
                     s.erase(s.begin()+i,s.begin()+k);
                }   
                }
            }
            return s;
        }
    };


int main() {
    Solution solution;
    string input = "abc1def2gh3";
    string result = solution.clearDigits(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}
