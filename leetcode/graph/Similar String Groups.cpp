// 839. Similar String Groups
// Hard
// 2.1K
// 208
// Companies
// Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

// Example 1:

// Input: strs = ["tars","rats","arts","star"]
// Output: 2
// Example 2:

// Input: strs = ["omv","ovm"]
// Output: 1

// Constraints:

// 1 <= strs.length <= 300
// 1 <= strs[i].length <= 300
// strs[i] consists of lowercase letters only.
// All words in strs have the same length and are anagrams of each other.
// Accepted
// 105.2K
// Submissions
// 193.9K
// Acceptance Rate
// 54.2%

class Solution
{
public:
    // This function checks if two strings s1 and s2 are similar or not.
    // Two strings are considered similar if they have exactly 2 characters different or no characters different.
    bool isSimilar(string s1, string s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;
            }
        }
        return diff == 0 or diff == 2;
    }

    // This function performs depth-first search on the adjacency list of the graph.
    // It takes the current node, the adjacency list, and a boolean array visit as input.
    // It marks the current node as visited and recursively calls dfs on all unvisited neighbors.
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visit)
    {
        visit[node] = true;
        for (auto adjnode : adj[node])
        {
            if (!visit[adjnode])
            {
                dfs(adjnode, adj, visit);
            }
        }
    }

    // This function takes a vector of strings as input and returns the number of groups of similar strings.
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();

        // Create an adjacency list for the graph, where each string is a node and two nodes are connected by an edge if they are similar.
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Perform dfs on each unvisited node and count the number of connected components.
        vector<bool> visit(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(i, adj, visit);
                ans++;
            }
        }

        return ans;
    }
};