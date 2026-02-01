#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
      
    vector<int> ans;
    vector<bool> visited(n, false);
    queue<int> q;

    // Start from vertex 0
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {

        int t = q.front();
        q.pop();

        ans.push_back(t);

        for(int i = 0; i < adj[t].size(); i++) {
            int neighbor = adj[t][i];

            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    // Create adjacency list
    vector<vector<int>> adj(n);

    // Read directed edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // Directed graph
    }

    vector<int> result = bfsTraversal(n, adj);

    // Print BFS traversal
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
