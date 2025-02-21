#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        int arr[26] = {0};
        int arr2[26] = {0};

        if (n != m) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            int count = s[i] - 'a';
            arr[count]++;
        }

        for (int i = 0; i < m; i++) {
            int count = t[i] - 'a';
            arr2[count]++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";

    if (solution.isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
