#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());

        // Sort lexicographically so smaller words come first
        sort(words.begin(), words.end());

        string ans = "";

        for (const string& word : words) {
            // If word length is 1 OR its prefix exists
            if (word.size() == 1 || st.count(word.substr(0, word.size() - 1))) {
                if (word.size() > ans.size()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"w", "wo", "wor", "worl", "world"};

    cout << "Longest word: " << sol.longestWord(words) << endl;

    return 0;
}
