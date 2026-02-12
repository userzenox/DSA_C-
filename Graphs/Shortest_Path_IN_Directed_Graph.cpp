#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Graph{
public:  
    unordered_map<int , list<pair<int,int>>> adj;
    
    void addEdge(int u, int v , int weight){
         adj[u].push_back({v, weight});   // cleaner brace init
    }
    
    void printAdj() {
        for(auto i : adj) {
            cout << i.first << " -> ";
            for(auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int , bool> &vis, stack<int> &topo){
         vis[node]  = true;

         for(auto neigh: adj[node]){
            if(!vis[neigh.first]){
                 dfs(neigh.first, vis, topo);
            }
         }
         topo.push(node);
    }
};

int main() {

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n = 6;
    unordered_map<int , bool> visited;
    stack<int> s;

    // Step 1: Topological Sort
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    // Step 2: Initialize distance
    int src  = 1;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Step 3: Relax edges in topo order
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top] != INT_MAX){
            for(auto i: g.adj[top]){
                
                int d = dist[top] + i.second;
                
                if(dist[i.first] > d){
                     dist[i.first] = d;   // ✅ fixed
                }
            }
        }
    }

    // Step 4: Print shortest distances
    cout << "\nShortest distances from source " << src << ":\n";
    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX)
            cout << "Node " << i << " : INF\n";
        else
            cout << "Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}
