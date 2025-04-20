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

        vector<int> next(n);
        next = nextsmallerelement(heights, n);

        vector<int> prev(n);
        prev = prevsmallerelement(heights, n);

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
};

int main() {
    Solution solution;

    // Input: Heights of the histogram bars
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Compute the largest rectangle area
    int result = solution.largestRectangleArea(heights);

    // Output the result
    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}