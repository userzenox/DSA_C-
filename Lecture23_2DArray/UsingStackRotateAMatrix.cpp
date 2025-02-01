#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        stack<int> stk; // Add a stack to hold the elements
        int r = row - 1;
        int c = 0;
        
        // Push elements into the stack
        while (c < col) {
            for (int i = r; i >= 0; i--) {
                stk.push(matrix[i][c]);
            }
            c++;
        }

        // Pop the elements from the stack and rotate the matrix
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                matrix[j][i] = stk.top();
                stk.pop();
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    sol.rotate(matrix);

    cout << "Rotated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
