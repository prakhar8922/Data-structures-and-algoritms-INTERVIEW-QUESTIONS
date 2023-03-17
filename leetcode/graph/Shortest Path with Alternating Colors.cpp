// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

// Example 1:

// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]
// Example 2:

// Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
// Output: [0,1,-1]

// Constraints:

// 1 <= n <= 100
// 0 <= redEdges.length, blueEdges.length <= 400
// redEdges[i].length == blueEdges[j].length == 2
// 0 <= ai, bi, uj, vj < n

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> dist(n, -1);
        vector<pair<int, int>> adj[n]; // The adjacency list is an array of pairs of integers, where each pair represents a node and its color (1 for red, 2 for blue).
        for (auto &it : redEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        for (auto &it : blueEdges)
        {
            adj[it[0]].push_back({it[1], 2});
        }
        vector<vector<bool>> vis(n, vector<bool>(3, false)); // This line creates a 2D vector vis of size n x 3, where each element vis[i][j] is a boolean indicating whether node i has been visited using color j (1 for red, 2 for blue).
        queue<vector<int>> q;
        q.push({0, 0, 0}); //{node,steps,prev col}
        dist[0] = 0;       // These lines set the distance of node 0 to 0, and mark it as visited using both red and blue colors.
        vis[0][1] = vis[0][2] = true;
        while (!q.empty())
        {
            int node = q.front()[0];
            int steps = q.front()[1];
            int prev_color = q.front()[2];
            q.pop();
            for (auto &it : adj[node])
            {
                auto adjnode = it.first;
                auto color = it.second;
                if (color == prev_color)
                    continue;
                if (!vis[adjnode][color])
                {
                    vis[adjnode][color] = true;
                    if (dist[adjnode] == -1)
                    {
                        dist[adjnode] = 1 + steps;
                    }
                    q.push({adjnode, 1 + steps, color});
                }
            }
        }
        return dist;
    }
};