#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

// DFS function to detect cycle
bool isCyclicDFS(unordered_map<int, list<int>> &adj,
                 unordered_map<int, bool> &visited,
                 unordered_map<int, bool> &dfsVisited,
                 int node) 
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node]) 
    {
        // If neighbour not visited → recurse
        if (!visited[neighbour]) 
        {
            bool cycleDetected = isCyclicDFS(adj, visited, dfsVisited, neighbour);
            if (cycleDetected)
                return true;
        }
        // If neighbour is in current DFS path → cycle
        else if (dfsVisited[neighbour]) 
        {
            return true;
        }
    }

    // Backtracking step
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) 
{
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (auto edge : edges) 
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Check for cycle in each component
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            if (isCyclicDFS(adj, visited, dfsVisited, i))
                return true;
        }
    }

    return false;
}

int main() 
{
    int n = 4;

    // Example: 0 → 1 → 2 → 3 → 1 (Cycle exists)
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    if (detectCycleInDirectedGraph(n, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
