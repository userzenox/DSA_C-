// code with time complexity of O(n*n) - n square

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<bool> occupied(days + 1, false);

        for(const auto& meeting: meetings){
            int start = meeting[0];
            int end = meeting[1];
            for(int i = start; i <= end; ++i){
                occupied[i] = true;
            }
        }

        int freeDays = 0;
        for(int i = 1; i <= days; i++){
            if(!occupied[i]){
                ++freeDays;
            }
        }
        return freeDays;
    }
};

int main() {
    Solution solution;
    int days = 10; // Example: total number of days in the calendar
    vector<vector<int>> meetings = {{1, 3}, {5, 6}, {8, 9}}; // Example: meetings scheduled with start and end days
    
    int freeDays = solution.countDays(days, meetings);
    cout << "Number of free days: " << freeDays << endl;

    return 0;
}