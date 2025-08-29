#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }            

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: Only left child
            if (root->left != nullptr && root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Only right child
            if (root->left == nullptr && root->right != nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 4: Two children
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* insertNode(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertNode(root->left, val);
        } else if (val > root->val) {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Insert nodes
    root = sol.insertNode(root, 50);
    root = sol.insertNode(root, 30);
    root = sol.insertNode(root, 70);
    root = sol.insertNode(root, 20);
    root = sol.insertNode(root, 40);
    root = sol.insertNode(root, 60);
    root = sol.insertNode(root, 80);

    cout << "Inorder traversal before deletion:\n";
    sol.inorderTraversal(root);
    cout << "\n";

    // Delete node with value 50
    root = sol.deleteNode(root, 50);

    cout << "Inorder traversal after deletion of 50:\n";
    sol.inorderTraversal(root);
    cout << "\n";

    return 0;
}
