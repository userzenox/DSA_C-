#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(nums, ans, index + 1);
            swap(nums[index], nums[i]); // Backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> permutations = sol.permute(nums);

    // Print all the permutations
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
