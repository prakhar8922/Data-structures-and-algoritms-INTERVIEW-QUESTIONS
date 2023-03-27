// 2360. Longest Cycle in a Graph
// Hard
// 1.5K
// 27
// Companies
// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node.

// Example 1:

// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.
// Example 2:

// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in this graph.

// Constraints:

// n == edges.length
// 2 <= n <= 105
// -1 <= edges[i] < n
// edges[i] != i

class Solution
{
public:
    int ans = -1;
    void dfs(int node, vector<int> &edges, unordered_map<int, int> &dist, vector<bool> &vis)
    {
        vis[node] = true;
        int adjnode = edges[node];
        if (adjnode != -1 and !vis[adjnode])
        { // If neighbor is not visited, we update dist[neighbor] = dist[node] + 1 and recursively perform the DFS traversal starting with neighbor.
            dist[adjnode] = dist[node] + 1;
            dfs(adjnode, edges, dist, vis);
        }
        else if (adjnode != -1 and dist.count(adjnode))
        {
            // If neighbor is already visited, one of two things can happen. It is either a cycle formation or neighbor was visited in a previous DFS traversal and not the current DFS traversal. This can be verified if the dist map has the key neighbor in it (we create a new map for every traversal).
            // If dist contains neighbor, it means we visited neighbor during the current DFS traversal itself and it is a formation of cycle. We update answer = max(answer, dist[node] - dist[neighbor] + 1 in this case.
            ans = max(ans, dist[node] - dist[adjnode] + 1);
        }
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                unordered_map<int, int> dist; // new map for every traversal
                dist[i] = 1;
                dfs(i, edges, dist, vis);
            }
        }
        return ans;
    }
};

// Time complexity: O(n).

// Initializing the visit array takes O(n) time.
// The dfs function visits each node once, which takes O(n) time in total. Because we have directed edges, each edge will be iterated once, resulting in O(n) operations in total while visiting all the nodes.
// Each operation on the dist map takes O(1) time. Because we insert a distance for each node when it is visited, it will take O(n) time to insert distances for all of the nodes. It is also used to check the formation of a cycle when a previously visited node is encountered again. Because there are nnn nodes, it can be checked at most nnn times. It would also take O(n) time in that case.

// Space complexity: O(n).

// The visit array takes O(n) space.
// The recursion call stack used by dfs can have no more than nnn elements in the worst-case scenario. It would take up O(n) space in that case.
// The dist map can also have no more than nnn elements and hence it would take up O(n) space as well.
