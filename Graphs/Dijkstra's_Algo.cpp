#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // Step 1: Create adjacency list
    vector<vector<pair<int,int>>> adj(vertices);

    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // Remove if graph is directed
    }

    // Step 2: Distance array
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Step 3: Min-heap (distance, node)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, source});

    // Step 4: Dijkstra Algorithm
    while(!pq.empty()) {

        pair<int,int> top = pq.top();
        pq.pop();

        int nodeDist = top.first;
        int node = top.second;

        // Skip outdated entries
        if(nodeDist > dist[node]) continue;

        for(auto neighbour : adj[node]) {

            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(dist[adjNode] > nodeDist + weight) {

                dist[adjNode] = nodeDist + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> vec(edges, vector<int>(3));

    for(int i = 0; i < edges; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }

    int source;
    cin >> source;

    vector<int> result = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for(int i = 0; i < vertices; i++) {
        if(result[i] == INT_MAX)
            cout << "Node " << i << " : INF\n";
        else
            cout << "Node " << i << " : " << result[i] << "\n";
    }

    return 0;
}
