#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer;
        
        for (int i = 0; i < prices.size(); i++) {
            int j = i + 1;
            while (j < prices.size() && j > i && prices[j] > prices[i]) {
                j++;
            }

            if (j < prices.size() && prices[j] <= prices[i]) {
                int dist = abs(prices[i] - prices[j]);
                answer.push_back(dist);
            } else {
                answer.push_back(prices[i]);
            }
        }
        return answer;
    }
};

int main() {
    // Input prices
    vector<int> prices = {8, 4, 6, 2, 3};

    // Create a Solution object
    Solution solution;

    // Call the function
    vector<int> result = solution.finalPrices(prices);

    // Print the result
    cout << "Final prices after discount: ";
    for (int price : result) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}
