#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // undirected
    }

    // DFS using stack to detect cycle
    bool isCycleUndirDFS(int src, vector<int> &vis) {
        stack<pair<int,int>> st; // {node, parent}
        st.push({src, -1});
        vis[src] = true;

        while(!st.empty()) {
            auto [u, par] = st.top();
            st.pop();

            for(int v : l[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    st.push({v, u});
                } else if(v != par) {
                    // visited neighbor which is not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle() {
        vector<int> vis(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycleUndirDFS(i, vis)) return true;
            }
        }

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2); // cycle: 0-1-2-0
    g.addEdge(3,4);

    cout << g.isCycle() << endl; // 1 = cycle present, 0 = no cycle

    return 0;
}
