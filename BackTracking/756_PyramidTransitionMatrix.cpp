#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above) {
        // If we reach a row of length 1, pyramid is successfully built
        if (curr.length() == 1) {
            return true;
        }

        // Finished building the current "above" row, move to the next level
        if (idx == curr.length() - 1) {
            return solve(above, mp, 0, "");
        }

        // Take the current pair of characters
        string pair = curr.substr(idx, 2);

        // If no allowed block can be placed over this pair, this path is invalid
        if (mp.find(pair) == mp.end()) {
            return false;
        }

        // Try all possible characters that can go above this pair
        for (char &ch : mp[pair]) {
            above.push_back(ch);

            if (solve(curr, mp, idx + 1, above)) {
                return true;
            }

            // Backtrack
            above.pop_back();
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        // Build map: "AB" -> list of chars 'C' such that "ABC" is allowed
        for (auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]);
        }

        return solve(bottom, mp, 0, "");
    }
};

int main() {
    // Example usage
    Solution sol;
    string bottom = "ABC";
    vector<string> allowed = {"ABD", "BCE", "DEF", "CEG"};
    bool canBuild = sol.pyramidTransition(bottom, allowed);
    cout << (canBuild ? "true" : "false") << endl;
    return 0;
}
