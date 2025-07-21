#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == n1 || root->data == n2) {
            return root;
        }

        Node* leftans = lca(root->left, n1, n2);
        Node* rightans = lca(root->right, n1, n2);

        if (leftans != NULL && rightans != NULL) {
            return root;
        }
        else if (leftans != NULL) {
            return leftans;
        }
        else {
            return rightans;
        }
    }
};

// Function to build a sample binary tree
/*
          1
         / \
        2   3
       / \   \
      4   5   6
*/
Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildTree();
    Solution sol;
    
    int n1 = 4, n2 = 5;
    Node* ancestor = sol.lca(root, n1, n2);
    if (ancestor != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found for " << n1 << " and " << n2 << endl;
    }

    // Trying another pair
    n1 = 4, n2 = 6;
    ancestor = sol.lca(root, n1, n2);
    if (ancestor != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found for " << n1 << " and " << n2 << endl;
    }

    return 0;
}
