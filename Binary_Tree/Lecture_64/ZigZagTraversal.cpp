#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            
            for(int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();
                
                // Normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;
                
                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            
            for (int i = 0; i < size; i++) {
                result.push_back(ans[i]);
            }

            // Flip direction
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

int main() {
    // Create a binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    cout << "ZigZag Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}
