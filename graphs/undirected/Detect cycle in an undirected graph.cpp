// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

// Example 1:

// Input:
// V = 5, E = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
// Output: 1
// Explanation:

// 1->2->3->4->1 is a cycle.
// Example 2:

// Input:
// V = 4, E = 2
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation:

// No cycle in the graph.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

// NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105
class Solution
{
private:
    bool dfs(int snode, int parent, int vis[], vector<int> adj[]) // snode=start node
    {
        vis[snode] = 1;
        // visit adjacent nodes
        for (auto adjacentNode : adj[snode])
        {
            // unvisited adjacent node
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, snode, vis, adj) == true)
                    return true;
            }
            // visited node but not a parent node
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        // for graph with connected components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

class Solution
{
private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        // store <source node, parent node>
        queue<pair<int, int>> q;
        q.push({src, -1});
        // traverse until queue is not empty
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // go to all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                // if adjacent node is unvisited
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode)
                {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        // there's no cycle
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};