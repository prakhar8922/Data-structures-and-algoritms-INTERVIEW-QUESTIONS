// Given an integer array nums of unique elements, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

class Solution
{
private:
    void subs(int idx, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds)
    {
        if (idx == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]); // picking the element
        subs(idx + 1, ans, nums, ds);
        ds.pop_back();

        subs(idx + 1, ans, nums, ds); // not picking the element
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        subs(0, ans, nums, ds);
        sort(ans.begin(), ans.end());
        return ans;
    }
};