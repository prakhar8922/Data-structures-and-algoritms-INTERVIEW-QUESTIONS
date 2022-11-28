/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return rev == to_string(x);
    }
};
// @lc code=end
