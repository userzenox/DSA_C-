#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int start = 0;
        int deficit = 0;
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            balance += gas[i] - cost[i];
            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        return (balance + deficit >= 0) ? start : -1;
    }
};

int main() {
    Solution solution;

    // Sample Input
    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = solution.canCompleteCircuit(gas, cost);
    cout << "Start index: " << result << endl;

    return 0;
}
