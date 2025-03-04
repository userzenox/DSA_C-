#include <iostream>
#include <cmath>  // For abs()
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int arr1[26] = {0}; // Initialize with 0 to avoid garbage values
        int arr2[26] = {0}; // Initialize with 0 to avoid garbage values

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            arr1[x] = i;
        }

        for (int i = 0; i < t.size(); i++) {
            int y = t[i] - 'a';
            arr2[y] = i;
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += abs(arr1[i] - arr2[i]);
        }

        return sum;
    }
};

int main() {
    Solution sol;
    string s, t;
    
    cout << "Enter first string (s): ";
    cin >> s;
    
    cout << "Enter second string (t): ";
    cin >> t;

    if (s.size() != t.size()) {
        cout << "Error: Strings must be of the same length (permutations of each other)." << endl;
        return 1; // Exit with error code
    }

    int result = sol.findPermutationDifference(s, t);
    cout << "Permutation Difference: " << result << endl;

    return 0;
}
