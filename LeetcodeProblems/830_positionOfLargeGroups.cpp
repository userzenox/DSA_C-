#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size();
        int count = 1;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == s[i + 1]) {
                count++;
            } else {
                if (count >= 3) {
                    ans.push_back({i - count + 1, i});
                }
                count = 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "abbxxxxzzy";
    vector<vector<int>> result = solution.largeGroupPositions(s);

    cout << "Large groups in the string are at positions: " << endl;
    for (const auto& group : result) {
        cout << "[" << group[0] << ", " << group[1] << "]" << endl;
    }

    return 0;
}
