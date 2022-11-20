// You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

// You can change at most one cell in grid from 0 to 1.

// You need to find the largest group of connected  1's.

// Two cells are said to be connected if both are adjacent to each other and both have same value.

// Example 1

// Input:
// 2
// 1 1
// 0 1

// Output:
// 4

// Explanation:
// By changing cell (2,1) ,we can obtain a connected group of 4 1's
// 1 1
// 1 1

// Example 2

// Input:
// 3
// 1 0 1
// 1 0 1
// 1 0 1

// Output:
// 7

// Explanation:
// By changing cell (3,2) ,we can obtain a connected group of 7 1's
// 1 0 1
// 1 0 1
// 1 1 1

// Your Task:
// You don't need to read or print anything. Your task is to complete the function MaxConnection() which takes a matrix grid[][] denoting the grid and return the maximum group of connected group of 1s.

// Constraints:

// 1 <= n<= 500
// 0 <= grid[i][j] <= 1

class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
private:
    bool isvalid(int nrow, int ncol, int n)
    {
        return nrow >= 0 and nrow < n and ncol >= 0 and ncol < n;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        DisjointSet ds(n * n);
        // for connecting all the 1 in the graph which are adjacent to each other and to make a component
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                // grid[row][col]=1 and its adjacent node is also 1
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if (isvalid(nrow, ncol, n) and grid[nrow][ncol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
        }
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                // grid[row][col]=0 and its adjacent node is  1
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components; // to have only unique ultimate parents so that no ulp may be
                // considered more than 1 times
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if (isvalid(nrow, ncol, n) and grid[nrow][ncol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNo = nrow * n + ncol;
                        components.insert(ds.findUpar(adjNo));
                    }
                }
                int totalsize = 0;
                for (auto it : components)
                {
                    totalsize += ds.size[it];
                }
                mx = max(mx, totalsize + 1);
            }
        }
        // edge case when all the elements of the grid is 1
        for (int cell = 0; cell < n * n; cell++)
        {
            mx = max(mx, ds.size[ds.findUpar(cell)]);
        }
        return mx;
    }
};