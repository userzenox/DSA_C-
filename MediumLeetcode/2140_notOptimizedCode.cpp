#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long sum = 0, maxsum = 0; // Use long long to prevent overflow

        for (int i = 0; i < n - 2; i++) { // Outer loop
            for (int j = i; j < n; j = j + 3) { // Inner loop, step size of 3
                // Add the first element of each sub-array
                sum = sum + questions[j][0];
            }

            // Update maximum sum
            maxsum = max(maxsum, sum);
            sum = 0; // Reset sum for the next iteration
        }
        return maxsum;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input for questions
    vector<vector<int>> questions = {
        {3, 2}, 
        {4, 3}, 
        {4, 4}, 
        {2, 5}
    };

    // Call the mostPoints function and print the result
    long long result = solution.mostPoints(questions);
    cout << "Maximum points: " << result << endl;

    return 0;
}