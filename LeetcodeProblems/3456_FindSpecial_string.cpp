#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (n < k) return false; // Early return if s is shorter than k
        if (k == 1) return true; // Handle the case where k is 1

        for (int i = 0; i <= n - k; i++) {
            bool isSpecial = true;
            char currentChar = s[i];

            // Check if the substring consists of one distinct character
            for (int j = i; j < i + k; j++) {
                if (s[j] != currentChar) {
                    isSpecial = false;
                    break;
                }
            }

            if (isSpecial) {
                // Check character before the substring
                if (i > 0 && s[i - 1] == currentChar) {
                    isSpecial = false;
                }
                // Check character after the substring
                if (i + k < n && s[i + k] == currentChar) {
                    isSpecial = false;
                }
            }

            if (isSpecial) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "aaabaaa";
    int k1 = 3;
    if (solution.hasSpecialSubstring(s1, k1)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    // Test case 2
    string s2 = "abc";
    int k2 = 2;
    if (solution.hasSpecialSubstring(s2, k2)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
