// You are given a weighted undirected graph having n vertices and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

// Example:
// Input:
// n = 5, m= 6
// edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
// Output:
// 1 4 3 5
// Explaination:
// Shortest path from 1 to n is by the path 1 4 3 5

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n)

// Constraint:
// 2 <= n <= 105
// 0 <= m <= 105
// 1 <= a, b <= n
// 1 <= w <= 105

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        dist[1] = 0;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int edgeW = it.second;
                if (dis + edgeW < dist[adjnode])
                {
                    dist[adjnode] = dis + edgeW;
                    pq.push({dist[adjnode], adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if (dist[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};