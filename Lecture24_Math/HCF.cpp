#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return (a == 0) ? b : a;
}

int main() {
    int a, b;
    cout << "Enter two numbers" << endl;
    cin >> a >> b;
    cout << "GCD is " << gcd(a, b);
    return 0;
}
