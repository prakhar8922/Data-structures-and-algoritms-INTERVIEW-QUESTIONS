// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

// Example 1:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
// Output: 8
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
// Example 2:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
// Output: 6
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
// Example 3:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
// Output: 0

// Constraints:

// 1 <= n <= 105
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai < bi <= n - 1
// fromi < toi
// hasApple.length == n

class Solution
{
private:
    int dfs(int currnode, int parent, vector<vector<int>> &adj, vector<bool> &hasApple)
    {
        int totaltime = 0, childtime = 0; // totalTime: This variable keeps track of the total time spent collecting all apples in the tree.
        // childTime: This variable keeps track of the time spent collecting all apples in the subtree of the current vertex.
        for (auto child : adj[currnode])
        {
            if (child == parent) // childTime > 0 indicates subtree of child has apples. Since the root node of the
                continue;        // subtree does not contribute to the time, even if it has an apple, we have to check it
                                 // independently.

            childtime = dfs(child, currnode, adj, hasApple);
            if (childtime or hasApple[child])
                totaltime += childtime + 2;
        }
        return totaltime;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};