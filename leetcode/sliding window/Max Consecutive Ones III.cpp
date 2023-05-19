// 1004. Max Consecutive Ones III
// Medium
// 6.3K
// 73
// Companies
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length
// Accepted
// 296.4K
// Submissions
// 469K
// Acceptance Rate
// 63.2%

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0, i = 0, j = 0, count0 = 0, n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
                count0++;
            while (count0 > k)
            { // Check if the number of 0s encountered so far (count0) is greater than k, which means we have more 0s than allowed flips.
                if (nums[i] == 0)
                    count0--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};