// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.

// Note: The Graph doesn't contain any negative weight cycle.

// Example 1:

// Input:
// V = 2
// adj [] = {{{1, 9}}, {{0, 9}}}
// S = 0
// Output:
// 0 9
// Explanation:

// The source vertex is 0. Hence, the shortest
// distance of node 0 is 0 and the shortest
// distance from node 1 is 9.

// Example 2:

// Input:
// V = 3, E = 3
// adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
// S = 2
// Output:
// 4 3 0
// Explanation:

// For nodes 2 to 0, we can follow the path-
// 2-1-0. This has a distance of 1+3 = 4,
// whereas the path 2-0 has a distance of 6. So,
// the Shortest path from 2 to 0 is 4.
// The shortest distance from 0 to 1 is 1 .

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

// Expected Time Complexity: O(V2).
// Expected Auxiliary Space: O(V2).

// Constraints:
// 1 ≤ V ≤ 1000
// 0 ≤ adj[i][j] ≤ 1000
// 1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
// 0 ≤ S < V

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        set<pair<int, int>> st;
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        st.insert({0, s});
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int edgeW = it[1];
                if (dis + edgeW < dist[adjnode])
                {
                    if (dist[adjnode] != 1e9)
                    {
                        st.erase({dist[adjnode], adjnode});
                    }
                    dist[adjnode] = dis + edgeW;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};

// {
// 	public:
// 	//Function to find the shortest distance of all the vertices
//     //from the source vertex S.
//     vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
//     {
//         // Code here
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         vector<int>dist(v,1e9);
//          dist[s]=0;
//         pq.push({0,s});
//         while(!pq.empty()){
//             int dis=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             for(auto it:adj[node]){
//                 int edgeweight=it[1];
//                 int adjnode=it[0];
//                 if(dis+edgeweight<dist[adjnode]){
//                     dist[adjnode]=dis+edgeweight;
//                     pq.push({dist[adjnode],adjnode});
//                 }
//             }
//         }
//         return dist;
//     }
// };