#include <iostream>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int row1 = 1, row2 = 1;
        int red1 = 0, blue1 = 0;
        int red2 = 0, blue2 = 0;

        while (true) {
            if (row1 % 2 != 0) {
                if (red1 + row1 > red) {
                    break;
                }
                red1 += row1;
            } else {
                if (blue1 + row1 > blue) {
                    break;
                }
                blue1 += row1;
            }
            row1++;
        }

        while (true) {
            if (row2 % 2 != 0) {
                if (blue2 + row2 > blue) {
                    break;
                }
                blue2 += row2;
            } else {
                if (red2 + row2 > red) {
                    break;
                }
                red2 += row2;
            }
            row2++;
        }

        return max(row1 - 1, row2 - 1);
    }
};

int main() {
    Solution solution;
    int red, blue;
    cout << "Enter the number of red and blue tiles: ";
    cin >> red >> blue;
    int result = solution.maxHeightOfTriangle(red, blue);
    cout << "Maximum height of the triangle: " << result << endl;
    return 0;
}
