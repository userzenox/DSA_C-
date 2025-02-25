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

int arrayToNumber2(vector<int>& digits) {
    int num = 0;
    for(int i=0;i<digits.size();i++){
        num = num*10 + digits[i];
   }
    return num+1;
}

vector<int> numberToArray(int number) {
    vector<int> digits;
    while (number > 0) {
        digits.insert(digits.begin(), number % 10);
        number /= 10;
    }
    return digits;
}


int main() {
    vector<int> digits = {1, 2, 3, 6, 9}; // example array
    int number = arrayToNumber2(digits);
    cout << "The number is: " << number << endl; // Output: 12345


    vector<int> incrementedDigits = numberToArray(number);
    cout << "The incremented digits are: ";
    for (int digit : incrementedDigits) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}
