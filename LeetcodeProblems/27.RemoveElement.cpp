#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = n;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == val) {
                swap(nums[i], nums[k - 1]);
                k--;
                nums.pop_back();
            }
        }
        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int newLength = solution.removeElement(nums, val);

    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
