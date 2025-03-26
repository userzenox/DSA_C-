#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                int sq = nums[i] * nums[i];
                sum += sq;
            }
        }
        return sum;
    }
};

int main() {
    // Create a Solution object
    Solution sol;

    // Test case: example input
    vector<int> nums = {2, 3, 4, 6};
    cout << "Input vector: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // Call the sumOfSquares method and output the result
    int result = sol.sumOfSquares(nums);
    cout << "Sum of squares: " << result << endl;

    return 0;
}