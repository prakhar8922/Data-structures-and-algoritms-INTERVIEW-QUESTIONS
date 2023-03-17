// 172. Factorial Trailing Zeroes
// Medium
// 2.6K
// 1.8K
// Companies
// Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0

// Constraints:

// 0 <= n <= 104

class Solution
{
public:
    // The function works by counting the number of factors of 5 in the prime factorization of n!. Since every pair of factors 2 and 5 gives one trailing zero, we only need to count the number of factors of 5.
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n >= 5)
        {
            int quotient = n / 5;
            n = quotient;
            count += quotient;
        }
        return count;
    }
};

// class Solution:
//     def trailingZeroes(self, n: int) -> int:
//         ans=0
//         while n>=5:
//             quotient=n//5
//             n=quotient
//             ans+=quotient
//         return ans