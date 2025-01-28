#include<iostream>
#include<vector>
#include<string>
using namespace std;


// here the compression is made characterwise

string compression(string s) {
    int count[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        count[index]++;
    }

    string result;
    for(int i = 0; i < 26; i++) {
        if(count[i] != 0) {
            char c = i + 'a';
            result.push_back(c);
            result += to_string(count[i]);
        }
    }
    return result;
}

int main() {
    string s = "aababca";
    cout << "Original string: " << s << endl;
    string compressed = compression(s);
    cout << "Compressed string: " << compressed << endl;
    return 0;
}
