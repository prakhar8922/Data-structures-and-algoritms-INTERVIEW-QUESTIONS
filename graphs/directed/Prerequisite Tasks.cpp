// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

// Example 1:

// Input:
// N = 4, P = 3
// prerequisites = {{1,0},{2,1},{3,2}}
// Output:
// Yes
// Explanation:
// To do task 1 you should have completed
// task 0, and to do task 2 you should
// have finished task 1, and to do task 3 you
// should have finished task 2. So it is possible.
// Example 2:

// Input:
// N = 2, P = 2
// prerequisites = {{1,0},{0,1}}
// Output:
// No
// Explanation:
// To do task 1 you should have completed
// task 0, and to do task 0 you should
// have finished task 1. So it is impossible.

// Your task:
// You don’t need to read input or print anything. Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false.

// Expected Time Complexity: O(N + P)
// Expected Auxiliary Space: O(N + P)

// Constraints:
// 1 ≤ N ≤ 104
// 1 ≤ P ≤ 105

public:
bool isPossible(int v, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[v];
    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    // Code here
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
    return topo.size() == v ? true : false;
}

;