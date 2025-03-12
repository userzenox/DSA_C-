#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int even_index = 0;
        int odd_index = 1;
        int n = nums.size();

        while (even_index < n && odd_index < n) {
            // Find the first misplaced even number
            while (even_index < n && nums[even_index] % 2 == 0) {
                even_index += 2;
            }

            // Find the first misplaced odd number
            while (odd_index < n && nums[odd_index] % 2 == 1) {
                odd_index += 2;
            }

            // Swap the misplaced even and odd numbers
            if (even_index < n && odd_index < n) {
                std::swap(nums[even_index], nums[odd_index]);
            }
        }

        return nums;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 2, 5, 7};
    std::vector<int> result = solution.sortArrayByParityII(nums);

    std::cout << "Sorted array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
