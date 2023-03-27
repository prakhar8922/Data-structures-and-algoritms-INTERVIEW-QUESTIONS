// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// Medium
// 1.1K
// 26
// Companies
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.

// Example 1:

// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
// Example 2:

// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.

// Constraints:

// 1 <= n <= 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.

class Solution
{
public:
    // DFS function to count the number of nodes in a connected component
    int dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        int count = 1; // initialize the count to 1 for the starting node
        // loop through all unvisited neighbors of the starting node
        for (auto &adjnode : adj[node])
        {
            if (!vis[adjnode])
            {
                count += dfs(adjnode, adj, vis); // recursively count the number of nodes
            }
        }
        return count; // return the total count of nodes in the component
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        long long ans = 0;
        vector<vector<int>> adj(n);

        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        long long countNodes = 0;
        long long remainingNodes = n;
        // loop through all nodes and count the number of nodes in each connected component
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]) // if the node is unvisited
            {
                countNodes = dfs(i, adj, vis); // count the number of nodes in the connected component
                ans += countNodes * (remainingNodes - countNodes);
                remainingNodes -= countNodes; // update the remaining nodes
            }
        }
        return ans;
    }
};
