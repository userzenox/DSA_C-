#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = -1;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            maxDistance = max(maxDistance, abs(nums[i] - nums[i + 1]));
        }

        // Include the circular case: first and last elements
        maxDistance = max(maxDistance, abs(nums[0] - nums[n - 1]));

        return maxDistance;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums = {1, 2, 4};
    
    int result = sol.maxAdjacentDistance(nums);
    cout << "Max Adjacent Distance: " << result << endl; // Expected Output: 3

    return 0;
}
