#include <iostream>
#include <string>
using namespace std;

int main() {
    char charArray[] = {'H', 'e', 'l', 'l', 'o'}; // example array
    string str(charArray, sizeof(charArray) / sizeof(charArray[0]));
    cout << "The string is: " << str << endl; // Output: Hello

    return 0;
}
