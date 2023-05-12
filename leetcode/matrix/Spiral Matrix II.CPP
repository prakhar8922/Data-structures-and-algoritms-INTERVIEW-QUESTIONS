// 59. Spiral Matrix II
// Medium
// 5.2K
// 219
// Companies
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20
// Accepted
// 456.9K
// Submissions
// 668.1K
// Acceptance Rate
// 68.4%

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = 0;          // left boundary
        int r = n - 1;      // right boundary
        int top = 0;        // top boundary
        int bottom = n - 1; // bottom boundary
        int dir = 0;        // direction (0 - right, 1 - down, 2 - left, 3 - up)
        int ele = 1;        // value to be filled in the matrix

        // Loop until the boundaries overlap
        while (l <= r && top <= bottom)
        {
            // Fill the top row from left to right
            if (dir == 0)
            {
                for (int i = l; i <= r; i++)
                {
                    ans[top][i] = ele;
                    ele++;
                }
                top++;
            }
            // Fill the right column from top to bottom
            if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][r] = ele;
                    ele++;
                }
                r--;
            }
            // Fill the bottom row from right to left
            if (dir == 2)
            {
                for (int i = r; i >= l; i--)
                {
                    ans[bottom][i] = ele;
                    ele++;
                }
                bottom--;
            }
            // Fill the left column from bottom to top
            if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][l] = ele;
                    ele++;
                }
                l++;
            }

            // Update the direction (0 to 3)
            dir = (dir + 1) % 4;
        }

        return ans;
    }
};