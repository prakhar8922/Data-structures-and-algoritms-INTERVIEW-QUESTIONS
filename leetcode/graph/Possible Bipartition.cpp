// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4] and group2 [2,3].
// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false

// Constraints:

// 1 <= n <= 2000
// 0 <= dislikes.length <= 104
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= n
// ai < bi
// All the pairs of dislikes are unique.

class Solution
{

private:
    bool dfs(int node, int nodecolor, vector<vector<int>> &adj, vector<int> &color)
    {
        color[node] = nodecolor; // colors the node with current nodecolor
        for (auto adjnode : adj[node])
        {
            if (color[adjnode] == color[node]) // if two adjacent nodes have same color return false
                return false;
            if (color[adjnode] == -1)
            {                                                   // if node is not coloured then colour it by calling dfs
                if (!dfs(adjnode, 1 - color[node], adj, color)) // if the dfs return false then return false
                    return false;
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(n + 1);
        for (auto it : dislikes)
        { // adjaceny list showing the edges between nodes
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n + 1, -1); // 0 denotes red and 1 denotes black
        for (int i = 1; i <= n; i++)
        { // for multi component graphs
            if (color[i] == -1)
            {
                if (!dfs(i, 0, adj, color)) // if the dfs return false than return false
                    return false;
            }
        }
        return true;
    }
};
