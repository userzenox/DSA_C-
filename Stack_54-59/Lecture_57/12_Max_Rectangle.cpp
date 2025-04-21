#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> nextsmallerelement(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> next(n);

        for (int i = n - 1; i >= 0; i--) {
            int num = heights[i];

            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }

    vector<int> prevsmallerelement(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int num = heights[i];

            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextsmallerelement(heights, n);
        vector<int> prev = prevsmallerelement(heights, n);

        int newarea = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            newarea = max(area, newarea);
        }

        return newarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[i][j] = (matrix[i][j] == '1') ? 1 : 0;
            }
        }

        int area = largestRectangleArea(heights[0]);

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (heights[i][j] != 0) {
                    heights[i][j] += heights[i - 1][j];
                } else {
                    heights[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(heights[i]));
        }

        return area;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int maxArea = sol.maximalRectangle(matrix);
    cout << "The maximal rectangle area is: " << maxArea << endl;

    return 0;
}
