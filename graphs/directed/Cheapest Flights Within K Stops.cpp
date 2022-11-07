// There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:
// Input:
// n = 4
// flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
// src = 0
// dst = 3
// k = 1
// Output:
// 700
// Explaination:
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Constraint:
// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Code here
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]}); // from->{to,price}
        }
        queue<pair<int, pair<int, int>>> q; //(stops,{node,price})
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stop > k)
                break;
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int edW = it.second;
                if (cost + edW < dist[adjnode] and stop <= k)
                {
                    dist[adjnode] = cost + edW;
                    q.push({stop + 1, {adjnode, dist[adjnode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};