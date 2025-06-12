#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Binary tree node definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Your solution class
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int , int > m;
        queue <pair<Node*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair <Node* ,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int level = temp.second;
            
            if(m.find(level) == m.end()){
                m[level] = frontNode->data;
            }
          
            if(frontNode->left){
                q.push(make_pair(frontNode->left, level+1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, level+1));
            }
        }
        
        for(const auto&p: m){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};

// Helper to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    /*
        Constructing the following tree:
                1
              /   \
             2     3
              \   / \
               4 5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.leftView(root);
    
    cout << "Left View: ";
    printVector(result);

    return 0;
}

