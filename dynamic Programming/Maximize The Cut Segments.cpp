// Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// Example 1:

// Input:
// N = 4
// x = 2, y = 1, z = 1
// Output: 4
// Explanation:Total length is 4, and the cut
// lengths are 2, 1 and 1.  We can make
// maximum 4 segments each of length 1.
// Example 2:

// Input:
// N = 5
// x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and
// the cut lengths are 5, 3 and 2. We can
// make two segments of lengths 3 and 2.
// Your Task:
// You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

// Expected Time Complexity : O(N)
// Expected Auxiliary Space: O(N)

// Constraints
// 1 <= N, x, y, z <= 104

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dp[10001];
    int solve(int n, int x, int y, int z)
    {

        if (n == 0)
            return 0;
        // n<0 is for the cases when in recursion the length of x,y,z becomes larger than the length of n
        if (n < 0)
            return INT_MIN;
        if (dp[n] != -1)
            return dp[n];
        // +1 is added to show a cut has been made
        int a = solve(n - x, x, y, z) + 1;

        int b = solve(n - y, x, y, z) + 1;

        int c = solve(n - z, x, y, z) + 1;
        // {} is used so that max operator can be used on multiple operators
        return dp[n] = max({a, b, c});
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, x, y, z);
        if (ans < 0)
            return 0;

        return ans;
    }
};