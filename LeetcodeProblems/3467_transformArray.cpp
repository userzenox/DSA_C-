#include <iostream>
#include <vector>
#include <algorithm>  // For sort, though it's already used in your solution class.

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for (int& num : nums) {
            num = num % 2;  // Sets even numbers to 0 and odd numbers to 1
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    // Example input array
    vector<int> nums = {7, 4, 5, 2, 9};

    // Create an object of the Solution class
    Solution solution;

    // Call the function
    vector<int> transformedNums = solution.transformArray(nums);

    // Print the transformed and sorted array
    cout << "Transformed Array: ";
    for (int num : transformedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
