// Given a number N. Find the length of the longest consecutive 1s in its binary representation.

// Example 1:

// Input: N = 14
// Output: 3
// Explanation:
// Binary representation of 14 is
// 1110, in which 111 is the longest
// consecutive set bits of length is 3.
// Example 2:

// Input: N = 222
// Output: 4
// Explanation:
// Binary representation of 222 is
// 11011110, in which 1111 is the
// longest consecutive set bits of length 4.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution
{
public:
    int maxConsecutiveOnes(int n)
    {
        int count = 0;
        while (n)
        {
            n = (n & (n << 1));
            count++;
        }
        return count;
    }
};

//  the operation x = (x & (x << 1)) reduces length of every sequence of 1s by one in binary representation of x. If we keep doing this operation in a loop, we end up with x = 0. The number of iterations required to reach 0 is actually length of the longest consecutive sequence of 1s.