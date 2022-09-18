// Given a number N. The task is to find the Nth catalan number.
// The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
// Note: Positions start from 0 as shown above.

// Example 1:

// Input:
// N = 5
// Output: 42
// Example 2:

// Input:
// N = 4
// Output: 14
// Your Task:
// Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 100

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the nth catalan number.
    cpp_int findCatalan(int n)
    {
        cpp_int dp[n + 1];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};