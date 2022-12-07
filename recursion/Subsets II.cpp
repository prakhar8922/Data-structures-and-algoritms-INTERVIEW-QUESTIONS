// Given an integer array nums that may contain duplicates, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

class Solution
{
private:
    void func(int idx, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds)
    {
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx and nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            func(i + 1, ans, nums, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, ans, nums, ds);
        return ans;
    }
};