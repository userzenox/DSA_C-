#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
    // Odd length strings can never be balanced
    if (str.length() % 2 != 0) return -1;

    stack<char> st;

    for (char ch : str) {
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{') {
                st.pop();  // valid pair
            } else {
                st.push(ch);  // unmatched closing
            }
        }
    }

    // After processing, stack contains only unmatched braces
    int a = 0, b = 0; // a = count of '{', b = count of '}'

    while (!st.empty()) {
        if (st.top() == '{') a++;
        else b++;
        st.pop();
    }

    // Each pair of same unmatched braces needs one reversal
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string str;
    cout << "Enter a string of curly braces: ";
    cin >> str;

    int result = findMinimumCost(str);

    if (result == -1) {
        cout << "The string cannot be balanced (odd length)." << endl;
    } else {
        cout << "Minimum number of reversals needed: " << result << endl;
    }

    return 0;
}
