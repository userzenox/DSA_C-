#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    int bit, count = 0;
    while (n != 0) {
        bit = n & 1;
        if (bit == 1) {
            count++;
        }
        n = n >> 1;
    }
    return count == 1;
}

int main() {
    int n;
    cin >> n;
    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }
    return 0;
}
