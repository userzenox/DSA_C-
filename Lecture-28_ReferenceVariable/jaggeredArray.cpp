#include <iostream>
using namespace std;

int main() {
    // Jagged array with stack memory (fixed inner array sizes)
    int row1[2] = {1, 2};
    int row2[3] = {3, 4, 5};
    int row3[1] = {6};

    int* jaggedArray[3] = {row1, row2, row3};

    // Print the jagged array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (i == 0 ? 2 : (i == 1 ? 3 : 1)); j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
