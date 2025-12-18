#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public: 
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(TrieNode* root, string word) {
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insert(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insert(root, word);
    }
    
private:
    // Helper DFS to get all words from current node
    void getsuggestions(TrieNode* root, vector<string>& temp, string prefix) {
        if(root->isTerminal) {
            temp.push_back(prefix);
        }
        
        for(int i = 0; i < 26; i++) {
            if(root->children[i]) {
                getsuggestions(root->children[i], temp, prefix + char('a' + i));
            }
        }
    }
    
public:
    vector<vector<string>> getsuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(char ch : str) {
            prefix += ch;  // Fixed: add actual char
            
            TrieNode* curr = prev->children[ch - 'a'];  // Fixed: use prev
            if(curr == NULL) {
                break;
            }
            
            vector<string> temp;
            getsuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie* t = new Trie();
    for(string contact : contactList) {
        t->insertWord(contact);
    }
    return t->getsuggestions(queryStr);
}

int main() {
    int n;
    cin >> n;
    vector<string> contactList(n);
    for(int i = 0; i < n; i++) {
        cin >> contactList[i];
    }
    
    string queryStr;
    cin >> queryStr;
    
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);
    
    cout << "Suggestions for each prefix:" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << "After '" << queryStr.substr(0, i+1) << "': ";
        for(string word : result[i]) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
