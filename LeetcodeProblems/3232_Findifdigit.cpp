#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;    
        for (int i = 0; i < nums.size(); i++) {
            // Check for single-digit numbers correctly
            if (abs(nums[i]) < 10) { 
                sum1 += nums[i];
            } else {
                sum2 += nums[i];
            }
        } 
        // Determine the result
        return sum1 != sum2;
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 12, -8, 45, -3, 9};

    // Create an instance of the Solution class
    Solution solution;

    // Call the canAliceWin function
    bool result = solution.canAliceWin(nums);

    // Display the result
    if (result) {
        cout << "Alice can win!" << endl;
    } else {
        cout << "Alice cannot win!" << endl;
    }

    return 0;
}