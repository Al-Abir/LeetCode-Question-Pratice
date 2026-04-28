#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
#define ll long long

vector<int> toSort(int V,vector<vector<int>> adj){
    vector<int> indree(V,0);
   
    //1 indree calculate;
    for(int u=0; u<V; u++){
          for(int v: adj[u]){
             indree[v]++;
          }
    }

    queue<int> q;

    // 2. push all 0 degre node 
    for(int i=0; i<V;i++){
        if(indree[i]==0){
            q.push(i);
        }
    }

    //3. BFS trevers

    vector<int> ans;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int neigh : adj[node]){
            
            indree[neigh]--;

            if(indree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    return ans;

}

int main() {
   

    int V,E;
    cin>>V>>E;
    
    vector<vector<int>> adj(V);

    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); // directed edge u->v;
    }

    vector<int> result = toSort(V,adj);



    //cycle check

    if(result.size()!=V){
        cout << "Cycle detected! Topological sort not possible\n";
    }else{
        cout << "Topological Order: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}