// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

class Solution
{
private:
    void func(int idx, vector<int> &ds, vector<vector<int>> &ans, int k, int n)
    {
        if (ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < n + 1; i++)
        {
            ds.push_back(i);
            func(i + 1, ds, ans, k, n);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        func(1, ds, ans, k, n);
        return ans;
    }
};