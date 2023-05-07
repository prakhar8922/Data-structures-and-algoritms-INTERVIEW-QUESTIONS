// 1697. Checking Existence of Edge Length Limited Paths
// Hard
// 1.2K
// 30
// Companies
// An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

// Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

// Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

// Example 1:

// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
// Output: [false,true]
// Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
// For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
// For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
// Example 2:

// Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
// Output: [true,false]
// Exaplanation: The above figure shows the given graph.

// Constraints:

// 2 <= n <= 105
// 1 <= edgeList.length, queries.length <= 105
// edgeList[i].length == 3
// queries[j].length == 3
// 0 <= ui, vi, pj, qj <= n - 1
// ui != vi
// pj != qj
// 1 <= disi, limitj <= 109
// There may be multiple edges between two nodes.
// Accepted
// 24.5K
// Submissions
// 42.1K
// Acceptance Rate
// 58.3%

class Solution
{
public:
    vector<int> parent, size;
    void make(int node)
    {
        parent[node] = node;
        size[node] = 1;
        return;
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void Union(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[2] <= b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        parent.resize(n, 0), size.resize(n, 0);
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < n; i++)
        {
            make(i);
        }
        for (int i = 0; i < queries.size(); i++)
        { // This code is adding an additional integer value to each query in the queries vector. Specifically, it is adding the index of the query within the queries vector as a fourth element to the query vector.
            // This line of code is useful later in the implementation because it allows the algorithm to keep track of which query in the queries vector corresponds to which element in the ans answer vector.
            queries[i].push_back(i);
        }

        // The algorithm sorts both the edgeList and queries vectors based on the value of the third element (index 2) in each vector. This is because the third element in both vectors corresponds to the limit value for the distance between vertices that is being queried
        sort(queries.begin(), queries.end(), comparator);
        sort(edgeList.begin(), edgeList.end(), comparator);

        int j = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            // it loops through the sorted edgeList vector and adds all edges with a distance limit less than the current query's limit to the Union-Find data structure.
            while (j < edgeList.size() and edgeList[j][2] < queries[i][2])
            {
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            parent[queries[i][0]] = findUPar(queries[i][0]);
            parent[queries[i][1]] = findUPar(queries[i][1]);

            // if the u and v vertices in the current query are in the same connected component of the Union-Find data structure. If they are, then there is a path between them with a distance less than or equal to the current query's limit, and the corresponding element in the ans vector is set to true. Otherwise, the ans vector element is set to false.
            ans[queries[i][3]] = (parent[queries[i][0]] == parent[queries[i][1]]);
        }
        return ans;
    }
};