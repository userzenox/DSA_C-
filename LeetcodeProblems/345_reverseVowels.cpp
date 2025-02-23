#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (isVowel(tolower(s[i]))) {
                if (isVowel(tolower(s[j]))) {
                    swap(s[i++], s[j--]);
                } else {
                    j--;
                }
            } else {
                i++;
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    string input = "hello";
    string output = solution.reverseVowels(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;
    
    input = "leetcode";
    output = solution.reverseVowels(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}
