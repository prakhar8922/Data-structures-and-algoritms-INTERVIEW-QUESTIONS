// 1319. Number of Operations to Make Network Connected
// Medium
// 3.8K
// 49
// Companies
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto adjnode : adj[node])
        {
            if (!vis[adjnode])
            {
                dfs(adjnode, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (n - 1 > connections.size())
            return -1; // A connected graph with the fewest edges is a tree with n - 1 edges connecting n nodes. So, in order for a graph with n nodes to be connected, the graph must have at least n - 1 edges. It is impossible to connect a graph that has fewer than n - 1 edges. Otherwise, it is always possible to connect the graph.
        vector<vector<int>> adj(n + 1);
        for (auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0; // number of connected components
        // Let's say that our graph has c different connected components. If we have at least n - 1 edges, then some components must have "extra" edges. We would replace these edges to connect all the components together.

        // How many edges do we need to replace? Imagine that each connected component is simplified to just a single node. Now, to connect this simplified graph, we know we need a minimum of c - 1 edges. Therefore, the answer is c - 1. We can imagine these c - 1 edges connecting the original connected components.

        // So, if there are at least n - 1 edges, the solution is the number of connected components minus one. Otherwise, we return -1.
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans - 1;
    }
};