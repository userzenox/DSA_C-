#include<iostream>
#include<string>
using namespace std;

#include<iostream>
using namespace std;

void compress(char s[], int n) {
    int i = 0;
    int ansIndex = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n && s[i] == s[j]) {
            j++;
        }

        s[ansIndex++] = s[i];
        int count = j - i;

        if (count > 1) {
            string cnt = to_string(count);
            for (char ch : cnt) {
                s[ansIndex++] = ch;
            }
        }
        i = j;
    }
    s[ansIndex] = '\0'; // Null-terminate the char array
}

int main() {
    char s[] = "aabbccc";
    int n = sizeof(s) / sizeof(s[0]) - 1; // Calculate the length of the char array

    compress(s, n);
    cout << "Compressed String: " << s << endl;

    return 0;
}





//for string
// string compress(string s) {
//     int i = 0;
//     int ansIndex = 0;
//     int n = s.length();
//     string result = "";

//     while (i < n) {
//         int j = i + 1;
//         while (j < n && s[i] == s[j]) {
//             j++;
//         }

//         result += s[i];
//         int count = j - i;

//         if (count > 1) {
//             result += to_string(count);
//         }
//         i = j;
//     }
//     return result;
// }

// int main() {
//     string s = "aabbbcccaaa";
//     string compressedString = compress(s);
//     cout << "Compressed String: " << compressedString << endl;

//     return 0;
// }
