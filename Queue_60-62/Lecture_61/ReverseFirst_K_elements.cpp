#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> q;
        vector<int> ans;

        // Process first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                q.push_back(i); 
            }
        }

        // Store result for first window
        if (!q.empty()) {
            ans.push_back(arr[q.front()]);
        } else {
            ans.push_back(0);
        }

        // Process the rest of the windows
        for (int i = k; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }

            // Add current element if it's negative
            if (arr[i] < 0) {
                q.push_back(i);
            }

            // Append result
            if (!q.empty()) {
                ans.push_back(arr[q.front()]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};

int main() {
    int n, k;

    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.firstNegInt(arr, k);

    cout << "First negative integers in every window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
