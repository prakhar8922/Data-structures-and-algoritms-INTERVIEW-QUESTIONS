// Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: 1 is the 2nd number
// of fibonacci series.
// Example 2:

// Input: n = 5
// Output: 5
// Explanation: 5 is the 5th number
// of fibonacci series.

// Your Task:
// You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1<= n <=1000

// Top down approach
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// class Solution {
//   public:
//   long long int dp[1001];
//   int m=1e9+7;
//   long long int solve(long long int n){

//       if(n==1 ||n==2)
//        return 1;
//        if(dp[n]!=-1)
//        return dp[n];
//        return dp[n]=solve(n-1)%m+solve(n-2)%m;

//   }

//     long long int nthFibonacci(long long int n){
//        memset(dp,-1,sizeof(dp));
//        return solve(n)%m;
//     }
// };

// Bottom up approach
class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        long long int dp[n + 1];
        long long int m = 1e9 + 7;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] % m + dp[i - 2] % m;
        }
        return dp[n] % m;
    }
};
