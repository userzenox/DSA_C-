#include <vector>
#include <iostream>
using namespace std;
//convert array to number
int arrayToNumber(vector<int>& digits) {
    int number = 0;
    for (int digit : digits) {
        number = number * 10 + digit;
    }
    return number+1;
}

int main() {
    vector<int> digits = {1, 2, 3, 9, 9}; // example array
    int number = arrayToNumber(digits);
    cout << "The number is: " << number << endl; // Output: 12345

    return 0;
}
