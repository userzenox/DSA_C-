#include<iostream>
#include<vector>
#include<cmath> // For abs() function
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        
        for (int i = 0; i < s.size() - 1; i++) {
            int c1 = s[i];
            int c2 = s[i + 1];
            sum += abs(c1 - c2); // Use abs() to get the absolute difference
        }
        
        return sum;
    }
};

int main() {
    Solution solution;
    string s = "hello";
    int score = solution.scoreOfString(s);

    cout << "Input: s = \"" << s << "\"" << endl;
    cout << "Output: " << score << endl;

    return 0;
}
