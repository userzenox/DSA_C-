#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of a binary tree node
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

// Solution class with bottomView function
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans; 
        if (root == NULL) return ans;

        map<int, int> hdNodeMap;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Overwrite for bottom view
            hdNodeMap[hd] = node->data;

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (const auto& [hd, val] : hdNodeMap) {
            ans.push_back(val);
        }

        return ans;
    }
};

// Main function to test the bottom view
int main() {
    /*
        Sample Tree:
                20
               /  \
             8     22
            / \      \
           5   3      25
              / \
             10 14

        Bottom view: 5 10 3 14 25
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
