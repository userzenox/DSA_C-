#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int,int> diameter(TreeNode* root){
        if (root == NULL) {
            return {0, 0}; // {diameter, height}
        }

        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        int height = max(left.second, right.second) + 1;
        int diameter = max({op1, op2, op3});

        return {diameter, height};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};

int main() {
    // Create a sample binary tree:
    /*
             1
           /   \
          2     3
         / \     
        4   5    
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << result << endl;

    // Clean up memory (optional but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
