// 410. Split Array Largest Sum
// Hard
// 7.6K
// 171
// Companies
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)
// Accepted
// 253.3K
// Submissions
// 473.8K
// Acceptance Rate
// 53.5%

class Solution
{
    // same question as 1011 capacity to ship packages within d days
public:
    bool isValid(vector<int> &nums, int maxcapacity, int k)
    {
        int daysrequired = 1, currweight = 0;
        for (auto &weight : nums)
        {
            currweight += weight;
            if (currweight > maxcapacity)
            {
                daysrequired++;
                currweight = weight; // if the  weight makes the currweight greater than the maxcapacity then go on to next day  and initialise the currweight to weight as the first weight on next day will be weight
            }
        }
        return daysrequired <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int maxweight = 0, totalweight = 0;
        for (auto &it : nums)
        {
            maxweight = max(maxweight, it);
            totalweight += it;
        }
        int l = maxweight, r = totalweight;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isValid(nums, mid, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};