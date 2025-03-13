#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first positive number index using binary search
        int left = 0, right = n - 1, firstPos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                firstPos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Find the first zero index using binary search
        left = 0, right = n - 1;
        int firstZero = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                firstZero = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int negCount = firstZero; // Count of negative numbers
        int posCount = n - firstPos; // Count of positive numbers
        
        return max(negCount, posCount);
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> testCases = {
        {-3, -2, -1, 0, 1, 2, 3},  // Both positive and negative, should return 3
        {-5, -4, -3, -2, -1},      // Only negatives, should return 5
        {1, 2, 3, 4, 5},           // Only positives, should return 5
        {0, 0, 0, 0},              // Only zeros, should return 0
        {-2, -1, 0, 0, 1, 2},      // Balanced case, should return 2
        {-10, -5, 0, 0, 5, 10}     // Another balanced case, should return 2
    };

    for (auto& test : testCases) {
        cout << "Maximum count of positives or negatives: " << sol.maximumCount(test) << endl;
    }

    return 0;
}
