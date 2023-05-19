// 1493. Longest Subarray of 1's After Deleting One Element
// Medium
// 1.5K
// 31
// Companies
// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// Accepted
// 63.1K
// Submissions
// 104.1K
// Acceptance Rate
// 60.6%

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        // easier variation of max consecutive ones 3
        int i = 0, j = 0, count0 = 0, ans = 0, n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
                count0++;
            while (count0 > 1)
            {
                if (nums[i] == 0)
                    count0--;
                i++;
            }
            ans = max(ans, j - i);
            j++;
        }
        return ans;
    }
};