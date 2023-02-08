// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (j + nums[j] >= i)
                {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[n - 1];

        int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
        while (lastJumpedPos < n - 1)
        {                                                  // loop till last jump hasn't taken us till the end
            maxReachable = max(maxReachable, i + nums[i]); // furthest index reachable on the next level from current level
            if (i == lastJumpedPos)
            {                                 // current level has been iterated & maxReachable position on next level has been finalised
                lastJumpedPos = maxReachable; // so just move to that maxReachable position
                jumps++;                      // and increment the level
                                              // NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
                                              //       This ensures jumps will only store minimum jump required to reach lastJumpedPos
            }
            i++;
        }
        return jumps;
    }
};