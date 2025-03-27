#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            vector<int> temp;
            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            reverse(temp.begin(), temp.end()); 
            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {123, 45, 6789}; // Example input
    vector<int> result = solution.separateDigits(nums);

    cout << "Separated Digits: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}
