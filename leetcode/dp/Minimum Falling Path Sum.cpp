// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:

// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:

// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int sum = INT_MAX;
        // first row of the matrix will remain same  hence we start from 1st indexed row
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j == 0)
                { // edge case for first column
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                }
                else if (j == col - 1)
                { // edge case for last column
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                }
                else
                { // for other cases
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                }
            }
        }
        for (int i = 0; i < col; i++)
        { // scanning last row for ans
            sum = min(sum, matrix[row - 1][i]);
        }
        return sum;
    }
};