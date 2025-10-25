#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<list>
#include<stack>
using namespace std;
#define ll long long

class Graph{
    public:
    int V;
    list<int> *l;
   Graph(int _v){
     V=_v;
     l= new list<int>[V];
   }

   void addEdge(int u,int v){
     l[u].push_back(v);
     l[v].push_back(u);
   }

   void PrintGraph(){
    for(int i=0; i<V; i++)
    {
         cout << "Node " << i << " -> ";
        for(int j:l[i]){
             cout<<j<<" ";
        }
        cout<<endl;
    }
}

   void bfs(){
    queue<int> q;
    vector<bool>vis(V,false);
    q.push(0);
    vis[0]=true;
    while( q.size()>0){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        // all negihobors
        for(int v : l[u]){
             if(!vis[v]){
                 vis[v]=true;
                 q.push(v);
             }
        }
    }
    cout<<endl;
   
  }
  void dfsHelper(int u, vector<bool> &vis) {
    vis[u] = true;
    cout << u << " ";

    for (int v : l[u]) {
        if (!vis[v]) {
            dfsHelper(v, vis);
        }
    }
}

void dfs() {
    vector<bool> vis(V, false); // ✅ Correct initialization

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsHelper(i, vis); // ✅ Correct variable
        }
    }
    cout<<endl;
}



//============stack using dfs ======
 void dfsIterative() {
        vector<bool> vis(V, false);
        stack<int> st;

        st.push(0);
        vis[0] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            cout << u << " ";

            // Important: adjacency list traverse
            for (int v : l[u]) {
                if (!vis[v]) {
                    st.push(v);
                    vis[v] = true;
                }
            }
        }

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 4);

    g.PrintGraph();
    cout<<"BFS"<<endl; 
    g.bfs();

    cout<<"DFS"<<endl;
    g.dfs();
    cout<<"iterative"<<endl;
    g.dfsIterative();

    return 0;
}