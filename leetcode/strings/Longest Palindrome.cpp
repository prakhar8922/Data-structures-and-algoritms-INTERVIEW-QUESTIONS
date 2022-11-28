// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto it : s)
            mp[it]++;
        int ans = 0;
        bool odd = false;
        for (auto it : mp)
        {
            if (it.second % 2 == 0) // if even occurences then add the length to ans
            {
                ans += it.second;
            }
            else
            {
                odd = true;
                ans += it.second - 1; // if odd occurences then subtract 1 from all odd counts to make them even and add them to ans
            }
        }
        if (odd)
        {
            ans++; // if odd count is present then add it to the result
        }
        return ans;
    }
};