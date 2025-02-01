#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for reverse function
using namespace std;

class Solution {
public:

void reverse(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int c1 = 0;
    int c2 = matrix[0].size() - 1; // Corrected: Subtract 1 to get the last valid index

    while (c1 < c2) { // Corrected: Use c1 < c2 condition
        for (int i = 0; i < rows; i++) {
            swap(matrix[i][c1], matrix[i][c2]);
        }
        c1++;
        c2--;
    }
}



    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();


        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

            reverse(matrix);
            
        
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
