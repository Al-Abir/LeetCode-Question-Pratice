#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
    int V;
    list<int>* l;

    // Constructor
    Graph(int _v) {
        V = _v;
        l = new list<int>[V];
    }

    // Edge যোগ করার function
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // undirected হলে
    }

    // Print function
    void PrintGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> ";
            for (int j : l[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph g(5); // ✅ এখানে 5 node এর একটা graph তৈরি হলো

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.PrintGraph(); // ✅ Output দেখা যাবে

    return 0;
}
