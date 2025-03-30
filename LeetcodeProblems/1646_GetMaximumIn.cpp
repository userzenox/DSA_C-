#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> nums(n + 1, 0);
        nums[0] = 0;
        nums[1] = 1;
        
        int maximum = 1;
        
        for (int i = 1; 2 * i <= n; i++) {
            nums[2 * i] = nums[i]; // Even index
            if (2 * i + 1 <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1]; // Odd index
                maximum = max(maximum, nums[2 * i + 1]);
            }
        }
        
        return maximum;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter a value for n: ";
    cin >> n;

    int result = solution.getMaximumGenerated(n);
    cout << "The maximum value in the generated array is: " << result << endl;

    return 0;
}
