#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int n = columnTitle.size(); 
        
        for(int i = 0; i < n; i++) {
            int a = columnTitle[i] - 'A' + 1;
            sum = sum * 26 + a;
        }
        
        return sum;
    }
};

int main() {
    Solution solution;
    string columnTitle;

    cout << "Enter the column title: ";
    cin >> columnTitle;

    int columnNumber = solution.titleToNumber(columnTitle);
    cout << "The column number is: " << columnNumber << endl;

    return 0;
}

