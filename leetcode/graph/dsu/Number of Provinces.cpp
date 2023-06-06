// 547. Number of Provinces
// Medium
// 8K
// 301
// Companies
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]
// Accepted
// 653.6K
// Submissions
// 1M
// Acceptance Rate
// 64.5%

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)

        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void Union(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = parent[ulp_v];
        }
        else
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u];
        }
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), ans = 0;
        DSU ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j and isConnected[i][j] == 1)
                {
                    int p1 = ds.findUPar(i);
                    int p2 = ds.findUPar(j);
                    if (p1 != p2)
                    {
                        ans++;
                        ds.Union(i, j);
                    }
                }
            }
        }
        return n - ans;
    }
};