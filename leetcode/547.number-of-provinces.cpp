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
// @lc code=end
