// 18. 4Sum
// Medium
// 8.7K
// 1K
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                long long num = (long long)target - (long long)nums[i] - (long long)nums[j];
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] < num)
                        l++;
                    else if (nums[l] + nums[r] > num)
                        r--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int temp1 = l, temp2 = r;
                        // skipping duplicate values for l and r index
                        while (nums[l] == nums[temp1] and l < r)
                            l++;
                        while (nums[r] == nums[temp2] and l < r)
                            r--;
                    }
                }
                // skipping duplicate values for jindex
                while (j + 1 < n and nums[j] == nums[j + 1])
                    j++;
            }
            // skipping duplicate values for i index
            while (i + 1 < n and nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};