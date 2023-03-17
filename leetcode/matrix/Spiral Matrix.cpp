// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int l = 0, r = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int dir = 0; // dir=0 mean left to right,dir=1 means top to bottom,dir=2 means right to left and dir=3 means bottom to top
        vector<int> ans;
        while (top <= bottom and l <= r)
        {
            if (dir == 0)
            {
                for (int i = l; i <= r; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][r]);
                }

                r--;
            }
            if (dir == 2)
            {
                for (int i = r; i >= l; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};