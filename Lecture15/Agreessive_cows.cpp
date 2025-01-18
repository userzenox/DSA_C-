#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid) {
    int cowCount = 1;
    int lastpos = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - lastpos >= mid) {
            cowCount++;
            if (cowCount == m) { // Correct condition to check the number of cows
                return true;
            }
            lastpos = arr[i];
        }
    }
    return false; // Return false if not possible to place all cows
}

int allocatecow(int arr[], int n, int m) {
    sort(arr, arr + n); // Correct usage of sort function
    int start = 1; // Initialize start to 1
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int end = max - min;
    int mid = start + (end - start) / 2;
    int ans = 0; // Initialize ans to 0

    while (start <= end) {
        if (ispossible(arr, n, m, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    int arr[5] = {4, 2, 1, 3, 6};
    int n = 5; // Number of stalls
    int m = 2; // Number of cows

    cout << "Maximum distance between cows: " << allocatecow(arr, n, m);

    return 0;
}
