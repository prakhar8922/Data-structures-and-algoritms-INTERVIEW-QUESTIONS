// 16. 3Sum Closest
// Medium
// 8.7K
// 467
// Companies
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX, closest;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target)
                    return target;
                else if (sum > target)
                {

                    high--;
                }
                else
                {

                    low++;
                }
                int diff = abs(sum - target);
                if (diff < mindiff)
                {
                    mindiff = diff;
                    closest = sum;
                }
            }
        }

        return closest;
    }
};