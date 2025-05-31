#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

// Definition for a binary tree node.
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
    pair<bool, int> checkbalance(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};
        }

        pair<bool, int> left = checkbalance(root->left);
        pair<bool, int> right = checkbalance(root->right);

        bool leftans = left.first;
        bool rightans = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        ans.first = leftans && rightans && diff;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return checkbalance(root).first;
    }
};

int main() {
    // Example 1: Balanced tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    Solution sol;
    cout << "Is tree 1 balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Example 2: Unbalanced tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);

    cout << "Is tree 2 balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
