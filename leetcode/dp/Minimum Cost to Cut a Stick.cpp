// 1547. Minimum Cost to Cut a Stick
// Hard
// 3K
// 58
// Companies
// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

// Example 1:

// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
// Example 2:

// Input: n = 9, cuts = [5,6,1,4,2]
// Output: 22
// Explanation: If you try the given cuts ordering the cost will be 25.
// There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

// Constraints:

// 2 <= n <= 106
// 1 <= cuts.length <= min(n - 1, 100)
// 1 <= cuts[i] <= n - 1
// All the integers in cuts array are distinct.
// Accepted
// 61.4K
// Submissions
// 102.4K
// Acceptance Rate
// 59.9%
class Solution
{
public:
    int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j) // Base case: if i is greater than j, no cuts are possible
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        // Iterate through all possible indices to make cuts
        for (int idx = i; idx <= j; idx++)
        {
            // Calculate the cost of making cuts at index 'idx'
            // The expression cuts[j + 1] - cuts[i - 1] calculates the cost of making cuts at a particular index within the given range.
            int cost = cuts[j + 1] - cuts[i - 1] + func(i, idx - 1, cuts, dp) + func(idx + 1, j, cuts, dp);

            mn = min(mn, cost);
        }
        return dp[i][j] = mn;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // The insertion of 0 at the beginning and n at the end of the cuts vector is done to include the starting and ending points of the entire range in the cutting process.
        cuts.push_back(n);            // Append 'n' to the end of the cuts vector
        cuts.insert(cuts.begin(), 0); // Insert 0 at the beginning of the cuts vector
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        sort(cuts.begin(), cuts.end()); // Sorting the cuts vector guarantees that the algorithm explores the different possible cut positions systematically, enabling it to find the minimum cost correctly.

        return func(1, cuts.size() - 2, cuts, dp);
    }
};