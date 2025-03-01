#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        int n = mat.size();  // Determine the size of the matrix

        if (n == 0 || mat[0][0] == 0) return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";
        solve(mat, n, ans, 0, 0, path, visited);
        return ans;
    }

  private:
    void solve(vector<vector<int>>& mat, int n, vector<string>& ans, int x, int y, string& path, vector<vector<bool>>& visited) {
        if (x == n - 1 && y == n - 1) {  // Destination reached
            ans.push_back(path);
            return;
        }

        visited[x][y] = true;

        // Move Left
        int newx = x;
        int newy = y - 1;
        if (isSafe(newx, newy, n, mat, visited)) {
            path.push_back('L');
            solve(mat, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Move Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, mat, visited)) {
            path.push_back('R');
            solve(mat, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Move Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, mat, visited)) {
            path.push_back('U');
            solve(mat, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        // Move Down
        newx = x + 1;
        newy = y;
        if (isSafe(newx, newy, n, mat, visited)) {
            path.push_back('D');
            solve(mat, n, ans, newx, newy, path, visited);
            path.pop_back();
        }

        visited[x][y] = false;
    }

    bool isSafe(int x, int y, int n, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    Solution solution;
    vector<string> result = solution.findPath(mat);

    for (const string& path : result) {
        cout << path << endl;
    }

    return 0;
}
