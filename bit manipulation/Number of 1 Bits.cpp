// Given a positive integer N, print count of set bits in it.

// Example 1:

// Input:
// N = 6
// Output:
// 2
// Explanation:
// Binary representation is '110'
// So the count of the set bit is 2.
// Example 2:

// Input:
// 8
// Output:
// 1
// Explanation:
// Binary representation is '1000'
// So the count of the set bit is 1.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        while (N)
        {
            N = N & (N - 1);
            count++;
        }
        return count;
    }
};

//  Brian Kernighan’s Algorithm:
// Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit.
// for example :
// 10 in binary is 00001010
// 9 in binary is 00001001
// 8 in binary is 00001000
// 7 in binary is 00000111
// So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count.
// The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.