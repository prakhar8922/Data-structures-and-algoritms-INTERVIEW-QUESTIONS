/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int lowerbound = -(pow(2, 31) / 10);
        int upperbound = (pow(2, 31) - 1) / 10;
        int ans = 0;
        while (x)
        {
            /* code */
            int lastdigit = x % 10;
            if (ans < lowerbound or ans > upperbound)
            {
                return 0;
            }
            ans = ans * 10 + lastdigit;
            x /= 10;
        }
        return ans;
    }
};
// @lc code=end
