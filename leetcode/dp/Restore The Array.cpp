// 1416. Restore The Array
// Hard
// 1.4K
// 47
// Companies
// A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: s = "1000", k = 10000
// Output: 1
// Explanation: The only possible array is [1000]
// Example 2:

// Input: s = "1000", k = 10
// Output: 0
// Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
// Example 3:

// Input: s = "1317", k = 2000
// Output: 8
// Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]

// Constraints:

// 1 <= s.length <= 105
// s consists of only digits and does not contain leading zeros.
// 1 <= k <= 109
// Accepted
// 52.1K
// Submissions
// 105.8K
// Acceptance Rate
// 49.2%

class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int startIdx, string &s, int k, vector<int> &dp)
    {
        if (startIdx == s.size())
            return 1;
        if (dp[startIdx] != -1)
            return dp[startIdx];
        long long ans = 0, currnum = 0;
        for (int i = startIdx; i < s.size(); i++)
        {
            currnum = (currnum * 10) + (s[i] - '0');
            if (currnum < 1 or currnum > k)
                break;
            long long ways = func(i + 1, s, k, dp);
            ans = (ans + ways) % mod;
        }
        return dp[startIdx] = ans;
    }
    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return func(0, s, k, dp);
    }
};