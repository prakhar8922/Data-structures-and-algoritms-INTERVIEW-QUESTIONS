// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.

// Constraints:

// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total_sum = 0, curr_sum_mx = 0, curr_sum_mn = 0, max_subarr = INT_MIN, min_subarr = INT_MAX;
        for (auto it : nums)
        {
            curr_sum_mx += it, curr_sum_mn += it, total_sum += it;
            max_subarr = max(max_subarr, curr_sum_mx);
            if (curr_sum_mx < 0)
                curr_sum_mx = 0;
            min_subarr = min(min_subarr, curr_sum_mn);
            if (curr_sum_mn > 0)
                curr_sum_mn = 0;
        }
        return (total_sum == min_subarr) ? max_subarr : max(max_subarr, total_sum - min_subarr); // if all the elements of the array is negative then return max_subarr using kadane algo else
        // there are two cases for max sum subaray. first is the subarray is present in linear form in the array
        // and the second is max sub array present in last and starting of the array making it wrap around the arr
        // for the answer in second case we will return total sum -min_subarr if it is wrapped
    }
};