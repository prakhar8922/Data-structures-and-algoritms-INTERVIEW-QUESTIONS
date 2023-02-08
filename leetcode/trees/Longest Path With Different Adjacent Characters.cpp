// You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

// You are also given a string s of length n, where s[i] is the character assigned to node i.

// Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

// Example 1:

// Input: parent = [-1,0,0,1,1,2], s = "abacbe"
// Output: 3
// Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
// It can be proven that there is no longer path that satisfies the conditions.
// Example 2:

// Input: parent = [-1,0,0,0], s = "aabc"
// Output: 3
// Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.

// Constraints:

// n == parent.length == s.length
// 1 <= n <= 105
// 0 <= parent[i] <= n - 1 for all i >= 1
// parent[0] == -1
// parent represents a valid tree.
// s consists of only lowercase English letters.

class Solution
{
private:
    int dfs(int currnode, vector<vector<int>> &adj, string &s, int &ans)
    {
        int currmax = 0, secondmax = 0;
        for (auto adjnode : adj[currnode])
        {
            int result = dfs(adjnode, adj, s, ans);
            if (s[currnode] == s[adjnode])
                continue; // no two same ch cant be adjacent
            if (result > currmax)
            {
                secondmax = currmax;
                currmax = result;
            }
            else if (result > secondmax)
            {
                secondmax = result;
            }
        }
        ans = max(ans, 1 + currmax + secondmax);
        return 1 + currmax;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        int ans = 1;
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i); // adjacency list
        }
        dfs(0, adj, s, ans);
        return ans;
    }
};