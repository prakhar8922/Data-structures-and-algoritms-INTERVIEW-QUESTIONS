// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

// You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

// Return the minimum number of flips to make s monotone increasing.

// Example 1:

// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:

// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
// Example 3:

// Input: s = "00011000"
// Output: 2
// Explanation: We flip to get 00000000.

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '0' or '1'.

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int cnt1 = 0, cntflp = 0;
        for (auto it : s)
        {
            if (it == '1')
            {
                cnt1++;
            }
            else
            { // Keep is as 0 and flip all the 1 so far ,for that we need to know about the count the one so far
                // Flip it to 1 and update our count_flip
                // Take the minmum of count_flip and count_one and update the count_flip because we want minimum
                cntflp = min(++cntflp, cnt1);
            }
        }
        return cntflp;
    }
};