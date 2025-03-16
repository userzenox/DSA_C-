#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int count = 0;
    int n = arr.size();
    
    // Instead of triple-loop, optimize by pruning invalid conditions earlier
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (abs(arr[i] - arr[j]) > a) continue; // Early pruning
            for (int k = j + 1; k < n; k++) {
                if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7, b = 2, c = 3;
    
    int result = countGoodTriplets(arr, a, b, c);
    cout << "Number of good triplets: " << result << endl; // Output: 4

    return 0;
}
