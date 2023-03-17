// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalsum = 0, n = nums.size();
        for (auto &it : nums)
            totalsum += it;
        if (totalsum % 2)
            return false; // if totalsum is odd return false as there cant be two equal subsets
        // s1+s2=total sum ,as s1 =s2 therefore s1=s2=totalsum/2 ,so we just have to find if there is a subset with sum equal to half the totalsum.
        int target = totalsum / 2;
        bool dp[n + 1][target + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = true;
                }
                else if (i == 0)
                    dp[i][j] = false;
                else if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};