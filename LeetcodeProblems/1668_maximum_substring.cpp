#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string s = word;
        
        while (sequence.find(s) != string::npos) {
            count++;
            s += word;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    string sequence = "ababcababcab"; // Example input
    string word = "ab"; // Example word
    int result = sol.maxRepeating(sequence, word);
    cout << "The maximum repeating value is: " << result << endl;

    return 0;
}
