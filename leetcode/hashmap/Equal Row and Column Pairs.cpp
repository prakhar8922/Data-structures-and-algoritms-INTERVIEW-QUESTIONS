// 2352. Equal Row and Column Pairs
// Medium
// 481
// 20
// Companies
// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

// Example 1:

// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]
// Example 2:

// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]

// Constraints:

// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 105
// Accepted
// 37.3K
// Submissions
// 52.8K
// Acceptance Rate
// 70.5%
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        map<vector<int>, int> mp;

        // Count occurrences of each row vector in 'grid'
        for (auto &it : grid)
        {
            mp[it]++;
        }

        // Count occurrences of each column vector in 'grid'
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> v;

            // Create column vector
            for (int j = 0; j < grid.size(); j++)
            {
                v.push_back(grid[j][i]);
            }

            // Add count of column vector to 'ans'
            ans += mp[v];
        }

        return ans;
    }
};