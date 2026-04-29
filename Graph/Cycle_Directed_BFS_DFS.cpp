#include <bits/stdc++.h>
using namespace std;

// DFS Helper (Directed Cycle Detection)
bool dfsHelper(int u, vector<bool>& vis, vector<bool>& recStack, vector<vector<int>>& adj){
    
    vis[u] = true;
    recStack[u] = true;

    for(auto v : adj[u]){
        if(!vis[v]){
            if(dfsHelper(v, vis, recStack, adj)){
                return true;
            }
        }
        else if(recStack[v]){
            return true; // cycle found
        }
    }

    recStack[u] = false;
    return false;
}

// DFS Cycle Detection
bool dfs(vector<vector<int>>& adj){
    int n = adj.size();
    
    vector<bool> vis(n, false);
    vector<bool> recStack(n, false);

    for(int i = 1; i < n; i++){   // 1-based
        if(!vis[i]){
            if(dfsHelper(i, vis, recStack, adj)){
                return true; // cycle exists
            }
        }
    }
    return false; // no cycle
}


//BFS (Kahn’s Algorithm - Topological Sort + Cycle Detection)
bool topoSort(vector<vector<int>>& adj){

    int V = adj.size();

    vector<int> indegree(V, 0);

    // indegree calculate (1-based)
    for(int u = 1; u < V; u++){
        for(auto v : adj[u]){
            indegree[v]++;
        }
    }

    queue<int> q;

    // push nodes with indegree 0
    for(int i = 1; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto v : adj[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    // if all nodes processed → no cycle
    return cnt == (V - 1);
}


int main() {
    
    int N;
    cin >> N;

    //1-based graph
    vector<vector<int>> adj(N + 1);

    // example graph (cycle: 3 → 4 → 5 → 3)
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);

    cout << "DFS Traverse\n";
    bool ans = dfs(adj);
    cout << ans << endl;   // true = cycle

    cout << "BFS Traverse\n";
    bool ans2 = topoSort(adj);
    cout << ans2 << endl;  // false = cycle

    return 0;
}