#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            while (true) {
                bool found = false;
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        // Find the closest non-digit character to the left
                        for (int j = i - 1; j >= 0; j--) {
                            if (!(s[j] >= '0' && s[j] <= '9')) {
                                s.erase(s.begin() + i); // Remove the digit
                                s.erase(s.begin() + j); // Remove the closest non-digit character to the left
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }
                }
                if (!found) break; // No more digits found, exit the loop
            }
            return s;
        }
    };

    
int main() {
    Solution solution;
    string input = "abc1def2gh3";
    string result = solution.clearDigits(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}
