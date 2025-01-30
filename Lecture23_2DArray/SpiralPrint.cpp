#include<iostream>
using namespace std;

// Function to print the matrix in spiral order
void Spiralprint(int arr[3][4], int r, int c) {
    int startrow = 0, endrow = r - 1;
    int startcol = 0, endcol = c - 1;

    while (startrow <= endrow && startcol <= endcol) {
        // Print top row
        for (int col = startcol; col <= endcol; col++) {
            cout << arr[startrow][col] << " ";
        }
        startrow++;

        // Print right column
        for (int row = startrow; row <= endrow; row++) {
            cout << arr[row][endcol] << " ";
        }
        endcol--;

        // Print bottom row if there is more than one row remaining
        if (startrow <= endrow) {
            for (int col = endcol; col >= startcol; col--) {
                cout << arr[endrow][col] << " ";
            }
            endrow--;
        }

        // Print left column if there is more than one column remaining
        if (startcol <= endcol) {
            for (int row = endrow; row >= startrow; row--) {
                cout << arr[row][startcol] << " ";
            }
            startcol++;
        }
    }
}

int main() {
    int arr[3][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12} };

    for (int row = 0; row < 3; row++) {  // Loop through rows first
        for (int col = 0; col < 4; col++) {  // Then loop through columns
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Spiral Order: ";
    Spiralprint(arr, 3, 4);

    return 0;
}
