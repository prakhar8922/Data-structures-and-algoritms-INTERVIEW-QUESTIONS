/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
private:
    void dfs(int node, vector<int> adjlst[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adjlst[node])
        {
            if (!vis[it])
            {
                dfs(it, adjlst, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &adj)
    {
        int v = adj.size();    // no of vertices
        vector<int> adjlst[v]; // vector having v size

        // to change adjacency matrix to list
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                // self nodes are not considered
                if (adj[i][j] == 1 and i != j)
                {
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        int vis[201] = {0};
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adjlst, vis);
            }
        }
        return count;
    }
};

@lc code = end

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
        {
            return node;
        }
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
    int numProvinces(vector<vector<int>> adj, int v)
    {
        // code here
        DisjointSet ds(v);
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};