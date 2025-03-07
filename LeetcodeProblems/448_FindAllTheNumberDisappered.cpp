#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    
    // Step 1: Mark the indices corresponding to the numbers present in the array
    for (int i = 0; i < n; ++i) {
        int index = abs(nums[i]) - 1;  // Get the index corresponding to the value
        if (nums[index] > 0) {  // Mark it negative to indicate the number is present
            nums[index] = -nums[index];
        }
    }
    
    // Step 2: Find the numbers that are missing (indices with positive values)
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            result.push_back(i + 1);  // The missing number is i + 1
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> missingNumbers = findDisappearedNumbers(nums);
    
    // Output the result
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    
    return 0;
}