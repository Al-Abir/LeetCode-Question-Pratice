#include <iostream>
#include <list>
#include<queue>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Add edge (undirected)
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Print graph
    void PrintEdge() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int neighbor : l[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(){
        queue<int>q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0]=true;
       while (q.size()>0)
       {
        /* code */
        int src = q.front();
        q.pop();

        cout<<src<<" ";

        for(int neigh: l[src]){
           if(!vis[neigh]){
               vis[neigh]=true;
               q.push(neigh);
           }
        }
       }
       
       
    }

  
    void dfs(){
        
        vector<bool> vis(V,false);
        for(int i=0;i<V; i++){
             if(!vis[i]){
                 dfsHelper(i,vis);
             }
        }
    }
 void dfsHelper(int src, vector<bool> &vis){
   
    cout<<src<<" ";
    vis[src]=true;

    for(int neigh : l[src]){
        if(!vis[neigh]){
            dfsHelper(neigh,vis);
        }
    }
}
};



void solve() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.PrintEdge();
    g.bfs();
     cout<<endl;
    g.dfs();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}