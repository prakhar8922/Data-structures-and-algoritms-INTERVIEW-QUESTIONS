// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Example 1:

// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explaination: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes the array height  and Returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Constraints
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

// Expected Time Complexity: O(Elog(V))
// Expected Space Complexity: O(N,M)

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};

        while (!pq.empty())
        {

            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n - 1 and c == m - 1)
            {
                return diff;
            }

            for (int i = 0; i < 4; i++)
            {

                int newr = r + delrow[i];
                int newc = c + delcol[i];

                if (newr >= 0 and newc >= 0 and newr < n and newc < m)
                {

                    int neweffort = max(abs(heights[r][c] - heights[newr][newc]), diff);

                    if (neweffort < dist[newr][newc])
                    {
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};