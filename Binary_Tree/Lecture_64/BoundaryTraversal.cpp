#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
public:
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
    void leftTraversal(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        ans.push_back(root->data);
        if (root->left)
            leftTraversal(root->left, ans);
        else
            leftTraversal(root->right, ans);
    }

    void leafTraversal(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }

    void rightTraversal(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        if (root->right)
            rightTraversal(root->right, ans);
        else
            rightTraversal(root->left, ans);
        ans.push_back(root->data);  // reverse order
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if (!(root->left == NULL && root->right == NULL))
            ans.push_back(root->data); // root is not a leaf

        leftTraversal(root->left, ans);
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        rightTraversal(root->right, ans);

        return ans;
    }
};

// Helper to build a basic binary tree
Node* buildSampleTree() {
    // Example tree:
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
    return root;
}

int main() {
    Node* root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
