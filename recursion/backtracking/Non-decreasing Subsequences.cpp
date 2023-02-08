// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

// Example 1:

// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// Example 2:

// Input: nums = [4,4,3,2,1]
// Output: [[4,4]]

// Constraints:

// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100

class Solution
{
private:
    void subs(int idx, vector<int> &nums, vector<int> &ds, set<vector<int>> &st)
    {
        if (idx >= nums.size())
        {
            if (ds.size() >= 2)
            {
                st.insert(ds);
            }
            return;
        }
        // if the ds remains increasing after appending nums[index]
        if (ds.empty() or ds.back() <= nums[idx])
        {
            ds.push_back(nums[idx]); // when taking the elemenent in the subsequence
            subs(idx + 1, nums, ds, st);
            ds.pop_back(); // when not taking the element in the subsequence
        }
        subs(idx + 1, nums, ds, st);
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        // sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        set<vector<int>> st;
        subs(0, nums, ds, st);

        for (auto it : st)
        {
            ans.push_back(it);
        }
        // return vector(st.begin(), st.end());

        return ans;
    }
};