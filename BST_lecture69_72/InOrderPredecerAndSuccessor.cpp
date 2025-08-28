#include <iostream>
#include <vector>
using namespace std;

// Definition for BST Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper to find the maximum node in left subtree (inorder predecessor)
    Node* rightMost(Node* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    // Helper to find the minimum node in right subtree (inorder successor)
    Node* leftMost(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // Finds predecessor and successor of key and returns them in a vector
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* curr = root;

        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                if (curr->left)
                    pre = rightMost(curr->left);
                if (curr->right)
                    suc = leftMost(curr->right);
                break;
            }
        }

        return {pre, suc};
    }
};

// Function to insert node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main() {
    /* Constructed BST:
               20
              /  \
             8   22
            / \
           4  12
              / \
             10 14
    */
    vector<int> nodes = {20, 8, 22, 4, 12, 10, 14};
    Node* root = nullptr;
    for (int x : nodes)
        root = insert(root, x);

    int key = 10;
    Solution sol;
    vector<Node*> res = sol.findPreSuc(root, key);

    cout << "Predecessor: ";
    if (res[0]) cout << res[0]->data << "\n";
    else cout << "None\n";

    cout << "Successor: ";
    if (res[1]) cout << res[1]->data << "\n";
    else cout << "None\n";

    return 0;
}
