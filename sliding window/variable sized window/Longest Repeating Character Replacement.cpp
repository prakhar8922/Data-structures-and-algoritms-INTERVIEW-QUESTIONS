// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = -1;
        int maxir = 0;
        while (j < n)
        {
            mp[s[j]]++;
            maxir = max(maxir, mp[s[j]]); // maximum repeating character freq
            if ((j - i + 1) - maxir > k)
            {               // if the current window has more than k replaceable characters
                mp[s[i]]--; // reduce the window size so as to limit the max number of unrepeating char
                // to k replacebale char
                i++;
            }
            ans = max(ans, j - i + 1); // max of the already found out window size and the newly formed window size

            j++;
        }
        return ans;
    }
};
