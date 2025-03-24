#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countAvailableDays(int days, vector<vector<int>>& meetings) {
    // Step 1: Sort meetings by start time
    sort(meetings.begin(), meetings.end());

    int availableDays = 0;
    int lastEnd = 0;  // Tracks the last occupied day

    // Step 2: Merge overlapping meetings and count free days
    for (const auto& meeting : meetings) {
        int start = meeting[0], end = meeting[1];

        // Count free days before the current meeting starts
        if (start > lastEnd + 1) {
            availableDays += (start - lastEnd - 1);
        }

        // Update the last occupied day
        lastEnd = max(lastEnd, end);
    }

    // Step 3: Count free days after the last meeting
    if (lastEnd < days) {
        availableDays += (days - lastEnd);
    }

    return availableDays;
}

int main() {
    int days = 10;
    vector<vector<int>> meetings = {{2, 5}, {7, 9}};

    cout << countAvailableDays(days, meetings) << endl;  // Output: 3

    return 0;
}
