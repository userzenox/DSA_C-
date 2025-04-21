#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        // Add a sentinel zero to flush remaining bars
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        // Remove the sentinel before returning
        heights.pop_back();

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = sol.largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;
    return 0;
}
