// code ninja 
// Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.

// If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

// For example,

// For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    int maxcount = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
        maxcount = max(maxcount, m[arr[i]]);
    }

    // Return the first element with max frequency
    for (int i = 0; i < n; i++) {
        if (m[arr[i]] == maxcount) {
            return arr[i];
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 3, 3};
    int n = arr.size();

    int result = maximumFrequency(arr, n);
    cout << "Element with maximum frequency: " << result << endl;

    return 0;
}
