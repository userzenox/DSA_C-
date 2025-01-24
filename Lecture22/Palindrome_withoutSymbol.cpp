#include <iostream>
#include <cctype> // For isalnum and tolower functions

using namespace std;

bool StrongPalindrome(char name[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        // Skip non-alphanumeric characters from the start
        while (s < e && !isalnum(name[s])) {
            s++;
        }
        // Skip non-alphanumeric characters from the end
        while (s < e && !isalnum(name[e])) {
            e--;
        }

        // Check if characters are not equal (case insensitive)
        if (tolower(name[s]) != tolower(name[e])) {
            return false;
        }

        s++;
        e--;
    }
    return true;
}

int main() {
    char str[] = "rr@r@fhfg";
    int len = sizeof(str) / sizeof(str[0]) - 1; // Exclude the null terminator

    if (StrongPalindrome(str, len)) {
        cout << "The string is a strong palindrome." << endl;
    } else {
        cout << "The string is not a strong palindrome." << endl;
    }

    return 0;
}
