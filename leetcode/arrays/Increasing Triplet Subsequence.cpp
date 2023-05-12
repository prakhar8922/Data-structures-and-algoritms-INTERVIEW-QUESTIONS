// 334. Increasing Triplet Subsequence
// Medium
// 6.4K
// 280
// Companies
// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

// Example 1:

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.
// Example 3:

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

// Constraints:

// 1 <= nums.length <= 5 * 105
// -231 <= nums[i] <= 231 - 1

// Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
// Accepted
// 387.1K
// Submissions
// 907.3K
// Acceptance Rate
// 42.7%

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int first = INT_MAX, mid = INT_MAX; // These variables will store the smallest and second smallest elements encountered so far in the vector.
        for (int i = 0; i < n; i++)
        {
            // If the current element is smaller than "first," update the value of "first" to the current element. This means we have found a new smallest element.
            // If the current element is greater than "first" but smaller than "mid," update the value of "mid" to the current element. This means we have found a new second smallest element.
            if (nums[i] <= first)
                first = nums[i];
            else if (nums[i] <= mid)
                mid = nums[i];
            else
                return true;
        }
        return false;
    }
};