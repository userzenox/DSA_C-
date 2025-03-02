#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while (index < nums.size()) {
            nums[index++] = 0;
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 4, 0, 4, 4};
    
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = sol.applyOperations(nums);

    cout << "Transformed array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
