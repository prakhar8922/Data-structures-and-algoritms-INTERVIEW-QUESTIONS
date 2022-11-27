// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }
        int maxl = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == 0)
            {
                maxl = i + 1;
            }
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    maxl = max(maxl, i - mp[sum]);
                }
                else
                    mp[sum] = i;
            }
        }
        return maxl;
    }
};