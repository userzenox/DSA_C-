#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n); 
        for (int i = 0; i < 2 * n; i++) {
            ans[i] = nums[i % n];
        }     
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<int> result = solution.getConcatenation(nums);

    // Printing the result
    cout << "Concatenated array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}