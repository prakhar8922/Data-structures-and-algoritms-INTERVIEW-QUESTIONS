// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution
{
public:
    int subsetSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int dp[n + 1][target + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= target; i++)
        {
            dp[0][i] = 0;
        }
        // Why are we not initializing entire first col to 1 ? like we did in the original subset count  problem it's because here in this problem, we may get 0 as input. Now when we get 0 as input, we have to consider two choices : include this 0 to form subset with sum 0, or exclude this 0 to form subset with sum 0. We initialize entire first col with 1 when we are sure that in the input we will be given numbers >=1 .
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // S1 - S2 = target
        // S1 + S2 = sum of all the elements
        // above 2 equations we get, 2* S1 = target + Sum of all the elements
        // => S1 = (target + Sum of all the elements) / 2
        // So, this problem now reduces to just finding count of subsets which are having sum equal to S1.
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
        }

        if (abs(target) > sum || (sum + target) % 2 != 0)
        {
            return 0;
        }
        int s1 = (sum + target) / 2;
        int ans = subsetSum(nums, s1);
        return ans;
    }
};