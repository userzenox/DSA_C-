#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Binary Tree Node structure
struct Node {
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
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node *root) {
        vector<int> ans; 
        if (root == NULL) return ans;

        map<int, int> m; // hd -> node data
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // If this HD is being seen for the first time
            if (m.find(hd) == m.end()) {
                m[hd] = frontNode->data;
            }

            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        for (const auto& p : m) {
            ans.push_back(p.second);
        }

        return ans;
    }
};

// Function to create a simple binary tree for demonstration
Node* createSampleTree() {
    /*
            1
           / \
          2   3
           \   \
            4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    return root;
}

int main() {
    Node* root = createSampleTree();
    Solution sol;
    
    vector<int> result = sol.topView(root);
    
    cout << "Top View of the Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
