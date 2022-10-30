// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:

// Input:

// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:

// Input:

// Output: 0
// Explanation: no cycle in the graph

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

public:
// Function to detect cycle in a directed graph.
bool isCyclic(int v, vector<int> adj[])
{
    // code here
    int cnt = 0;
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return cnt == v ? false : true;
}

;

// private:
// bool dfs(int node, vector<int> adj[], int vis[], int pathvis[])
// {
//     vis[node] = 1;
//     pathvis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//         {
//             if (dfs(it, adj, vis, pathvis) == true)
//                 return true;
//         }
//         else if (pathvis[it])
//             return true;
//     }
//     pathvis[node] = 0;
//     return false;
// }

// public:
// // Function to detect cycle in a directed graph.
// bool isCyclic(int v, vector<int> adj[])
// {
//     // code here
//     int vis[v] = {0};
//     int pathvis[v] = {0};
//     for (int i = 0; i < v; i++)
//     {
//         if (vis[i] == 0)
//         {
//             if (dfs(i, adj, vis, pathvis) == true)
//                 return true;
//         }
//     }
//     return false;
// }

;