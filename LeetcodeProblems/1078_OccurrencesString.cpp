#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> third;
        string word;
        vector<string> words;
        text += ' '; 

        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += text[i];
            }
        }

        for (int i = 0; i < words.size() - 2; ++i) {
            if (words[i] == first && words[i + 1] == second) {
                third.push_back(words[i + 2]);
            }
        }

        return third;
    }
};

int main() {
    Solution solution;
    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";
    
    vector<string> result = solution.findOcurrences(text, first, second);
    
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
