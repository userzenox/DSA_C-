#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0, bitwiseAnd = 0, maxLength = 0;

        for (int j = 0; j < nums.size(); j++) {
            while ((bitwiseAnd & nums[j]) != 0) {
                bitwiseAnd ^= nums[i];
                i++;
            }
            bitwiseAnd |= nums[j];
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 2, 4, 8};

    // Call the function and print the result
    int result = solution.longestNiceSubarray(nums);
    cout << "The length of the longest nice subarray is: " << result << endl;

    return 0;
}
