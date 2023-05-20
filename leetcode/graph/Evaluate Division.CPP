// 399. Evaluate Division
// Medium
// 7.4K
// 651
// Companies
// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation:
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]

// Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.
// Accepted
// 346.9K
// Submissions
// 575.8K
// Acceptance Rate
// 60.3%

class Solution
{
public:
    double dfs(string node, string target, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited)
    {
        // Check if the current node has been visited before or if it has no neighbors
        if (visited.find(node) != visited.end() || adj[node].empty())
            return -1.0; // Return -1.0 to indicate failure

        visited.insert(node); // Mark the current node as visited

        // Check if the current node is the target node
        if (node == target)
            return 1.0; // Return 1.0 to indicate success

        double product = -1.0; // Initialize the product to -1.0

        // Explore the neighbors of the current node
        for (auto &[child, value] : adj[node])
        {
            double result = dfs(child, target, adj, visited); // Recursively call dfs on each neighbor

            // If a valid result is obtained from the neighbor, update the product and break the loop
            if (result != -1.0)
            {
                product = value * result;
                break;
            }
        }

        visited.erase(node); // Remove the current node from the visited set before returning

        return product; // Return the calculated product
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = queries.size(), m = values.size();
        vector<double> ans(n, -1.0); // Initialize the answer vector with -1.0 values

        unordered_set<string> st;                                // Set to keep track of all the variables
        unordered_map<string, vector<pair<string, double>>> adj; // Adjacency list representation of the graph

        int i = 0;
        for (auto &equation : equations)
        {
            adj[equation[0]].push_back({equation[1], values[i]});
            adj[equation[1]].push_back({equation[0], 1 / values[i]});
            st.insert(equation[0]);
            st.insert(equation[1]);
            i++;
        }

        i = 0;
        for (auto &query : queries)
        {
            // Check if either of the variables in the query is not present in the input equations
            if (st.find(query[0]) == st.end() || st.find(query[1]) == st.end())
                ans[i] = -1.0; // Set the answer to -1.0

            // Check if both variables in the query are the same
            else if (query[0] == query[1])
                ans[i] = 1.0; // Set the answer to 1.0

            else
            {
                unordered_set<string> visited;                  // Initialize the visited set for each query
                ans[i] = dfs(query[0], query[1], adj, visited); // Call the dfs function to calculate the result
            }

            i++;
        }

        return ans; // Return the answer vector
    }
};