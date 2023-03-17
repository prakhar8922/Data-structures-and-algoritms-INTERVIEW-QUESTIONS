// There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

// There is a meeting for the representatives of each city. The meeting is in the capital city.

// There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

// A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

// Return the minimum number of liters of fuel to reach the capital city.

// Example 1:

// Input: roads = [[0,1],[0,2],[0,3]], seats = 5
// Output: 3
// Explanation:
// - Representative1 goes directly to the capital with 1 liter of fuel.
// - Representative2 goes directly to the capital with 1 liter of fuel.
// - Representative3 goes directly to the capital with 1 liter of fuel.
// It costs 3 liters of fuel at minimum.
// It can be proven that 3 is the minimum number of liters of fuel needed.
// Example 2:

// Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
// Output: 7
// Explanation:
// - Representative2 goes directly to city 3 with 1 liter of fuel.
// - Representative2 and representative3 go together to city 1 with 1 liter of fuel.
// - Representative2 and representative3 go together to the capital with 1 liter of fuel.
// - Representative1 goes directly to the capital with 1 liter of fuel.
// - Representative5 goes directly to the capital with 1 liter of fuel.
// - Representative6 goes directly to city 4 with 1 liter of fuel.
// - Representative4 and representative6 go together to the capital with 1 liter of fuel.
// It costs 7 liters of fuel at minimum.
// It can be proven that 7 is the minimum number of liters of fuel needed.
// Example 3:

// Input: roads = [], seats = 1
// Output: 0
// Explanation: No representatives need to travel to the capital city.

// Constraints:

// 1 <= n <= 105
// roads.length == n - 1
// roads[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// roads represents a valid tree.
// 1 <= seats <= 105

class Solution
{
private:
    int dfs(int node, int parent, unordered_map<int, vector<int>> &adj, long long &ans, int seats)
    {
        // p variable is used to store the number of passengers on the child's car, and the passengers variable is used to store the total number of passengers for all the children of a node.
        int passengers = 0;

        for (auto &child : adj[node])
        {

            if (child != parent)
            {
                // recursively call the dfs function for the child
                int p = dfs(child, node, adj, ans, seats);
                // add the number of passengers on the child's car to the total
                passengers += p;
                // add the fuel cost for the child's car to the total
                ans += (int)ceil(p * 1.0 / seats); // The p variable is multiplied by 1.0 to ensure that the division p / seats returns a floating-point number instead of an integer. This is necessary because the ceil function only works on floating-point numbers. If p was not multiplied by 1.0, the division p / seats would return an integer, and the ceil function would have no effect.
            }
        }
        // return the total number of passengers, including the passengers on the current node's car
        return passengers + 1;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {

        int n = roads.size();

        unordered_map<int, vector<int>> adj;

        for (auto &it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // variable to store the minimum fuel cost
        long long ans = 0;

        dfs(0, -1, adj, ans, seats);

        return ans;
    }
};