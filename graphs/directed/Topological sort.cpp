// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.
// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v, vector<int> adj[])
    {
        // code here
        vector<int> topo;
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
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};

class Solution
{
private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        int vis[v] = {0};
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};