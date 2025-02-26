#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(string digits, string output, int index, string map[], vector<string>& ans) {
        // base case
        if(index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0'; 
        string value = map[number];

        for(int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index + 1, map, ans);
            output.pop_back();  // This is backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length() == 0) {
            return ans;
        }

        string output;
        int index = 0;
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, map, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);

    // Print the combinations
    for(const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
