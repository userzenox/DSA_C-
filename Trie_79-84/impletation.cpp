
#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
       char data;
       TrieNode* children[26];
       bool isTerminal ;
       
       TrieNode(char ch){
          data = ch;
          
          for(int i=0; i<26; i++){
             children[i] = NULL;
          }

          isTerminal = false;
       }
};

class Trie{
    public: 
      TrieNode* root;

       Trie() {
        root = new TrieNode('\0');  // ✅ initialize root
    }
     
      void insert(TrieNode* root, string word ){
          
        //base call
        if( word.size() == 0 ){
            root-> isTerminal = true;
            return;
        }

         int index = word[0] - 'a';
          TrieNode* child;

         if(root->children[index] != NULL ){
              child = root->children[index];
         }
         else{
             child = new TrieNode(word[0]);
             root->children[index] = child;
         }

         insert(child, word.substr(1));
      }

     void insertWord( string word){
          insert(root, word);
     }
};

int main(){
   
    Trie * t = new Trie();
    t-> insertWord("abcd"); 
    return 0;
}
