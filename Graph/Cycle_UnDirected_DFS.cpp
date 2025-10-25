#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int _v) {
        V = _v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Recursive DFS to detect cycle in undirected graph
    bool isCycleUndirDFS(int src, int par, vector<bool> &vis) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (isCycleUndirDFS(v, src, vis)) {
                    return true;  // cycle found in recursive call
                }
            } else if (v != par) {
                return true;  // back edge found → cycle
            }
        }

        return false; // no cycle in this path
    }

    bool containsCycle() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUndirDFS(i, -1, vis)) { // -1 means no parent
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    // Example 1: Graph with a cycle
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0); // creates a cycle

    if (g1.containsCycle())
        cout << "Graph g1 has a cycle" << endl;
    else
        cout << "Graph g1 has no cycle" << endl;

    // Example 2: Graph without a cycle
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    if (g2.containsCycle())
        cout << "Graph g2 has a cycle" << endl;
    else
        cout << "Graph g2 has no cycle" << endl;

    return 0;
}
