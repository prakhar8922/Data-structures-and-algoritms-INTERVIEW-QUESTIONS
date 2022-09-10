// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.

// Example 1:

// Input:
// X = 44, Y = 3
// L = 1,  R = 5
// Output: 47
// Explaination: presenation of 44 and 3 are
// 101100 and 11. So in the range 1 to 5 there
// are two set bits. If those are set in 44
// it will become 101111 = 47.

// Example 2:

// Input:
// X = 16, Y = 2
// L = 1,  R = 3
// Output: 18
// Explaination: representation of 16 and 2
// are 10000 and 10. If the mentioned rule is
// followed then 16 will become 10010 = 18.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the dunction setSetBit() which takes the number x, y, l and r as input parameters and return the modified value of x.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        for (int i = l; i <= r; i++)
        {
            // Find a mask (A number whose
            // only set bit is at i'th position)
            int mask = 1 << (i - 1);

            // If i'th bit is set in y, set i'th
            // bit in x also.
            if (y & mask)
                x = x | mask;
        }
        return x;
    }
};