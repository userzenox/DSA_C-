#include<iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sort0(int array[], int n) {
    cout << "sort working" << endl;
    int i = 0, j = n - 1;
    int step = 0;

    while (i < j) {
        while (array[i] == 0 && i < j) {
            i++;
        }
        while (array[j] == 1 && i < j) {
            j--;
        }
        if (i < j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
        cout << "step " << step++ << endl;
        printArray(array, n);
    }
}

int main() {
    int arr[8] = {0, 1, 1, 0, 1, 0, 1, 0};

    printArray(arr, 8);

    sort0(arr, 8);

    printArray(arr, 8);

    return 0;
}
