#include<iostream>
#include<vector>
using namespace std;

void solve(string s,vector<char> output,int index , vector<vector<char>> &ans){

    if(index>=s.size()){
        ans.push_back(output);
        
        return ;
    }

    //excluding 
    solve(s,output,index+1,ans);

    //including
    int element = s[index];
    output.push_back(element);
    solve(s,output,index+1,ans);

}

vector<vector<char>> subsets(string s){
    vector<char> output;
    vector<vector<char>> ans;
     int index=0;
     solve(s,output,index,ans);
     return ans;

}


int main() {
    string s = "abc";
    vector<vector<char>> result = subsets(s);  // Get the subsets

    // Print the subsets
    for (const auto& subset : result) {
        cout << "{ ";
        for (char ch : subset) {
            cout << ch << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}