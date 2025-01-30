#include <iostream>
using namespace std;

void sum(int arr[][4]) {
    int sum = 0;
    for (int row = 0; row < 3; row++) {
        sum = 0; // Reset sum for each row
        for (int col = 0; col < 4; col++) {
            sum += arr[row][col];
            cout << arr[row][col];
            if (col < 3) {
                cout << " + ";
            }
        }
        cout << " = " << sum << endl;
    }
}

int main() {
    int arr[3][4];

    cout << "Enter elements of the array:\n";
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cin >> arr[row][col];
        }
    }

    sum(arr);
 
    return 0;
}
