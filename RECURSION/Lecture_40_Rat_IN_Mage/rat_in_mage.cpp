#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   

    vector<string> findPath(vector<vector<int>> &m, int n) {
      
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    // Debug print to check the input matrix
    cout << "Input matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
    vector<string> result = obj.findPath(m, n);
    if (result.size() == 0) cout << -1;
    else for (string s : result) cout << s << " ";
    cout << endl;
    return 0;
}
