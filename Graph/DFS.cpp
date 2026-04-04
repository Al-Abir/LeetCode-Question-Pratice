#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfsHelper(int src, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& result){
        vis[src] = true;
        result.push_back(src);

        for(int neigh : adj[src]){
            if(!vis[neigh]){
                dfsHelper(neigh, adj, vis, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        vector<int> result;

        dfsHelper(0, adj, vis, result);

        return result;
    }
};

int main() {
    int V;
    cin >> V;  // number of nodes

    vector<vector<int>> adj(V);
    
    for(int i = 0; i < V; i++) {
        int size;
        cin >> size;  // number of neighbors for node i
        adj[i].resize(size);
        for(int j = 0; j < size; j++) {
            cin >> adj[i][j];
        }
    }

    Solution sol;
    vector<int> dfsTraversal = sol.dfs(adj);

    // print DFS result
    for(int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}