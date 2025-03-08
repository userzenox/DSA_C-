#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min = INT_MAX;
        
        for (int i = 0; i <= blocks.size() - k; i++) {
            int countB = 0;
            int countW = 0;
            
            for (int j = i; j < i + k; j++) { 
                if (blocks[j] == 'B') {
                    countB++;                             
                } else {
                    countW++;  
                }     
            }
            if (countW < min) {
                min = countW;
            }
        }

        return min;
    }
};

int main() {
    Solution solution;
    string blocks = "WBBWWBBBWBW";
    int k = 8;
    int result = solution.minimumRecolors(blocks, k);
    cout << "Minimum recolors needed: " << result << endl;
    return 0;
}
