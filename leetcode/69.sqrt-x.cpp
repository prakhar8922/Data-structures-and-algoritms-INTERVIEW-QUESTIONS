/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long s = 0, end = x, mid, ans;
        while (s <= end)
        {
            mid = (s + end) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                s = mid + 1;
                ans = mid;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
