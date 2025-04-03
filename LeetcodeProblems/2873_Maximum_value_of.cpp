#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxs = 0;  
        
        for(int i = 0; i < n; i++) {          
            for(int j = i + 1; j < n; j++) {  
                for(int k = j + 1; k < n; k++) { 
                    long long sum = (long long)(nums[i] - nums[j]) * nums[k];
                    maxs = max(maxs, sum);
                }
            }
        } 

        return maxs;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 5, 7}; // Example input
    long long result = sol.maximumTripletValue(nums);
    
    cout << "Maximum Triplet Value: " << result << endl;
    
    return 0;
}
