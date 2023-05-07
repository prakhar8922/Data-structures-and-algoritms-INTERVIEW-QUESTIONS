// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Medium
// 2.5K
// 220
// Companies
// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106
// Accepted
// 58.3K
// Submissions
// 142.4K
// Acceptance Rate
// 40.9%

class Solution
{
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int l = 0, r = nums.size() - 1;
        vector<int> pow2(n, 1);

        // Compute powers of 2 modulo mod and store them in the vector pow2
        for (int i = 1; i < n; i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        while (l <= r)
        {

            // If the sum of the numbers at indices l and r is less than or equal to target, then update the answer
            // by adding the number of subsequences that can be formed using the numbers between indices l and r (inclusive).
            // Also, increment l by 1 to consider the next possible subsequence that includes nums[l].
            if (nums[l] + nums[r] <= target)
            {
                ans = (ans + pow2[r - l]) % mod;
                l++;
            }

            // Otherwise, decrement r by 1 to consider the next possible subsequence that includes nums[r].
            else
                r--;
        }

        return ans;
    }
};