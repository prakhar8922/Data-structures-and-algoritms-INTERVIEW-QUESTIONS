// 216. Combination Sum III
// Medium
// 4.9K
// 96
// Companies
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

// Constraints:

// 2 <= k <= 9
// 1 <= n <= 60
// Accepted
// 401.3K
// Submissions
// 592.2K
// Acceptance Rate
// 67.8%

class Solution
{
public:
    void func(int cnum, vector<int> &ds, vector<vector<int>> &ans, int k, int n)
    {
        // Base case: if n is negative or the size of ds is greater than k, return
        if (n < 0 || ds.size() > k)
            return;

        // If n is 0 and the size of ds is k, it means we have found a valid combination
        if (n == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }

        // Explore all possible candidates starting from cnum
        for (int i = cnum; i <= 9; i++)
        {
            ds.push_back(i); // Include the current candidate

            // Recursively call the function with the updated parameters
            func(i + 1, ds, ans, k, n - i);

            ds.pop_back(); // Backtrack: Remove the current candidate to explore other possibilities
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        func(1, ds, ans, k, n); // Call the helper function to find combinations
        return ans;
    }
};