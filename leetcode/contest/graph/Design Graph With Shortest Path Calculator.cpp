// 2642. Design Graph With Shortest Path Calculator
// Hard
// 96
// 10
// Companies
// There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

// Implement the Graph class:

// Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
// addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
// int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.

// Example 1:

// Input
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
// [[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
// Output
// [null, 6, -1, null, 6]

// Explanation
// Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
// g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
// g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
// g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
// g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.

// Constraints:

// 1 <= n <= 100
// 0 <= edges.length <= n * (n - 1)
// edges[i].length == edge.length == 3
// 0 <= fromi, toi, from, to, node1, node2 <= n - 1
// 1 <= edgeCosti, edgeCost <= 106
// There are no repeated edges and no self-loops in the graph at any point.
// At most 100 calls will be made for addEdge.
// At most 100 calls will be made for shortestPath.
// Accepted
// 6.3K
// Submissions
// 11.4K
// Acceptance Rate
// 55.3%

class Graph
{
public:
    // vector<pair<int,pair<int,int>>>adj;//{node1->{node2,cost}}
    vector<vector<pair<int, int>>> adj;
    int size;
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        size = n;
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        queue<pair<int, int>> q; //{node,price}
        q.push({node1, 0});
        int n = size;
        vector<int> dist(n, 1e9);
        dist[node1] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int cost = it.second;
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int edW = it.second;
                if (cost + edW < dist[adjnode])
                {
                    dist[adjnode] = cost + edW;
                    q.push({adjnode, dist[adjnode]});
                }
            }
        }
        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};
