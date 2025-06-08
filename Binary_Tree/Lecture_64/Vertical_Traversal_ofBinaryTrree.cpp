#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Define the structure for a binary tree node
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
    // Function to perform vertical order traversal
    vector<vector<int>> verticalOrder(Node *root) {
        // This map will store: horizontal distance -> level -> list of node values
        map<int, map<int, vector<int>>> nodes;

        // Queue for BFS traversal: stores (Node*, (horizontal distance, level))
        queue<pair<Node*, pair<int, int>>> q;

        // Final result
        vector<vector<int>> ans;

        // Base case: empty tree
        if (root == NULL) {
            return ans;
        }

        // Start BFS with root at hd=0 and level=0
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            // Get front element from queue
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;    // horizontal distance
            int lvl = temp.second.second;  // vertical level (depth)

            // Store the node value in the map
            nodes[hd][lvl].push_back(frontNode->data);

            // If left child exists, push it into queue with hd-1 and level+1
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            // If right child exists, push it into queue with hd+1 and level+1
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        // Traverse the map and prepare the final answer
        for (auto& i : nodes) { // horizontal distance sorted
            vector<int> col;
            for (auto& j : i.second) { // levels sorted
                for (int val : j.second) { // values at that level
                    col.push_back(val);
                }
            }
            ans.push_back(col); // Add the column to the result
        }

        return ans;
    }
};

// Helper function to build a sample binary tree
Node* buildSampleTree() {
    /*
        Constructing this binary tree:
        
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

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
    // Build the tree
    Node* root = buildSampleTree();

    // Create Solution object and call verticalOrder
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);

    // Print the result
    cout << "Vertical Order Traversal:\n";
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
