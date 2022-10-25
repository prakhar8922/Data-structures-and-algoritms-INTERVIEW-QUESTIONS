#include <iostream>
using namespace std;

int main()
{
    int n, m; // n are the  number of nodes and m is the number of edges present in the graph
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1-based indexing,   list to store the edges and nodes connected,  for 0 based indexing adj[n]
    for (int i = 0; i < m; i++)
    {
        int u, v; // signifies U node is connected to V node
        cin >> u >> v;
        // for undireted graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}