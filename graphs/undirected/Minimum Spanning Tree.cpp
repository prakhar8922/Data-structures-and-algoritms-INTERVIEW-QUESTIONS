// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// Example 1:

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1

// Output:
// 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Example 2:

// Input:
// 2 1
// 0 1 5

// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.

// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

// In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.

// Expected Time Complexity: O(ElogV).
// Expected Auxiliary Space: O(V2).

// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// Graph is connected and doesn't contain self loops & multiple edges.

// kruskal algo
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    { // findUpar=find ultimate parent of node
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u); // ulp_u=ultimate parent of u
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node, adjnode}});
            }
        }
        DisjointSet ds(v);
        sort(edges.begin(), edges.end());
        int mwt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mwt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mwt;
    }
};

// PRIMS ALGO
// class Solution
// {
// public:
//     // Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int v, vector<vector<int>> adj[])
//     {
//         // code here
//         int sum = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> vis(v, 0);
//         pq.push({0, 0}); // weight and node
//         while (!pq.empty())
//         {
//             int wt = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
//             if (vis[node] == 1)
//                 continue;  // if the node has already been visited
//             vis[node] = 1; // if the node has not been visited
//             sum += wt;
//             for (auto it : adj[node])
//             {
//                 int adjnode = it[0];
//                 int edW = it[1];
//                 if (!vis[adjnode])
//                 {
//                     pq.push({edW, adjnode});
//                 }
//             }
//         }
//         return sum;
//     }
// };