#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to check if two trees are identical
bool isIdentical(Node* r1, Node* r2) {
    // Both trees are empty
    if (r1 == NULL && r2 == NULL) {
        return true;
    }

    // One of the trees is empty
    if (r1 == NULL || r2 == NULL) {
        return false;
    }

    // Check current data and recurse on left and right subtrees
    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

// Main function
int main() {
    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isIdentical(root1, root2)) {
        cout << "The trees are identical.\n";
    } else {
        cout << "The trees are NOT identical.\n";
    }

    return 0;
}
