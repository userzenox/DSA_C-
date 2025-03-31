#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            ans[i] = sum;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 2, 3, 4};

    // Calling runningSum function
    vector<int> result = solution.runningSum(nums);

    // Output the result
    cout << "Running Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
