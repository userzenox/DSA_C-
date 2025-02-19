#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans ){
       if(index >= nums.size()){
        ans.push_back(output);
          return ; 
       }

       //exclude
       solve(nums,output, index+1, ans);

       //include
       int element = nums[index]; 
       output.push_back(element);

       solve(nums,output, index+1, ans);

}

vector<vector<int>> subsets( vector<int> arr, int n){
    vector<vector<int>> ans;
    vector<int> output;

    int index = 0;
    solve(arr,output, index,ans);
    return ans;    
    
}

int main() {
    vector<int> arr = {1, 2, 3};
    int size = arr.size();
    vector<vector<int>> result = subsets(arr, size);  // Get the subsets

    // Print the subsets
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
