#include <iostream>
#include <algorithm>
using namespace std;

// Definition of the Node
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
    int height(Node* root) {
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

    int diameter(Node* root) {
        if(root == NULL){
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + 1 + height(root->right);
        int ans = max(op1, max(op2, op3));
        return ans - 1; // diameter in terms of number of edges
    }
};

int main() {
    // Manually constructing the binary tree
    /*
              1
             / \
            2   3
           / \     
          4   5    
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int result = sol.diameter(root);
    cout << "Diameter of the binary tree is: " << result << endl;

    return 0;
}
