#include <iostream>
#include <utility>
using namespace std;

// Tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Fast utility function to check Sum Tree
pair<bool, int> isSumTreeFast(Node* root) {
    // base case
    if (root == NULL) {
        return make_pair(true, 0);
    }

    if (root->left == NULL && root->right == NULL) {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (left && right && condn) {
        ans.first = true;
        ans.second = 2 * root->data;
    } else {
        ans.first = false;
        ans.second = 0;
    }

    return ans;
}

// Wrapper function
bool isSumTree(Node* root) {
    return isSumTreeFast(root).first;
}

// Main function
int main() {
    /*
         26
        /  \
      10    3
     /  \     \
    4    6     3
    */

    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if (isSumTree(root)) {
        cout << "The tree is a Sum Tree.\n";
    } else {
        cout << "The tree is NOT a Sum Tree.\n";
    }

    return 0;
}
