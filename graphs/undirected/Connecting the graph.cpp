// You are given a graph with n vertices and m edges.

// You can remove one edge from anywhere and add that edge between any two vertices in one operation.

// Find the minimum number of operation that will be required to make the graph connected.

// If it is not possible to make the graph connected, return -1.

// Example 1:

// Input:
// n=4
// m=3
// Edge=[ [0, 1] , [0, 2] , [1, 2] ]

// Output:
// 1

// Explanation:
// Remove edge between vertices 1 and 2 and add between vertices 1 and 3.

// Example 2:

// Input:
// n=6
// m=5
// Edge=[ [0,1] , [0,2] , [0,3] , [1,2] , [1,3] ]

// Output:
// 2

// Explanation:
// Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)

// Your Task:

// You don't need to read or print anything. Your task is to complete the function Solve() which takes an integer n denoting no. of vertices and a matrix edge[][] denoting the the edges of graph and return the minimum number of operation to connect a graph

// Constraints:

// 1<=n<=105
// 0<=m<=105
// 0<=edge[i][0],edge[i][1]

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
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
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        DisjointSet ds(n);
        int cntExt = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUpar(u) == ds.findUpar(v))
                cntExt++;
            else
                ds.unionBySize(u, v);
        }
        int cntC = 0; // connected components
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                cntC++;
        }
        int ans = cntC - 1;
        return cntExt >= ans ? ans : -1;
    }
};