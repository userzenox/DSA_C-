#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string s2 = s;

        for (int i = 0; i < indices.size(); i++) {
            s2[indices[i]] = s[i];
        }

        return s2;
    }
};

int main() {
    Solution solution;

    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};

    string restoredString = solution.restoreString(s, indices);

    cout << "Original string: " << s << endl;
    cout << "Restored string: " << restoredString << endl;

    return 0;
}
