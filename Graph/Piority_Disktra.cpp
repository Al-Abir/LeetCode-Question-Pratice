#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int> // {distance, vertex}

void dijkstra(int n, vector<vector<pii>> &adj, int src) {
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    pq.push({0, src});

    while(!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we already found a shorter path to u, skip
        if(dist > distance[u]) continue;

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    // Print distances
    for(int i=0; i<n; i++) {
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    vector<vector<pii>> adj(n); // adjacency list

    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    dijkstra(n, adj, 0); // source = 0

    return 0;
}
