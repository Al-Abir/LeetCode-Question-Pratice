#include <iostream>
#include <vector>
#include <algorithm>
#include<list>
#include<queue>

using namespace std;
#define ll long long

class Graph{
    public:
     int V;
     list<int>*l;

     Graph(int v){
        V=v;
        l = new list<int>[V];
     }

     void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
     }
     bool isCycleUndirBFS(int src, vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;
        while(!q.empty()){
             int u = q.front().first;
             int par =  q.front().second;
            q.pop();

            for(int v : l[u]){
                if(!vis[v]){
                   q.push({v,u});
                }else if(v!=par){
                    return true;
                }
            }
        }
        return false;
     }

     bool isCycle(){
        vector<int> vis(V,false);
        for(int i=0; i<V; i++){
             if(!vis[i]){
                if(isCycleUndirBFS(i,vis)){
                    return true;
                }
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
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;
    return 0;
}