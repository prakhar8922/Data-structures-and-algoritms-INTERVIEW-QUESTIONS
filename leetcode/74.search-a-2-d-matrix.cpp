/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int N = mat.size();
        int M = mat[0].size();
        int rows = 0;
        int cols = M - 1;
        while (rows < N and cols >= 0)
        {
            int element = mat[rows][cols];
            if (element == x)
                return true;
            if (element < x)
                rows++;
            else
                cols--;
        }
        return false;
    }
};
// @lc code=end
