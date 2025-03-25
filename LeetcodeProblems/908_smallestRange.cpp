#include <iostream>
#include <vector>
#include <algorithm>  // For max_element and min_element

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxNo = *max_element(nums.begin(), nums.end());
        int minNo = *min_element(nums.begin(), nums.end());

        return max(0, (maxNo - minNo) - 2 * k);
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 3, 6};
    int k1 = 2;
    cout << "Output 1: " << solution.smallestRangeI(nums1, k1) << endl;  // Expected: 1

    // Test case 2
    vector<int> nums2 = {4, 8, 10};
    int k2 = 3;
    cout << "Output 2: " << solution.smallestRangeI(nums2, k2) << endl;  // Expected: 0

    // Test case 3: Single element
    vector<int> nums3 = {5};
    int k3 = 10;
    cout << "Output 3: " << solution.smallestRangeI(nums3, k3) << endl;  // Expected: 0

    // Test case 4: Already small range
    vector<int> nums4 = {7, 7, 7, 7};
    int k4 = 5;
    cout << "Output 4: " << solution.smallestRangeI(nums4, k4) << endl;  // Expected: 0

    return 0;
}
