#include <iostream>
#include <algorithm> // for max()
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int height(Node* node) {
        if (node == NULL) {
            return -1; // height in terms of edges. Use 0 if height in terms of nodes
        }

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int treeHeight = sol.height(root);
    cout << "Height of the binary tree: " << treeHeight << endl;

    return 0;
}
