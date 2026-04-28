#include <bits/stdc++.h>
using namespace std;

// DFS function
bool dfs(int node, vector<vector<int>>& adj, 
         vector<bool>& vis, vector<bool>& pathVis) {

    vis[node] = true;
    pathVis[node] = true;

    for (auto neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (dfs(neighbor, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[neighbor]) {
            return true; // 🔥 cycle found
        }
    }

    pathVis[node] = false; // backtrack
    return false;
}

// Main cycle detection function
bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    vector<bool> pathVis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 6; // number of nodes

    vector<vector<int>> adj(V);

    // Directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    // adj[3].push_back(0);
     adj[0].push_back(4);
     adj[4].push_back(5);
     adj[5].push_back(0);
  

    if (isCycle(V, adj))
        cout << "Cycle Detected\n";
    else{

        cout << "No Cycle\n";
    }

    return 0;
}