// 2444. Count Subarrays With Fixed Bounds
// Hard
// 1.2K
// 22
// Companies
// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
// Example 2:

// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

// Constraints:

// 2 <= nums.length <= 105
// 1 <= nums[i], minK, maxK <= 106

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int mink, int maxk)
    {
        long long ans = 0;
        int lastmin = -1, lastmax = -1, leftbound = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= mink and nums[i] <= maxk)
            {
                lastmin = (mink == nums[i]) ? i : lastmin;
                lastmax = (maxk == nums[i]) ? i : lastmax;
                // Let smaller = min(lastmin, lastmax), so the range [smaller, i] contains at least one minK and one maxK
                ans += max(0, min(lastmin, lastmax) - leftbound); // we use the max function with 0 in max(0, ...) so that if lastMin/lastMax are not found yet, we get a negative value for the second argument and add nothing to count. The min(lastMin, lastMax) part ensures that we use the leftmost of lastMin/lastMax, so we do not exclude the lastMin/lastMax in any of our subarrays. We subtract the leftBound to only consider valid values (thus ignoring values at the leftBound and further to the left).
            }
            else
            {
                leftbound = i;
                lastmin = -1, lastmax = -1;
            }
        }
        return ans;
    }
};

class Solution:
    def countSubarrays(self, nums: List[int], mink: int, maxk: int) -> int:
        count=0
        n=len(nums)
        lastmin,lastmax,leftbound=-1,-1,-1
        for i in range(n):
            if nums[i]>=mink and nums[i]<=maxk:
                lastmin=i if nums[i]==mink else lastmin
                lastmax=i if nums[i]==maxk else lastmax
                count+=max(0,min(lastmin,lastmax)-leftbound)
            else:
                leftbound=i
                lastmax,lastmin=-1,-1    
                
        return count